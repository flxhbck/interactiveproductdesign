/*
    ┬┌─┐  ┌┬┐┌─┐┬  ┌─┐┌─┐┬ ┬┬  ┌─┐
    ││ │  ││││ ││  ├┤ │  │ ││  ├┤
    ┴└─┘  ┴ ┴└─┘┴─┘└─┘└─┘└─┘┴─┘└─┘

   This code is a starting point for projects with the IO Molecule 1.0 board.
   It defines which pins are used for which inputs.
   Serial Call and Response
   Language: Wiring/Arduino

   This program sends an ASCII A (byte of value 65) on startup and repeats that
   until it gets some data in. Then it waits for a byte in the serial port, and
   sends three sensor values whenever it gets a byte in.

   The circuit:
   - potentiometers attached to analog inputs 0 and 1
   - pushbutton attached to digital I/O 2

  http://www.arduino.cc/en/Tutorial/SerialCallResponse

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
#define PUSH1     1
#define PUSH2     0
#define TURN1     A1
#define TURN2     A0



#define NUMPIXELS 16    // number of NEOPIXELS


Servo servo;
Adafruit_NeoPixel neopixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXELS, NEO_GRB + NEO_KHZ800);



int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0;    // digital sensor
int inByte = 0;         // incoming serial byte

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  servo.attach(SERVO);
  neopixels.begin();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(MOTOR, OUTPUT);

  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);

  establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();

    // send your data

    // read first analog input, divide by 4 to make the range 0-255:
    firstSensor = analogRead(A0) / 4;
    // delay 10ms to let the ADC recover:
    delay(10);
    // read second analog input, divide by 4 to make the range 0-255:
    secondSensor = analogRead(A1) / 4;
    // read switch, map it to 0 or 255L
    thirdSensor = map(digitalRead(0), 0, 1, 100, 20);

    // send sensor values:
    Serial.write(firstSensor);
    Serial.write(secondSensor);
    Serial.write(thirdSensor);




    // do the stuff that is supposed to happen on the Arduino based on what letter is sent.
    if (inByte == 'A') {
      digitalWrite(MOTOR, HIGH);
      digitalWrite(LED1, HIGH);

    } else if (inByte == 'B') {
      digitalWrite(MOTOR, LOW);
      digitalWrite(LED1, LOW);
    }


  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}
