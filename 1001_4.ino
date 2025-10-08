const int pushButton=2;
const int rLEDPin=3;
const int bLEDPin=4;
const int gLEDPin=5;

int buttonState=0;
int ledcolor=0;
bool ButtonPressed= false;
unsigned long previousMills=0;
String currentcolor="led";
const long interval=1000;
bool ledColorOrder=true;

void setup() {
  pinMode(rLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(pushButton, INPUT);
}
void loop() {
  buttonState=digitalRead(pushButton);
  Serial.print("currentcolor: ");
  Serial.println(buttonState);
  if(buttonState == HIGH && !ButtonPressed) {
  ledColorOrder = !ledColorOrder;
  ButtonPressed = true;
  } 
  if(buttonState == LOW && ButtonPressed){
  ButtonPressed = false;
  }
  unsigned long currentMills=millis();
  if(currentMills-previousMills>=interval){
    previousMills=currentMills;
    if(ledColorOrder==true){
       ledcolor = ledcolor + 1;
       if(ledcolor>3)
        ledcolor=0;
    }
    else{
      ledcolor=ledcolor-1;
      if(ledcolor<0)
      ledcolor=3;
    }
  }
if(ledcolor==0){
    digitalWrite(rLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==1){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
}else if(ledcolor==2){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
}else if(ledcolor==3){
  digitalWrite(rLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(gLEDPin, LOW);
}
}
  
