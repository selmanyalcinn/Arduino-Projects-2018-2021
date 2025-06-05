#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
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

  // clear the screen with a black background
  TFTscreen.background(255, 255, 255);

  // write the static text to the screen
  // set the font color to white TFTscreen.stroke(129, 129, 129);
  TFTscreen.setTextSize(2);

}

void loop() {
  // put your main code here, to run repeatedly:
TFTscreen.text("İcilen Sigara Grafigi",0,120);
TFTscreen.stroke(0,0,0);
TFTscreen.text("Gun",7,0);
TFTscreen.line(30,0,30,9);
TFTscreen.text("Hafta",35,0);
TFTscreen.text("Ay",60,0);
TFTscreen.text("Yıl",140,0);
 TFTscreen.line(5,0,5,115);
 TFTscreen.line(5,10,500,10);
 TFTscreen.text("",0,110);
}
