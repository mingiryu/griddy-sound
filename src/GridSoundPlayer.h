#pragma once

#include "ofMain.h"

class GridSoundPlayer
{
	public:
		void setup(int width_, int height_);
		void update();
		/**
		 * Draw row by column rectangles in griedient.
		 */
		void drawGrid();
		/**
		 * Plays the sound based on (x,y) coordinate.
		 */
		void playGrid(int x, int y);

	private:
		vector<ofSoundPlayer> grid; // row by column matrix of sound, use indexof() to access.
		int width, height, scale;
		int row, col;

		/**
		 * Loads up a single audio file with gradient speed and pan.
		 */
		void loadGrid(string sound_file_name);
		/**
		 * Reduces (x,y) coordinates to (idx).
		 */
		int indexof(int x, int y); 
		/**
		 * Replacement of ofSoundStopAll().
		 * ofSoundStopAll() is supported for windows/macos.
		 */
		void soundStopAll();
};
