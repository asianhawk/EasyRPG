/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG Player.
// 
// EasyRPG Player is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// EasyRPG Player is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "rpg_item.h"
#include "rpg_skill.h"
#include "rpg_enemyaction.h"
#include "game_system.h"
#include "game_party.h"
#include "game_switches.h"
#include "scene_battle.h"

////////////////////////////////////////////////////////////
void Scene_Battle::AttackEnemy(Battle::Ally& ally, Battle::Enemy& enemy) {
	const RPG::Item& weapon = Data::items[ally.game_actor->GetWeaponId() - 1];
	double to_hit = 100 - (100 - weapon.hit) * (1 + (1.0 * enemy.game_enemy->GetAgi() / ally.GetActor()->GetAgi() - 1) / 2);

	if (rand() % 100 < to_hit) {
		int effect = ally.GetActor()->GetAtk() / 2 - enemy.game_enemy->GetDef() / 4;
		if (effect < 0)
			effect = 0;
		int act_perc = (rand() % 40) - 20;
		int change = effect * act_perc / 100;
		effect += change;

		enemy.game_enemy->SetHp(enemy.game_enemy->GetHp() - effect);
		Floater(enemy.sprite, Font::ColorDefault, effect, 60);
	}
	else
		Floater(enemy.sprite, Font::ColorDefault, Data::terms.miss, 60);
}

////////////////////////////////////////////////////////////
void Scene_Battle::UseItem(Battle::Ally& ally, const RPG::Item& item, Battle::Ally* ally_target) {
	if (item.type != RPG::Item::Type_medicine)
		return;
	if (item.ocassion_field)
		return;

	if (!item.entire_party)
		UseItemAlly(ally, item, ally_target);
	else
		for (std::vector<Battle::Ally>::iterator it = allies.begin(); it != allies.end(); it++)
			UseItemAlly(ally, item, &*it);

	switch (item.uses) {
		case 0:
			// unlimited uses
			break;
		case 1:
			// single use
			Game_Party::LoseItem(item.ID, 1, false);
			item_window->Refresh();
			break;
		default:
			// multiple use
			// FIXME: we need a Game_Item type to hold the usage count
			break;
	}
}

////////////////////////////////////////////////////////////
void Scene_Battle::UseItemAlly(Battle::Ally& ally, const RPG::Item& item, Battle::Ally* target) {
	if (item.ko_only && !target->GetActor()->IsDead())
		return;

	// HP recovery
	int hp = item.recover_hp_rate * target->GetActor()->GetMaxHp() / 100 + item.recover_hp;
	target->GetActor()->SetHp(target->GetActor()->GetHp() + hp);

	// SP recovery
	int sp = item.recover_sp_rate * target->GetActor()->GetMaxSp() / 100 + item.recover_sp;
	target->GetActor()->SetSp(target->GetActor()->GetSp() + sp);

	if (hp > 0)
		Floater(target->sprite, 9, hp, 60);
	else if (sp > 0)
		Floater(target->sprite, 9, sp, 60);

	// Status recovery
	for (int i = 0; i < (int) item.state_set.size(); i++)
		if (item.state_set[i])
			target->GetActor()->RemoveState(i + 1);
}

////////////////////////////////////////////////////////////
void Scene_Battle::UseSkill(Battle::Ally& ally, const RPG::Skill& skill) {

	int sp = ally.GetActor()->CalculateSkillCost(skill.ID);
	if (sp > ally.GetActor()->GetSp()) // not enough SP
		return;

	switch (skill.type) {
		case RPG::Skill::Type_teleport:
			// FIXME: teleport skill
			break;
		case RPG::Skill::Type_escape:
			Escape();
			break;
		case RPG::Skill::Type_switch:
			if (!skill.occasion_battle)
				return;
			Game_Switches[skill.switch_id] = true;
			break;
		case RPG::Skill::Type_normal:
		default:
			switch (skill.scope) {
				case RPG::Skill::Scope_enemy:
					UseSkillEnemy(ally, skill, &enemies[target_enemy]);
					return;
				case RPG::Skill::Scope_enemies:
					for (std::vector<Battle::Enemy>::iterator it = enemies.begin(); it != enemies.end(); it++)
						UseSkillEnemy(ally, skill, &*it);
					break;
				case RPG::Skill::Scope_self:
					UseSkillAlly(ally, skill, &ally);
					break;
				case RPG::Skill::Scope_ally:
					UseSkillAlly(ally, skill, &allies[target_ally]);
					return;
				case RPG::Skill::Scope_party:
					for (std::vector<Battle::Ally>::iterator it = allies.begin(); it != allies.end(); it++)
						UseSkillAlly(ally, skill, &*it);
					break;
			}
			break;
	}

	if (skill.type != RPG::Skill::Type_normal)
		Game_System::SePlay(skill.sound_effect);

	ally.GetActor()->SetSp(ally.GetActor()->GetSp() - sp);
}

////////////////////////////////////////////////////////////
void Scene_Battle::UseSkillAlly(Battle::Battler& user, const RPG::Skill& skill, Battle::Battler* target) {
	Game_Battler* actor = target->GetActor();
	bool miss = true;

	if (skill.power > 0) {
		if (rand() % 100 < skill.hit) {
			miss = false;

			// FIXME: is this still affected by stats for allies?
			int effect = skill.power;

			if (skill.variance > 0) {
				int var_perc = skill.variance * 5;
				int act_perc = rand() % (var_perc * 2) - var_perc;
				int change = effect * act_perc / 100;
				effect += change;
			}

			if (skill.affect_hp)
				actor->SetHp(actor->GetHp() + effect);
			if (skill.affect_sp)
				actor->SetSp(actor->GetSp() + effect);
			if (skill.affect_attack)
				actor->SetAtk(actor->GetAtk() + effect);
			if (skill.affect_defense)
				actor->SetDef(actor->GetDef() + effect);
			if (skill.affect_spirit)
				actor->SetSpi(actor->GetSpi() + effect);
			if (skill.affect_agility)
				actor->SetAgi(actor->GetAgi() + effect);

			if (skill.affect_hp || skill.affect_sp)
				Floater(target->sprite, 9, effect, 60);
		}
	}

	for (int i = 0; i < (int) skill.state_effects.size(); i++) {
		if (!skill.state_effects[i])
			continue;
		if (rand() % 100 >= skill.hit)
			continue;

		miss = false;

		if (skill.state_effect)
			actor->AddState(i + 1);
		else
			actor->RemoveState(i + 1);
	}

	if (miss)
		Floater(target->sprite, Font::ColorDefault, Data::terms.miss, 60);
}

////////////////////////////////////////////////////////////
void Scene_Battle::UseSkillEnemy(Battle::Battler& user, const RPG::Skill& skill, Battle::Battler* target) {
	Game_Battler* actor = target->GetActor();
	bool miss = true;

	if (skill.power > 0) {
		if (rand() % 100 < skill.hit) {
			miss = false;

			// FIXME: This is what the help file says, but it doesn't look right
			int effect = skill.power +
				user.GetActor()->GetAtk() * skill.pdef_f / 20 + 
				actor->GetDef() * skill.mdef_f / 40;

			if (skill.variance > 0) {
				int var_perc = skill.variance * 5;
				int act_perc = rand() % (var_perc * 2) - var_perc;
				int change = effect * act_perc / 100;
				effect += change;
			}

			if (skill.affect_hp)
				actor->SetHp(actor->GetHp() - effect);
			if (skill.affect_sp)
				actor->SetSp(actor->GetSp() - effect);
			if (skill.affect_attack)
				actor->SetAtk(actor->GetAtk() - effect);
			if (skill.affect_defense)
				actor->SetDef(actor->GetDef() - effect);
			if (skill.affect_spirit)
				actor->SetSpi(actor->GetSpi() - effect);
			if (skill.affect_agility)
				actor->SetAgi(actor->GetAgi() - effect);

			if (skill.affect_hp || skill.affect_sp)
				Floater(target->sprite, Font::ColorDefault, effect, 60);
		}
	}

	for (int i = 0; i < (int) skill.state_effects.size(); i++) {
		if (!skill.state_effects[i])
			continue;
		if (rand() % 100 >= skill.hit)
			continue;

		miss = false;

		if (skill.state_effect)
			actor->RemoveState(i + 1);
		else
			actor->AddState(i + 1);
	}

	if (miss)
		Floater(target->sprite, Font::ColorDefault, Data::terms.miss, 60);
}

////////////////////////////////////////////////////////////
bool Scene_Battle::EnemyActionValid(const RPG::EnemyAction& action, Battle::Enemy* enemy) {
	switch (action.condition_type) {
		case RPG::EnemyAction::ConditionType_always:
			return true;
		case RPG::EnemyAction::ConditionType_switch:
			return Game_Switches[action.switch_id];
		case RPG::EnemyAction::ConditionType_turn:
		{
			int interval = action.condition_param2 == 0 ? 1 : action.condition_param2;
			int turns = turn_fragments / turn_length;
			return (turns - action.condition_param1) % interval == 0;
		}
		case RPG::EnemyAction::ConditionType_actors:
		{
			int count = 0;
			for (std::vector<Battle::Enemy>::const_iterator it = enemies.begin(); it != enemies.end(); it++)
				if (it->game_enemy->Exists())
					count++;
			return count >= action.condition_param1 && count <= action.condition_param2;
		}
		case RPG::EnemyAction::ConditionType_hp:
		{
			int hp_percent = enemy->game_enemy->GetHp() * 100 / enemy->game_enemy->GetMaxHp();
			return hp_percent >= action.condition_param1 && hp_percent <= action.condition_param2;
		}
		case RPG::EnemyAction::ConditionType_sp:
		{
			int sp_percent = enemy->game_enemy->GetSp() * 100 / enemy->game_enemy->GetMaxSp();
			return sp_percent >= action.condition_param1 && sp_percent <= action.condition_param2;
		}
		case RPG::EnemyAction::ConditionType_party_lvl:
		{
			int party_lvl = 0;
			for (std::vector<Battle::Ally>::const_iterator it = allies.begin(); it != allies.end(); it++)
				party_lvl += it->game_actor->GetLevel();
			party_lvl /= allies.size();
			return party_lvl >= action.condition_param1 && party_lvl <= action.condition_param2;
		}
		case RPG::EnemyAction::ConditionType_party_fatigue:
		{
			int party_exh = 0;
			for (std::vector<Battle::Ally>::const_iterator it = allies.begin(); it != allies.end(); it++)
				// FIXME: this is what the help file says, but it looks wrong
				party_exh += 100 - (200 * it->GetActor()->GetHp() / it->GetActor()->GetMaxHp() -
									100 * it->GetActor()->GetSp() / it->GetActor()->GetMaxSp() / 3);
			party_exh /= allies.size();
			return party_exh >= action.condition_param1 && party_exh <= action.condition_param2;
		}
		default:
			return true;
	}
}

////////////////////////////////////////////////////////////
const RPG::EnemyAction* Scene_Battle::ChooseEnemyAction(Battle::Enemy* enemy) {
	const std::vector<RPG::EnemyAction>& actions = enemy->rpg_enemy->actions;
	std::vector<int> valid;
	std::vector<RPG::EnemyAction>::const_iterator it;
	int total = 0;
	for (int i = 0; i < (int) actions.size(); i++) {
		const RPG::EnemyAction& action = actions[i];
		if (EnemyActionValid(action, enemy)) {
			valid.push_back(i);
			total += action.rating;
		}
	}

	int which = rand() % total;
	for (std::vector<int>::const_iterator it = valid.begin(); it != valid.end(); it++) {
		const RPG::EnemyAction& action = actions[*it];
		if (which >= action.rating) {
			which -= action.rating;
			continue;
		}

		return &action;
	}

	return NULL;
}

////////////////////////////////////////////////////////////
void Scene_Battle::EnemyAttackAlly(Battle::Enemy& enemy, Battle::Ally& ally) {
	if (ally.GetActor()->IsDead())
		return;

	int hit = enemy.rpg_enemy->miss ? 70 : 90;
	double to_hit = 100 - (100 - hit) * (1 + (1.0 * ally.GetActor()->GetAgi() / enemy.game_enemy->GetAgi() - 1) / 2);

	if (rand() % 100 < to_hit) {
		int effect = enemy.game_enemy->GetAtk() / 2 - ally.GetActor()->GetDef() / 4;
		if (effect < 0)
			effect = 0;
		int act_perc = (rand() % 40) - 20;
		int change = effect * act_perc / 100;
		effect += change;

		ally.GetActor()->SetHp(ally.GetActor()->GetHp() - effect);
		Floater(ally.sprite, Font::ColorDefault, effect, 60);
	}
	else
		Floater(ally.sprite, Font::ColorDefault, Data::terms.miss, 60);
}

////////////////////////////////////////////////////////////
void Scene_Battle::EnemySkill(Battle::Enemy& enemy, const RPG::Skill& skill) {
	int sp = enemy.game_enemy->CalculateSkillCost(skill.ID);
	if (sp > enemy.game_enemy->GetSp()) // not enough SP
		return;

	switch (skill.type) {
		case RPG::Skill::Type_teleport:
			// FIXME: can monsters teleport?
			EnemyEscape();
			break;
		case RPG::Skill::Type_escape:
			EnemyEscape();
			break;
		case RPG::Skill::Type_switch:
			if (!skill.occasion_battle)
				return;
			Game_Switches[skill.switch_id] = true;
			break;
		case RPG::Skill::Type_normal:
		default:
			switch (skill.scope) {
				case RPG::Skill::Scope_enemy:
					UseSkillAlly(enemy, skill, &allies[target_ally]);
					return;
				case RPG::Skill::Scope_enemies:
					for (std::vector<Battle::Ally>::iterator it = allies.begin(); it != allies.end(); it++)
						UseSkillAlly(enemy, skill, &*it);
					break;
				case RPG::Skill::Scope_self:
					UseSkillEnemy(enemy, skill, &enemy);
					break;
				case RPG::Skill::Scope_ally:
					UseSkillEnemy(enemy, skill, &enemies[target_enemy]);
					return;
				case RPG::Skill::Scope_party:
					for (std::vector<Battle::Enemy>::iterator it = enemies.begin(); it != enemies.end(); it++)
						UseSkillEnemy(enemy, skill, &*it);
					break;
			}
			break;
	}

	if (skill.type != RPG::Skill::Type_normal)
		Game_System::SePlay(skill.sound_effect);

	enemy.game_enemy->SetSp(enemy.game_enemy->GetSp() - sp);
}

