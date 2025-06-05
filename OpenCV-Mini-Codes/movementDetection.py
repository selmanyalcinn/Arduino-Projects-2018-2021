import cv2
from datetime import datetime

def hareket(t1,t2,t3):
    fark1=cv2.absdiff(t3,t2)
    fark2=cv2.absdiff(t2,t1)
    return cv2.bitwise_and(fark1,fark2)

esikdeger=140000
cam=cv2.VideoCapture(0)
pencere="Hareket Algilama"
cv2.namedWindow(pencere)
t1=cv2.cvtColor(cam.read()[1],cv2.COLOR_BGR2GRAY)
t2=cv2.cvtColor(cam.read()[1],cv2.COLOR_BGR2GRAY)
t3=cv2.cvtColor(cam.read()[1],cv2.COLOR_BGR2GRAY)
zamankontrol=datetime.now().strftime("%Ss")

while True:
    cv2.imshow(pencere,cam.read()[1])
    if cv2.countNonZero(hareket(t1,t2,t3))>esikdeger and zamankontrol != datetime.now().strftime("%Ss"):
        far_resim=cam.read()[1]
        cv2.imwrite(datetime.now().strftime("%Y%m%d_%Hh%Mm%Ss%f")+".jpg",far_resim)
    zamankontrol=datetime.now().strftime("%Ss")
    t1=t2
    t2=t3
    t3=cv2.cvtColor(cam.read()[1],cv2.COLOR_BGR2GRAY)
    key=cv2.waitKey(10)
    if key==27:
        cv2.destroyWindow(pencere)
        break
