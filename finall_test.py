#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 28 00:38:26 2018

@author: wjf

"""

import time
import cv2 as cv

def mat_inter(x1, y1, w1, h1, x2, y2, w2, h2):
    lx = abs((x1 + x1 + w1) / 2 - (x2 + x2 + w2) / 2)   #distance between the zhongdian_x
    ly = abs((y1 + y1 + h1) / 2 - (y2 + y2 + h2) / 2)   #distance between zhongdian_y
    if lx <= (w1 + w2) / 2 and ly <= (h1 + h2) / 2:
        return True
    else:
        return False
    
    
def solve_coincide(x1, y1, w1, h1, x2, y2, w2, h2):
    if mat_inter(x1, y1, w1, h1, x2, y2, w2, h2)==True:
        col=min(x1+w1,x2+w2)-max(x1,x2)
        row=min(y1+h1,y2+h2)-max(y1,y2)
        intersection=col*row
        area1=w1*h1
        area2=w2*h2
        coincide=float(intersection)/min(area1,area2)
        return coincide
    else:
        return False

pathf = './haar-model/cascade.xml' 



people_cascade = cv.CascadeClassifier(pathf) 




cap=cv.VideoCapture(0)
cv.namedWindow('Person Detected!') 
counter=0
while True:
        counter=0
        sucess,img=cap.read()
        if img is None:
            print("none")
            break
        #img=img.astype(np.float32)
        #gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY) 
        faces = people_cascade.detectMultiScale(gray,1.1,5,cv.CASCADE_SCALE_IMAGE,(25,25),(150,150))    
        temp=0
        for (x,y,w,h) in faces: 
            if temp==1:
                area=solve_coincide(x,y,w,h,x2,y2,w2,h2)
                print(area)
                if area==False or area<0.5:                     #重叠区域阈值
                    img = cv.rectangle(img, (x,y), (x+w,y+h), (255,0,0),2) 
                    counter=counter+1
            else:
                img = cv.rectangle(img, (x,y), (x+w,y+h), (255,0,0),2)  
                counter=counter+1
            x2=x
            y2=y
            w2=w
            h2=h
            temp=1
        number="person_number:"+str(counter)
        img = cv.putText(img, str(number), (50, 50), cv.FONT_HERSHEY_SIMPLEX, 1.2, (0, 255, 0), 2)
        cv.imshow('Person Detected!',img) 
        
        k=cv.waitKey(1)
        print(counter)
        time.sleep(0.05)
        if k==27:
            cv.destroyAllWindows()
            break
cap.release()