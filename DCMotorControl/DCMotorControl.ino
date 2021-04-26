#define pinEN 5
#define inPos 4
#define inNeg 3
/*
int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int pinEN = 5;
int inPos = 4;
int inNeg = 3;*/

int mSpeed = 100; // motor speed, PWM range of 0-255
String pic;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinEN, OUTPUT);
  pinMode(inPos,OUTPUT);
  pinMode(inNeg,OUTPUT);

  //pinMode(speedPin, OUTPUT);
  //pinMode(dir1,OUTPUT);
  //pinMode(dir2,OUTPUT);
  while(!Serial){}
}

void loop() {
  // put your main code here, to run repeatedly:
  /////////// forward generic forward
  digitalWrite(inPos,LOW);
  digitalWrite(inNeg,HIGH);
  //digitalWrite(dir1,HIGH);
  //digitalWrite(dir2,LOW);
  Serial.println("ON or OFF?");
  while (Serial.available()==0){
  }
  pic = Serial.readString();
  Serial.println(pic);
  if (pic == "ON"){
    mSpeed = 255;
    Serial.println("Should work");
  }
  else if (pic == "OFF")
    mSpeed =   0; 
  Serial.println(mSpeed);
  //analogWrite(pinEN,mSpeed);
  analogWrite(pinEN,mSpeed);
}
