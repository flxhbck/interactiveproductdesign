/*
  Arduino as Keyboard example

  ****************************************************************
  Make sure to download the HID-Project Library before using this!
  ****************************************************************

  Circuit:
  - Arduino Leonardo or Micro
  - make a circuit that connects D2 to ground

  See HID Project documentation for more information.
  https://github.com/NicoHood/HID/wiki/Keyboard-API#improved-keyboard

  The Library mostly improves on the standard keyboard example. Use the arduino reference to check the keyboard controls.
  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/

  Special Key-Codes are here:
  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/

  Use the Media-Keys Example for Media Keys like Play/Pause

  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.
*/

#include "HID-Project.h"

const int pinLed = LED_BUILTIN;
const int pinButton = 2;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);

  // Sends a clean report to the host. This is important on any Arduino type.
  Keyboard.begin();
}


void loop() {
  // Trigger caps lock manually via button
  if (!digitalRead(pinButton)) {
    digitalWrite(pinLed, HIGH);

    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('3');

    delay(100);

    Keyboard.releaseAll();

    
    // Press a single character, special non ascii characters wont work.
    //Keyboard.write('a');

    // Write single keys, do not use a number here!
    //Keyboard.write(KEY_ENTER);

    // You can wakeup you PC from sleep.
    // This might be not supported on all hardware, but on all OS types.
    //Keyboard.wakeupHost();

    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
}
