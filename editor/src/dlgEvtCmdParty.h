/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG Editor.
//
// EasyRPG Editor is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// EasyRPG Editor is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLGEVTCMDPARTY_H_
#define _DLGEVTCMDPARTY_H_

////////////////////////////////////////////////////////////
/// @file
/// Subclass of dlgEvtCmdParty_Base, which is generated by wxFormBuilder.
////////////////////////////////////////////////////////////

#include "gui_events_page_1.h"

/// Implementing dlgEvtCmdParty_Base
class dlgEvtCmdParty : public dlgEvtCmdParty_Base {
public:
	/// Constructor
	dlgEvtCmdParty(wxWindow* parent);
private:
	/// Cancel dialog on click
	void btnCancel_click(wxCommandEvent& WXUNUSED(event));
};

#endif
