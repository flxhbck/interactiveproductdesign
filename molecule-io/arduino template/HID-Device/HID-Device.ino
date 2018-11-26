/*
    ┬┌─┐  ┌┬┐┌─┐┬  ┌─┐┌─┐┬ ┬┬  ┌─┐
    ││ │  ││││ ││  ├┤ │  │ ││  ├┤
    ┴└─┘  ┴ ┴└─┘┴─┘└─┘└─┘└─┘┴─┘└─┘

   This code is the starting point for a HID via USB project with the IO Molecule 1.0 board.
   It defines which pins are used for which inputs and implements basic functions of the HID-Project Library.

*/

#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include "HID-Project.h"



// connectors
#define DIGITAL   22
#define ANALOG-1  A2
#define ANALOG-2  A3
#define LED1      13
#define LED2      10
#define MOTOR     9
#define SERVO     6
#define NEOPIXELS 12

// on-board components
#define TONE      5
#define PUSH1     1
#define PUSH2     0
#define TURN1     A1
#define TURN2     A0



#define NUMPIXELS 16    // number of NEOPIXELS


Servo servo;
Adafruit_NeoPixel neopixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXELS, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO);
  neopixels.begin();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(MOTOR, OUTPUT);

  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop() {

  if (!digitalRead(PUSH1)) {
    digitalWrite(LED1, HIGH);

    // Use the default print functions
    //Keyboard.println("Hello World!");

    // Press a single character, special non ascii characters wont work.
    //Keyboard.write('a');

    // Write single keys, do not use a number here!
    //Keyboard.write(KEY_ENTER);


    // If you really wish to press a RAW keycode without the name use this:
    //Keyboard.write(KeyboardKeycode(40));

    // Use (a limited number of) consumer keys.
    // Only works with the lower 255 keys and on linux only.
    // Keyboard.write(MEDIA_PLAY_PAUSE);

    // Linux also supports several system function via consumer report.
    //Keyboard.write(CONSUMER_POWER);
    //Keyboard.write(CONSUMER_SLEEP);

    // You can also use some special keyboard keys on linux.
    //Keyboard.write(KEY_POWER);
    //Keyboard.write(KEY_F13);

    // You can wakeup you PC from sleep.
    // This might be not supported on all hardware, but on all OS types.
    //Keyboard.wakeupHost();

    // Simple debounce
    delay(300);
    digitalWrite(LED1, LOW);

    
  }

}

