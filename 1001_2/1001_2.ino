const int pushButton=2;
const int rLEDPin=3;
const int bLEDPin=4;
const int gLEDPin=5;

int buttonState=0;
int ledcolor=0;
bool ButtonPressed= false;
void setup() {
  pinMode(rLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(pushButton, INPUT);
}
void loop() {
  buttonState=digitalRead(pushButton);
  if(buttonState == HIGH && !ButtonPressed) {
  ledcolor = ledcolor + 1;
  ButtonPressed = true;
  } 
  if(buttonState == LOW && ButtonPressed){
  ButtonPressed = false;
  }
  if(ledcolor==0){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==1){
    digitalWrite(rLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==2){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==3){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
}else if(ledcolor==4){
  digitalWrite(rLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==5){
  digitalWrite(rLEDPin, LOW);
  digitalWrite(bLEDPin, HIGH);
  digitalWrite(gLEDPin, LOW);
}else if(ledcolor==6){
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(gLEDPin, LOW);
}else if(ledcolor==7){
  digitalWrite(rLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(gLEDPin, LOW);
}else if(ledcolor==8){
  ledcolor=0;
}
}
  