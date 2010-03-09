//////////////////////////////////////////////////////////////////////////////////
/// This file is part of EasyRPG Player.
/// 
/// EasyRPG Player is free software: you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
/// 
/// EasyRPG Player is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU General Public License for more details.
/// 
/// You should have received a copy of the GNU General Public License
/// along with EasyRPG Player.  If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// Headers
////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <stdarg.h>
#include "output.h"
#include "options.h"
#include "player.h"
#include "msgbox.h"
#include "graphics.h"

////////////////////////////////////////////////////////////
/// Output Error
////////////////////////////////////////////////////////////
void Output::Error(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char str[256];
#ifdef MSVC
    vsprintf_s(str, 256, fmt, args);
#else
    vsprintf(str, fmt, args);
#endif
    Output::ErrorStr((std::string)str);

    va_end(args);
}
void Output::ErrorStr(std::string err){
    if (OUTPUT_TYPE == OUTPUT_CONSOLE) {
        std::cout << err << std::endl;
        std::cout << std::endl;
        std::cout << "EasyRPG Player will close now. Press any key..." << std::endl;
        #ifdef MSVC
            _getch();
        #else
            getch();
        #endif
    }
    else if (OUTPUT_TYPE == OUTPUT_FILE) {
        std::ofstream file;
        file.open(OUTPUT_FILENAME, std::ios::out | std::ios::app);
        file << err;
        file.close();
    }
    else if (OUTPUT_TYPE == OUTPUT_MSGBOX) {
        MsgBox::Error(err, GAME_TITLE);
    }
    Player::Exit();
}

////////////////////////////////////////////////////////////
/// Output Warning
////////////////////////////////////////////////////////////
void Output::Warning(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char str[256];
#ifdef MSVC
    vsprintf_s(str, 256, fmt, args);
#else
    vsprintf(str, fmt, args);
#endif
    Output::WarningStr((std::string)str);

    va_end(args);
}
void Output::WarningStr(std::string warn) {
    if (OUTPUT_TYPE == OUTPUT_CONSOLE) {
        std::cout << warn << std::endl;
    }
    else if (OUTPUT_TYPE == OUTPUT_FILE) {
        std::ofstream file;
        file.open(OUTPUT_FILENAME, std::ios::out | std::ios::app);
        file << warn;
        file.close();
    }
    else if (OUTPUT_TYPE == OUTPUT_MSGBOX) {
        Graphics::TimerWait();
        MsgBox::Warning(warn, GAME_TITLE);
        Graphics::TimerContinue();
    }
}

////////////////////////////////////////////////////////////
/// Output Post message 
////////////////////////////////////////////////////////////
void Output::Post(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char str[256];
#ifdef MSVC
    vsprintf_s(str, 256, fmt, args);
#else
    vsprintf(str, fmt, args);
#endif
    Output::PostStr((std::string)str);

    va_end(args);
}
void Output::PostStr(std::string msg) {
    if (OUTPUT_TYPE == OUTPUT_CONSOLE) {
        std::cout << msg << std::endl;
    }
    else if (OUTPUT_TYPE == OUTPUT_FILE) {
        std::ofstream file;
        file.open(OUTPUT_FILENAME, std::ios::out | std::ios::app);
        file << msg;
        file.close();
    }
    else if (OUTPUT_TYPE == OUTPUT_MSGBOX) {
        Graphics::TimerWait();
        MsgBox::OK(msg, GAME_TITLE);
        Graphics::TimerContinue();
    }
}