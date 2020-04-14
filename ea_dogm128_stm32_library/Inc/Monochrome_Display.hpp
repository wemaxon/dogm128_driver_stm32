/*
 *    Copyright (C) 2019,2020  Maximilian Anton Weber
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef MONOCHROME_DISPLAY_HPP
#define MONOCHROME_DISPLAY_HPP


#include "EA_DOGM128_6_com.hpp"
#include "bitmap_data.hpp"
#include "font_data.hpp"
#include <string>


class Monochrome_Display
{
	public:
		void init(SPI_HandleTypeDef* in_hspi);
		void clear();
		void updateBuffer();
		void setPixel(uint8_t xpos, uint8_t ypos, bool bstate);
		void drawLine(uint8_t Ax,uint8_t Ay,uint8_t Bx,uint8_t By, bool binverted = false);
		void drawImage(const Image* Bitmap, uint8_t xpos, uint8_t ypos, bool binverted = false);
		void writeString(const std::string& input, const Font* font, uint8_t xpos, uint8_t ypos, bool binverted = false);
		void test();

	private:
		EA_DOGM_128 Display;

		uint8_t drawBitchain(const uint8_t* bitmap_arr, uint8_t xpos, uint8_t ypos, uint8_t xsize, uint8_t ysize, bool binverted = false);
		uint8_t drawBitchain(uint8_t* bitmap_arr, uint8_t xpos, uint8_t ypos, uint8_t xsize, uint8_t ysize, bool binverted = false);
		void writeChar(uint8_t character, const Font* font, uint8_t xpos, uint8_t ypos, bool binverted = false);



};































#endif
