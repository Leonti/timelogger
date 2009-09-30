/*************************************************************************************
*  Time Logger - writes time in and time out into database                           *
*  Copyright (C) 2009  Leonti Bielski                                                *
*                                                                                    *
*  This program is free software; you can redistribute it and/or modify              *
*  it under the terms of the GNU General Public License as published by              *
*  the Free Software Foundation; either version 2 of the License, or                 *
*  (at your option) any later version.                                               *
*                                                                                    *
*  This program is distributed in the hope that it will be useful,                   *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of                    *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                     *
*  GNU General Public License for more details.                                      *
*                                                                                    *
*  You should have received a copy of the GNU General Public License                 *
*  along with this program; if not, write to the Free Software                       *
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA    *
*************************************************************************************/

#include "time_loggerMain.h"
#include "version.h"
//#include <cstdlib>
//#include <string>
#include <wx/msgdlg.h>
#include <wx/config.h>

//(*InternalHeaders(time_loggerFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)


//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(time_loggerFrame)
const long time_loggerFrame::ID_STATICTEXT1 = wxNewId();
const long time_loggerFrame::ID_STATICTEXT2 = wxNewId();
const long time_loggerFrame::ID_STATICTEXT3 = wxNewId();
const long time_loggerFrame::ID_BUTTON1 = wxNewId();
const long time_loggerFrame::ID_BUTTON2 = wxNewId();
const long time_loggerFrame::ID_BUTTON3 = wxNewId();
const long time_loggerFrame::ID_BUTTON4 = wxNewId();
const long time_loggerFrame::ID_BUTTON5 = wxNewId();
const long time_loggerFrame::ID_BUTTON6 = wxNewId();
const long time_loggerFrame::ID_BUTTON7 = wxNewId();
const long time_loggerFrame::ID_BUTTON8 = wxNewId();
const long time_loggerFrame::ID_BUTTON9 = wxNewId();
const long time_loggerFrame::ID_BUTTON13 = wxNewId();
const long time_loggerFrame::ID_BUTTON10 = wxNewId();
const long time_loggerFrame::ID_BUTTON11 = wxNewId();
const long time_loggerFrame::ID_BUTTON12 = wxNewId();
const long time_loggerFrame::ID_STATUSBAR1 = wxNewId();
const long time_loggerFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(time_loggerFrame,wxFrame)
    //(*EventTable(time_loggerFrame)
    //*)
END_EVENT_TABLE()

time_loggerFrame::time_loggerFrame(wxWindow* parent,wxWindowID id)
{

readSet();


    std::string version = AutoVersion::FULLVERSION_STRING;
    wxString vers;
    vers << AutoVersion::MAJOR << _T(".") << AutoVersion::MINOR << _T(".") << AutoVersion::BUILD;

    //(*Initialize(time_loggerFrame)
    wxGridSizer* GridSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxGridSizer* GridSizer6;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Time Logger"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NORMAL_FILE")),wxART_OTHER));
    	SetIcon(FrameIcon);
    }
    GridSizer6 = new wxGridSizer(1, 1, 0, 0);
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxSize(180,90), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(2, 2, 0, 0);
    FlexGridSizer4->Add(30,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Current time:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(20,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    FlexGridSizer4->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(30,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(24,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
    GridSizer1 = new wxGridSizer(3, 4, 10, 10);
    Button1 = new wxButton(this, ID_BUTTON1, _("1"), wxDefaultPosition, wxSize(170,170), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    GridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont Button2Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    GridSizer1->Add(Button2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    wxFont Button3Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    GridSizer1->Add(Button3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    wxFont Button4Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button4->SetFont(Button4Font);
    GridSizer1->Add(Button4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button5 = new wxButton(this, ID_BUTTON5, _("5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    wxFont Button5Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button5->SetFont(Button5Font);
    GridSizer1->Add(Button5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    wxFont Button6Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button6->SetFont(Button6Font);
    GridSizer1->Add(Button6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button7 = new wxButton(this, ID_BUTTON7, _("7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    wxFont Button7Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button7->SetFont(Button7Font);
    GridSizer1->Add(Button7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button8 = new wxButton(this, ID_BUTTON8, _("8"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    wxFont Button8Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button8->SetFont(Button8Font);
    GridSizer1->Add(Button8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button9 = new wxButton(this, ID_BUTTON9, _("9"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    wxFont Button9Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button9->SetFont(Button9Font);
    GridSizer1->Add(Button9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button13 = new wxButton(this, ID_BUTTON13, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
    wxFont Button13Font(56,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button13->SetFont(Button13Font);
    GridSizer1->Add(Button13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(GridSizer1, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);
    FlexGridSizer3 = new wxFlexGridSizer(5, 1, 0, 0);
    Button10 = new wxButton(this, ID_BUTTON10, _("<--"), wxDefaultPosition, wxSize(170,85), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    wxFont Button10Font(32,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button10->SetFont(Button10Font);
    FlexGridSizer3->Add(Button10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(20,85,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button11 = new wxButton(this, ID_BUTTON11, _("Cancel"), wxDefaultPosition, wxSize(170,85), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    wxFont Button11Font(26,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button11->SetFont(Button11Font);
    FlexGridSizer3->Add(Button11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(20,85,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button12 = new wxButton(this, ID_BUTTON12, _("Enter"), wxDefaultPosition, wxSize(170,170), 0, wxDefaultValidator, _T("ID_BUTTON12"));
    wxFont Button12Font(40,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button12->SetFont(Button12Font);
    FlexGridSizer3->Add(Button12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer6->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridSizer6);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -10 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(100, false);
    GridSizer6->Fit(this);
    GridSizer6->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton6Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton7Click);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton8Click);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton9Click);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton13Click1);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton12Click);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton13Click);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&time_loggerFrame::OnButton11Click);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&time_loggerFrame::OnTimer1Trigger);
    //*)
SetTitle(_T("Time Logger ") + vers);

conn = new mysqlpp::Connection(false);


connect_to_db();
empId = 0;
}

void time_loggerFrame::readSet(void){
conn = new mysqlpp::Connection(false);
    config = new wxConfig(_T("timelogger"));
    sett.lang = 0;
    wxString lng = config->Read(_T("program/lang"));
    if(lng!=_T("")){
        long temp;
        lng.ToLong(&temp);
        sett.lang = temp;
        }

if(config->Read(_T("/program/run")) !=_T("1") || config->Read(_T("/program/run_again")) == _T("1")){
    settings *set_dlg = new settings(this);
    set_dlg->confi = config;
    set_dlg->conn = conn;
    set_dlg->set_now = &sett;
    set_dlg->fill_all();
    set_dlg->ShowModal();
    delete set_dlg;
        }

if(sett.lang != 0){
Locale.Init(sett.lang, wxLOCALE_CONV_ENCODING);
                // Initialize the catalogs we'll be using
Locale.AddCatalog(wxT("timelogger"));
    }

    }
int  time_loggerFrame::connect_to_db(void)
{

    host = config->Read(_T("/mysql/host"));
    user = config->Read(_T("/mysql/user"));
    pass = config->Read(_T("/mysql/pass"));
    dbase = config->Read(_T("/mysql/dbase"));



    if (conn->connect(wx2std(dbase,wxConvUI).c_str(),wx2std(host,wxConvUI).c_str(),wx2std(user,wxConvUI).c_str(),wx2std(pass,wxConvUI).c_str()))
    {
        StatusBar1->SetStatusText(_("Connected to the database."));
//        dbase_connected = true;
        return 0;
    }
    else
    {
        StatusBar1->SetStatusText(_("Unable no connect to database '") + dbase + _("' on ") + host,0);

        wxMessageBox(_("Unable to connect to the database. Reason:\n") + std2wx(conn -> error(),wxConvUI),_("Not connected."), wxOK);
  //      dbase_connected = false;
        return 1;
    }



}

time_loggerFrame::~time_loggerFrame()
{
    //(*Destroy(time_loggerFrame)
    //*)
}

void time_loggerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}



void time_loggerFrame::OnButton1Click(wxCommandEvent& event)
{
    if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("1"));
}

void time_loggerFrame::OnButton2Click(wxCommandEvent& event)
{
        if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("2"));
}

void time_loggerFrame::OnButton3Click(wxCommandEvent& event)
{
        if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("3"));
}

void time_loggerFrame::OnButton4Click(wxCommandEvent& event)
{
        if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("4"));
}

void time_loggerFrame::OnButton5Click(wxCommandEvent& event)
{
        if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("5"));
}

void time_loggerFrame::OnButton6Click(wxCommandEvent& event)
{
        if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("6"));
}

void time_loggerFrame::OnButton7Click(wxCommandEvent& event)
{
        if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("7"));
}

void time_loggerFrame::OnButton8Click(wxCommandEvent& event)
{
        if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("8"));
}

void time_loggerFrame::OnButton9Click(wxCommandEvent& event)
{
        if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("9"));
}

void time_loggerFrame::OnButton11Click(wxCommandEvent& event)
{

    if(StaticText1->GetLabel()!=_T("")){
if(StaticText1->GetLabel()==_T("9999")){
    StaticText1->SetLabel(_T(""));
    settings* set_dlg = new settings(this);
    set_dlg->confi = config;
    set_dlg->set_now = &sett;
    set_dlg->conn = conn;
    set_dlg->fill_all();
    set_dlg->ShowModal();
    connect_to_db();
        }else{

    if (getEmployeeId() !=1 )
    {
    StaticText1->SetLabel(_T(""));
        login* Mylogin = new login(0);
        Mylogin->empId = empId;
        Mylogin -> empName = empName;
        Mylogin -> conn = conn;
        Mylogin->setFace();
        Mylogin->ShowModal();
        Mylogin->Destroy();
        delete Mylogin;
    }
    else
    {
    StaticText1->SetLabel(_T(""));
        wxMessageDialog* dlg = new wxMessageDialog(this, _("Sorry, but there is no such ID in our database."),_("Wrong ID"), wxOK);
        dlg->ShowModal();
        delete dlg;
    }
          }
}
}

int time_loggerFrame::getEmployeeId(){
    int toRet;
    mysqlpp::Query query = conn->query();
    query << "SELECT `emp_id`, `emp_name` FROM `employees` WHERE `emp_ssn` ="<< wx2std(StaticText1->GetLabel(),wxConvUI) <<" LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();
if(res.num_rows() != 0){
if(res){
        mysqlpp::Row row = res.at(0);
        empId = int(row["emp_id"]);
        empName = std2wx(std::string(row["emp_name"]), wxConvUI);
toRet = 0;
}
}else{
        empId = 0;
toRet = 1;
}
return toRet;
    }

void time_loggerFrame::OnButton12Click(wxCommandEvent& event)
{
    wxString labelValue = StaticText1->GetLabel();
    labelValue.Remove(labelValue.Length()-1, labelValue.Length());
    StaticText1->SetLabel(labelValue);

}

void time_loggerFrame::OnButton13Click(wxCommandEvent& event)
{
    StaticText1->SetLabel(_T(""));
}



void time_loggerFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    wxDateTime currentTime = wxDateTime::Now();
    StaticText3->SetLabel(currentTime.FormatTime());
}

void time_loggerFrame::OnButton13Click1(wxCommandEvent& event)
{
            if(StaticText1->GetLabel().Length() < 4)
    StaticText1->SetLabel(StaticText1->GetLabel() + _T("0"));
}
