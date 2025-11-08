const int buttonPin = 4;
const int ledPin = 3;
bool buttonState = 0;

void setup(){
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop(){
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH){
    digitalWrite(ledPin, LOW);
  }
  if(buttonState == LOW){
    digitalWrite(ledPin ,HIGH);
  }
}
