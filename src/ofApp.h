#pragma once

#include "ofMain.h"
#include "ContourTracker.h"
#include "GridSoundPlayer.h"

class ofApp : public ofBaseApp
{

  public:
	void setup();
	void update();
	void draw();

	void mousePressed(int x, int y, int button);

	ContourTracker contourTracker;
	GridSoundPlayer gridSoundPlayer;
};
