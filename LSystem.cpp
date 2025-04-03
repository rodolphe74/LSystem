#include "LSystem.h"
#include <iostream>
#include <stdio.h>


void LSystem::setAxiom(std::string axiom)
{
	this->axiom = axiom;

	// Copy axiom into vector
	for (int i = 0; i < axiom.size(); i++) {
		recursions.push_back(axiom[i]);
	}
}

void LSystem::addRule(char key, std::string rule)
{
	this->rules[key] = rule;
}

void LSystem::setAngle(float angle)
{
	this->angle = angle;
}

void LSystem::setLength(float length)
{
	this->length = length;
}

void LSystem::recurse(int depth)
{
	int currentRule = 0;


	for (int i = 0; i < depth; i++) {
		int currentRecursionIndex = 0;
		std::vector<char> currentRecursion;
		for (int j = 0; j < recursions.size(); j++) {
			char key = recursions[j];
			if (rules.count(key)) {
				std::string rule = rules[key];
				for (int k = 0; k < rule.size(); k++) {
					currentRecursion.push_back(rule[k]);
				}
			}
			else {
				currentRecursion.push_back(key);
			}
		}
		recursions = currentRecursion;
	}

}

void LSystem::dumpRecursion()
{
	FILE *f = fopen("recursion.txt", "w");
	for (int i = 0; i < recursions.size(); i++) {
		std::cout << recursions[i] << std::endl;
		fwrite(&(recursions[i]), 1, 1, f);
	}
	fclose(f);
}

void LSystem::wxDraw(wxGraphicsContext *gc, float x, float y, float startAngle)
{
	Turtle *t = new Turtle(gc);

	t->moveTo(x, y);
	t->turn(startAngle);

	for (int i = 0; i < recursions.size(); i++) {
		char c = recursions[i];
		switch (c)
		{
		case 'G':
		case 'F':
			t->draw(length);
			break;
		case '+':
			t->turn(angle);
			break;
		case '-':
			t->turn(-angle);
			break;
		case '[' :
			t->pushOnStack();
			break;
		case ']':
			t->popFromStack();
			break;
		default:
			break;
		}
	}



	delete t;
}
