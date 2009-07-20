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
#include "db_set_panel.h"

//(*InternalHeaders(db_set_panel)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(db_set_panel)
const long db_set_panel::ID_STATICTEXT1 = wxNewId();
const long db_set_panel::ID_STATICTEXT2 = wxNewId();
const long db_set_panel::ID_TEXTCTRL1 = wxNewId();
const long db_set_panel::ID_STATICTEXT3 = wxNewId();
const long db_set_panel::ID_TEXTCTRL2 = wxNewId();
const long db_set_panel::ID_STATICTEXT4 = wxNewId();
const long db_set_panel::ID_TEXTCTRL3 = wxNewId();
const long db_set_panel::ID_STATICTEXT5 = wxNewId();
const long db_set_panel::ID_TEXTCTRL4 = wxNewId();
const long db_set_panel::ID_CHECKBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(db_set_panel,wxPanel)
	//(*EventTable(db_set_panel)
	//*)
END_EVENT_TABLE()

db_set_panel::db_set_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(db_set_panel)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(5, 1, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Please edit this setting before connecting to the database."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(4, 2, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Host"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("localhost"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("User"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("root"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer2->Add(TextCtrl2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer2->Add(TextCtrl3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Database name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("etm"), wxDefaultPosition, wxSize(120,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer2->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Show this dialog on next startup"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	FlexGridSizer1->Add(CheckBox1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)
	dbase_connected = false;
}

db_set_panel::~db_set_panel()
{
	//(*Destroy(db_set_panel)
	//*)
}

void db_set_panel::Save(void){
    confi->Write(_T("/mysql/host"), TextCtrl1->GetValue());
    confi->Write(_T("/mysql/user"), TextCtrl2->GetValue());
    confi->Write(_T("/mysql/pass"), TextCtrl3->GetValue());
    confi->Write(_T("/mysql/dbase"), TextCtrl4->GetValue());
    confi->Write(_T("/program/run"), _T("1"));

if(CheckBox1->GetValue())
    confi->Write(_T("/program/run_again"), _T("1"));
    else
    confi->Write(_T("/program/run_again"), _T("0"));



if(dbase_connected == false){
conn->connect("", wx2std(TextCtrl1->GetValue(),wxConvUI).c_str(),wx2std(TextCtrl2->GetValue(),wxConvUI).c_str(),wx2std(TextCtrl3->GetValue(),wxConvUI).c_str());
   if (*conn)
    {
         dbase_connected = true;
}
    else
    {
       wxMessageBox(std2wx(conn -> error(),wxConvUI));
        dbase_connected = false;
    }
}




    }

void db_set_panel::fill_all(){

TextCtrl1->Clear();
TextCtrl1->WriteText(confi->Read(_T("/mysql/host")));

TextCtrl2->Clear();
TextCtrl2->WriteText(confi->Read(_T("/mysql/user")));

TextCtrl3->Clear();
TextCtrl3->WriteText(confi->Read(_T("/mysql/pass")));

TextCtrl4->Clear();
TextCtrl4->WriteText(confi->Read(_T("/mysql/dbase")));

if(confi->Read(_T("/program/run_again")) == _T("1")){
    CheckBox1->SetValue(true);
    }
    }



