#pragma once
#include "wx/wx.h"
#include "DB_Manager.h"

class Results_Dlg :
	public wxDialog
{
public:
	Results_Dlg(wxWindow *parent, const wxString &title);
	~Results_Dlg();

private:
    std::vector<Result> results;
};

