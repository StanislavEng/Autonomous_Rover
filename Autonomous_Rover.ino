/*  Start of code for Arduino side of Version 1 of Autonomous Rover
 *  This is the slave device in the system and will be set up as so
 *  Will connect Arduino to ultrasonic sensors, and DC motors via motor controller
 *  
 *  Start Date: April 24, 2021
 *  Written by: Stanislav Svichkar
 *  Last Modified: 
 */

// general setup
const byte slaveAddress = 0x08; // this is the address of the slave device in I2C line
//byte LED = 12; // Will use to check incoming data on breadboard (as opposed to on Arduino via pin13)
const byte readPin = 13; // Checks incoming data, either on Arduino alone or also hooked up on LED

// masking setup
//byte bitUlSo = 64; // checks if ultrasonic command 
const byte maskM2 = 32; // checks if motor 2 is activated (turn right if alone)
const byte maskM1 = 16; // checks if motor 1 is activated (turn  left if alone)
const byte maskRev = 8; // checks direction of movement   (1 for reverse, 0 for forward)
const byte maskMot = 4; // checks if moving               (1 to turn motor on);
const byte maskHS  = 2; // checks if half speed           (1 halves motor speed, 0 doesn't)
const byte maskLED = 1; // transmit LED on                (1 for LED on, 0 for LED off)

// Ultrasonic setup
const byte TRIG = 6; // Trig pin for ultrasonic  
const byte ECHO = 7; // Echo pin for ultrasonic

// MOTOR DRIVER 1 (LEFT)
/*#define enM1 5     // enable pin with PWM
#define M1dir1 4   // IN+
#define M1dir2 3   // IN-*/
const byte enM1 = 5;
const byte dir1M1 = 4;
const byte dir1M2 = 3; 
byte m1Speed = 0;   // speed of left motors 

// MOTOR DRIVER 2 (RIGHT)
/*#define enM2 10    // enable pin with PWM
#define M2dir1 9   // IN+
#define M2dir2 8   // IN-*/
const byte enM2 = 10;
const byte dir1M2 = 9;
const byte dir2M2 = 8;
int m2Speed = 0;   // speed of right motors

const byte setPin = [dir2M1, dir1M1, enM1, dir2M2, dir1M2, enM2];

void setup(){
  Wire.begin(slaveAddress); // turns on wire as a slave
  // Wire.begin(); // This indicates that the device is the master, not the slave
  Serial.begin(9600);

  for (int i = 0; i < sizeof(setPin)/sizeof(setPin[0]);i++){
    pinMode(setPin[i],OUTPUT); 
  }
  
  Wire.onReceive(receiveEvent);

  while (!Serial()){}
  
}

void loop(){
  // for now (and probably forever) it just exists , will have to learn interrupts later
  delay(100);
}

void receiveEvent(int howMany){
  while (Wire.available()){
    byte I2C = Wire.read(); // maximum usable 7 bits
    byte LED = I2C & maskLED;
    if (LED = 1
  }
}
