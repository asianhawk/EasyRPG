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

#ifndef _PLAYER_H_
#define _PLAYER_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "baseui.h"

////////////////////////////////////////////////////////////
/// Player namespace.
////////////////////////////////////////////////////////////
namespace Player {
	////////////////////////////////////////////////////////
	/// Initialize EasyRPG player.
	////////////////////////////////////////////////////////
	void Init();

	////////////////////////////////////////////////////////
	/// Run the game engine.
	////////////////////////////////////////////////////////
	void Run();

	////////////////////////////////////////////////////////
	/// Pause the game engine.
	////////////////////////////////////////////////////////
	void Pause();

	////////////////////////////////////////////////////////
	/// Resume the game engine.
	////////////////////////////////////////////////////////
	void Resume();

	////////////////////////////////////////////////////////
	/// Update EasyRPG player.
	////////////////////////////////////////////////////////
	void Update();

	////////////////////////////////////////////////////////
	/// Exit EasyRPG player.
	////////////////////////////////////////////////////////
	void Exit();

	/// Exit flag, if true will exit application on next Player::Update.
	extern bool exit_flag;

	/// Reset flag, if true will restart game on next Player::Update.
	extern bool reset_flag;
}

#endif
