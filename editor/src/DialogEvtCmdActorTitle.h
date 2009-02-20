// -*- C++ -*- generated by wxGlade 0.6.3 on Sun Feb 15 04:53:05 2009 from "/home/fdelapena/programacion/easyrpg/trunk/editor/wxglade/easyrpg.wxg"

#include <wx/wx.h>
#include <wx/image.h>

#ifndef DIALOGEVTCMDACTORTITLE_H
#define DIALOGEVTCMDACTORTITLE_H

// begin wxGlade: ::dependencies
// end wxGlade

// begin wxGlade: ::extracode

// end wxGlade


class DialogEvtCmdActorTitle: public wxDialog {
public:
    // begin wxGlade: DialogEvtCmdActorTitle::ids
    // end wxGlade

    DialogEvtCmdActorTitle(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);

private:
    // begin wxGlade: DialogEvtCmdActorTitle::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: DialogEvtCmdActorTitle::attributes
    wxStaticBox* szTitle_staticbox;
    wxStaticBox* szActor_staticbox;
    wxChoice* chActor;
    wxTextCtrl* tcTitle;
    wxButton* btnOK;
    wxButton* btnCancel;
    wxButton* btnHelp;
    // end wxGlade
}; // wxGlade: end class


#endif // DIALOGEVTCMDACTORTITLE_H