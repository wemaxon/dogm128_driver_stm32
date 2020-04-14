# -*- coding: utf-8 -*-
"""
Created on Thu Jan  9 16:35:18 2020

@author: Max
"""

#Set Parameters for img
########################################################
file_path = '33.bmp'

dimensionX = 6
dimensionY = 5

amount = 256

########################################################


import cv2
import numpy as np

for i in range(amount):
    img_binary = np.full((dimensionY, dimensionX), 255)
    img_name = str(i) + ".bmp"
    cv2.imwrite(img_name, img_binary)
