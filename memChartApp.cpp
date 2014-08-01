/***************************************************************
 * Name:      memChartApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jan Luka (jluka@nsn.pl)
 * Created:   2014-07-16
 * Copyright: Jan Luka ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "memChartApp.h"

//(*AppHeaders
#include "memChartMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(memChartApp);

bool memChartApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	memChartFrame* Frame = new memChartFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
