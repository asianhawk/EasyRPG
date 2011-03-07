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
#include "lmt_reader.h"
#include "lmt_chunks.h"
#include "data.h"
#include "reader_util.h"
#include "reader_struct.h"

////////////////////////////////////////////////////////////
/// Load Map Tree
////////////////////////////////////////////////////////////
bool LMT_Reader::Load(const std::string& filename) {
	LcfReader reader(filename, ReaderUtil::GetEncoding());
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't find %s map tree file.\n", filename.c_str());
		return false;
	}
	std::string header;
	reader.ReadString(header, reader.ReadInt());
	if (header != "LcfMapTree") {
		LcfReader::SetError("%s is not a valid RPG2000 map tree.\n", filename.c_str());
		return false;
	}
	TypeReader<RPG::TreeMap>::ReadLcf(Data::treemap, reader, 0);
	return true;
}

////////////////////////////////////////////////////////////
/// Save Map Tree
////////////////////////////////////////////////////////////
bool LMT_Reader::Save(const std::string& filename) {
	LcfWriter writer(filename, ReaderUtil::GetEncoding());
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't find %s map tree file.\n", filename.c_str());
		return false;
	}
	const std::string header("LcfMapTree");
	writer.WriteInt(header.size());
	writer.Write(header);
	TypeReader<RPG::TreeMap>::WriteLcf(Data::treemap, writer);
	return true;
}

////////////////////////////////////////////////////////////
/// Save Map Tree as Xml
////////////////////////////////////////////////////////////
bool LMT_Reader::SaveXml(const std::string& filename) {
	XmlWriter writer(filename);
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't find %s map tree file.\n", filename.c_str());
		return false;
	}
	writer.BeginElement("LMT");
	TypeReader<RPG::TreeMap>::WriteXml(Data::treemap, writer);
	writer.EndElement("LMT");
	return true;
}

////////////////////////////////////////////////////////////
/// Load Map Tree as XML
////////////////////////////////////////////////////////////
bool LMT_Reader::LoadXml(const std::string& filename) {
	XmlReader reader(filename);
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't open %s map tree file.\n", filename.c_str());
		return false;
	}
	reader.SetHandler(new RootXmlHandler<RPG::TreeMap>(Data::treemap, "LMT"));
	reader.Parse();
	return true;
}

