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
