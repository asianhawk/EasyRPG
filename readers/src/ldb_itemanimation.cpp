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
#include "reader_struct.h"

////////////////////////////////////////////////////////////
/// Read ItemAnimation
////////////////////////////////////////////////////////////
EASYRPG_STRUCT_ID_READER(ItemAnimation, WithID)

EASYRPG_STRUCT_NAME(ItemAnimation)

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT ItemAnimation

EASYRPG_STRUCT_FIELDS_BEGIN(ItemAnimation)
	EASYRPG_STRUCT_TYPED_FIELD(int, type),
	EASYRPG_STRUCT_TYPED_FIELD(int, weapon_anim),
	EASYRPG_STRUCT_TYPED_FIELD(int, movement),
	EASYRPG_STRUCT_TYPED_FIELD(int, after_image),
	EASYRPG_STRUCT_TYPED_FIELD(int, attacks),
	EASYRPG_STRUCT_TYPED_FIELD(bool, ranged),
	EASYRPG_STRUCT_TYPED_FIELD(int, ranged_anim),
	EASYRPG_STRUCT_TYPED_FIELD(int, ranged_speed),
	EASYRPG_STRUCT_TYPED_FIELD(int, battle_anim),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
