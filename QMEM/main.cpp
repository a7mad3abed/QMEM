#include "MainFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	wxImage::AddHandler(new wxPNGHandler);
	//wxInitAllImageHandlers();
	auto myFrame = new MainFrame();
	myFrame->Show(true);
	return true;
}