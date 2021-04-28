import RPi.GPIO as GPIO
from time import sleep
from smbus import SMBus

##### Start of I2C initilization #####
SLAVE_ADDRESS = 0x8 # address of Arduino in I2C
bus = SMBus(1)  # initilization needed for I2C  / indicates I2C bus 1 in dev/ic2-1

##### start of GPIO initilization ####
sendLED = 12 # LED that turns on while data sending (curious about speed)

GPIO.setmode(GPIO.BOARD)

GPIO.setup(sendLED,GPIO.OUT)

### working variables ###
myStop = 1  # sanity check code instead of while true
datSend = 0 # initialize data to send

while myStop = 1:
	#GPIO.output(sendLED,False)
	print("Do you want to move forward?") # user input code for debugging temporarily
	## will comment code when autonomy comes
	motDrive = input("Y/N >>> ")

	if   motDrive == "Y":
		datSend = 0x4
	elif motDrive == "N":
		datSend = 0x1

	print("Ping Ultrasonic?") # user input code for debugging temporarily
	ultSon = input("Y/N >> ")

	if ultSon == "Y":
		datSend = datSend | 01000000
	GPIO.output(sendLED,True)
	print("Sending value of ", datSend, " to Arduino")
	bus.write_byte(SLAVE_ADDRESS,datSend)

	print("End the code?")
	GPIO.output(sendLED,False)
	checkStop = print("Y/N >>> ")

	if checkStop == "Y":
		myStop = 0

GPIO.cleanup() # just in case
