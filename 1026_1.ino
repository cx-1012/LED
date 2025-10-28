const int RledPin=9;
const int GledPin=10;
const int BledPin=11;
const int buttonPin = 8;

int mood=0;
const int neutralMood=10;
unsigned long previousMillis=0;
int fadingDirection=1;
int buttonState=0;
bool ButtonPressed=false;
unsigned long touchedTimer=0;
unsigned long reducedTimer=0;
const long unTouchInterval=5000;
const long reducedInterval=1000;


void setup(){
  pinMode(RledPin,OUTPUT);
  pinMode(GledPin,OUTPUT);
  pinMode(BledPin,OUTPUT);
  pinMode(buttonPin,INPUT);

  mood=neutralMood;
}

void loop(){
  showLEDState(mood);

  buttonState=digitalRead(buttonPin);

  if(buttonState==HIGH && !ButtonPressed){
    mood=mood+1;
    if(mood>=20) mood=20;
    touchedTimer=millis();
    ButtonPressed=true;
  }
  if(buttonState==LOW && ButtonPressed){
    ButtonPressed=false;
  }

  unsigned long currentTimer=millis();
  if(currentTimer-touchedTimer>unTouchInterval){
    if(currentTimer-reducedTimer>reducedInterval){
      mood=mood-1;
      if(mood<0)mood=0;{
        reducedTimer=currentTimer;
      }
    }
  }
}

void showLEDState(int state){
  float brightnessInterval=255/10.0;
  if(state>=neutralMood){
    analogWrite(RledPin,255);
    analogWrite(GledPin,brightnessInterval*(mood-neutralMood));
    analogWrite(BledPin,255-brightnessInterval*(mood-neutralMood));
  }
  else{
    analogWrite(GledPin,255-brightnessInterval*(mood-neutralMood));
    analogWrite(RledPin,brightnessInterval*(mood-neutralMood));
    analogWrite(BledPin,255);
  }
}