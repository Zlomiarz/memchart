/***************************************************************
 * Name:      memChartMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Jan Luka (jluka@nsn.pl)
 * Created:   2014-07-16
 * Copyright: Jan Luka ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "memChartMain.h"
#include "DataStore.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(memChartFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

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

//(*IdInit(memChartFrame)
const long memChartFrame::ID_CHECKBOX1 = wxNewId();
const long memChartFrame::ID_CHECKBOX3 = wxNewId();
const long memChartFrame::ID_CHECKBOX2 = wxNewId();
const long memChartFrame::ID_CHECKBOX4 = wxNewId();
const long memChartFrame::ID_CHECKBOX5 = wxNewId();
const long memChartFrame::ID_CHECKBOX6 = wxNewId();
const long memChartFrame::ID_PANEL1 = wxNewId();
const long memChartFrame::idMenuQuit = wxNewId();
const long memChartFrame::idMenuAbout = wxNewId();
const long memChartFrame::ID_STATUSBAR1 = wxNewId();
//*)
const long memChartFrame::ID_TIMER = wxNewId();

BEGIN_EVENT_TABLE(memChartFrame,wxFrame)
    //(*EventTable(memChartFrame)
    //*)
END_EVENT_TABLE()

memChartFrame::memChartFrame(wxWindow* parent,wxWindowID id):timer(this, ID_TIMER)
{
    //(*Initialize(memChartFrame)
    wxMenuItem* MenuItem2;
    wxBoxSizer* ChartContainer;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(0);
    ChartContainer = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer1->Add(ChartContainer, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("all"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    BoxSizer1->Add(CheckBox1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox3 = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Radio"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBox3->SetValue(false);
    BoxSizer1->Add(CheckBox3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox2 = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Rp1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(false);
    BoxSizer1->Add(CheckBox2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox4 = new wxCheckBox(Panel1, ID_CHECKBOX4, _("Rp3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    CheckBox4->SetValue(false);
    BoxSizer1->Add(CheckBox4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox5 = new wxCheckBox(Panel1, ID_CHECKBOX5, _("Hw"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    CheckBox5->SetValue(false);
    BoxSizer1->Add(CheckBox5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox6 = new wxCheckBox(Panel1, ID_CHECKBOX6, _("State"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    CheckBox6->SetValue(false);
    BoxSizer1->Add(CheckBox6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&memChartFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&memChartFrame::OnAbout);
    //*)
    Connect(ID_TIMER,wxEVT_TIMER,(wxObjectEventFunction)&memChartFrame::onTimer);
    timer.Start(REFRESH_RATE);
    srand(time(NULL));
    cw = new ChartWindow(Panel1);
    ChartContainer->Add(cw, 1, wxALL|wxEXPAND, 5);
}

memChartFrame::~memChartFrame()
{
    //(*Destroy(memChartFrame)
    //*)
}



void memChartFrame::updateChart(){
    cw->updateChart();
}

void memChartFrame::updateStatiscics(){
    DataStore::getInstance()->update();
}

void memChartFrame::OnQuit(wxCommandEvent& event){
    Close();
}

void memChartFrame::OnAbout(wxCommandEvent& event){
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void memChartFrame::onTimer(wxTimerEvent& event){
    updateStatiscics();
    updateChart();
    
}
