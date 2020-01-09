# -*- coding: utf-8 -*-
"""
Created on Wed Dec 11 00:34:44 2019

@author: Maximilian Anton Weber
"""



#Set Parameters for img
########################################################
file_path = 'test_lynn.png'

dimensionX = 64
dimensionY = 32

Threshhold = 127
########################################################



import cv2




def set_bit(value, bit):
    return value | (1<< (7 - bit))

def clear_bit(value, bit):
    return value & ~(1<< ( 7 - bit))

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




def process_image(image, dimensionX, dimensionY, Threshhold):
    
    original_rows, original_cols = image.shape
    
    if(original_rows != dimensionY or original_cols != dimensionX):
        print("Resizing Image")
        img_resized = cv2.resize(image, (dimensionX, dimensionY), interpolation=cv2.INTER_AREA)    # interpolation=cv2.INTER_AREA 
    else:
        print("No need to resize Image")
        img_resized = image
    
    retval, img_binary = cv2.threshold(img_resized,Threshhold,255,cv2.THRESH_BINARY)
    
    img_name = "Monochrome_Bitmap (" + str(file_path) + ").bmp"
    cv2.imwrite(img_name, img_binary)
    
    return img_binary


img_read = cv2.imread(file_path, 0)
image = process_image(img_read, dimensionX, dimensionY, Threshhold)

bit_arr = img_to_hex(image)
         
            
Out_File_name = "Binary_Data (" + str(file_path) + ").txt"
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






