from picamera import PiCamera
from time import sleep

#camera = picamera.PiCamera()
camera = PiCamera()
#camera.resolution = (1920x1080) 

#camera.capture('Test.jpg')

camera.start_preview()
# for if you're feelng feisty
#for i in range(5) 
sleep(15)
#	camera.capture('/home/pi/capture%s.jpg' %i)
camera.capture('/home/pi/capture1.jpg')
# camera.start_recording('/home/pi/video.h264')
#camera.wait_recording(10)
#camera.stop_recording()
camera.stop_preview()
