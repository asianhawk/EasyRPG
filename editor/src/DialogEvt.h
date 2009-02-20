// -*- C++ -*- generated by wxGlade 0.6.3 on Sun Feb 15 04:53:05 2009 from "/home/fdelapena/programacion/easyrpg/trunk/editor/wxglade/easyrpg.wxg"

#include <wx/wx.h>
#include <wx/image.h>

#ifndef DIALOGEVT_H
#define DIALOGEVT_H

// begin wxGlade: ::dependencies
#include <wx/spinctrl.h>
#include <wx/notebook.h>
// end wxGlade

// begin wxGlade: ::extracode

// end wxGlade


class DialogEvt: public wxDialog {
public:
    // begin wxGlade: DialogEvt::ids
    // end wxGlade

    DialogEvt(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);

private:
    // begin wxGlade: DialogEvt::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: DialogEvt::attributes
    wxStaticBox* szEvtCmd_staticbox;
    wxStaticBox* szSpeed_staticbox;
    wxStaticBox* szAnimation_staticbox;
    wxStaticBox* szPriority_staticbox;
    wxStaticBox* szTrigger_staticbox;
    wxStaticBox* szMovement_staticbox;
    wxStaticBox* szGraphic_staticbox;
    wxStaticBox* szStartingConditions_staticbox;
    wxStaticBox* szName_staticbox;
    wxTextCtrl* stName;
    wxButton* btnNewPage;
    wxButton* btnCopyPage;
    wxButton* btnPastePage;
    wxButton* btnDeletePage;
    wxCheckBox* chbSwitchA;
    wxTextCtrl* tcSwitchA;
    wxButton* btnSwitchA;
    wxStaticText* stSwitchA;
    wxCheckBox* chbSwitchB;
    wxTextCtrl* tcSwitchB;
    wxButton* btnSwitchB;
    wxStaticText* stSwitchB;
    wxCheckBox* chbVariable;
    wxTextCtrl* tcVariable;
    wxButton* btnVariable;
    wxStaticText* stVariable1;
    wxSpinCtrl* spinVariable;
    wxStaticText* stVariable2;
    wxCheckBox* chbObject;
    wxChoice* chObject;
    wxStaticText* stObject;
    wxCheckBox* chbActor;
    wxChoice* chActor;
    wxStaticText* stActor;
    wxCheckBox* chbTimer;
    wxSpinCtrl* spinTimerMinutes;
    wxStaticText* stTimerColon;
    wxSpinCtrl* spinTimerSeconds;
    wxStaticText* stTimer;
    wxStaticBitmap* bmpGraphic;
    wxCheckBox* chbGraphicTranslucent;
    wxButton* btnGraphic;
    wxChoice* chMovement;
    wxStaticText* stMovementRate;
    wxChoice* chMovementRate;
    wxButton* btnMovementCreatePath;
    wxChoice* chTrigger;
    wxChoice* chPriority;
    wxCheckBox* chOverlap;
    wxChoice* chAnimation;
    wxChoice* chSpeed;
    wxListBox* listEvtCmd;
    wxPanel* pnPage;
    wxNotebook* nbPage;
    wxButton* btnOK;
    wxButton* btnCancel;
    wxButton* btnApply;
    wxButton* btnHelp;
    // end wxGlade
}; // wxGlade: end class


#endif // DIALOGEVT_H