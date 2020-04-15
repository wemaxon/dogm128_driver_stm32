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
#Set Parameters for font pixel height, width and amount of characters


generate_in_folder = 'generated_font_template/'


dimensionX = 6
dimensionY = 5

amount = 256

########################################################


import cv2
import numpy as np


for i in range(amount):
    img_binary = np.full((dimensionY, dimensionX), 255)
    img_name = str(i)
    img_path = generate_in_folder + str(i) + ".bmp"
    cv2.imwrite(img_path, img_binary)
