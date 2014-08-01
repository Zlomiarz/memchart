/***************************************************************
 * Name:      memChartMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jan Luka (jluka@nsn.pl)
 * Created:   2014-07-16
 * Copyright: Jan Luka ()
 * License:
 **************************************************************/

#ifndef MEMCHARTMAIN_H
#define MEMCHARTMAIN_H

#include "MemTracer.h"
#include "StatisticData.h"
#include "ChartWindow.h"

//(*Headers(memChartFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

const int REFRESH_RATE = 1000;
class memChartFrame: public wxFrame
{
    public:

        memChartFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~memChartFrame();

    private:
        void updateStatiscics();
        void initStatistics();
        void updateChart();
        
        wxTimer timer;
        ChartWindow* cw;
        
        static const long ID_TIMER;
        
        //(*Handlers(memChartFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void onTimer(wxTimerEvent& event);
        //*)

        //(*Identifiers(memChartFrame)
        static const long ID_CHECKBOX1;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX4;
        static const long ID_CHECKBOX5;
        static const long ID_CHECKBOX6;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(memChartFrame)
        wxCheckBox* CheckBox3;
        wxCheckBox* CheckBox2;
        wxCheckBox* CheckBox6;
        wxPanel* Panel1;
        wxCheckBox* CheckBox1;
        wxStatusBar* StatusBar1;
        wxCheckBox* CheckBox4;
        wxCheckBox* CheckBox5;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MEMCHARTMAIN_H
