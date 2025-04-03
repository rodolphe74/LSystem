#pragma once

#include "Turtle.h"
#include <map>
#include <string>
#include <vector>
#include <wx/dcclient.h>
#include <wx/dcgraph.h>
#include <wx/wx.h>


#define M_PI 3.1415926535897932384626433832795
#define DEGTORAD(x)(x / 180.0f * M_PI)
#define RADTODEG(x)(x * M_PI * 180.0f)

class LSystem
{
private:
	std::vector<char> recursions;
	std::stack<Pen> stack;
	std::string axiom;
	int rulesCount = 0;
	std::map<char, std::string> rules;
	float angle = (float)M_PI;
	float length = 1;

public:
	void setAxiom(std::string axiom);
	void addRule(char key, std::string rule);
	void setAngle(float angle);
	void setLength(float length);
	void recurse(int depth = 3);
	void dumpRecursion();
	void wxDraw(wxGraphicsContext *gc, float x, float y, float startAngle = 0);
};

