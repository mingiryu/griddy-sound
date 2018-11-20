#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"

class ContourTracker {
	public:
		void setup(int width_, int height_);
		void update();
		void draw();

		vector<ofVec2f> & getPoints();
		void mousePressed(int x, int y, int button);

	private:
		ofVideoGrabber vidGrabber;
		int width, height, scale;

		ofxCvColorImage colorImage;
		ofxCvGrayscaleImage grayImage, grayBgImage, grayDiff;
		ofxCvFloatImage grayImageFloat, grayBgFloat; // Used for adaptive background, image multiplication.

		ofxPanel gui;

		ofColor targetColor; // User selected color.
		ofParameter<float> delta; // Maximum distance between targetColor and pixel color.

		ofxCvContourFinder contourFinder;
		ofParameter<int> threshold, minArea, maxArea, maxContours;
		ofParameter<bool> bApproximateContour;
		bool bLearnBackground;

		vector<ofVec2f> points;
};
