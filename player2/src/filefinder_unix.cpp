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

#if UNIX || DINGOO

////////////////////////////////////////////////////////////
/// Headers
////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include "filefinder.h"

////////////////////////////////////////////////////////////
/// Global Variables
////////////////////////////////////////////////////////////
namespace FileFinder {
    std::string fonts_path;
    std::string rtp_path;
	std::string rtp_paths[3];
}

////////////////////////////////////////////////////////////
/// Initialize
////////////////////////////////////////////////////////////
void FileFinder::Init() {
    // TODO find default paths
	rtp_path = "";
	fonts_path = "";
}

////////////////////////////////////////////////////////////
/// To upper
////////////////////////////////////////////////////////////
static std::string str_toupper(std::string str) {
    std::string new_str = "";

    for (unsigned int i = 0; i <= str.length(); i++) {
        new_str += (char)toupper((int)str[i]);
    }
    return new_str;
}
static std::string str_toupper(char* str) {
    std::string new_str = "";

    for (unsigned int i = 0; i <= strlen(str); i++) {
        new_str += (char)toupper((int)str[i]);
    }
    return new_str;
}

////////////////////////////////////////////////////////////
/// Check if file exists
////////////////////////////////////////////////////////////
static bool fexists(std::string filename) {
	
	FILE *tempFile;
	tempFile = fopen(filename.c_str(), "r");
    if (tempFile) {
		fclose(tempFile);
		return true;
	}
	return false;
	
}

////////////////////////////////////////////////////////////
/// Make path
////////////////////////////////////////////////////////////
std::string slasher(std::string str) {
	for(unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == '\\') {
			str[i] = '/';
		}
	}
	return str;
}

////////////////////////////////////////////////////////////
/// Find image
////////////////////////////////////////////////////////////
std::string FileFinder::FindImage(std::string name) {
	
	name = slasher(name);
	std::string path = name;
	if (fexists(path)) return path;
	path = name; path += ".bmp";
	if (fexists(path)) return path;
	path = name; path += ".gif";
	if (fexists(path)) return path;
	path = name; path += ".png";
	if (fexists(path)) return path;
    path = name; path += ".xyz";
	if (fexists(path)) return path;
	for (int i = 0; i < 3; i++) {
		if (rtp_paths[i] != "") {
			std::string rtp_path = slasher(rtp_paths[i]);
			rtp_path += name;
			path = rtp_path;
			if (fexists(path)) return path;
			path = rtp_path; path += ".bmp";
			if (fexists(path)) return path;
			path = rtp_path; path += ".gif";
			if (fexists(path)) return path;
			path = rtp_path; path += ".png";
			if (fexists(path)) return path;
            path = rtp_path; path += ".xyz";
			if (fexists(path)) return path;
		}
	}

	return "";
}

////////////////////////////////////////////////////////////
/// Find music
////////////////////////////////////////////////////////////
std::string FileFinder::FindMusic(std::string name) {
	name = slasher(name);
	std::string path = name;
	if (fexists(path)) return path;
	path = name; path += ".wav";
	if (fexists(path)) return path;
	path = name; path += ".mid";
	if (fexists(path)) return path;
	path = name; path += ".midi";
	if (fexists(path)) return path;
	path = name; path += ".ogg";
	if (fexists(path)) return path;
	path = name; path += ".mp3";
	if (fexists(path)) return path;
	for (int i = 0; i < 3; i++) {
		if (rtp_paths[i] != "") {
			std::string rtp_path = slasher(rtp_paths[i]);
			rtp_path += name;
			path = rtp_path;
			if (fexists(path)) return path;
			path = rtp_path; path += ".wav";
			if (fexists(path)) return path;
			path = rtp_path; path += ".mid";
			if (fexists(path)) return path;
			path = rtp_path; path += ".midi";
			if (fexists(path)) return path;
			path = rtp_path; path += ".ogg";
			if (fexists(path)) return path;
			path = rtp_path; path += ".mp3";
			if (fexists(path)) return path;
		}
	}
	return "";
}

////////////////////////////////////////////////////////////
/// Find font
////////////////////////////////////////////////////////////
std::string FileFinder::FindFont(std::string name) {
	name = slasher(name);
	std::string path = name;
	if (fexists(path)) return path;
	path = name; path += ".ttf";
	if (fexists(path)) return path;

	path = fonts_path; path += name;
	if (fexists(path)) return path;
	path = fonts_path; path += name; path += ".ttf";
	if (fexists(path)) return path;

	return "";
}

#endif
