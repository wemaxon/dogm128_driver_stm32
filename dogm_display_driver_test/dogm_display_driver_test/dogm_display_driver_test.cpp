#include <iostream>

using namespace std;





uint8_t Width = 5;
uint8_t Height = 5;

uint8_t bitmap[] = { 0xF4, 0xBD, 0x29 };





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

