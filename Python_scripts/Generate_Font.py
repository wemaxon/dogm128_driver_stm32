# -*- coding: utf-8 -*-
"""
   Copyright (C) 2019,2020  Maximilian Anton Weber
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
"""





########################################################
#Insert the Path and Font Name
font_path = 'FONTS/'                    #EXAMPLE = 'FONTS/'
font_name = 'smallFT'                   #EXAMPLE = 'smallFT'


dimensionX = 6
dimensionY = 5

bytesize = 4

amount = 256

########################################################

import Image_to_Hex_data as ItH
import cv2


letters_list = []

for i in range(amount):
    img_name = font_path + font_name + '/' + str(i) + ".bmp"
    img_read = cv2.imread(img_name, 0)
    letter_bytes = ItH.img_to_hex(img_read)
    print(letter_bytes)
    for k in range(len(letter_bytes)):
        letters_list.append(letter_bytes[k])


Out_File_name = font_path + font_name +'.txt'
Out_File = open(Out_File_name, "w+")
Out_File.write("Font Hex from bmp Generator \nBuilt for low resoultion monochrome displays \nWritten by Maximilian Weber \n\n\n")   
Out_File.write("Font Dimensions: \nX= ")
Out_File.write(str(dimensionX))
Out_File.write("\nY= ")
Out_File.write(str(dimensionY))
Out_File.write("\nPixels or Bits per Font= ")
Out_File.write(str(dimensionY*dimensionX))
Out_File.write("\n\n")

letter_counter = 0
hex_written = 0
Out_File.write("{")
for i in range(len(letters_list)):
    Out_File.write("0x%02X" % letters_list[i])
    
    if((i + 1) < len(letters_list)):
        Out_File.write(", ")
        
    hex_written = hex_written +1    
    if(hex_written % bytesize == 0):
        Out_File.write(" // ASCI " + str(letter_counter))
        letter_counter +=1
        Out_File.write("\n")
Out_File.write("}")

Out_File.close()