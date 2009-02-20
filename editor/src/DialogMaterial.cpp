// -*- C++ -*- generated by wxGlade 0.6.3 on Sun Feb 15 04:53:05 2009 from "/home/fdelapena/programacion/easyrpg/trunk/editor/wxglade/easyrpg.wxg"

#include "DialogMaterial.h"

// begin wxGlade: ::extracode

// end wxGlade


DialogMaterial::DialogMaterial(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long WXUNUSED(style)):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxTHICK_FRAME)
{
    // begin wxGlade: DialogMaterial::DialogMaterial
    const wxString listFolders_choices[] = {
        _("Backdrop"),
        _("Battle"),
        _("CharSet"),
        _("ChipSet"),
        _("FaceSet"),
        _("GameOver"),
        _("Monster"),
        _("Movie"),
        _("Music"),
        _("Panorama"),
        _("Picture"),
        _("Sound"),
        _("System"),
        _("Title")
    };
    listFolders = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 14, listFolders_choices, 0);
    const wxString *listFiles_choices = NULL;
    listFiles = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, listFiles_choices, 0);
    btnImport = new wxButton(this, wxID_ANY, _("Import..."));
    btnExport = new wxButton(this, wxID_ANY, _("Export..."));
    btnDelete = new wxButton(this, wxID_ANY, _("Delete..."));
    const wxString rbFormat_choices[] = {
        _("PNG"),
        _("XYZ")
    };
    rbFormat = new wxRadioBox(this, wxID_ANY, _("Import/export as"), wxDefaultPosition, wxDefaultSize, 2, rbFormat_choices, 1, wxRA_SPECIFY_COLS);
    btnClose = new wxButton(this, wxID_CLOSE, wxEmptyString);
    btnHelp = new wxButton(this, wxID_HELP, wxEmptyString);

    set_properties();
    do_layout();
    // end wxGlade
}


void DialogMaterial::set_properties()
{
    // begin wxGlade: DialogMaterial::set_properties
    SetTitle(_("Material Manager"));
    listFolders->SetSelection(0);
    rbFormat->SetSelection(0);
    btnClose->SetDefault();
    // end wxGlade
}


void DialogMaterial::do_layout()
{
    // begin wxGlade: DialogMaterial::do_layout
    wxBoxSizer* szMaterial = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* szBottom = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* szTop = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* szRight = new wxBoxSizer(wxVERTICAL);
    szTop->Add(listFolders, 1, wxALL|wxEXPAND, 1);
    szTop->Add(listFiles, 1, wxALL|wxEXPAND, 1);
    szRight->Add(btnImport, 0, wxALL|wxEXPAND, 1);
    szRight->Add(btnExport, 0, wxALL|wxEXPAND, 1);
    szRight->Add(btnDelete, 0, wxALL|wxEXPAND, 1);
    szRight->Add(0, 0, 1, wxEXPAND, 0);
    szRight->Add(rbFormat, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 1);
    szTop->Add(szRight, 0, wxEXPAND, 0);
    szMaterial->Add(szTop, 1, wxEXPAND, 0);
    szBottom->Add(btnClose, 0, wxALL, 1);
    szBottom->Add(btnHelp, 0, wxALL, 1);
    szMaterial->Add(szBottom, 0, wxRIGHT|wxBOTTOM|wxALIGN_RIGHT, 3);
    SetSizer(szMaterial);
    szMaterial->Fit(this);
    Layout();
    // end wxGlade
}
