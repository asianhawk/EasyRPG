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
/// Read BattleCommand
////////////////////////////////////////////////////////////
template <>
IDReader<RPG::BattleCommand>* Struct<RPG::BattleCommand>::ID_reader = new IDReaderT<RPG::BattleCommand, WithID>();

template <>
const std::string Struct<RPG::BattleCommand>::name("BattleCommand");

template <>
const Field<RPG::BattleCommand>* Struct<RPG::BattleCommand>::fields[] = {
	new TypedField<RPG::BattleCommand, std::string>	(&RPG::BattleCommand::name,	LDB_Reader::ChunkBattleCommand::name,	"name"),
	new TypedField<RPG::BattleCommand, int>			(&RPG::BattleCommand::type,	LDB_Reader::ChunkBattleCommand::type,	"type"),
	NULL
};
