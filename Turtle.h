#pragma once

#include <stack>
#include <wx/dcclient.h>
#include <wx/dcgraph.h>
#include <wx/wx.h>


struct Pen {
	float x, y;
	float angle;
};

typedef struct Pen Pen;

class Turtle
{
private:
	Pen pen;
	std::stack<Pen> stack;
	wxGraphicsContext *gc;

public:

	Turtle(wxGraphicsContext *gc) {
		this->pen.x = 0;
		this->pen.y = 0;
		this->pen.angle = 0;
		this->gc = gc;
	}

	Turtle(wxGraphicsContext *gc,  float x, float y) {
		this->pen.x = x;
		this->pen.y = y;
		this->pen.angle = 0;
		this->gc = gc;
	}

	void moveTo(float x, float y);
	void drawTo(float x, float y);
	void turn(float angle);
	void go(float dist);
	void draw(float dist);
	void pushOnStack();
	void popFromStack();
};

