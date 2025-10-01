const int pushButton=2;
const int rLEDPin=3;
const int bLEDPin=4;
const int gLEDPin=5;

int buttonState=0;
int ledcolor=0;
bool ButtonPressed= false;
String currentcolor="led";
void setup() {
  pinMode(rLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(pushButton, INPUT);
  Serial.begin(9600);
}
void loop() {
  buttonState=digitalRead(pushButton);
  Serial.print("currentcolor: ");
  Serial.println(currentcolor);
  if(buttonState == HIGH && !ButtonPressed) {
  ledcolor = ledcolor + 1;
  ButtonPressed = true;
  } 
  if(buttonState == LOW && ButtonPressed){
  ButtonPressed = false;
  }
  if(ledcolor==0){
    currentcolor="led off";
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==1){
  currentcolor="red";
    digitalWrite(rLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==2){
  currentcolor="blue";
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==3){
  currentcolor="green";
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
}else if(ledcolor==4){
  currentcolor="purple";
  digitalWrite(rLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==5){
  currentcolor="yellow";
  digitalWrite(rLEDPin, LOW);
  digitalWrite(bLEDPin, HIGH);
  digitalWrite(gLEDPin, LOW);
}else if(ledcolor==6){
  currentcolor="cyan";
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(gLEDPin, LOW);
}else if(ledcolor==7){
  currentcolor="white";
  digitalWrite(rLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(gLEDPin, LOW);
}else if(ledcolor==8){
  ledcolor=0;
}
}
  