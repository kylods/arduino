#include <stdint.h>
#include <Arduino.h>

#include "WiFiS3.h"
#include "Arduino_LED_Matrix.h"
#include "arduino_secrets.h"
#include "animation.h"

ArduinoLEDMatrix matrix;

#define BUTTON_PIN 4

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  //load frames from the animation.h file
  matrix.loadSequence(animation);
  // start the matrix
  matrix.begin();
  
  // turn on autoscroll to avoid calling next() to show the next frame; the paramenter is in milliseconds
  // matrix.autoscroll(300);

  //play the animation on the matrix
  matrix.play(true);

  //define LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == 0){
    digitalWrite(LED_BUILTIN, 1);
  }
  else {
    digitalWrite(LED_BUILTIN, 0);
  }
}