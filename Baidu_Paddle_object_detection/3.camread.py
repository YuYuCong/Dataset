# coding:UTF-8
'''
/*=================================================================================
 *                      Copyleft! 2018 William Yu
 *          Some rights reserved：CC(creativecommons.org)BY-NC-SA
 * Programmer(s)           : William Yu, windmillyucong@163.com
 * Modification History    : ver1.0, 2018.11.16, William Yu
 *                          
=================================================================================*/
'''
import cv2

if __name__ == '__main__':
    
  
    while True: 
        frame = cv2.imread("./imgprocessed.png")
        cv2.imshow("imgprocessed", frame)
        cv2.waitKey(50)
        if cv2.waitKey(1) & 0xFF == ord('q'): 
            break 