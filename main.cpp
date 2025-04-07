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

	//lsys.setAxiom("VZFFF");
	//lsys.addRule('V', "[+++W][---W]YV");
	//lsys.addRule('W', "+X[-W]Z");
	//lsys.addRule('X', "-W[+X]Z");
	//lsys.addRule('Y', "YZ");
	//lsys.addRule('Z', " [-FFF][+FFF]F");
	//lsys.recurse(11);
	//lsys.dumpRecursion();
	//lsys.setLength(10.0f);
	//lsys.setAngle((float)DEGTORAD(20));

	lsys.setAxiom("af");
	lsys.addRule('a', "FFFFFv[+++h][---q]fb");
	lsys.addRule('b', "FFFFFv[+++h][---q]fc");
	lsys.addRule('c', "FFFFFv[+++fa]fd");
	lsys.addRule('d', "FFFFFv[+++h][---q]fe");
	lsys.addRule('e', "FFFFFv[+++h][---q]fg");
	lsys.addRule('g', "FFFFFv[---fa]fa");
	lsys.addRule('h', "ifFF");
	lsys.addRule('i', "fFFF[--m]j");
	lsys.addRule('j', "fFFF[--n]k");
	lsys.addRule('k', "fFFF[--o]l");
	lsys.addRule('l', "fFFF[--p]");
	lsys.addRule('m', "fFn");
	lsys.addRule('n', "fFo");
	lsys.addRule('o', "fFp");
	lsys.addRule('p', "fF");
	lsys.addRule('q', "rfF");
	lsys.addRule('r', "fFFF[++m]s");
	lsys.addRule('s', "fFFF[++n]t");
	lsys.addRule('t', "fFFF[++o]u");
	lsys.addRule('u', "fFFF[++p]");
	lsys.addRule('v', "Fv");	
	lsys.recurse(16);
	lsys.dumpRecursion();
	lsys.setLength(2.5f);
	lsys.setAngle((float)DEGTORAD(12));


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
		lsys.wxDraw(gc, 400, 550, (float)M_PI / 2.0f);
		delete gc;
	}


}