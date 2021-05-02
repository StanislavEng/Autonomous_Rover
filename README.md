# Autonomous_Rover
Autonomous rover controlled using Raspberry Pi Brain and Arduino Controller
### BEING WORKED ON INDEPENDENT BRANCHES TO NOT HAVE TO KEEP RPI FILES IN ARDUINO FOLDER AND ARDUINO FILES ON RPI

## Background
This will be a multi-step longer term ongoing project I will work on that will, most likely, grow and develop into something more complex as time goes on. 

Starting off this will be a more simple project, with a Raspberry Pi as the brain of this autonomous robot, controlling the actions of the robot.  
The Arduino will act as the controller of the system, the interface between the peripherals such as the ultrasonic sensor (initially and the motors).

This project will involve an Arduino Uno 3 (because that's what I have) and a Raspberry Pi 4, and perhaps swap to a Raspberry Pi Zero later (size).

This will, probably/hopefully, evolve into a more complex system, perhaps with an ESP32 w/ a camera  
as a source of sight for machine vision and WIFI communication to a Raspberry Pi base station? Not too sure yet.   
This will communicate with the Arduino still controlling the peripherals but being told where to go and when by the Raspberry Pi. 

Eventually, I want to evolve the project to include more machine vision, analyzing obstacles in the way, figuring out where to drive on its own.  
I also want to implement some sort of mapping system where it will, based on its movements and obstacles, to create a layout of its environment.  
I want to implement the machine vision along with machine learning later on to be able to autonomously navigate its environment. 

## Phase 1 
To start off, I will start slow and more learn to control the different peripherals and learn more about I2C  
(and maybe other ie. SPI) communication between the Arduino and Raspberry Pi.  
This is currently on hold until my Logic Level Converters arrive to safely communicate both ways. 

The peripherals I have in mind right now are:  
HC-SR04 Ultrasonic Sensor (as you do) x 3 (? tbd)
TT Motor DC Motor x 4
L298N Motor Drive Controller x2
LED (Because why not) x 4

When the logic level controller arrives, I will use ultrasonic sensor data from the Arduino, sent to the Raspberry Pi,  
to determine if the car should move forwards, or move back and rotate. I will have the Raspberry Pi also control LEDs 
to indicate the state of the robot. Green = Good / Move Forward. Red = Stop / Wall in front. Yellow = Adjusting. 

This will be the phase at which I will also try to keep the Raspberry Pi more busy with a slowly building (probably very inaccurate)  
map of the environment, and use that as a way of determining which way to move forward later. 

## Phase 2 
This phase will introduce cameras and machine vision, giving the Raspberry Pi more work.  
This may be using one of the official Rpi camera modules and/or may be an ESP32 w/ Camera module that I have.  
I may eventually take the Rpi off this, to become more battery efficient. (I haven't planned the mobile system details fully just yet).

The rest will probably come as I work on stuff and see how things do or do not work out. 
  
  
  
  
#### note to self, when installing OpenCV, use pip for learning versions 
#### not to self #2, when installing OpenCV with Pip, force a <4.3 to make it a reasonable time to install
