// -*- C++ -*- generated by wxGlade 0.6.3 on Sun Feb 15 04:53:05 2009 from "/home/fdelapena/programacion/easyrpg/trunk/editor/wxglade/easyrpg.wxg"

#include "DialogEvtCmdSavePermissions.h"

// begin wxGlade: ::extracode

// end wxGlade


DialogEvtCmdSavePermissions::DialogEvtCmdSavePermissions(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long WXUNUSED(style)):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxTHICK_FRAME)
{
    // begin wxGlade: DialogEvtCmdSavePermissions::DialogEvtCmdSavePermissions
    const wxString rbOperation_choices[] = {
        _("Forbid saving"),
        _("Alllow saving")
    };
    rbOperation = new wxRadioBox(this, wxID_ANY, _("Operation"), wxDefaultPosition, wxDefaultSize, 2, rbOperation_choices, 1, wxRA_SPECIFY_ROWS);
    btnOK = new wxButton(this, wxID_OK, wxEmptyString);
    btnCancel = new wxButton(this, wxID_CANCEL, wxEmptyString);
    btnHelp = new wxButton(this, wxID_HELP, wxEmptyString);

    set_properties();
    do_layout();
    // end wxGlade
}


void DialogEvtCmdSavePermissions::set_properties()
{
    // begin wxGlade: DialogEvtCmdSavePermissions::set_properties
    SetTitle(_("Save permissions"));
    rbOperation->SetSelection(0);
    btnOK->SetDefault();
    // end wxGlade
}


void DialogEvtCmdSavePermissions::do_layout()
{
    // begin wxGlade: DialogEvtCmdSavePermissions::do_layout
    wxBoxSizer* szSavePermissions = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* szBottom = new wxBoxSizer(wxHORIZONTAL);
    szSavePermissions->Add(rbOperation, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 1);
    szBottom->Add(btnOK, 0, wxALL|wxALIGN_BOTTOM, 1);
    szBottom->Add(btnCancel, 0, wxALL|wxALIGN_BOTTOM, 1);
    szBottom->Add(btnHelp, 0, wxALL|wxALIGN_BOTTOM, 1);
    szSavePermissions->Add(szBottom, 1, wxRIGHT|wxBOTTOM|wxALIGN_RIGHT, 3);
    SetSizer(szSavePermissions);
    szSavePermissions->Fit(this);
    Layout();
    // end wxGlade
}
