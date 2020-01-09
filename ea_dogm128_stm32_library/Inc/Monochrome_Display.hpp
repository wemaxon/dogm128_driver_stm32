#ifndef MONOCHROME_DISPLAY_HPP
#define MONOCHROME_DISPLAY_HPP


#include "EA_DOGM128_6_com.hpp"



class Monochrome_Display
{
	public:
		void init(SPI_HandleTypeDef* in_hspi);
		void clear();
		void updateBuffer();
		bool setPixel(uint8_t xpos, uint8_t ypos, bool bstate);
		void drawLine(uint8_t Ax,uint8_t Ay,uint8_t Bx,uint8_t By, bool bstate = true);
		void test();


	private:
		EA_DOGM_128 Display;

		uint8_t drawBitchain(uint8_t* bitmap_arr, uint8_t xpos, uint8_t ypos, uint8_t xsize, uint8_t ysize, bool bstate = true);
		uint8_t abs(uint8_t value);



};































#endif
