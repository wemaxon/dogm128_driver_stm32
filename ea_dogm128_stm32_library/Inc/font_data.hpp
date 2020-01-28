/*
 * This file is part of Maximilian Weber's Electronics Assembly DOGM128 Monochrome Display Library.
 *
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


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
