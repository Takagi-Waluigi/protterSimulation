#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	angleTester.setup();
	simulator.setup();


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	switch (mode)
	{
	case 0:
		angleTester.draw();
		break;

	case 1:
		simulator.drawSimulationViewer(false);
		break;

	case 2:
		simulator.drawSimulationViewer(true);
		break;


	}

	ofDrawBitmapString("press 0/1/2 to switch modes", 30, ofGetHeight() - 30);
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case '0':
		mode = 0;
		break;


	case '1':
		mode = 1;
		break;

	case '2':
		mode = 2;
		break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
