// -*- C++ -*- generated by wxGlade 0.6.3 on Sun Feb 15 04:53:05 2009 from "/home/fdelapena/programacion/easyrpg/trunk/editor/wxglade/easyrpg.wxg"

#include <wx/wx.h>
#include <wx/image.h>

#ifndef DIALOGEVTCMDEQUIPMENT_H
#define DIALOGEVTCMDEQUIPMENT_H

// begin wxGlade: ::dependencies
// end wxGlade

// begin wxGlade: ::extracode

// end wxGlade


class DialogEvtCmdEquipment: public wxDialog {
public:
    // begin wxGlade: DialogEvtCmdEquipment::ids
    // end wxGlade

    DialogEvtCmdEquipment(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);

private:
    // begin wxGlade: DialogEvtCmdEquipment::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: DialogEvtCmdEquipment::attributes
    wxStaticBox* szOperand_staticbox;
    wxStaticBox* szTarget_staticbox;
    wxRadioButton* rbtnTargetParty;
    wxRadioButton* rbtnTargetFixed;
    wxChoice* chTargetFixed;
    wxRadioButton* rbtnTargetVariable;
    wxTextCtrl* tcTargetVariable;
    wxButton* btnTargetVariable;
    wxRadioBox* rbOperation;
    wxRadioButton* rbtnOperandConstant;
    wxChoice* chOperandConstant;
    wxRadioButton* rbtnOperandVariable;
    wxTextCtrl* tcOperandVariable;
    wxButton* btnOperandVariable;
    wxRadioBox* rbRemove;
    wxButton* btnOK;
    wxButton* btnCancel;
    wxButton* btnHelp;
    // end wxGlade
}; // wxGlade: end class


#endif // DIALOGEVTCMDEQUIPMENT_H