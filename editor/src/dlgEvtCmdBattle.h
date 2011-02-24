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

#ifndef _DLGEVTCMDBATTLE_H_
#define _DLGEVTCMDBATTLE_H_

////////////////////////////////////////////////////////////
/// @file
/// Subclass of dlgEvtCmdBattle_Base, which is generated by wxFormBuilder.
////////////////////////////////////////////////////////////

#include "gui_events_page_2.h"

/// Implementing dlgEvtCmdBattle_Base
class dlgEvtCmdBattle : public dlgEvtCmdBattle_Base {
public:
	/// Constructor
	dlgEvtCmdBattle(wxWindow* parent);
private:
	/// Cancel dialog on click
	void btnCancel_click(wxCommandEvent& WXUNUSED(event));
};

#endif
