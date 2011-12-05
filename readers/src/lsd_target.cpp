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
#include "lsd_reader.h"
#include "lsd_chunks.h"
#include "reader_struct.h"

////////////////////////////////////////////////////////////
/// Read Saved Target
////////////////////////////////////////////////////////////
EASYRPG_STRUCT_ID_READER(SaveTarget, WithID)

EASYRPG_STRUCT_NAME(SaveTarget)

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveTarget

EASYRPG_STRUCT_FIELDS_BEGIN(SaveTarget)
	EASYRPG_STRUCT_TYPED_FIELD(int, map_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, map_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, map_y),
	EASYRPG_STRUCT_TYPED_FIELD(bool, switch_on),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_id),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
