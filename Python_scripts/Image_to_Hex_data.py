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





#Set Parameters for img
########################################################
#Insert the Image Path and Name
img_path = 'IMAGES/'                #EXAMPLE = 'IMAGES/'
img_name = 'camaro.jpg'             #EXAMPLE = 'camaro.jpg'

dimensionX = 128
dimensionY = 64

Threshhold = 127
########################################################



import cv2



def set_bit(value, bit):
    return value | (1<< (7 - bit))

def clear_bit(value, bit):
    return value & ~(1<< ( 7 - bit))

def process_image(image, dimensionX, dimensionY, Threshhold):
    
    original_rows, original_cols = image.shape
    
    if(original_rows != dimensionY or original_cols != dimensionX):
        print("Resizing Image")
        img_resized = cv2.resize(image, (dimensionX, dimensionY), interpolation=cv2.INTER_AREA)    # interpolation=cv2.INTER_AREA 
    else:
        print("No need to resize Image")
        img_resized = image
    
    retval, img_binary = cv2.threshold(img_resized,Threshhold,255,cv2.THRESH_BINARY)
    
    out_img_name = img_path + '/' + "Monochrome_Bitmap (" + img_name + ").bmp"
    cv2.imwrite(out_img_name, img_binary)
    
    return img_binary


def img_to_hex(image):
    bit_arr = [0]
    bitposcounter = 0
    
    rows,cols = image.shape
    
    for y in range(rows):
        for x in range(cols):
            
            #print("bitposcounter: %s" % (bitposcounter))
            #print("img[%s][%s]: %s" % (x, y, img_binary[y,x]))
            #print("setting bit %s at bit_arr[%s]" % ((bitposcounter%8),(bitposcounter//8)))
         
            
            if(image[y,x] == 0):
                bit_arr[bitposcounter//8] = set_bit(bit_arr[bitposcounter//8], (bitposcounter%8))
                
            elif(image[y,x] == 255):
                bit_arr[bitposcounter//8] = clear_bit(bit_arr[bitposcounter//8], (bitposcounter%8))
                 
                
            bitposcounter = bitposcounter + 1    
            if(bitposcounter >= (len(bit_arr) * 8)):
                #print("appended to bit_arr")
                bit_arr.append(0)
    return bit_arr

def save_hex_to_file(bit_arr, dimensionX, dimensionY):
    Out_File_name = img_path + '/' + "Binary_Data (" + img_name + ").txt"
    Out_File = open(Out_File_name, "w+")
    Out_File.write("Image to Binary Bitmap Converter \nBuilt for low resoultion monochrome displays \nWritten by Maximilian Weber \n\n\n")   
    Out_File.write("Image Dimensions: \nX= ")
    Out_File.write(str(dimensionX))
    Out_File.write("\nY= ")
    Out_File.write(str(dimensionY))
    Out_File.write("\nPixels or Bits= ")
    Out_File.write(str(dimensionY*dimensionX))
    Out_File.write("\n\n")
    
    
    hex_written = 0
    Out_File.write("{")
    for i in range(len(bit_arr)):
        Out_File.write("0x%02X" % bit_arr[i])
        
        if((i + 1) < len(bit_arr)):
            Out_File.write(", ")
            
        hex_written = hex_written +1    
        if(hex_written % 15 == 0):
            Out_File.write("\n") 
    Out_File.write("}")
    
    Out_File.close()
    
    print("File has been written")
     

def main():
    img_read = cv2.imread(img_path + img_name, 0)
    image = process_image(img_read, dimensionX, dimensionY, Threshhold)
    Hex_Data = img_to_hex(image)
    save_hex_to_file(Hex_Data, dimensionX, dimensionY)
    
if __name__ == "__main__":
    main()



     







