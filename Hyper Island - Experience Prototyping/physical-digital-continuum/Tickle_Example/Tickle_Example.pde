/**
 * Tickle - SerialCallResponse
 * 
 * The word "tickle" jitters when the cursor hovers over.
 * Sometimes, it can be tickled off the screen.
 */

import processing.serial.*;


String message = "tickle";
float x, y; // X and Y coordinates of text
float hr, vr;  // horizontal and vertical radius of the text
int xpos, ypos;                // Starting position of the ball
boolean tickling = false;


Serial myPort;                       // The serial port
int[] serialInArray = new int[3];    // Where we'll put what we receive
int serialCount = 0;                 // A count of how many bytes we receive
boolean firstContact = false;        // Whether we've heard from the microcontroller


void setup() {
  size(510, 510);

  // Create the font
  textFont(createFont("SourceCodePro-Regular.ttf", 36));
  textAlign(CENTER, CENTER);

  hr = textWidth(message) / 2;
  vr = (textAscent() + textDescent()) / 2;
  noStroke();
  x = width / 2;
  y = height / 2;

  println(Serial.list());
  int portLength = Serial.list().length;
  String portName = Serial.list()[portLength-1];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  // Instead of clearing the background, fade it by drawing
  // a semi-transparent rectangle on top
  fill(204, 120);
  rect(0, 0, width, height);
  
  fill(0);
  ellipse(xpos, ypos, 5, 5);


  // If the cursor is over the text, change the position
  if (abs(mouseX - x) < hr &&
    abs(mouseY - y) < vr) {
    x += random(-5, 5);
    y += random(-5, 5);
    tickling = true;
  } else {
    tickling = false;
  }
  fill(0);
  text("tickle", x, y);
}


void serialEvent(Serial myPort) {
  // read a byte from the serial port:
  int inByte = myPort.read();
  // if this is the first byte received, and it's an A, clear the serial
  // buffer and note that you've had first contact from the microcontroller.
  // Otherwise, add the incoming byte to the array:
  if (firstContact == false) {
    if (inByte == 'A') {
      myPort.clear();          // clear the serial port buffer
      firstContact = true;     // you've had first contact from the microcontroller
      myPort.write('A');       // ask for more
    }
  } else {
    // Add the latest byte from the serial port to array:
    serialInArray[serialCount] = inByte;
    serialCount++;

    // If we have 3 bytes:
    if (serialCount > 2 ) {
      xpos = serialInArray[0]*2;
      ypos = serialInArray[1]*2;

      // print the values (for debugging purposes only):
      println(xpos + "\t" + ypos);

      // Send a capital A to request new sensor readings:
      if (tickling == true) {
        myPort.write('A');
      } else {
        myPort.write('B');
      }
      // Reset serialCount:
      serialCount = 0;
    }
  }
}
