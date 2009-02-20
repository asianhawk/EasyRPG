// -*- C++ -*- generated by wxGlade 0.6.3 on Sun Feb 15 04:53:05 2009 from "/home/fdelapena/programacion/easyrpg/trunk/editor/wxglade/easyrpg.wxg"

#include <wx/wx.h>
#include <wx/image.h>

#ifndef DIALOGEVTCMDEVENTMOVEMENT_H
#define DIALOGEVTCMDEVENTMOVEMENT_H

// begin wxGlade: ::dependencies
// end wxGlade

// begin wxGlade: ::extracode

// end wxGlade


class DialogEvtCmdEventMovement: public wxDialog {
public:
    // begin wxGlade: DialogEvtCmdEventMovement::ids
    // end wxGlade

    DialogEvtCmdEventMovement(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);

private:
    // begin wxGlade: DialogEvtCmdEventMovement::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: DialogEvtCmdEventMovement::attributes
    wxStaticBox* szPath_staticbox;
    wxStaticBox* SzOptions_staticbox;
    wxStaticBox* szTarget_staticbox;
    wxChoice* chTarget;
    wxRadioBox* rbSpeed;
    wxListBox* listPath;
    wxButton* btnDelete;
    wxButton* btnClear;
    wxCheckBox* chbLoop;
    wxCheckBox* ChkIgnore;
    wxButton* btnUp;
    wxButton* btnLookUp;
    wxButton* btnStartJump;
    wxButton* btnRight;
    wxButton* btnLookRight;
    wxButton* btnEndJump;
    wxButton* btnDown;
    wxButton* btnLookDown;
    wxButton* btnFixDirection;
    wxButton* btnLeft;
    wxButton* btnLookLeft;
    wxButton* btnCancelFix;
    wxButton* btnRightUp;
    wxButton* btn90Right;
    wxButton* btnGhost;
    wxButton* btnRightDown;
    wxButton* btn90Left;
    wxButton* btnEndGhost;
    wxButton* btnLeftUp;
    wxButton* btn180Right;
    wxButton* btnStopAnimation;
    wxButton* btnLeftDown;
    wxButton* btnRightLeft;
    wxButton* btnContinueAnimation;
    wxButton* btnRandom;
    wxButton* btnRandomDirection;
    wxButton* btnTrasparencyUp;
    wxButton* btnFollowPlayer;
    wxButton* btnLookPlayer;
    wxButton* btnTrasparencyDown;
    wxButton* btnEvadePlayer;
    wxButton* btnTurnBack;
    wxButton* btnEnableSwitch;
    wxButton* btnGo;
    wxButton* btnWait;
    wxButton* btnDisableSwitch;
    wxButton* btnSpeedUp;
    wxButton* btnFrequencyUp;
    wxButton* btnChangeGraphic;
    wxButton* btnSpeedDown;
    wxButton* btnFrequencyDown;
    wxButton* btnSoundEffect;
    wxButton* btnOK;
    wxButton* btnCancel;
    wxButton* btnHelp;
    // end wxGlade
}; // wxGlade: end class


#endif // DIALOGEVTCMDEVENTMOVEMENT_H