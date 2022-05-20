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

#include "EA_DOGM128_6_com.hpp"
#include "stm32f4xx_hal.h"


void EA_DOGM_128::init(SPI_HandleTypeDef* in_hspi, GPIO_TypeDef* Port_CS, uint16_t Pin_CS, GPIO_TypeDef* Port_A0, uint16_t Pin_A0, GPIO_TypeDef* Port_RST, uint16_t Pin_RST)
{
	hspi = in_hspi;

	port_CS = Port_CS;
	pin_CS = Pin_CS;
	port_A0 = Port_A0;
	pin_A0 = Pin_A0;
	port_RST = Port_RST;
	pin_RST = Pin_RST;


	// RESET
	HAL_GPIO_WritePin(Port_RST, Pin_RST , GPIO_PIN_RESET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(Port_RST, Pin_RST , GPIO_PIN_SET);
	HAL_Delay(100);

	send_Command(0x40);	// Display start line = 0
	send_Command(0xA0);	// ADC normal
	send_Command(0xC8);	// COM0 - COM63 Reverse
	send_Command(0xA6);	// Display normal, not mirrored
	send_Command(0xA2);	// Set bias 1/9
	send_Command(0x2F);	// Booster, regulator and follower on
	send_Command(0xF8);	// Set internal booster to 4x
	send_Command(0x00);	// Set internal booster to 4x
	send_Command(0x27);	// Contrast set
	send_Command(0x81);	// Contrast set
	send_Command(0x16);	// Contrast set
	send_Command(0xAD);	// Indicator on
	send_Command(0x00);	// Indicator Mode
	send_Command(0xAF);	// Display on

	HAL_Delay(10);

	clear();	//clear display
}

void EA_DOGM_128::send_Data(uint8_t byte)
{
	HAL_GPIO_WritePin(port_CS, pin_CS , GPIO_PIN_RESET);
	HAL_SPI_Transmit(hspi, &byte,1,100);
	HAL_GPIO_WritePin(port_CS, pin_CS , GPIO_PIN_SET);
}

void EA_DOGM_128::send_Command(uint8_t byte)
{
	HAL_GPIO_WritePin(port_A0, pin_A0 , GPIO_PIN_RESET);	// Take A0 Low for Command

	send_Data(byte);

	HAL_GPIO_WritePin(port_A0, pin_A0 , GPIO_PIN_SET);		// Take A0 High again
}

void EA_DOGM_128::updateBuffer()
{
	for (int page = 0; page < 8; ++page)
	{
		send_Command(0xB0 + page); // Set Page

		send_Command(0b00010000); // Set column to 0 (Column will auto increment after writing)
		send_Command(0b00000100);

		for (int column = 0; column < 128; ++column)
		{
				send_Data(buffer[column][page]);
		}
	}

}


void EA_DOGM_128::clearBuffer()
{
	for (int page = 0; page < 8; ++page)
	{
		for (int column = 0; column < 128; ++column)
		{
			buffer[column][page] = 0x00;
		}
	}
}

void EA_DOGM_128::clear()
{
	clearBuffer();
	updateBuffer();
}

bool EA_DOGM_128::setPixel(uint8_t xpos, uint8_t ypos, bool bstate)
{
	if (xpos > 127 || ypos > 63)
	{
		return false;
	}
	else
	{
		uint8_t page = ypos / 8;
		uint8_t place = ypos % 8;

		if (bstate == true)
		{
			buffer[xpos][page] |= 1UL << place;
		}
		else if (bstate == false)
		{
			buffer[xpos][page] &= ~(1UL << place);
		}

		return true;
	}
}


