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

#ifndef _GAME_PARTY_H_
#define _GAME_PARTY_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <map>
#include "game_actor.h"
#include "main_data.h"

////////////////////////////////////////////////////////////
/// Game_Party class
////////////////////////////////////////////////////////////
namespace Game_Party {
	////////////////////////////////////////////////////////
	/// Initialize Game_Party.
	////////////////////////////////////////////////////////
	void Init();

	////////////////////////////////////////////////////////
	/// Initial party setup.
	////////////////////////////////////////////////////////
	void SetupStartingMembers();

	////////////////////////////////////////////////////////
	/// Battle test party setup.
	////////////////////////////////////////////////////////
	//void SetupBattleTestMembers();

	////////////////////////////////////////////////////////
	/// Refresh party members.
	////////////////////////////////////////////////////////
	//void Refresh();

	////////////////////////////////////////////////////////
	/// Get maximum level.
	/// @return max party level.
	////////////////////////////////////////////////////////
	//int MaxLevel();

	////////////////////////////////////////////////////////
	/// Add an actor.
	/// @param actor_id : database actor id
	////////////////////////////////////////////////////////
	void AddActor(int actor_id);

	////////////////////////////////////////////////////////
	/// Remove an actor.
	/// @param actor_id : database actor id
	////////////////////////////////////////////////////////
	void RemoveActor(int actor_id);

	////////////////////////////////////////////////////////
	/// Get if an actor is in party.
	/// @param actor : actor object
	/// @return whether the actor is in party.
	////////////////////////////////////////////////////////
	bool IsActorInParty(Game_Actor* actor_id);

	////////////////////////////////////////////////////////
	/// Gain gold.
	/// @param value : gained gold
	////////////////////////////////////////////////////////
	void GainGold(int value);

	////////////////////////////////////////////////////////
	/// Lose gold.
	/// @param value : lost gold
	////////////////////////////////////////////////////////
	//void LoseGold(int value);

	////////////////////////////////////////////////////////
	/// Increase steps in 1.
	////////////////////////////////////////////////////////
	//void IncreaseSteps();

	////////////////////////////////////////////////////////
	/// Get number of possessed items.
	/// @param item_id : database item id
	/// @return number of items
	////////////////////////////////////////////////////////
	int ItemNumber(int item_id);

	////////////////////////////////////////////////////////
	/// Gain an amount of items.
	/// @param item_id : database item id
	/// @param number : gained quantity
	////////////////////////////////////////////////////////
	void GainItem(int item_id, int number);

	////////////////////////////////////////////////////////
	/// Lose an amount of items.
	/// @param item_id : database item id
	/// @param number : lost quantity
	////////////////////////////////////////////////////////
	//void LoseItem(int item_id, int number);

	////////////////////////////////////////////////////////
	/// Get if item can be used.
	/// @param item_id : database item id
	/// @return whether the item can be used
	////////////////////////////////////////////////////////
	//bool IsItemUsable(item_id);

	////////////////////////////////////////////////////////
	/// Clear all actors in party actions.
	////////////////////////////////////////////////////////
	//void ClearActions();

	////////////////////////////////////////////////////////
	/// Determine if a command can be inputed.
	/// @return whether a command can be inputed
	////////////////////////////////////////////////////////
	//bool IsInputable();

	////////////////////////////////////////////////////////
	/// Determine if everyone is dead.
	/// @return whether all are dead
	////////////////////////////////////////////////////////
	//bool AreAllDdead();

	////////////////////////////////////////////////////////
	/// Slip damage check.
	////////////////////////////////////////////////////////
	//void CheckMapSlipDamage();

	////////////////////////////////////////////////////////
	/// Random selection of target actor.
	/// @param hp0 : only targets actors with 0 hp
	/// @return target actor
	////////////////////////////////////////////////////////
	//Game_Actor* RandomTargetActor(bool hp0 = false);

	////////////////////////////////////////////////////////
	/// Smooth selection of target actor.
	/// @param actor_index : actor index in party
	/// @return target actor
	////////////////////////////////////////////////////////
	//Game_Actor* SmoothTargetActor(int actor_index);

	/// @return gold possessed
	int GetGold();

	/// @return steps walked
	int GetSteps();

	/// @return actors in party list
	std::vector<Game_Actor*>& GetActors();

	/// @return number of battles
	int GetBattleCount();

	/// @return number of battles wins
	int GetWinCount();

	/// @return number of battles defeats
	int GetDefeatCount();

	/// @return number of battles escaped
	int GetRunCount();
}

#endif
