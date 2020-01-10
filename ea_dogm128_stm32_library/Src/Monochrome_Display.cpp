#include "Monochrome_Display.hpp"
#include "stm32f4xx_hal.h"

void Monochrome_Display::init(SPI_HandleTypeDef* in_hspi)
{
	Display.init(in_hspi);
}

void Monochrome_Display::clear()
{
	Display.clear();
}

void Monochrome_Display::setPixel(uint8_t xpos, uint8_t ypos, bool bstate)
{
	Display.setPixel(xpos, ypos, bstate);
}
void Monochrome_Display::drawLine(uint8_t Ax,uint8_t Ay,uint8_t Bx,uint8_t By, bool binverted)
{
	if (Ax == Bx) //horizontale Linie
	{
		for (int var = 0; var < abs(Ay-By); ++var)
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
	if (Ay == By) //vertikale Linie
	{
		for (int var = 0; var < abs(Ax-Bx); ++var)
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


void Monochrome_Display::drawImage(const Image* Bitmap, uint8_t xpos, uint8_t ypos, bool binverted)
{
	drawBitchain(Bitmap->BitChain, xpos, ypos, Bitmap->Width, Bitmap->Height, binverted);
}

void Monochrome_Display::writeChar(uint8_t character, const Font* font, uint8_t xpos, uint8_t ypos, bool binverted)
{
	const uint8_t* char_address = font->BitChain +(character*4);

	drawBitchain(char_address, xpos, ypos, font->Width, font->Height, binverted);

	//drawBitchain(lynns, 0, 0, 51, 64);
}


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
	writeString("ABCDEFGHIJKLMNOPQRSTUVWXYUZ", &smallFT, 0, 0);
	Display.updateBuffer();

	HAL_Delay(3000);

	drawImage(&lynn, 0, 0);
	Display.updateBuffer();




}


uint8_t Monochrome_Display::abs(uint8_t value)
{
	if (value < 0)
	{
		return !value;
	}
	else
	{
		return value;
	}
}
