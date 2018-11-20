#include "GridSoundPlayer.h"

void GridSoundPlayer::setup(int width_, int height_)
{
	width = width_;
	height = height_;
	scale = ofGetHeight() / height;
	row = 10;
	col = 10;
	loadGrid("sounds/synth.wav");
}

void GridSoundPlayer::update()
{
	ofSoundUpdate();
}

void GridSoundPlayer::drawGrid() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ofSetColor(i*col + j*row);
			ofDrawRectangle(scale*width/col * i, scale*height/row * j, width*scale/row, height*scale/row);
		}
	}
}

void GridSoundPlayer::loadGrid(string sound_file_name) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ofSoundPlayer sound;
			sound.load(sound_file_name);
			sound.setSpeed(0.1f + (2.0*i)/col);
			sound.setPan(-1.0f + (2.0*j)/row);
			grid.push_back(sound);
		}
	}
}

int GridSoundPlayer::indexof(int x, int y) {
	x /= (scale*width / col);
	y /= (scale*height / row);
	return x + col * y;
}

void GridSoundPlayer::playGrid(int x, int y)
{
	ofSoundPlayer & sound = grid[indexof(x, y)];
	if (!sound.isPlaying()) {
		//soundStopAll();
		sound.play();
	}
}

void GridSoundPlayer::soundStopAll() {
	for (auto s : grid) {
		if (s.isPlaying()) {
			s.stop();
		}
	}
}
