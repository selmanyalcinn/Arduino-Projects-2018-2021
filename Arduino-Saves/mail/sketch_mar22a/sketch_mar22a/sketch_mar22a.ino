/*
  Arduino TFT text example

  This example demonstrates how to draw text on the
  TFT with an Arduino. The Arduino reads the value
  of an analog sensor attached to pin A0, and writes
  the value to the LCD screen, updating every
  quarter second.

  This example code is in the public domain

  Created 15 April 2013 by Scott Fitzgerald

  http://arduino.cc/en/Tutorial/TFTDisplayText

*/

#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// pin definition for the Leonardo
// #define cs   7
// #define dc   0
// #define rst  1

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen
char ebced2[4];
int a;
int b;
int abc;
int x;
int sz;
unsigned long sure = 100000000;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(255, 255, 255);
  // set the font size
  TFTscreen.setTextSize(2);
  // write the text to the top left corner of the screen
  TFTscreen.text("Sensor Value :\n ", 0, 0);
  // ste the font size very large for the loop
  TFTscreen.setTextSize(2);
}

void loop() {

  // Read the value of the sensor on A0
  String ebced = String(abc);
  a = digitalRead(2);
  b = digitalRead(4);
  if (a == 1) {
    abc++;
  }
  if (b == 1) {

    abc--;
    Serial.println("eksildi");
  }
  if (a==0 && b==0) {
    Serial.println("Stabil");
    delay(500);
    // convert the reading to a char array
    ebced.toCharArray(ebced2, 4);

    // set the font color
    TFTscreen.stroke(255, 255, 255);
    // print the sensor value
    TFTscreen.text(ebced2, 0, 20);
  }

  if (a != 0 || b != 0) {
    Serial.println("Dongu2d");
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(ebced2, 0, 20);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(ebced2, 0, 20);

  }
}
