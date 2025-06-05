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
int yon = 1;
int onay = 1;
int abc;
int bca;
int buton1;
int buton2;
int buton3;
int buton4;
int buton5;
char ebced[4];
char ebced2[4];
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);
  TFTscreen.setTextSize(2);
}

void loop() {
  String y = String(abc);
  y.toCharArray(ebced, 4);
  buton1 = digitalRead(2);
  buton2 = digitalRead(3);
  if (buton1 == 1) {
    while (buton1 == 1) {
      buton1 = digitalRead(2);
    }
    abc++;
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(ebced, 0, 20);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(ebced, 0, 20);
  }
  if (buton2 == 1) {
    while (buton2 == 1) {
      buton2 = digitalRead(3);
    }
    abc--;
    bca=abc;
    String y = String(abc);
  y.toCharArray(ebced, 4);
  String z=String(bca);
  z.toCharArray(ebced2,4);
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(ebced, 0, 20);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(ebced2, 0, 20);
  }
  if (buton1 == 0 ) {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text("GunlukIcılen", 0, 0);
    TFTscreen.text(ebced, 0, 20);

  }
}

