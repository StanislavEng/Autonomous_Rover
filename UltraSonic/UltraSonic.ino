int Trig = 8;
int Echo = 4;
int pingTravel;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Trig,LOW);
  delayMicroseconds(10);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  pingTravel = pulseIn(Echo,HIGH); 
  delay(25);
  Serial.println(pingTravel);
}
