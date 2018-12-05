#include "ofApp.h"

void ofApp::setup()
{
	int width = 320;
	int height = 240;
	contourTracker.setup(width, height);
	gridSoundPlayer.setup(width, height);
}

void ofApp::update()
{
	contourTracker.update();
	gridSoundPlayer.update();
}

void ofApp::draw()
{
	contourTracker.draw();
	gridSoundPlayer.drawGrid();

	vector<ofVec2f> &points = contourTracker.getPoints();
	for (auto p : points)
	{
		ofSetColor(255);
		ofDrawCircle(p.x, p.y, 10);
		gridSoundPlayer.playGrid(p.x, p.y);
	}
}

void ofApp::mousePressed(int x, int y, int button)
{
	contourTracker.mousePressed(x, y, button);
}

void ofApp::keyPressed(int key)
{
	if (key == 's') {
		gridSoundPlayer.soundStopAll();
	}
	if (key == 'h') {
		gridSoundPlayer.hold();
	}
	if (key == 'r') {
		gridSoundPlayer.releaseAll();
	}
}
