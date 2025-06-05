#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// pin definition for the Leonardo
// #define cs   7
// #define rst  1

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen
int duman;
int x;
int buton1;
int buton2;
int buton3;
int buton4;
int buton5;
int yon;
int onay = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
  TFTscreen.begin();
  // clear the screen with a black background
  TFTscreen.background(255, 255, 255);

  // write the static text to the screen
  // set the font color to white
  // set the font size
  // write the text to the top left corner of the screen
}

void loop() {
  // put your main code here, to run repeatedly:
  buton1 = digitalRead(2);
  buton2 = digitalRead(3);
  buton3 = digitalRead(4);
  buton4 = digitalRead(5);
  buton5 = digitalRead(6);
  if (buton1 == 1) {
    while (buton1 == 1) {
      buton1 = digitalRead(2);
    }
    yon++;
  }
  if (yon == 1 && onay == 0) {
        TFTscreen.setTextSize(2);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text("Bagimlilik", 0, 15);
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.line(0, 35, 500, 35);
    TFTscreen.line(0, 36, 500, 36);
    TFTscreen.text("Kalp Sagligi", 0, 45);
    TFTscreen.line(0, 67, 500, 67);
    TFTscreen.line(0, 68, 500, 68);
    TFTscreen.text("Hava Kalitesi", 0, 77),
                   TFTscreen.line(0, 99, 500, 99);
    TFTscreen.line(0, 100, 500, 100);
    TFTscreen.text("Ag Baglantisi", 0, 109);
    TFTscreen.line(0, 131, 500, 121);
    TFTscreen.line(0, 131, 500, 122);
  }
  if (yon == 2 && onay == 0) {

    TFTscreen.stroke(100, 100, 100);
    TFTscreen.text("Bagimlilik", 0, 15);
    TFTscreen.line(0, 35, 500, 35);
    TFTscreen.line(0, 36, 500, 36);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text("Kalp Sagligi", 0, 45);
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.line(0, 67, 500, 67);
    TFTscreen.line(0, 68, 500, 68);
    TFTscreen.text("Hava Kalitesi", 0, 77),
                   TFTscreen.line(0, 99, 500, 99);
    TFTscreen.line(0, 100, 500, 100);
    TFTscreen.text("Ag Baglantisi", 0, 109);
    TFTscreen.line(0, 131, 500, 121);
    TFTscreen.line(0, 131, 500, 122);
  }
  if (yon == 3 && onay == 0) {
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.text("Bagimlilik", 0, 15);
    TFTscreen.line(0, 35, 500, 35);
    TFTscreen.line(0, 36, 500, 36);
    TFTscreen.text("Kalp Sagligi", 0, 45);
    TFTscreen.line(0, 67, 500, 67);
    TFTscreen.line(0, 68, 500, 68);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text("Hava Kalitesi", 0, 77);
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.line(0, 99, 500, 99);
    TFTscreen.line(0, 100, 500, 100);
    TFTscreen.text("Ag Baglantisi", 0, 109);
    TFTscreen.line(0, 131, 500, 121);
    TFTscreen.line(0, 131, 500, 122);

  }
  if (yon == 4 && onay == 0) {
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.text("Bagimlilik", 0, 15);
    TFTscreen.line(0, 35, 500, 35);
    TFTscreen.line(0, 36, 500, 36);
    TFTscreen.text("Kalp Sagligi", 0, 45);
    TFTscreen.line(0, 67, 500, 67);
    TFTscreen.line(0, 68, 500, 68);
    TFTscreen.text("Hava Kalitesi", 0, 77),
                   TFTscreen.line(0, 99, 500, 99);
    TFTscreen.line(0, 100, 500, 100);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text("Ag Baglantisi", 0, 109);
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.line(0,  131, 500, 121);
    TFTscreen.line(0, 131, 500, 122);
  }
  if (yon == 5) {
    yon = 1;
  }
  duman = analogRead(A0);
  if (yon == 3 && onay == 1) {
    if (duman > 300 &&  duman <= 400) {
      while (duman > 300 &&  duman <= 400) {
        if (x == 1) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Kotu", 30, 40);
          TFTscreen.text("Normal", 30, 40);
          x = 0;
        }
        //TFTscreen.setTextSize(3);
        Serial.println(duman);
        TFTscreen.stroke(0, 255, 0);
        TFTscreen.text("Cok Iyı", 40, 50);
        TFTscreen.stroke(0, 255, 0);
        TFTscreen.line(7, 80, 57, 80);
        TFTscreen.line(7, 81, 57, 81);
        TFTscreen.line(7, 82, 57, 82);
        TFTscreen.line(7, 83, 57, 83);
        TFTscreen.line(7, 84, 57, 84);
        TFTscreen.line(7, 85, 57, 85);
        TFTscreen.line(7, 86, 57, 86);
        TFTscreen.stroke(0, 255, 255);
        TFTscreen.line(57, 80, 105, 80);
        TFTscreen.line(57, 81, 105, 81);
        TFTscreen.line(57, 82, 105, 82);
        TFTscreen.line(57, 83, 105, 83);
        TFTscreen.line(57, 84, 105, 84);
        TFTscreen.line(57, 85, 105, 85);
        TFTscreen.line(57, 86, 105, 86);
        TFTscreen.stroke(0, 0, 255);
        TFTscreen.line(105, 80, 153, 80);
        TFTscreen.line(105, 81, 153, 81);
        TFTscreen.line(105, 82, 153, 82);
        TFTscreen.line(105, 83, 153, 83);
        TFTscreen.line(105, 84, 153, 84);
        TFTscreen.line(105, 85, 153, 85);
        TFTscreen.line(105, 86, 153, 86);
        TFTscreen.setTextSize(2);
        TFTscreen.stroke(0, 0, 0);
        TFTscreen.text("Hava Kalitesi", 0, 5);
        TFTscreen.line(0, 27, 160, 27);
      }
      x = 1;
    }
    if (duman <= 300 && duman > 100) {
      while (duman <= 300 && duman > 100) {
        if (x == 1) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Cok Iyi", 30, 40);
          TFTscreen.text("Kotu", 30, 40);
          x = 0;
        }
        TFTscreen.setTextSize(3);
        TFTscreen.stroke(0, 255, 255);
        TFTscreen.text("Normal", 30, 40);
        TFTscreen.stroke(0, 255, 0);
        TFTscreen.line(7, 80, 57, 80);
        TFTscreen.line(7, 81, 57, 81);
        TFTscreen.line(7, 82, 57, 82);
        TFTscreen.line(7, 83, 57, 83);
        TFTscreen.line(7, 84, 57, 84);
        TFTscreen.line(7, 85, 57, 85);
        TFTscreen.line(7, 86, 57, 86);
        TFTscreen.stroke(0, 255, 255);
        TFTscreen.line(57, 80, 105, 80);
        TFTscreen.line(57, 81, 105, 81);
        TFTscreen.line(57, 82, 105, 82);
        TFTscreen.line(57, 83, 105, 83);
        TFTscreen.line(57, 84, 105, 84);
        TFTscreen.line(57, 85, 105, 85);
        TFTscreen.line(57, 86, 105, 86);
        TFTscreen.stroke(0, 0, 255);
        TFTscreen.line(105, 80, 153, 80);
        TFTscreen.line(105, 81, 153, 81);
        TFTscreen.line(105, 82, 153, 82);
        TFTscreen.line(105, 83, 153, 83);
        TFTscreen.line(105, 84, 153, 84);
        TFTscreen.line(105, 85, 153, 85);
        TFTscreen.line(105, 86, 153, 86);
        TFTscreen.setTextSize(2);
        TFTscreen.stroke(0, 0, 0);
        TFTscreen.text("Hava Kalitesi", 0, 5);
        TFTscreen.line(0, 27, 160, 27);
      }
      x = 1;
    }
    if (duman <= 100 && duman > 0) {
      while (duman <= 100 && duman > 0) {
        if (x == 1) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Cok Iyi", 30, 40);
          TFTscreen.text("Normal", 30, 40);
          x = 0;
        }
        TFTscreen.setTextSize(3);
        Serial.println(duman);
        TFTscreen.stroke(0, 0, 255);
        TFTscreen.text("Kotu", 30, 40);
        TFTscreen.stroke(0, 255, 0);
        TFTscreen.line(7, 80, 57, 80);
        TFTscreen.line(7, 81, 57, 81);
        TFTscreen.line(7, 82, 57, 82);
        TFTscreen.line(7, 83, 57, 83);
        TFTscreen.line(7, 84, 57, 84);
        TFTscreen.line(7, 85, 57, 85);
        TFTscreen.line(7, 86, 57, 86);
        TFTscreen.stroke(0, 255, 255);
        TFTscreen.line(57, 80, 105, 80);
        TFTscreen.line(57, 81, 105, 81);
        TFTscreen.line(57, 82, 105, 82);
        TFTscreen.line(57, 83, 105, 83);
        TFTscreen.line(57, 84, 105, 84);
        TFTscreen.line(57, 85, 105, 85);
        TFTscreen.line(57, 86, 105, 86);
        TFTscreen.stroke(0, 0, 255);
        TFTscreen.line(105, 80, 153, 80);
        TFTscreen.line(105, 81, 153, 81);
        TFTscreen.line(105, 82, 153, 82);
        TFTscreen.line(105, 83, 153, 83);
        TFTscreen.line(105, 84, 153, 84);
        TFTscreen.line(105, 85, 153, 85);
        TFTscreen.line(105, 86, 153, 86);
        TFTscreen.setTextSize(2);
        TFTscreen.stroke(0, 0, 0);
        TFTscreen.text("Hava Kalitesi", 0, 5);
        TFTscreen.line(0, 27, 160, 27);
      }
      x = 1;
    }
  }
}
