const int rLEDPin=3;
const int bLEDPin=4;
const int gLEDPin=5;
int brightness=0;
int fadeAmount=5;
int ledcolor=0;

void setup() {
  pinMode(rLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
}
void loop() {
  if(ledcolor==0){
    digitalWrite(rLEDPin,brightness);
    digitalWrite(bLEDPin,255);
    digitalWrite(gLEDPin,255);
  }
  if(ledcolor==1){
    digitalWrite(rLEDPin,255);
    digitalWrite(bLEDPin,brightness);
    digitalWrite(gLEDPin,255);
  }
  if(ledcolor==2){
    digitalWrite(rLEDPin,255);
    digitalWrite(bLEDPin,255);
    digitalWrite(gLEDPin,brightness);
  }
  brightness=brightness+fadeAmount;
  if(brightness<=0||brightness>=255){
    fadeAmount=-fadeAmount;
    if(brightness>=255){
      ledcolor=ledcolor+1;
      if(ledcolor>2)
      ledcolor=0;
    }
  }
  delay(30);
}
  