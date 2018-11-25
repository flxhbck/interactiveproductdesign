/*
  Play/Pause music with Arduino as Keyboard

  ****************************************************************
  Make sure to download the HID-Project Library before using this!
  ****************************************************************
  
  Circuit:
  - Arduino Leonardo or Micro
  - make a circuit that connects D2 to ground

  See HID Project documentation for more Consumer keys.
  https://github.com/NicoHood/HID/wiki/Consumer-API
  
  See HID Project documentation for more information.
  https://github.com/NicoHood/HID/wiki/Keyboard-API#improved-keyboard

  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.
*/

#include "HID-Project.h"

const int pinLed = LED_BUILTIN;
const int pinButton = 2;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);

  Consumer.begin(); // you need this for the HID library to work.
}

void loop() {
  if (!digitalRead(pinButton)) {
    digitalWrite(pinLed, HIGH);

    Consumer.write(MEDIA_PLAY_PAUSE); // send the key-command for play/pause
    // See HID Project documentation for more Consumer keys
    
    delay(300); // Simple debounce, makes sure there are no "double presses"
    digitalWrite(pinLed, LOW);
  }
}
