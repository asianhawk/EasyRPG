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
#include "lmu_reader.h"
#include "lmu_chunks.h"
#include "reader_struct.h"

////////////////////////////////////////////////////////////
/// Read Move Route
////////////////////////////////////////////////////////////
EASYRPG_STRUCT_ID_READER(MoveRoute, NoID)

EASYRPG_STRUCT_NAME(MoveRoute)

#define EASYRPG_CHUNK_SUFFIX LMU_Reader
#define EASYRPG_CURRENT_STRUCT MoveRoute

EASYRPG_STRUCT_FIELDS_BEGIN(MoveRoute)
	EASYRPG_STRUCT_SIZE_FIELD(RPG::MoveCommand, move_commands),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::MoveCommand> , move_commands),
	EASYRPG_STRUCT_TYPED_FIELD(bool, repeat),
	EASYRPG_STRUCT_TYPED_FIELD(bool, skippable),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX

