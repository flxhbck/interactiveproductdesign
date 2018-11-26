/*
    ┬┌─┐  ┌┬┐┌─┐┬  ┌─┐┌─┐┬ ┬┬  ┌─┐
    ││ │  ││││ ││  ├┤ │  │ ││  ├┤
    ┴└─┘  ┴ ┴└─┘┴─┘└─┘└─┘└─┘┴─┘└─┘

   This code is a starting point for projects with the IO Molecule 1.0 board.
   It defines which pins are used for which inputs.

*/

#include <Servo.h>
#include <Adafruit_NeoPixel.h>


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
#define PUSH1     0
#define PUSH2     1
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
}

void loop() {



}
