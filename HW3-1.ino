#define BUTTON_PIN 2
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6

int mode = 0;
bool lastButtonState = HIGH;
unsigned long lastDebounce = 0;

int colorIndex = 0;
int brightness = 0;
int fadeDirection = 1;
unsigned long lastUpdate = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  allOff();
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);

  if (reading == LOW && lastButtonState == HIGH && millis() - lastDebounce > 200) {
    lastDebounce = millis();
    mode++;
    if (mode > 3) mode = 0;
  }
  lastButtonState = reading;

  switch (mode) {
    case 0:
      allOff();
      break;
    case 1:
      rainbowBreath(20); 
      break;
    case 2:
      rainbowBreath(5); 
      break;
    case 3:
      setColor(255, 255, 255); 
      break;
  }
}

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, 255 - r);
  analogWrite(GREEN_PIN, 255 - g);
  analogWrite(BLUE_PIN, 255 - b);
}

void allOff() {
  setColor(0, 0, 0);
}

void rainbowBreath(int stepDelay) {
  unsigned long now = millis();
  if (now - lastUpdate < stepDelay) return;
  lastUpdate = now;

  int colors[7][3] = {
    {255,   0,   0}, 
    {255, 255,   0}, 
    {  0, 255,   0}, 
    {  0, 255, 255}, 
    {  0,   0, 255}, 
    {255,   0, 255}, 
    {255, 255, 255}  
  };

  brightness += fadeDirection * 5;
  if (brightness >= 255) {
    brightness = 255;
    fadeDirection = -1;
  } else if (brightness <= 0) {
    brightness = 0;
    fadeDirection = 1;
    colorIndex++;
    if (colorIndex >= 7) colorIndex = 0; 
  }

  int r = (colors[colorIndex][0] * brightness) / 255;
  int g = (colors[colorIndex][1] * brightness) / 255;
  int b = (colors[colorIndex][2] * brightness) / 255;
  setColor(r, g, b);
}
