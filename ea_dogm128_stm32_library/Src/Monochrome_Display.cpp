#include "Monochrome_Display.hpp"

#include "EA_DOGM128_6_com.hpp"
#include "stm32f4xx_hal.h"

#include "bitmap_data.hpp"





void Monochrome_Display::init(SPI_HandleTypeDef* in_hspi)
{
	Display.init(in_hspi);
}

void Monochrome_Display::clear()
{
	Display.clear();
}

void Monochrome_Display::drawLine(uint8_t Ax,uint8_t Ay,uint8_t Bx,uint8_t By, bool bstate)
{
	if (Ax == Bx) //horizontale Linie
	{
		for (int var = 0; var < abs(Ay-By); ++var)
		{
			Display.setPixel(Ax, var, bstate);
		}
	}

	if (Ay == By) //vertikale Linie
	{
		for (int var = 0; var < abs(Ax-Bx); ++var)
		{
			Display.setPixel(var, Ay, bstate);
		}
	}
}

uint8_t Monochrome_Display::drawBitchain(uint8_t* bitmap_arr, uint8_t xpos, uint8_t ypos, uint8_t xsize, uint8_t ysize, bool bstate)
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
				Display.setPixel(xpos, ypos, bstate);
			}
			else
			{
				Display.setPixel(xpos, ypos, !bstate);
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

void Monochrome_Display::test()
{
	for (int page = 0; page < 8; ++page)
	{
		drawBitchain(teile, 0, 0, 128, 64, true);
	}
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
