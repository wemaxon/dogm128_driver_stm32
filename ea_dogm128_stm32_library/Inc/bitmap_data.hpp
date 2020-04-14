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
extern const Image camaro;
extern const Image htw;


#endif
