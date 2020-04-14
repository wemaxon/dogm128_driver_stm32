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




#ifndef __EA_DOGM128_6_COM_HPP
#define __EA_DOGM128_6_COM_HPP


#include "stm32f4xx_hal.h"



class EA_DOGM_128
{
	public:
		uint8_t Width = 128;
		uint8_t Height = 64;

		void init(SPI_HandleTypeDef* in_hspi);
		void updateBuffer();
		void clear();
		bool setPixel(uint8_t xpos, uint8_t ypos, bool bstate);


	private:
		SPI_HandleTypeDef* hspi;
		uint8_t buffer[128][8] = {0};

		void send_Data(uint8_t byte);
		void send_Command(uint8_t byte);

};




#endif
