#ifndef BITMAP_DATA_HPP
#define BITMAP_DATA_HPP

#include "stdint.h"


struct Image
{
	uint8_t Width;
	uint8_t Height;
	uint8_t BitChain[];
};


extern const Image lynn;
extern const Image buchstabe;


#endif
