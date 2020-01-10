#ifndef FONT_DATA_HPP
#define FONT_DATA_HPP

#include "stdint.h"


struct Font
{
	uint8_t Width;
	uint8_t Height;
	uint8_t BytesPerLetter;
	uint8_t BitChain[];
};

extern const Font smallFT;



#endif
