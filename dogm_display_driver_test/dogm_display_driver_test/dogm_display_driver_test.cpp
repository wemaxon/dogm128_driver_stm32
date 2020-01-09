#include <iostream>

using namespace std;





uint8_t Width = 64;
uint8_t Height = 64;

uint8_t bitmap[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x7F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFE, 0x40, 0x00, 0x00, 0x00, 0x00,
0x07, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00,
0x00, 0x1F, 0xE0, 0x3F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x07, 0xF0, 0x00, 0x00,
0x00, 0x00, 0x7C, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x7C, 0x00,
0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x3E,
0x00, 0x00, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x00,
0x3E, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x18, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x03, 0xF8, 0x0E,
0x07, 0xFF, 0x00, 0x00, 0x00, 0x03, 0xF8, 0x7E, 0x0F, 0xFF, 0x00, 0x00, 0x00, 0x07, 0xF0,
0x58, 0x1F, 0xFE, 0x00, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x08, 0x1A, 0x00, 0x00, 0x00, 0x07,
0xF0, 0x00, 0x08, 0x1A, 0x00, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x08, 0x1E, 0x00, 0x00, 0x00,
0x07, 0xF0, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x1F, 0x00, 0x00,
0x00, 0x0F, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x3F, 0x40,
0x00, 0x00, 0x1F, 0xFC, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x1F, 0xFC, 0x00, 0x00, 0x7F,
0x80, 0x00, 0x00, 0x1F, 0xFC, 0x00, 0x08, 0x7F, 0x00, 0x00, 0x00, 0x1F, 0xFE, 0x00, 0x00,
0xFF, 0x00, 0x00, 0x00, 0x3F, 0xFE, 0x00, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0x00,
0x03, 0xFF, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x07, 0xFF, 0x80, 0x00, 0x00, 0x3F, 0xFF,
0x00, 0x0F, 0xFF, 0xC0, 0x00, 0x00, 0x3F, 0xFF, 0x80, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x1F,
0xFF, 0x80, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x1F, 0xFF, 0x80, 0x07, 0xFF, 0xF0, 0x00, 0x00,
0x1F, 0xBF, 0xC0, 0x0F, 0xE7, 0xFF, 0x00, 0x00, 0x0F, 0xFF, 0xF0, 0xFF, 0xC7, 0xFF, 0x80,
0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xC0, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xE0, 0x00, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x7F, 0x7F, 0xFF, 0xFF, 0xF7,
0xFF, 0xF0, 0x04, 0xFF, 0x7F, 0xFF, 0xFF, 0xF1, 0xFF, 0xF0, 0x0D, 0xFE, 0xFF, 0xFF, 0xFF,
0xF1, 0xFF, 0xF8, 0x0F, 0xFE, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xF8, 0x1F, 0xC9, 0xFF, 0xFF,
0xFF, 0xFC, 0xFF, 0xFC, 0x1F, 0xDB, 0xFE, 0x7F, 0xFF, 0xFD, 0xFF, 0xFC, 0x3F, 0x87, 0xFF,
0xFF, 0xFF, 0x3D, 0xFF, 0xFE, 0x3F, 0x87, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFE, 0x3F, 0x3F,
0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x7F, 0xEF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0x7F,
0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0x7F, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x00 };





bool picture[128][64] = { 0 };


void setPixel(uint8_t xpos, uint8_t ypos, bool bstate = true)
{
	picture[xpos][ypos] = bstate;
}

uint8_t drawBitmap(uint8_t* bitmap_arr, uint8_t xpos, uint8_t ypos, uint8_t xsize, uint8_t ysize, bool bstate)
{
	uint16_t bitlength = xsize * ysize;

	uint8_t startposx = xpos;
	uint8_t startposy = ypos;

	for (int arr_pos = 0; arr_pos <= bitlength / 8; ++arr_pos)
	{
		for (int bit_pos = 0; bit_pos < 8; ++bit_pos)
		{
			uint8_t temp = 1 << (7 - bit_pos);
			uint8_t bmp_temp = *(bitmap_arr + arr_pos);

			if (bmp_temp & temp)	// Check if Certain Bit in Byte is set
			{
				setPixel(xpos, ypos, bstate);
			}
			else
			{
				setPixel(xpos, ypos, !bstate);
			}

			xpos += 1;

			if (xpos >= startposx + xsize)
			{
				xpos = startposx;
				ypos += 1;
			}
			if (ypos >= startposy + ysize)
			{
				return 0;
			}
		}
	}

	return 1;
}


int main()
{

	int retval = drawBitmap(bitmap, 0, 0, Width, Height, true);



	for (size_t y = 0; y < 64; y++)
	{
		for (size_t x = 0; x < 128; x++)
		{
			if (picture[x][y] == true)
			{
				cout << "x";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n -------------------------------------------------------" + retval << endl << endl;
}

