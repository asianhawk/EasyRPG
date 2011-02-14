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
#include "data.h"
#include "player.h"
#include "sprite.h"
#include "cache.h"
#include "battle_battler.h"

////////////////////////////////////////////////////////////
Battle::Enemy::Enemy(const RPG::TroopMember* member, int id) :
	Battler(Battler::Side_Enemy, id),
	game_enemy(new Game_Enemy(member->ID)),
	member(member),
	rpg_enemy(&Data::enemies[member->ID - 1]),
	fade(0),
	defending(false),
	charged(false),
	escaped(false)
{
	speed = 25 + rand() % 10;
	game_enemy->SetHidden(member->invisible);
}

void Battle::Enemy::CreateSprite() {
	Bitmap* graphic = Cache::Monster(rpg_enemy->battler_name);
	bool hue_change = rpg_enemy->battler_hue != 0;
	if (hue_change) {
		Surface* new_graphic = Surface::CreateSurface(graphic->GetWidth(), graphic->GetHeight());
		new_graphic->HueChangeBlit(0, 0, graphic, graphic->GetRect(), rpg_enemy->battler_hue);
		delete graphic;
		graphic = new_graphic;
	}

	sprite = new Sprite();
	sprite->SetBitmap(graphic, hue_change);
	sprite->SetOx(graphic->GetWidth() / 2);
	sprite->SetOy(graphic->GetHeight() / 2);
	sprite->SetX(member->x);
	sprite->SetY(member->y);
	sprite->SetZ(member->y);
	sprite->SetVisible(!game_enemy->IsHidden());
}

void Battle::Enemy::Transform(int enemy_id) {
	rpg_enemy = &Data::enemies[enemy_id - 1];
	game_enemy->Transform(enemy_id);
	delete sprite;
	CreateSprite();
}

////////////////////////////////////////////////////////////
Battle::Ally::Ally(Game_Actor* game_actor, int id) :
	Battler(Battler::Side_Ally, id),
	game_actor(game_actor),
	rpg_actor(&Data::actors[game_actor->GetId() - 1]),
	sprite_frame(-1),
	sprite_file(""),
	anim_state(Idle),
	defending(false)
{
	speed = 30 + rand() % 10;
}

void Battle::Ally::CreateSprite() {
	if (Player::engine != Player::EngineRpg2k3)
		return;

	sprite = new Sprite();
	sprite->SetOx(24);
	sprite->SetOy(24);
	sprite->SetX(rpg_actor->battle_x);
	sprite->SetY(rpg_actor->battle_y);
	sprite->SetZ(rpg_actor->battle_y);

	SetAnimState(anim_state);
	UpdateAnim(0);
}

void Battle::Ally::SetAnimState(int state) {
	if (Player::engine != Player::EngineRpg2k3)
		return;

	anim_state = state;

	const RPG::BattlerAnimation& anim = Data::battleranimations[rpg_actor->battler_animation - 1];
	const RPG::BattlerAnimationExtension& ext = anim.base_data[anim_state - 1];
	if (ext.battler_name == sprite_file)
		return;

	sprite_file = ext.battler_name;
	sprite->SetBitmap(Cache::BattleCharset(sprite_file));
}

void Battle::Ally::UpdateAnim(int cycle) {
	if (Player::engine != Player::EngineRpg2k3)
		return;

	static const int frames[] = {0,1,2,1};
	int frame = frames[(cycle / 15) % 4];
	if (frame == sprite_frame)
		return;

	const RPG::BattlerAnimation& anim = Data::battleranimations[rpg_actor->battler_animation - 1];
	const RPG::BattlerAnimationExtension& ext = anim.base_data[anim_state - 1];

	sprite->SetSrcRect(Rect(frame * 48, ext.battler_index * 48, 48, 48));
}

