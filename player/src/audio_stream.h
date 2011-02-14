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

#ifndef _EASYRPG_AUDIOSTREAM_H_
#define _EASYRPG_AUDIOSTREAM_H_

#include "system.h"
namespace Audio {

class AudioStream {
public:
	virtual ~AudioStream();

	virtual int ReadBuffer(int16* buf, const int samples) = 0;

	virtual bool IsStereo() = 0;

	virtual bool EndOfStream() = 0;

	virtual int GetRate() = 0;
};




}


#endif 
