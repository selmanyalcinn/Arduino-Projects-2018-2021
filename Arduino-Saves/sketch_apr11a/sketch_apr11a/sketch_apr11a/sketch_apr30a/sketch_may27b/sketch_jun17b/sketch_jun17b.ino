#include <TFT.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define cs   10
#define dc   9
#define rst  8

TFT TFTscreen = TFT(cs, dc, rst);
void setup() {
  // put your setup code here, to run once:
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);
  TFTscreen.setTextSize(40);
}

void loop() {
  // put your main code here, to run repeatedly:
 TFTscreen.stroke(0,0,0);
 TFTscreen.text("MMMMMM",0,0);
 TFTscreen.text("MMMMMM",70,0);
 TFTscreen.text("MMMMMM",60,0);
 TFTscreen.text("MMMMMM",110,0);
 TFTscreen.text("MMMMMM",40,0);
 TFTscreen.text("MMMMMM",150,0);
}
