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

#ifndef LOGIN_H
#define LOGIN_H

//(*Headers(login)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
//*)
#include <wx/msgdlg.h>
#include <string>
#include <mysql++.h>
#include <iostream>
#include "wx_std.h"
#include <wx/msgdlg.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/dcclient.h>
#include <wx/image.h>
//#include <sstream>

class login: public wxDialog
{
public:

    login(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~login();

    //(*Identifiers(login)
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_WIND1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    //*)
    void setFace();
    int empId;
    wxString empName;
    mysqlpp::Connection* conn;

protected:

    //(*Handlers(login)
    void OnButton2Click(wxCommandEvent& event);
    void OnButton3Click(wxCommandEvent& event);
    void OnImage1Paint(wxPaintEvent& event);
    //*)
    void OnButton(wxCommandEvent& event);

    //(*Declarations(login)
    wxGridSizer* GridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxWindow* Image1;
    wxButton* Button1;
    wxButton* Button2;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    //*)
    wxClientDC* photoDC;
    wxWindow* photoWindow;

private:

    wxArrayInt jobList;
    int jobId;
    wxString getJobName(int jobId);
    DECLARE_EVENT_TABLE()
};

#endif
