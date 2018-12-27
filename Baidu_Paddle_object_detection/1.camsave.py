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
    
    cap = cv2.VideoCapture(0) 

    while True: 
        ret,frame = cap.read() 
        # frame = cv2.resize(frame,(480,320),interpolation=cv2.INTER_CUBIC)
        if ret == True: 
            # cv2.imshow("frame", frame) 
            cv2.imwrite("frame.jpg", frame)
            if cv2.waitKey(10) & 0xFF == ord('q'): 
               break 
        else: 
            break
    cap.release()
    cv2.destroyAllWindows()