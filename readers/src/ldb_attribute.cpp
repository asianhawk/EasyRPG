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
/// Read Attribute
////////////////////////////////////////////////////////////
RPG::Attribute LDB_Reader::ReadAttribute(Reader& stream) {
	RPG::Attribute attribute;
	attribute.ID = stream.Read32(Reader::CompressedInteger);

	Reader::Chunk chunk_info;
	while (!stream.Eof()) {
		chunk_info.ID = stream.Read32(Reader::CompressedInteger);
		if (chunk_info.ID == ChunkData::END) {
			break;
		} else {
			chunk_info.length = stream.Read32(Reader::CompressedInteger);
			if (chunk_info.length == 0) continue;
		}
		switch (chunk_info.ID) {
		case ChunkAttribute::name:
			attribute.name = stream.ReadString(chunk_info.length);
			break;
		case ChunkAttribute::type:
			attribute.type = stream.Read32(Reader::CompressedInteger);
			break;
		case ChunkAttribute::a_rate:
			attribute.a_rate = stream.Read32(Reader::CompressedInteger);
			break;
		case ChunkAttribute::b_rate:
			attribute.b_rate = stream.Read32(Reader::CompressedInteger);
			break;
		case ChunkAttribute::c_rate:
			attribute.c_rate = stream.Read32(Reader::CompressedInteger);
			break;
		case ChunkAttribute::d_rate:
			attribute.d_rate = stream.Read32(Reader::CompressedInteger);
			break;
		case ChunkAttribute::e_rate:
			attribute.e_rate = stream.Read32(Reader::CompressedInteger);
			break;
		default:
			stream.Seek(chunk_info.length, Reader::FromCurrent);
		}
	}
	return attribute;
}
