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
#include "reader_lcf.h"
#include "reader_struct.h"

////////////////////////////////////////////////////////////
/// Read Animation
////////////////////////////////////////////////////////////
EASYRPG_STRUCT_ID_READER(Animation, WithID)

EASYRPG_STRUCT_NAME(Animation)

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT Animation

EASYRPG_STRUCT_FIELDS_BEGIN(Animation)
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, animation_name),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::AnimationTiming> , timings),
	EASYRPG_STRUCT_TYPED_FIELD(int, scope),
	EASYRPG_STRUCT_TYPED_FIELD(int, position),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::AnimationFrame> , frames),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
