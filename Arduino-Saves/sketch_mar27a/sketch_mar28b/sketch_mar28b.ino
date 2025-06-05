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

void setup() {
    TFTscreen.begin();
    TFTscreen.background(255, 255, 255);
    TFTscreen.setTextSize(2);
}

void loop() {
  TFTscreen.stroke(0,0,0);
  TFTscreen.text("Icilen Sigara Grafigi",0,0);
  TFTscreen.line(5,0,5,120);
  TFTscreen.line(5,125,150,125);
}
