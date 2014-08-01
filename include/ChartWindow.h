#pragma once
#include <wx/window.h>
#include "chartdir.h"

class ChartWindow:public wxWindow
{
    public:
        ChartWindow(wxWindow* parent);
        virtual ~ChartWindow();
        void updateChart();

    protected:
        BaseChart* makeChart(int width, int heigh );
		wxImage theBitmap;

		void onPaint(wxPaintEvent & evt);
		void paintNow();
		void render(wxDC& dc);
		
	private:

		DECLARE_EVENT_TABLE()

};
