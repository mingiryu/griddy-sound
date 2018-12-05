#include "GridSoundPlayer.h"

void GridSoundPlayer::setup(int width_, int height_)
{
	width = width_;
	height = height_;
	scale = ofGetHeight() / height;
	
	loadSound("ProducerSpot-808-Drums");
	row = sqrt(grid.size());
	col = row;
	//loadGrid("sounds/synth.wav");
}

void GridSoundPlayer::update()
{
	ofSoundUpdate();
}

void GridSoundPlayer::drawGrid() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ofColor color(i*col + j*row);
			if (grid[i + col * j].isPlaying()) {
				ofSetColor(color + ofColor::blue);
			} else {
				ofSetColor(color);
			}
			ofDrawRectangle(scale*width/col * i, scale*height/row * j, width*scale/row, height*scale/row);
		}
	}
}

void GridSoundPlayer::loadSound(const std::string& file)
{
	string dat = file + "/loadSound.dat";
	 
	vector<string> file_list = ofSplitString(ofBufferFromFile(dat).getText(), "\n");
	for (int i = 0; i < file_list.size(); i++) {	
		ofSoundPlayer sound;
		string file_name = file_list[i];
		
		if (file_name.length() > 1) {
			sound.load(file + "/" + file_name);
			grid.push_back(sound);
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

void GridSoundPlayer::hold() {
	for (auto sound : grid) {
		if (sound.isPlaying()) {
			sound.setLoop(true);
		}
	}
}

void GridSoundPlayer::releaseAll() {
	for (auto sound : grid) {
		sound.setLoop(false);
	}
}