#include "Turtle.h"


void Turtle::moveTo(float x, float y)
{
	pen.x = x;
	pen.y = y;
}

void Turtle::drawTo(float x, float y)
{
	gc->StrokeLine(pen.x, pen.y, x, y);
	pen.x = x;
	pen.y = y;
}

void Turtle::turn(float angle)
{
	pen.angle += angle;
}

void Turtle::go(float dist)
{
	float endX = pen.x + dist * cos(pen.angle);
	float endY = pen.y - dist * sin(pen.angle);
	pen.x = endX;
	pen.y = endY;

}

void Turtle::draw(float dist)
{
	float endX = pen.x + dist * cos(pen.angle);
	float endY = pen.y - dist * sin(pen.angle);
	gc->StrokeLine(pen.x, pen.y, endX, endY);
	pen.x = endX;
	pen.y = endY;
}

void Turtle::pushOnStack()
{
	stack.push(pen);
}

void Turtle::popFromStack()
{
	pen = stack.top();
	stack.pop();
}
