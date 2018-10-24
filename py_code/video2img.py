import cv2

img = cv2.imread("lena.png") # load image
cv2.imshow("image", img)    # show image
cv2.waitKey(0)  # wait until key pressed
