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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "ldb_reader.h"
#include "ldb_chunks.h"
#include "reader.h"

////////////////////////////////////////////////////////////
/// Read AnimationTiming
////////////////////////////////////////////////////////////
RPG::AnimationTiming LDB_Reader::ReadAnimationTiming(Reader& stream) {
	RPG::AnimationTiming timing;
	stream.ReadInt();

	Reader::Chunk chunk_info;
	while (!stream.Eof()) {
		chunk_info.ID = stream.ReadInt();
		if (chunk_info.ID == ChunkData::END) {
			break;
		} else {
			chunk_info.length = stream.ReadInt();
			if (chunk_info.length == 0) continue;
		}
		switch (chunk_info.ID) {
		case ChunkAnimationTiming::frame:
			timing.frame = stream.ReadInt();
			break;
		case ChunkAnimationTiming::se:
			timing.se = ReadSound(stream);
			break;
		case ChunkAnimationTiming::flash_scope:
			timing.flash_scope = stream.ReadInt();
			break;
		case ChunkAnimationTiming::flash_red:
			timing.flash_red = stream.ReadInt();
			break;
		case ChunkAnimationTiming::flash_green:
			timing.flash_green = stream.ReadInt();
			break;
		case ChunkAnimationTiming::flash_blue:
			timing.flash_blue = stream.ReadInt();
			break;
		case ChunkAnimationTiming::flash_power:
			timing.flash_power = stream.ReadInt();
			break;
		case ChunkAnimationTiming::screen_shake:
			timing.screen_shake = stream.ReadInt();
			break;
		default:
			stream.Skip(chunk_info);
		}
	}
	return timing;
}
