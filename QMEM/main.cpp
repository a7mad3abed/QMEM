#include "MainFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{
    auto myFrame = new MainFrame();
	myFrame->Show(true);
	return true;
}
