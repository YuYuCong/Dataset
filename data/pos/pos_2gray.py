#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 20:46:51 2018

@author: wjf
"""

import cv2 as cv 



for i in range (114):
    img1 = cv.imread('%d.jpg'%(i),0)
    img = cv.resize(img1,(50,50),interpolation=cv.INTER_CUBIC)
    cv.imwrite('pos%d.jpg'%(i),img)
 
