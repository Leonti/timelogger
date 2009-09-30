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

#ifndef TIME_SHITSMAIN_H
#define TIME_SHITSMAIN_H

//(*Headers(time_loggerFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)
//#include "employee.h"
#include "login.h"
#include <fstream>
#include "wx_std.h"
#include "settings.h"
#include <string>
#include <mysql++.h>
#include <iostream>
#include "wx_std.h"
#include <wx/msgdlg.h>
#include <wx/stdpaths.h>

class time_loggerFrame: public wxFrame
{
    public:

        time_loggerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~time_loggerFrame();


    private:

        //(*Handlers(time_loggerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnButton8Click(wxCommandEvent& event);
        void OnButton9Click(wxCommandEvent& event);
        void OnButton11Click(wxCommandEvent& event);
        void OnButton12Click(wxCommandEvent& event);
        void OnButton13Click(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnButton13Click1(wxCommandEvent& event);
        void OnButton13Click2(wxCommandEvent& event);
        //*)

        //(*Identifiers(time_loggerFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_BUTTON8;
        static const long ID_BUTTON9;
        static const long ID_BUTTON13;
        static const long ID_BUTTON10;
        static const long ID_BUTTON11;
        static const long ID_BUTTON12;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(time_loggerFrame)
        wxStatusBar* StatusBar1;
        wxButton* Button4;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button12;
        wxStaticText* StaticText1;
        wxTimer Timer1;
        wxButton* Button8;
        wxStaticText* StaticText3;
        wxButton* Button5;
        wxButton* Button9;
        wxStaticText* StaticText2;
        wxButton* Button11;
        wxButton* Button7;
        wxButton* Button6;
        wxButton* Button13;
        wxButton* Button10;
        //*)
        wxConfig *config;
        mysqlpp::Connection* conn;
        current_settings sett;
    wxString host;
    wxString user;
    wxString pass;
    wxString dbase;
        int empId;
        wxString empName;

        int getEmployeeId(void);
        int connect_to_db(void);
        wxLocale Locale;
        void readSet(void);

        DECLARE_EVENT_TABLE()
};

#endif // TIME_SHITSMAIN_H
