# -*- coding: utf-8 -*-
"""
Created on Thu Jan  9 16:35:18 2020

@author: Max
"""

#Set Parameters for font pixel height, width and amount of characters
########################################################
generate_in_folder = 'generated_font_template'


dimensionX = 6
dimensionY = 5

amount = 256

########################################################


import cv2
import numpy as np


for i in range(amount):
    img_binary = np.full((dimensionY, dimensionX), 255)
    img_name = str(i)
    img_path = generate_in_folder + '/' + str(i) + ".bmp"
    cv2.imwrite(img_path, img_binary)
