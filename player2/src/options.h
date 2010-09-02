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

#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#define RPG2K	1
#define RPG2K3	2

#define OUTPUT_NONE		0
#define OUTPUT_CONSOLE	1
#define OUTPUT_FILE		2
#define OUTPUT_MSGBOX	3
#define OUTPUT_SCREEN	4

////////////////////////////////////////////////////////////
/// RPGMAKER
///		Defines RPG Maker compability, RPG2K for RPG Maker 2000
///		and RPG2K3 for RPG Maker 2003.
////////////////////////////////////////////////////////////
#define RPGMAKER RPG2K

////////////////////////////////////////////////////////////
/// GAME_TITLE
///		Window title to show.
///
/// SCREEN_WIDTH SCREEN_HEIGHT
///		Screen default width and height.
///
/// BPP
///		Screen bits per pixel
///
/// ALLOW_FULLSCREEN_TOGGLE
///		Allows user to change fullscreen state.
///
/// RUN_FULLSCREEN
///		Run game in fullscreen mode.
///
/// PAUSE_GAME_WHEN_FOCUS_LOST PAUSE_AUDIO_WHEN_FOCUS_LOST
///		Pause the game process and/or audio when the player window
///		looses its focus.
////////////////////////////////////////////////////////////
#define GAME_TITLE "EasyRPG Player"
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#ifdef DINGOO
	#define BPP	16
#else
	#define BPP 32
#endif
#define ALLOW_FULLSCREEN_TOGGLE true
#define RUN_FULLSCREEN false
#define PAUSE_GAME_WHEN_FOCUS_LOST true
#define PAUSE_AUDIO_WHEN_FOCUS_LOST true

////////////////////////////////////////////////////////////
/// INI_NAME
///		INI configuration filename.
///
/// READ_INI_GAME_TITLE
///		Read game title from ini file.
///
/// DATABASE_NAME
///		Database filename.
////////////////////////////////////////////////////////////
#define INI_NAME "./RPG_RT.ini"
#define READ_INI_GAME_TITLE true
#define DATABASE_NAME "RPG_RT.ldb"
#define TREEMAP_NAME "RPG_RT.lmt"

////////////////////////////////////////////////////////////
/// DEFAULT_FPS
///		Default fps rate.
///
/// DEFAULT_BACKCOLOR
///		Default back color for the player window.
////////////////////////////////////////////////////////////
#define DEFAULT_FPS 60
#define DEFAULT_BACKCOLOR 0x00000000

////////////////////////////////////////////////////////////
/// OUTPUT_TYPE
///		OUTPUT_NONE - no output
///		OUTPUT_CONSOLE - print to console
///		OUTPUT_FILE - write to file
///		OUTPUT_MSGBOX - create pop up message box
///		OUTPUT_SCREEN - write to screen
///
/// OUTPUT_FILE
///		Name of the file for output.
////////////////////////////////////////////////////////////
#if DINGOO || UNIX
	#define OUTPUT_TYPE OUTPUT_FILE
#else
	#define OUTPUT_TYPE OUTPUT_MSGBOX
#endif
#define OUTPUT_FILENAME "log.txt"

#endif
