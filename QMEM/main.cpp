#include "MyFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{
	MyFrame* myFrame = new MyFrame(wxString("QMEM"));
	myFrame->Show(true);
	return true;
}
