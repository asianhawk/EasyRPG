// -*- C++ -*- generated by wxGlade 0.6.3 on Sun Feb 15 04:53:05 2009 from "/home/fdelapena/programacion/easyrpg/trunk/editor/wxglade/easyrpg.wxg"

#include "DialogEvtCmdSystemSound.h"

// begin wxGlade: ::extracode

// end wxGlade


DialogEvtCmdSystemSound::DialogEvtCmdSystemSound(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long WXUNUSED(style)):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxTHICK_FRAME)
{
    // begin wxGlade: DialogEvtCmdSystemSound::DialogEvtCmdSystemSound
    szSound_staticbox = new wxStaticBox(this, -1, _("Sound"));
    SzSystemSound2_staticbox = new wxStaticBox(this, -1, _("Sound type"));
    const wxString *chSystemSound_choices = NULL;
    chSystemSound = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, chSystemSound_choices, 0);
    tcSound = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    btnSound = new wxButton(this, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
    btnOK = new wxButton(this, wxID_OK, wxEmptyString);
    btnCancel = new wxButton(this, wxID_CANCEL, wxEmptyString);
    btnHelp = new wxButton(this, wxID_HELP, wxEmptyString);

    set_properties();
    do_layout();
    // end wxGlade
}


void DialogEvtCmdSystemSound::set_properties()
{
    // begin wxGlade: DialogEvtCmdSystemSound::set_properties
    SetTitle(_("Change system sound"));
    chSystemSound->SetMinSize(wxSize(50, -1));
    tcSound->SetMinSize(wxSize(50, -1));
    btnOK->SetDefault();
    // end wxGlade
}


void DialogEvtCmdSystemSound::do_layout()
{
    // begin wxGlade: DialogEvtCmdSystemSound::do_layout
    wxBoxSizer* szSystemSound = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* szBottom = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* szTop = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* szSound = new wxStaticBoxSizer(szSound_staticbox, wxHORIZONTAL);
    wxStaticBoxSizer* SzSystemSound2 = new wxStaticBoxSizer(SzSystemSound2_staticbox, wxHORIZONTAL);
    SzSystemSound2->Add(chSystemSound, 1, wxALIGN_CENTER_VERTICAL, 0);
    szTop->Add(SzSystemSound2, 1, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 1);
    szSound->Add(tcSound, 1, wxALIGN_CENTER_VERTICAL, 0);
    szSound->Add(btnSound, 0, wxALIGN_CENTER_VERTICAL, 0);
    szTop->Add(szSound, 1, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 1);
    szSystemSound->Add(szTop, 1, wxEXPAND, 0);
    szBottom->Add(btnOK, 0, wxALL, 1);
    szBottom->Add(btnCancel, 0, wxALL, 1);
    szBottom->Add(btnHelp, 0, wxALL, 1);
    szSystemSound->Add(szBottom, 0, wxRIGHT|wxBOTTOM|wxALIGN_RIGHT, 3);
    SetSizer(szSystemSound);
    szSystemSound->Fit(this);
    Layout();
    // end wxGlade
}
