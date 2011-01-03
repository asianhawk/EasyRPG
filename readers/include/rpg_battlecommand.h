/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG.
//
// EasyRPG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// EasyRPG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

#ifndef _RPG_BATTLECOMMAND_H_
#define _RPG_BATTLECOMMAND_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <vector>

////////////////////////////////////////////////////////////
/// RPG::BattleCommand class
////////////////////////////////////////////////////////////
namespace RPG {
	class BattleCommand {
	public:
		enum Type {
			Type_attack = 0,
			Type_skill = 1,
			Type_subskill = 2,
			Type_defense = 3,
			Type_item = 4,
			Type_escape = 5,
			Type_special = 6
		};

		BattleCommand();
		
		int ID;
		std::string name;
		int type;
	};

	class BattleCommands {
	public:
		BattleCommands();
		
		std::vector<RPG::BattleCommand> commands;
		int placement;
		int row;
		int battle_type;
		int death_handler1;
		int unknown1;
		int death_handler2;
		int death_event;
		int window_size;
		int transparency;
		bool teleport;
		int teleport_id;
		int teleport_x;
		int teleport_y;
		int teleport_face;
	};
}

#endif
