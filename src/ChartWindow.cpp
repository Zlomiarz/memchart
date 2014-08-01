#include "ChartWindow.h"
#include "DataStore.h"
#include <wx/mstream.h>

BEGIN_EVENT_TABLE(ChartWindow, wxWindow)
    EVT_PAINT(ChartWindow::onPaint)
END_EVENT_TABLE()

ChartWindow::ChartWindow(wxWindow* parent):wxWindow(parent, wxID_ANY){
    SetSize( wxSize(100, 100) );
    SetMinSize( wxSize(100, 200) );
    SetMaxSize( wxSize(10000, 10000) );
}

ChartWindow::~ChartWindow()
{
    //dtor
}

void ChartWindow::onPaint(wxPaintEvent & evt){
    wxPaintDC dc(this);
    render(dc);
}

void ChartWindow::render(wxDC&  dc){
    int neww, newh;
    dc.GetSize( &neww, &newh );
	if (!theBitmap.IsOk()){
	    dc.SetPen(*wxWHITE_PEN);
        dc.SetBrush(*wxWHITE_BRUSH);
        wxCoord width,height;
        dc.GetSize(&width,&height);
        dc.DrawRectangle(0, 0, width, height);
		return;
	}
    

    if (neww != theBitmap.GetWidth() || newh != theBitmap.GetHeight())
		theBitmap.Rescale( neww, newh);
	wxBitmap resized = wxBitmap(theBitmap);
    dc.DrawBitmap(resized, 0, 0, false);
}

BaseChart* ChartWindow::makeChart(int width, int height){

	
    // Create a XYChart object of size 600 x 350 pixels
    XYChart *chart = new XYChart(width, height);

    // Set the plotarea at (50, 25) and of size 500 x 250 pixels. Enable both the
    // horizontal and vertical grids by setting their colors to grey (0xc0c0c0)
    chart->setPlotArea(50, 25, width-100, height-100)->setGridColor(0xc0c0c0, 0xc0c0c0);
    
    std::vector<std::string> components =  DataStore::getInstance()->getComponents();
    
    for (unsigned i=0;i<components.size();++i){
        double* data = DataStore::getInstance()->getStatisticsData(components[i])->allocatedMem.data();
        int size = DataStore::getInstance()->getStatisticsData(components[i])->allocatedMem.size();
    
        if (size != 0)
            chart->addLineLayer(DoubleArray(data, size));
    }

    // Set the labels on the x axis.
    //c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

    // Display 1 out of 3 labels on the x-axis.
    //chart->xAxis()->setLabelStep(3);

    return chart;
}

void ChartWindow::paintNow(){
    wxClientDC dc(this);
    render(dc);
}

void ChartWindow::updateChart(){

    const char* pointer;
    int len;
    wxSize size = GetClientSize();
    BaseChart* chart = makeChart(size.GetWidth(), size.GetHeight());

    chart->makeChart(4, &pointer, &len);
	wxMemoryInputStream stream(pointer, len);
	if (!theBitmap.LoadFile(stream, wxBITMAP_TYPE_BMP))
		return;
	paintNow();


    delete chart;
}
