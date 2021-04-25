/*  Start of code for Arduino side of Version 1 of Autonomous Rover
 *  This is the slave device in the system and will be set up as so
 *  Will connect Arduino to ultrasonic sensors, and DC motors via motor controller
 *  
 *  Start Date: April 24, 2021
 *  Written by: Stanislav Svichkar
 *  Last Modified: 
 */
byte slaveAddress = 0x08; // this is the address of the slave device in I2C line
byte LED = 12; // Will use to check incoming data on breadboard (as opposed to on Arduino via pin13)

void setup(){
  Wire.begin(slaveAddress); 
  // Wire.begin(); // This indicates that the device is the master, not the slave
  Serial.begin(9600);

  Wire.onReceive(receiveEvent);
  
}

void loop(){
  
}

void receiveEvent(int howMany){
  
}
