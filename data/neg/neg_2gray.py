#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 20:46:51 2018

@author: wjf
"""

import cv2 as cv 

for i in range (145):
    img = cv.imread('*.jpg'%(i),0)
    cv.imwrite('neg%d.jpg'%(i),img)