#include <Arduino.h>

// @author PoofyPloop

// LED states
int LEDState = HIGH;
int CurrentState;
int PreviousState;


void setup() {
  // initializing button and led
  pinMode(D5, INPUT_PULLUP);
  pinMode(D4, OUTPUT);

  // setting analog max range
  analogWriteRange(1023);

  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop() {
  digitalWrite(D4, CurrentState);

  // Setting state value
  PreviousState = CurrentState;
  CurrentState = digitalRead(D5);

  // button toggle condition
  if(PreviousState == HIGH && CurrentState == LOW) {
    LEDState = !LEDState;
    digitalWrite(D4, LEDState);
  }

  // led brightness control
  if (LEDState == LOW) {
    int iVal = analogRead(A0);
    analogWrite(D4, iVal);
  }
  
}
