/*************************************************************************************
*  Time Logger - writes time in and time out into database                           *
*  Copyright (C) 2008  Leonti Bielski                                                *
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

#include "login.h"
#include "wx_std.h"
//(*InternalHeaders(login)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)
//#include </home/leonti/proba/emp_2/employee.h>


//(*IdInit(login)
const long login::ID_STATICTEXT1 = wxNewId();
const long login::ID_STATICTEXT2 = wxNewId();
const long login::ID_WIND1 = wxNewId();
const long login::ID_BUTTON1 = wxNewId();
const long login::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(login,wxDialog)
    //(*EventTable(login)ws
    //*)
END_EVENT_TABLE()

login::login(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(login)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    GridSizer1 = new wxGridSizer(1, 1, 0, 0);
    FlexGridSizer1 = new wxFlexGridSizer(5, 1, 0, 0);
    FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(2, 1, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome, Preved Medvedov!"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(22,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Position: Groundskeeping"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(20,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    FlexGridSizer4->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Image1 = new wxWindow(this,ID_WIND1);
    Image1 -> SetSize(200,200);
    FlexGridSizer3->Add(Image1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Choose job:"));
    FlexGridSizer2 = new wxFlexGridSizer(2, 0, 0, 0);
    StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("LOGOUT"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font(48,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont Button2Font(22,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    FlexGridSizer1->Add(Button2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridSizer1);
    GridSizer1->Fit(this);
    GridSizer1->SetSizeHints(this);

    Image1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&login::OnImage1Paint,0,this);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&login::OnButton2Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&login::OnButton3Click);
    //*)

    //		Image1 -> SetSize(200,200); //paste above
}

login::~login()
{
    //(*Destroy(login)
    //*)
}

void login::setFace()
{
jobId = 0;
    StaticText1->SetLabel(_("Welcome, ") + empName + _T("!"));
    mysqlpp::Query query = conn->query();
    query << "SELECT `time_job_id` FROM `time` WHERE `time_emp_id`="<< empId <<" ORDER BY `time_time` DESC LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();
    if(res){
if(res.num_rows() != 0){
mysqlpp::Row row = res.at(0);
jobId = int(row["time_job_id"]);
}
StaticText2->SetLabel(_("Position: ") + getJobName(jobId));

    }

    query << "SELECT `job_id` FROM `emp_jobs` WHERE `emp_id`=" << empId;
    res = query.store();
        if (res){
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
         int jobIdTemp = int(row["job_id"]);

                wxString b_name = _T("button_id_");
                b_name << jobIdTemp;
               wxButton* grid_button = new wxButton(this, 6000 + jobIdTemp, getJobName(jobIdTemp), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, b_name);
    wxFont grid_buttonFont(36,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    grid_button->SetFont(grid_buttonFont);

    if(jobIdTemp == jobId){
        grid_button->Enable(false);
        }
            FlexGridSizer2->Add(grid_button, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);
                Connect(6000 + jobIdTemp, wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&login::OnButton);






            }
GridSizer1->SetSizeHints(this);
        }
if(jobId == 0){
    Button1->Enable(false);
    }

}


wxString login::getJobName(int jobId){
    wxString toRet;
    if(jobId != 0){
    mysqlpp::Query query = conn->query();
    query << "SELECT `job_title` FROM `jobs` WHERE `job_id`="<< jobId <<" LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();
if(res){
    mysqlpp::Row row = res.at(0);
    toRet = std2wx(std::string(row["job_title"]),wxConvUI);
    }
    }else{
    toRet = _("OFF");
        }
return toRet;
    }



void login::OnButton(wxCommandEvent& event)
{

int jobIdTemp = event.GetId() - 6000;
    if (jobId == jobIdTemp)
    {
        wxMessageDialog* dlg = new wxMessageDialog(this, _("You are already working as a ") + getJobName(jobId) + _("! Choose another job or logout. Otherwise press \"Close\"."), _("Wrong choice"), wxOK);
        dlg->ShowModal();
        delete dlg;
    }
    else
    {

wxDateTime current = wxDateTime::Now();
wxString formTime = current.FormatISODate() + _T(" ") + current.FormatISOTime();
    mysqlpp::Query query = conn->query();
    query << "INSERT INTO `time` (`time_id`, `time_emp_id`, `time_time`, `time_job_id`, `time_edited`) VALUES (NULL, '"<< empId <<"', '"<< wx2std(formTime,wxConvUI) <<"', '"<< jobIdTemp <<"', '0')";
    query.execute();
        wxMessageDialog* dlg = new wxMessageDialog(this, _("Your current position is ") + getJobName(jobIdTemp) + _T("."), _("Login"), wxOK);
        dlg->ShowModal();
        Show(0);
        delete dlg;
    }

}



void login::OnButton2Click(wxCommandEvent& event)
{

    if (jobId == 0)
    {
        wxMessageDialog* dlg = new wxMessageDialog(this, _("You are already off! Choose job or press \"Close\"."), _("Wrong choice"), wxOK);
        dlg->ShowModal();
        delete dlg;
    }
    else
    {
wxDateTime current = wxDateTime::Now();
wxString formTime = current.FormatISODate() + _T(" ") + current.FormatISOTime();
    mysqlpp::Query query = conn->query();
    query << "INSERT INTO `time` (`time_id`, `time_emp_id`, `time_time`, `time_job_id`, `time_edited`) VALUES (NULL, '"<< empId <<"', '"<< wx2std(formTime,wxConvUI) <<"', '0', '0')";
    query.execute();

        wxMessageDialog* dlg = new wxMessageDialog(this, _("You logged out. Enjoy your time off!"), _("Logout"), wxOK);
        dlg->ShowModal();
        Show(0);
        delete dlg;
    }

}

void login::OnButton3Click(wxCommandEvent& event)
{
    Show(0);
}




void login::OnImage1Paint(wxPaintEvent& event)
{
        wxStandardPaths path;
wxFileName imageName;
imageName.Assign(path.GetDataDir(),_T("photo.png"));
        wxImage img(imageName.GetFullPath(),wxBITMAP_TYPE_PNG);
    photoWindow = FindWindow(ID_WIND1);
    photoDC = new wxClientDC(photoWindow);

    wxPoint p=photoWindow->GetPosition();
    wxSize sz=photoWindow->GetClientSize();
    photoDC -> DrawBitmap(img.Scale(sz.GetWidth(),sz.GetHeight()),0,0,false);

                mysqlpp::Query query = conn->query();
        query << "SELECT `photo` FROM `employees` WHERE `emp_id`=" << empId << " LIMIT 1";
        mysqlpp::StoreQueryResult res = query.store();
        if (res)
        {
            mysqlpp::Row row = res.at(0);
    wxPoint p=photoWindow->GetPosition();
    wxSize sz=photoWindow->GetClientSize();
mysqlpp::Row::reference it = row["photo"];
int length = it.length();
                    if(length != 0){
const char* str = it.data();

unsigned char * NewImgData = ( unsigned char * ) malloc( length );

    memcpy( NewImgData, str, length );
    wxImage img(200,200,NewImgData);
    photoDC -> DrawBitmap(img.Scale(sz.GetWidth(),sz.GetHeight()),0,0,false);
}/*else{
wxStandardPaths path;
wxFileName imageName;
imageName.Assign(path.GetDataDir(),_T("photo.png"));

    wxImage img(imageName.GetFullPath(),wxBITMAP_TYPE_PNG);
    photoDC -> Clear();
    photoDC -> DrawBitmap(img.Scale(sz.GetWidth(),sz.GetHeight()),0,0,false);
    photoDC -> DrawText(_("No photo"), 10, 10);
} */}
}
