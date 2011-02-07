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

#ifndef _EASYRPG_CHANNEL_H_
#define _EASYRPG_CHANNEL_H_

#include "system.h"
#include "resampler.h"


namespace Audio {

class Channel {
public:

	typedef int16* pBuf;

	Channel(uint16 _rate, uint16 _vol, uint8 _balance, pBuf& data);
	~Channel();

	void Pause() { paused = true; }
	void Resume() { paused = false; }
	bool Paused() const { return paused; }

	void SetBalance(uint8 b) { balance = b; }
	uint8 GetBalance() const { return balance; }

	void SetVolume(uint16 v) { vol = v; }
	uint16 GetVolume() const { return vol; }

	void Mix(int16 *stream, int len);


private:

	Resampler *resampler;

	uint16 rate;
	uint16 vol;
	uint8 balance;
	pBuf buffer;
	bool paused;

};

}

#endif
