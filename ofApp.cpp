#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(2);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int radius = 240;
	int len = radius * 2.5;

	for (int param = 0; param <= 100; param++) {

		int deg = (param * 3.6 - 135);
		deg += ofMap(ofNoise(ofGetFrameNum() * 0.01), 0, 1, -730, 720);

		auto location_1 = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
		auto location_2 = this->make_point(len, param);

		ofDrawLine(location_1, location_2);

		ofDrawCircle(location_1, 3);
		ofDrawRectangle(location_2, 6, 6);
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}