#include "AngleTester.h"

void AngleTester::setup()
{
	gui.setup();

	float initVal = 1.57894737;
	
	lengthRatio.set("length ratio", initVal , 0, 5);
	angleRatio.set("angle ratio", 3, 0, 5);
	angle.set("angle", 0, -30, 30);

	gui.add(lengthRatio);
	gui.add(angleRatio);
	gui.add(angle);
}

void AngleTester::draw()
{

	ofVec2f posA, posB, posC;	//リンクの各頂点の座標
	float thetaPlate, thetaA, thetaB, thetaC;	//各頂点における角度θ
	float a, b, c;	//各頂点の長さ
	float offset = 8.0; //描画上のオフセット
	int w = ofGetWidth();
	int h = ofGetHeight();

	lengthRatio = 1.57894737;
	thetaPlate = ofDegToRad(angle);

	a = 19.0;
	b = 30.0;

	ofSetColor(128);

	ofDrawLine(w * 0.25, h * 0.5, w * 0.75, h * 0.5);

	ofSetColor(255);

	posA.x = w * 0.5 * cos(thetaPlate) + w * 0.25;
	posA.y = w * 0.5 * sin(thetaPlate) + h * 0.50;

	posB.x = w * 0.75;
	posB.y = sqrt(double(a * a + b * b)) * offset + h * 0.50;

	thetaC = HALF_PI - thetaPlate * angleRatio;
    
	c = sqrt(a * a + b * b - 2 * a * b * cos(thetaC));

	float cosBvalue = (c * c + a * a - b * b) / (2 * c * a);
	thetaB = acos(cosBvalue);

	ofClamp(thetaB, 0, 180);

	float thetaBA = atan2(posA.y - posB.y, posA.x - posB.x);
	posC.x = posB.x - a * cos(thetaBA + thetaB) * offset;
	posC.y = posB.y + a * sin(thetaBA + thetaB) * offset;

	ofDrawLine(posA, posB);
	ofDrawLine(posB, posC);
	ofDrawLine(posC, posA);	
	ofDrawLine(w * 0.25, h * 0.5, posA.x, posA.y);

	ofNoFill();
	ofDrawCircle(posA, 20);
	ofDrawCircle(posB, 20);
	ofDrawCircle(posC, 20);
	ofDrawCircle(w * 0.25, h * 0.5, 20);

	gui.draw();

	ofDrawBitmapString("servo angle: " + ofToString(90 - ofRadToDeg(thetaBA + thetaB)), ofGetWidth() / 2, 30);
	//ofDrawBitmapString("servo angle: " + ofToString(calcAngle(angle, angleRatio)), ofGetWidth() / 2, 45);

}

float AngleTester::calcAngle(float inputAngle, float ar)
{
	float outputAngle = 0.0;

	ofVec2f posA, posB, posC;	//リンクの各頂点の座標
	float thetaPlate, thetaB, thetaC;	//各頂点における角度θ
	float a, b, c;	//各頂点の長さ
	float offset = 8.0;
	int w = ofGetWidth();
	int h = ofGetHeight();

	thetaPlate = ofDegToRad(inputAngle);

	thetaC = HALF_PI - thetaPlate * ar;

	a = 19.0;
	b = 30.0;
	c = sqrt(a * a + b * b - 2 * a * b * cos(thetaC));

	posA.x = w * 0.5 * cos(thetaPlate) + w * 0.25;
	posA.y = w * 0.5 * sin(thetaPlate) + h * 0.50;

	posB.x = w * 0.75;
	posB.y = sqrt(double(a * a + b * b)) * offset + h * 0.50;

	float cosBvalue = (c * c + a * a - b * b) / (2 * c * a);
	thetaB = acos(cosBvalue);

	ofClamp(thetaB, 0, 180);

	float thetaBA = atan2(posA.y - posB.y, posA.x - posB.x);

	return outputAngle = 90 - ofRadToDeg(thetaBA + thetaB);
}