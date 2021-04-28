#include <Stepper.h>

//int stepsPerRevolution=2048; // What? Is this right
//const int StepsPerRev = 64; // from 5.625deg/64 in datasheet | half step mode
const int StepsPerRev = 32; // this is full step modee apparently? 
const int gearRatio = 64; // from datasheet
const int stepsPerRevolution = StepsPerRev * gearRatio; // 2048
//int stepsPerRevolution = StepsPerRev * gearRatio; // cheeky and maybe not great way of defining but easy changing
int motDir = 1; // smarter way of doing it
int stepWbut = 1;

int motSpeed = 10; // RPM
int stepsRequired;
int dt = 10; // ms

int buttPin = 4;
bool buttPres = true;;
bool oldVal = true;

Stepper myStepper(stepsPerRevolution,8,10,9,11); // matching pairs IN1-IN3 and IN2-IN4 on datasheets
//Stepper myStepper(stepWbut,8,10,9,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);

  pinMode(buttPin, INPUT);
  digitalWrite(buttPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttPres = digitalRead(buttPin);
  Serial.println(buttPres);
  if (buttPres == 0 && oldVal == 1)
    motDir = -motDir;
  //Serial.println(motDir*stepsPerRevolution);
  //myStepper.step(motDir*stepsPerRevolution); // from the total number of steps ie 2048
  myStepper.step(motDir*stepWbut);
  oldVal = buttPres;
  //delay(dt);
  //myStepper.step(-stepsPerRevolution);
  //delay(dt);
}
