byte pbread = 12;
byte LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pbread,OUTPUT);
  digitalWrite(pbread,HIGH);
  Serial.begin(9600);
}

String myinput;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("High or Low?");
  while(Serial.available()>0){
  }
  myinput = Serial.read();
  if (myinput == "high")
    digitalWrite(pbread,HIGH);
  else
    digitalWrite(pbread,LOW);
    
}
