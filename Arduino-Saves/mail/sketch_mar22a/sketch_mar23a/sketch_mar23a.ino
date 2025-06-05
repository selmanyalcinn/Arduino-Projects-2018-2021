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

int x = 341;
int a;
int onlar;
int yuzler;
int birler;
int abc;
char ebced[4];
int z;
char ebced2[4];
char ebced3[4];
String sz;
String szx;
int xy;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
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
  a = digitalRead(2);
  if (a == 1 ) {
    while (a == 1) {
      a = digitalRead(2);
    }
    abc++;
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(ebced, 0, 20);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(ebced, 0, 20);
  }
  String y = String(abc);
  y.toCharArray(ebced, 4);
  if (a == 0) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text(ebced, 0, 20);
  }
}
