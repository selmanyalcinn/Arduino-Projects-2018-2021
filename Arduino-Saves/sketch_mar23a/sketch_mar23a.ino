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
char ebced[4];
int buton1;
int buton2;
int buton3;
int buton4;
int buton5;
int yon = 1;
int onay=1;
int abc;
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
  buton1 = digitalRead(2);
  buton2 = digitalRead(3);
  buton3 = digitalRead(4);
  buton4 = digitalRead(5);
  buton5 = digitalRead(6);
  String y = String(abc);
  y.toCharArray(ebced, 4);
  if (yon == 1 && onay == 1) { 
  if (buton4 == 1 ) {
    while (buton4 == 1) {
      buton4 = digitalRead(5);
    }
    abc++;
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(ebced, 0, 20);
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(ebced, 0, 20);
  }
  if (buton5 == 1) {
    while (buton5 == 1) {
      buton5 = digitalRead(6);
    }
    abc--;
    if(abc<0){
      abc++;
    }
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(ebced, 0, 20);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(ebced, 10, 20);
  }
  }
  if (buton1 == 1) {
    TFTscreen.stroke(255,255, 255);
    TFTscreen.text("Gunluk Icilen",0,0);
    TFTscreen.text(ebced, 0, 20);
    TFTscreen.text("Azaltilacagi",0,40);
    TFTscreen.text("Gun",0,55);
    
  }
   if (buton1 == 0) {
    TFTscreen.stroke(0,0,0);
    TFTscreen.text("Gunluk Icilen",0,0);
    TFTscreen.text(ebced, 0, 20);
    TFTscreen.text("Azaltilacagi",0,40);
    TFTscreen.text("Gun",0,55);
    
  }
  }
