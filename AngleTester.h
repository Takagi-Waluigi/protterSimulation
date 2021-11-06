#pragma once
#include "ofMain.h"
#include "ofxGui.h"
class AngleTester
{
public:
	void setup();
	void draw();

	float calcAngle(float inputAngle, float ar);

	ofxPanel gui;
	ofParameter<float> lengthRatio;
	ofParameter<float> angle;
	ofParameter<float> angleRatio;
};

