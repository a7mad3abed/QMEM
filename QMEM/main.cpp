#include "MainWindow.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{
	auto myFrame = new MainWindow(wxString("QMEM"));
	myFrame->Show(true);
	return true;
}
