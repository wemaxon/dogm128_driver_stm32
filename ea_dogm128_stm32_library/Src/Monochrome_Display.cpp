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

#include "Monochrome_Display.hpp"
#include "stm32f4xx_hal.h"


/**
 * Initializes display
 *
 * @param SPI handle structure
 */
void Monochrome_Display::init(SPI_HandleTypeDef* in_hspi)
{
	Display.init(in_hspi);
}


/**
 * Clears display
 */
void Monochrome_Display::clear()
{
	Display.clear();
}


/**
 * Sends image Data from display buffer to display
 */
void Monochrome_Display::updateBuffer()
{
	Display.updateBuffer();
}


/**
 * Sets a certain pixel in the display buffer
 *
 * @param xpos,ypos X- and Y-coordinates of the pixel
 * @param bstate Boolean value of the pixel
 */
void Monochrome_Display::setPixel(uint8_t xpos, uint8_t ypos, bool bstate)
{
	Display.setPixel(xpos, ypos, bstate);
}


/**
 * Draws a line from point A to point B in the display buffer
 *
 * @param Ax,Ay,Bx,By X- and Y-coordinates of the Corners A and B
 * @param binverted Inverts line if true
 */
void Monochrome_Display::drawLine(uint8_t Ax,uint8_t Ay,uint8_t Bx,uint8_t By, bool binverted)
{
	if (Ay == By) //vertikale Linie
	{
		for (int var = 0; var < Ax-Bx; ++var)
		{
			if(binverted)
			{
				setPixel(Ax, var, false);
			}
			else
			{
				setPixel(Ax, var, true);
			}
		}
	}
	if (Ax == Bx) //horizontale Linie
	{
		for (int var = 0; var < Ay-By; ++var)
		{
			if (binverted)
			{
				setPixel(var, Ay, false);
			}
			else
			{
				setPixel(var, Ay, true);
			}
		}
	}
}


/**
 * Draws binary image on display buffer
 *
 * @param bitmap_arr Pointer to array with stored binary image data
 * @param xpos,ypos X- and Y-coordinates of the image
 * @param xsize,ysize Horizontal and vertical size of the image stored in bitmap_arr
 * @param binverted Inverts image if true
 */
uint8_t Monochrome_Display::drawBitchain(const uint8_t* bitmap_arr, uint8_t xpos, uint8_t ypos, uint8_t xsize, uint8_t ysize, bool binverted)
{
	uint16_t bitlength = xsize * ysize;

	uint8_t startposx = xpos;
	uint8_t startposy = ypos;

	for (int arr_pos = 0; arr_pos <= bitlength/8; ++arr_pos)
	{
		for (int bit_pos = 0; bit_pos < 8; ++bit_pos)
		{
			uint8_t temp = 1 << (7 - bit_pos);
			uint8_t bmp_temp = *(bitmap_arr + arr_pos);

			if(bmp_temp & temp)						// Check if Certain Bit in Byte is set
			{
				Display.setPixel(xpos, ypos, !binverted);
			}
			else
			{
				Display.setPixel(xpos, ypos, binverted);
			}

			xpos += 1;

			if (xpos >= startposx + xsize)
			{
				xpos = startposx;
				ypos += 1;
			}
			if(ypos >= startposy + ysize)
			{
				return 0;
			}
		}
	}
	return 1;
}


/**
 * Draws binary image on display buffer
 *
 * @param bitmap_arr Pointer to array with stored binary image data
 * @param xpos,ypos X- and Y-coordinates of the image
 * @param xsize,ysize Horizontal and vertical size of the image stored in bitmap_arr
 * @param binverted Inverts image if true
 */
uint8_t Monochrome_Display::drawBitchain(uint8_t* bitmap_arr, uint8_t xpos, uint8_t ypos, uint8_t xsize, uint8_t ysize, bool binverted)
{
	uint16_t bitlength = xsize * ysize;

	uint8_t startposx = xpos;
	uint8_t startposy = ypos;

	for (int arr_pos = 0; arr_pos <= bitlength/8; ++arr_pos)
	{
		for (int bit_pos = 0; bit_pos < 8; ++bit_pos)
		{
			uint8_t temp = 1 << (7 - bit_pos);
			uint8_t bmp_temp = *(bitmap_arr + arr_pos);

			if(bmp_temp & temp)						// Check if Certain Bit in Byte is set
			{
				Display.setPixel(xpos, ypos, !binverted);
			}
			else
			{
				Display.setPixel(xpos, ypos, binverted);
			}

			xpos += 1;

			if (xpos >= startposx + xsize)
			{
				xpos = startposx;
				ypos += 1;
			}
			if(ypos >= startposy + ysize)
			{
				return 0;
			}
		}
	}
	return 1;
}


/**
 * Draws image object on display buffer
 *
 * @param image Pointer to image object
 * @param xpos,ypos X- and Y-coordinates of the image
 * @param binverted Inverts image if true
 */
void Monochrome_Display::drawImage(const Image* Bitmap, uint8_t xpos, uint8_t ypos, bool binverted)
{
	drawBitchain(Bitmap->BitChain, xpos, ypos, Bitmap->Width, Bitmap->Height, binverted);
}

/**
 * Draws character on display buffer
 *
 * @param character
 * @param font Pointer to font that the character will be written in
 * @param xpos,ypos X- and Y-coordinates of the character
 * @param binverted Inverts character if true
 */
void Monochrome_Display::writeChar(uint8_t character, const Font* font, uint8_t xpos, uint8_t ypos, bool binverted)
{
	const uint8_t* char_address = font->BitChain +(character*4);

	drawBitchain(char_address, xpos, ypos, font->Width, font->Height, binverted);

	//drawBitchain(lynns, 0, 0, 51, 64);
}

/**
 * Draws string on display buffer
 *
 * @param string
 * @param font Pointer to font that the string will be written in
 * @param xpos,ypos X- and Y-coordinates of the string
 * @param binverted Inverts string if true
 */
void Monochrome_Display::writeString(const std::string& input, const Font* font, uint8_t xpos, uint8_t ypos, bool binverted)
{
	uint8_t current_xpos = xpos;
	uint8_t current_ypos = ypos;

	for(const char& c : input) {
	   writeChar(c, font, current_xpos, current_ypos, binverted);

	   if ((current_xpos + font->Width) > Display.Width)
	   {
		   current_xpos = xpos;
		   current_ypos += font->Height + 1;
	   }
	   else
	   {
		   current_xpos += font->Width;
	   }
	}

}



void Monochrome_Display::test()
{

	updateBuffer();


}


