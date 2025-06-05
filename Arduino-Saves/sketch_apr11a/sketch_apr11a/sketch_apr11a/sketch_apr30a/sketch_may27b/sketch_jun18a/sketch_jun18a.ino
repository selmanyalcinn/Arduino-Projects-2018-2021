#include <TFT.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define cs   10
#define dc   9
#define rst  8

TFT TFTscreen = TFT(cs, dc, rst);
int sag = 0;
char ebced[4];
char ebced2[4];
char ebced3[4];
char ebcedsigara[4];
char ebcedazalacakgun[4];
char ebcedyazi[12];
int bca;
int buton;
int buton2;
int buton3;
int buton4;
int buton5;
int yon = 1;
int yon2;
int onay;
int abc;
int abc2;
int sigara = 0;
int azalacakgun;
int azalacakgun2;
int f;
String yazi = "Ag Adi Giriniz";
char anebced[11];
char anebced2[11];
String an;
String an2;
int anan;
int duman;
int x;
String str;
String z;
const int sensor = A1;
int periyot = 20;
double alfa = 0.75;
double yenileme = 0.0;
const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;
int nabiz;
int inputPin = A0;
unsigned long t1;
int duzeneuyulamayangun;
unsigned long interval = 86400000;
unsigned long previousMillis = 0;
unsigned long interval2 = 420000;
unsigned long previousMillis2 = 0;
String ebcednabiz1;
char ebcednabiz[3];
String ebcedortalama;
char ebcedortalama1[3];
void setup() {
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);
  TFTscreen.setTextSize(2);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long currentMillis2 = millis();
  String y = String(abc);
  y.toCharArray(ebced, 4);
  String sz = String(azalacakgun);
  sz.toCharArray(ebced3, 4);
  String zeynep = String(sigara);
  yazi.toCharArray(ebcedyazi, 4);
  zeynep.toCharArray(ebcedsigara, 4);
  an.toCharArray(anebced, 11);
  buton = digitalRead(2);
  buton2 = digitalRead(3);
  buton3=digitalRead(4);
  duman=analogRead(A0);
  if (buton == 1) {
    while (buton == 1) {
      buton = digitalRead(2);
    }
    if(onay==0){
    yon++;
    }
    if(onay==1){
      yon2++;
    }
    if (yon2 == 2) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text("<  Bagimlilik", 0, 0);
      TFTscreen.line(0, 25, 200, 25);
      TFTscreen.line(0, 26, 200, 26);
      TFTscreen.text("Bugun Icilen:", 0, 35);
      TFTscreen.text(ebcedsigara, 0, 55);
      TFTscreen.text("Gunluk Icilen ", 0, 80);
      TFTscreen.text("12", 0, 100);
    }
    if (yon2 == 3) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text("Bugun Icilen", 0, 5);
      TFTscreen.text(ebcedsigara, 0, 25);
      TFTscreen.text("Gunluk Icilen", 0, 43);
      TFTscreen.text(ebced2, 0, 63);
      TFTscreen.text("Azaltilacagi", 0, 80);
      TFTscreen.text("Gun", 0, 95);
      TFTscreen.text(ebcedazalacakgun, 0, 112);
      yon2 = 0;
    }
  }
  if (buton2 == 1) {
    while (buton2 == 1) {
      buton2 = digitalRead(3);
    }
    onay++;
    if (yon == 1) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.setTextSize(3);
      TFTscreen.text("Menu", 2, 5);
      TFTscreen.setTextSize(2);
      TFTscreen.text("Kalp Sagligi", 2, 62);
      TFTscreen.text("Bagimlilik", 2, 35);
      TFTscreen.text("Hava Kalitesi", 2, 89);
    }
    if (yon == 3) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.setTextSize(3);
      TFTscreen.text("Menu", 2, 5);
      TFTscreen.setTextSize(2);
      TFTscreen.text("Kalp Sagligi", 2, 62);
      TFTscreen.text("Bagimlilik", 2, 35);
      TFTscreen.text("Hava Kalitesi", 2, 89);
    }
    if (yon == 2) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.setTextSize(3);
      TFTscreen.text("Menu", 2, 5);
      TFTscreen.setTextSize(2);
      TFTscreen.text("Kalp Sagligi", 2, 62);
      TFTscreen.text("Bagimlilik", 2, 35);
      TFTscreen.text("Hava Kalitesi", 2, 89);
    }
    if (onay == 2) {
      yon2 = 0;
      if (yon2 == 0 ) {
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text("<  Bagimlilik", 0, 0);
        TFTscreen.line(0, 25, 200, 25);
        TFTscreen.line(0, 26, 200, 26);
        TFTscreen.text("Bugun Icilen:", 0, 35);
        TFTscreen.text(ebcedsigara, 0, 55);
        TFTscreen.text("Gunluk Icilen ", 0, 80);
        TFTscreen.text(ebced2, 0, 100);
        TFTscreen.text("Bugun Icilen", 0, 5);
        TFTscreen.text(ebcedsigara, 0, 25);
        TFTscreen.text("Gunluk Icilen", 0, 43);
        TFTscreen.text(ebced2, 0, 63);
        TFTscreen.text("Azaltilacagi", 0, 80);
        TFTscreen.text("Gun", 0, 95);
        TFTscreen.text(ebcedazalacakgun, 0, 112);
        TFTscreen.text("Hava Kalitesi", 0, 5);
        TFTscreen.line(127, 76, 127, 90);
        TFTscreen.line(128, 76, 128, 90);
        TFTscreen.line(129, 76, 129, 90);
        TFTscreen.line(130, 76, 130, 90);
        TFTscreen.line(131, 76, 131, 90);
        TFTscreen.line(81, 76, 81, 90);
        TFTscreen.line(82, 76, 82, 90);
        TFTscreen.line(83, 76, 83, 90);
        TFTscreen.line(84, 76, 84, 90);
        TFTscreen.line(30, 76, 30, 90);
        TFTscreen.line(31, 76, 31, 90);
        TFTscreen.line(32, 76, 32, 90);
        TFTscreen.line(33, 76, 33, 90);
        TFTscreen.line(57, 80, 105, 80);
        TFTscreen.line(57, 81, 105, 81);
        TFTscreen.line(57, 82, 105, 82);
        TFTscreen.line(57, 83, 105, 83);
        TFTscreen.line(57, 84, 105, 84);
        TFTscreen.line(57, 85, 105, 85);
        TFTscreen.line(57, 86, 105, 86);
        TFTscreen.line(105, 80, 153, 80);
        TFTscreen.line(105, 81, 153, 81);
        TFTscreen.line(105, 82, 153, 82);
        TFTscreen.line(105, 83, 153, 83);
        TFTscreen.line(105, 84, 153, 84);
        TFTscreen.line(105, 85, 153, 85);
        TFTscreen.line(105, 86, 153, 86);
        TFTscreen.line(7, 80, 57, 80);
        TFTscreen.line(7, 81, 57, 81);
        TFTscreen.line(7, 82, 57, 82);
        TFTscreen.line(7, 83, 57, 83);
        TFTscreen.line(7, 84, 57, 84);
        TFTscreen.line(7, 85, 57, 85);
        TFTscreen.line(7, 86, 57, 86);
        TFTscreen.setTextSize(3);
        TFTscreen.text("Normal", 30, 40);
        TFTscreen.text("Cok Iyi", 30, 40);
        TFTscreen.text("Kotu", 30, 40);
        TFTscreen.setTextSize(2);
        TFTscreen.text("<Kalp Sagligi", 0, 5);
        TFTscreen.line(0, 27, 160, 27);
        TFTscreen.line(0, 28, 160, 28);
        TFTscreen.text("Nabziniz:", 0, 35);
        TFTscreen.text("Ortalama:", 0, 55);
        ebcednabiz1 = String(nabiz);
        ebcednabiz1.toCharArray(ebcednabiz, 3);
        ebcedortalama = String(average);
        ebcedortalama.toCharArray(ebcedortalama1, 3);
        TFTscreen.text(ebcednabiz, 105, 35);
        TFTscreen.text(ebcedortalama1, 105, 55);
        delay(250);
        TFTscreen.text(ebcednabiz, 105, 35);
        TFTscreen.text(ebcedortalama1, 105, 55);
      }
      TFTscreen.setTextSize(2);
      onay = 0;
    }
  }
  if (yon == 1 && onay == 0) {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.setTextSize(3);
    TFTscreen.text("Menu", 2, 5);
    TFTscreen.setTextSize(2);
    TFTscreen.text("Bagimlilik", 2, 35);
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.text("Kalp Sagligi", 2, 62);
    TFTscreen.text("Hava Kalitesi", 2, 89);
  }
  if (yon == 2 && onay == 0) {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.setTextSize(3);
    TFTscreen.text("Menu", 2, 5);
    TFTscreen.setTextSize(2);
    TFTscreen.text("Kalp Sagligi", 2, 62);
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.text("Bagimlilik", 2, 35);
    TFTscreen.text("Hava Kalitesi", 2, 89);
  }
  if (yon == 3 && onay == 0) {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.setTextSize(3);
    TFTscreen.text("Menu", 2, 5);
    TFTscreen.setTextSize(2);
    TFTscreen.text("Hava Kalitesi", 2, 89);
    TFTscreen.stroke(100, 100, 100);
    TFTscreen.text("Bagimlilik", 2, 35);
    TFTscreen.text("Kalp Sagligi", 2, 62);
  }
  if (yon == 4) {
    yon = 1;
  }
  if (yon == 1 && onay == 1) {
    if (yon2 == 1 || yon2 == 2) {
      if (buton3 == 1) {
        while (buton3 == 1) {
          buton3 = digitalRead(4);
        }
        if (yon2 == 1) {
          abc++;
          bca = abc;
          String z = String(bca);
          z.toCharArray(ebced2, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced, 0, 100);
        }
        if (yon2 == 2) {
          azalacakgun++;
          azalacakgun2 = azalacakgun;
          String s = String(azalacakgun);
          s.toCharArray(ebcedazalacakgun, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced3, 0, 112);
        }
      }
      if (buton5 == 1) {
        while (buton5 == 1) {
          buton5 = digitalRead(12);
        }
        if (yon2 == 1) {
          abc--;
          bca = abc;
          String z = String(bca);
          z.toCharArray(ebced2, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced, 0, 100);
          if (abc < 0) {
            abc++;
            bca = abc;
            String z = String(bca);
            z.toCharArray(ebced2, 4);
          }
          if (abc == 0) {
            TFTscreen.stroke(255, 255, 255);
            TFTscreen.text(ebced2, 0, 112);
            TFTscreen.stroke(0, 0, 0);
            TFTscreen.text(anebced, 0, 112);
          }
        }
        if (yon2 == 2) {
          azalacakgun--;
          azalacakgun2 = azalacakgun;
          String s = String(azalacakgun);
          s.toCharArray(ebcedazalacakgun, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced3, 0, 112);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced, 0, 100);
          if (azalacakgun < 0) {
            azalacakgun++;
            azalacakgun2 = azalacakgun;
            String s = String(azalacakgun);
            s.toCharArray(ebcedazalacakgun, 4);
          }
        }
      }
    }
    if (yon2 == 0 && yon != 4) {
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("<  Bagimlilik", 0, 0);
      TFTscreen.line(0, 25, 200, 25);
      TFTscreen.line(0, 26, 200, 26);
      TFTscreen.text("Bugun Icilen:", 0, 35);
      TFTscreen.text(ebcedsigara, 0, 55);
      TFTscreen.stroke(100, 100, 100);
      TFTscreen.text("Gunluk Icilen ", 0, 80);
    }
    if (yon2 == 1 && onay == 1) {
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("<  Bagimlilik", 0, 0);
      TFTscreen.line(0, 25, 200, 25);
      TFTscreen.line(0, 26, 200, 26);
      TFTscreen.stroke(100, 100, 100);
      TFTscreen.text("Bugun Icilen:", 0, 35);
      TFTscreen.text(ebcedsigara, 0, 55);
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("Gunluk Icilen ", 0, 80);
    }
    if (yon2 == 2 && onay == 1 ) {
      TFTscreen.stroke(100, 100, 100);
      TFTscreen.text("Bugun Icilen", 0, 5);
      TFTscreen.text(ebcedsigara, 0, 25);
      TFTscreen.text("Gunluk Icilen", 0, 43);
      TFTscreen.text(ebced2, 0, 63);
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("Azaltilacagi", 0, 80);
      TFTscreen.text("Gun", 0, 95);
      TFTscreen.text(ebcedazalacakgun, 0, 112);
    }
  }
  
  if (yon == 3 && onay == 1) {
    if (yon == 3 && onay == 1) {
      if (duman > 320 &&  duman <= 400) {
        if (x != 1) {
          TFTscreen.setTextSize(3);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Normal", 30, 40);
          TFTscreen.text("Cok Iyı", 30, 40);
          TFTscreen.line(127, 76, 127, 90);
          TFTscreen.line(128, 76, 128, 90);
          TFTscreen.line(129, 76, 129, 90);
          TFTscreen.line(130, 76, 130, 90);
          TFTscreen.line(131, 76, 131, 90);
          TFTscreen.line(81, 76, 81, 90);
          TFTscreen.line(82, 76, 82, 90);
          TFTscreen.line(83, 76, 83, 90);
          TFTscreen.line(84, 76, 84, 90);
          TFTscreen.line(30, 76, 30, 90);
          TFTscreen.line(31, 76, 31, 90);
          TFTscreen.line(32, 76, 32, 90);
          TFTscreen.line(33, 76, 33, 90);
          TFTscreen.line(57, 80, 105, 80);
          TFTscreen.line(57, 81, 105, 81);
          TFTscreen.line(57, 82, 105, 82);
          TFTscreen.line(57, 83, 105, 83);
          TFTscreen.line(57, 84, 105, 84);
          TFTscreen.line(57, 85, 105, 85);
          TFTscreen.line(57, 86, 105, 86);
          TFTscreen.line(105, 80, 153, 80);
          TFTscreen.line(105, 81, 153, 81);
          TFTscreen.line(105, 82, 153, 82);
          TFTscreen.line(105, 83, 153, 83);
          TFTscreen.line(105, 84, 153, 84);
          TFTscreen.line(105, 85, 153, 85);
          TFTscreen.line(105, 86, 153, 86);
          TFTscreen.line(7, 80, 57, 80);
          TFTscreen.line(7, 81, 57, 81);
          TFTscreen.line(7, 82, 57, 82);
          TFTscreen.line(7, 83, 57, 83);
          TFTscreen.line(7, 84, 57, 84);
          TFTscreen.line(7, 85, 57, 85);
          TFTscreen.line(7, 86, 57, 86);
          x = 1;
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
        TFTscreen.line(105, 80, 127, 80);
        TFTscreen.line(105, 81, 127, 81);
        TFTscreen.line(105, 82, 127, 82);
        TFTscreen.line(105, 83, 127, 83);
        TFTscreen.line(105, 84, 127, 84);
        TFTscreen.line(105, 85, 127, 85);
        TFTscreen.line(105, 86, 127, 86);
        TFTscreen.line(131, 80, 153, 80);
        TFTscreen.line(131, 81, 153, 81);
        TFTscreen.line(131, 82, 153, 82);
        TFTscreen.line(131, 83, 153, 83);
        TFTscreen.line(131, 84, 153, 84);
        TFTscreen.line(131, 85, 153, 85);
        TFTscreen.line(131, 86, 153, 86);
        TFTscreen.stroke(100, 100, 100);
        TFTscreen.line(127, 76, 127, 90);
        TFTscreen.line(128, 76, 128, 90);
        TFTscreen.line(129, 76, 129, 90);
        TFTscreen.line(130, 76, 130, 90);
        TFTscreen.line(131, 76, 131, 90);
        x = 1;
      }
      if (duman <= 300 && duman > 100) {
        if (x != 2) {
          TFTscreen.setTextSize(3);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Cok Iyi", 30, 40);
          TFTscreen.text("Kotu", 30, 40);
          TFTscreen.line(127, 76, 127, 90);
          TFTscreen.line(128, 76, 128, 90);
          TFTscreen.line(129, 76, 129, 90);
          TFTscreen.line(130, 76, 130, 90);
          TFTscreen.line(131, 76, 131, 90);
          TFTscreen.line(81, 76, 81, 90);
          TFTscreen.line(82, 76, 82, 90);
          TFTscreen.line(83, 76, 83, 90);
          TFTscreen.line(84, 76, 84, 90);
          TFTscreen.line(30, 76, 30, 90);
          TFTscreen.line(31, 76, 31, 90);
          TFTscreen.line(32, 76, 32, 90);
          TFTscreen.line(33, 76, 33, 90);
          TFTscreen.line(57, 80, 105, 80);
          TFTscreen.line(57, 81, 105, 81);
          TFTscreen.line(57, 82, 105, 82);
          TFTscreen.line(57, 83, 105, 83);
          TFTscreen.line(57, 84, 105, 84);
          TFTscreen.line(57, 85, 105, 85);
          TFTscreen.line(57, 86, 105, 86);
          TFTscreen.line(105, 80, 153, 80);
          TFTscreen.line(105, 81, 153, 81);
          TFTscreen.line(105, 82, 153, 82);
          TFTscreen.line(105, 83, 153, 83);
          TFTscreen.line(105, 84, 153, 84);
          TFTscreen.line(105, 85, 153, 85);
          TFTscreen.line(105, 86, 153, 86);
          TFTscreen.line(7, 80, 57, 80);
          TFTscreen.line(7, 81, 57, 81);
          TFTscreen.line(7, 82, 57, 82);
          TFTscreen.line(7, 83, 57, 83);
          TFTscreen.line(7, 84, 57, 84);
          TFTscreen.line(7, 85, 57, 85);
          TFTscreen.line(7, 86, 57, 86);
          x = 2;
        }
        TFTscreen.setTextSize(3);
        TFTscreen.stroke(0, 255, 255);
        TFTscreen.text("Normal", 30, 40);
        TFTscreen.stroke(0, 0, 255);
        TFTscreen.line(105, 80, 153, 80);
        TFTscreen.line(105, 81, 153, 81);
        TFTscreen.line(105, 82, 153, 82);
        TFTscreen.line(105, 83, 153, 83);
        TFTscreen.line(105, 84, 153, 84);
        TFTscreen.line(105, 85, 153, 85);
        TFTscreen.line(105, 86, 153, 86);
        TFTscreen.stroke(0, 255, 255);
        TFTscreen.line(57, 80, 81, 80);
        TFTscreen.line(57, 81, 81, 81);
        TFTscreen.line(57, 82, 81, 82);
        TFTscreen.line(57, 83, 81, 83);
        TFTscreen.line(57, 84, 81, 84);
        TFTscreen.line(57, 85, 81, 85);
        TFTscreen.line(57, 86, 81, 86);
        TFTscreen.line(85, 80, 105, 80);
        TFTscreen.line(85, 81, 105, 81);
        TFTscreen.line(85, 82, 105, 82);
        TFTscreen.line(85, 83, 105, 83);
        TFTscreen.line(85, 84, 105, 84);
        TFTscreen.line(85, 85, 105, 85);
        TFTscreen.line(85, 86, 105, 86);
        TFTscreen.stroke(100, 100, 100);
        TFTscreen.line(81, 76, 81, 90);
        TFTscreen.line(82, 76, 82, 90);
        TFTscreen.line(83, 76, 83, 90);
        TFTscreen.line(84, 76, 84, 90);
        TFTscreen.stroke(0, 255, 0);
        TFTscreen.line(7, 80, 57, 80);
        TFTscreen.line(7, 81, 57, 81);
        TFTscreen.line(7, 82, 57, 82);
        TFTscreen.line(7, 83, 57, 83);
        TFTscreen.line(7, 84, 57, 84);
        TFTscreen.line(7, 85, 57, 85);
        TFTscreen.line(7, 86, 57, 86);
        x = 2;
      }
      if (duman <= 100 && duman > 0) {
        if (x != 3) {
          TFTscreen.setTextSize(3);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Kotu", 30, 40);
          TFTscreen.text("Normal", 30, 40);
          TFTscreen.line(127, 76, 127, 90);
          TFTscreen.line(128, 76, 128, 90);
          TFTscreen.line(129, 76, 129, 90);
          TFTscreen.line(130, 76, 130, 90);
          TFTscreen.line(131, 76, 131, 90);
          TFTscreen.line(81, 76, 81, 90);
          TFTscreen.line(82, 76, 82, 90);
          TFTscreen.line(83, 76, 83, 90);
          TFTscreen.line(84, 76, 84, 90);
          TFTscreen.line(30, 76, 30, 90);
          TFTscreen.line(31, 76, 31, 90);
          TFTscreen.line(32, 76, 32, 90);
          TFTscreen.line(33, 76, 33, 90);
          TFTscreen.line(57, 80, 105, 80);
          TFTscreen.line(57, 81, 105, 81);
          TFTscreen.line(57, 82, 105, 82);
          TFTscreen.line(57, 83, 105, 83);
          TFTscreen.line(57, 84, 105, 84);
          TFTscreen.line(57, 85, 105, 85);
          TFTscreen.line(57, 86, 105, 86);
          TFTscreen.line(105, 80, 153, 80);
          TFTscreen.line(105, 81, 153, 81);
          TFTscreen.line(105, 82, 153, 82);
          TFTscreen.line(105, 83, 153, 83);
          TFTscreen.line(105, 84, 153, 84);
          TFTscreen.line(105, 85, 153, 85);
          TFTscreen.line(105, 86, 153, 86);
          TFTscreen.line(7, 80, 57, 80);
          TFTscreen.line(7, 81, 57, 81);
          TFTscreen.line(7, 82, 57, 82);
          TFTscreen.line(7, 83, 57, 83);
          TFTscreen.line(7, 84, 57, 84);
          TFTscreen.line(7, 85, 57, 85);
          TFTscreen.line(7, 86, 57, 86);
          x = 3;
        }
        TFTscreen.setTextSize(3);
        TFTscreen.stroke(0, 255, 0);
        TFTscreen.text("Cok Iyi", 30, 40);
        TFTscreen.line(7, 80, 30, 80);
        TFTscreen.line(7, 81, 30, 81);
        TFTscreen.line(7, 82, 30, 82);
        TFTscreen.line(7, 83, 30, 83);
        TFTscreen.line(7, 84, 30, 84);
        TFTscreen.line(7, 85, 30, 85);
        TFTscreen.line(7, 86, 30, 86);
        TFTscreen.line(34, 80, 57, 80);
        TFTscreen.line(34, 81, 57, 81);
        TFTscreen.line(34, 82, 57, 82);
        TFTscreen.line(34, 83, 57, 83);
        TFTscreen.line(34, 84, 57, 84);
        TFTscreen.line(34, 85, 57, 85);
        TFTscreen.line(34, 86, 57, 86);
        TFTscreen.stroke(100, 100, 100);
        TFTscreen.line(30, 76, 30, 90);
        TFTscreen.line(31, 76, 31, 90);
        TFTscreen.line(32, 76, 32, 90);
        TFTscreen.line(33, 76, 33, 90);
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
        x = 3;
      }
      TFTscreen.setTextSize(2);
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("Hava Kalitesi", 0, 5);
      TFTscreen.line(0, 27, 160, 27);
    }
  }
  if (yon == 2 && onay == 1) {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text("<Kalp Sagligi", 0, 5);
    TFTscreen.line(0, 27, 160, 27);
    TFTscreen.line(0, 28, 160, 28);
    TFTscreen.text("Nabziniz:", 0, 35);
    TFTscreen.text("Ortalama:", 0, 55);
    ebcednabiz1 = String(nabiz);
    ebcednabiz1.toCharArray(ebcednabiz, 3);
    ebcedortalama = String(average);
    ebcedortalama.toCharArray(ebcedortalama1, 3);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(ebcednabiz, 105, 35);
    TFTscreen.text(ebcedortalama1, 105, 55);
    delay(250);
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(ebcednabiz, 105, 35);
    TFTscreen.text(ebcedortalama1, 105, 55);
  }
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    digitalWrite(13, !digitalRead(13));
    previousMillis = currentMillis;
    t1++;
  }
  if (duman > 350) {
    Serial.println("Asa");
    if ((unsigned long)(currentMillis2 - previousMillis2) >= interval2) {
      previousMillis2 = currentMillis2;
      sigara++;
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text(ebcedsigara, 0, 55);
    }
  }
}
