#include "LSystem.h"
#include <wx/dcclient.h>
#include <wx/dcgraph.h>
#include <wx/wx.h>

class MyApp : public wxApp {
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
	LSystem lsys;
	MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
	~MyFrame();

private:
	void OnPaint(wxPaintEvent &event);
	wxDECLARE_EVENT_TABLE();
};


wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_PAINT(MyFrame::OnPaint)
wxEND_EVENT_TABLE()

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
	MyFrame *frame = new MyFrame("Turtle", wxPoint(50, 50), wxSize(800, 600));
	frame->Show(true);
	return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size) {

	SetBackgroundColour(wxColor(255, 255, 255));
	Refresh();


	//lsys.setAxiom("F-G-G");
	//lsys.addRule('F', "F-G+F+G-F");
	//lsys.addRule('G', "GG");
	//lsys.recurse(6);
	//lsys.dumpRecursion();
	//lsys.setLength(6);
	//lsys.setAngle((float)DEGTORAD(120));

	//lsys.setAxiom("Y");
	//lsys.addRule('X', "X[-FFF][+FFF]FX");
	//lsys.addRule('Y', "YFX[+Y][-Y]");
	//lsys.recurse(6);
	//lsys.dumpRecursion();
	//lsys.setLength(4.0f);
	//lsys.setAngle((float)DEGTORAD(25.7));

	lsys.setAxiom("F++F++F");
	lsys.addRule('F', "F-F++F-F");
	lsys.addRule('Y', "YFX[+Y][-Y]");
	lsys.recurse(5);
	lsys.dumpRecursion();
	lsys.setLength(2.0f);
	lsys.setAngle((float)DEGTORAD(60));

}

MyFrame::~MyFrame() {
}

void MyFrame::OnPaint(wxPaintEvent &event) {
	wxPaintDC dc(this);
	wxGraphicsContext *gc = wxGraphicsContext::Create(dc);

	if (gc)
	{
		gc->SetAntialiasMode(wxANTIALIAS_DEFAULT);
		gc->SetPen(wxPen(wxColor(0, 0, 0), 1));
		//lsys.wxDraw(gc, 200, 120);
		//lsys.wxDraw(gc, 350, 550, (float)M_PI / 2.0f);
		lsys.wxDraw(gc, 150, 420);
		delete gc;
	}


}