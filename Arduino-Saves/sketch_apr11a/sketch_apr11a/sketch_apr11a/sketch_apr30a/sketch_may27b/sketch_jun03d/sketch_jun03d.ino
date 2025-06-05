#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
#include <SoftwareSerial.h>

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
SoftwareSerial s(5, 6);
// char array to print to the screen
int sag = 0;
char ebced[4];
char ebced2[4];
char ebced3[4];
char ebcedsigara[4];
char ebcedazalacakgun[4];
char ebcedyazi[12];
int bca;
int buton1;
int buton2;
int buton3;
int buton4;
int buton5;
int yon = 1;
int yon2;
int onay;
int abc;
int abc2;
int sigara = 16;
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
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int nabiz;
int inputPin = A0;
unsigned long t1;
String toplam2;
String toplam3;
String toplam4;
String toplam5;
String toplam6;
String toplam7;
String toplam8;
String toplam9;
String toplam10;
String toplam11;
String toplam12;
String toplam13;
String virgul = ",";
int duzeneuyulamayangun;
void setup() {
  s.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);
  TFTscreen.setTextSize(2);
}

void loop() {
  String y = String(abc);
  y.toCharArray(ebced, 4);
  String sz = String(azalacakgun);
  sz.toCharArray(ebced3, 4);
  String zeynep = String(sigara);
  yazi.toCharArray(ebcedyazi, 4);
  zeynep.toCharArray(ebcedsigara, 4);
  an.toCharArray(anebced, 11);
  buton1 = digitalRead(2);
  buton2 = digitalRead(3);
  buton3 = digitalRead(4);
  buton4 = digitalRead(7);
  buton5 = digitalRead(12);
  duman = analogRead(A0);
  static double oncekideger = 0;
  static double oncekiyenileme = 0;
  int ritim = analogRead(sensor);
  double deger = alfa * oncekideger + (0 - alfa) * ritim;
  yenileme = deger - oncekideger;
  nabiz = ritim / 10;
  oncekideger = deger;
  oncekiyenileme = yenileme;
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(nabiz);
  total = (total / total) + readings[readIndex];
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  average = total / numReadings;
  delay(1);
  if (buton1 == 1) {
    while (buton1 == 1) {
      buton1 = digitalRead(2);
    }
    if (onay == 0) {
      yon++;
    }
    if (yon == 4 && onay == 1 && yon2 != 3 || yon == 1 && onay == 1) {
      yon2++;
      if (yon == 4 && onay == 1 && yon2 == 3) {
        yon2 = 0;
      }
      if (yon2 == 2) {
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text("<  Bagimlilik", 0, 0);
        TFTscreen.line(0, 25, 200, 25);
        TFTscreen.line(0, 26, 200, 26);
        TFTscreen.text("Bugun Icilen:", 0, 35);
        TFTscreen.text(ebcedsigara, 0, 55);
        TFTscreen.text("Icilen Sigara ", 0, 80);
        TFTscreen.text("Grafikleri", 0, 95);
        TFTscreen.stroke(100, 100, 100);
      }
      if (yon2 == 2 && onay == 1 ) {
        TFTscreen.stroke(0, 0, 0);
        TFTscreen.text("Gunluk Icilen", 0, 50);
        TFTscreen.text(ebced2, 0, 65);
        TFTscreen.stroke(100, 100, 100);
        TFTscreen.text("Icilen Sigara", 0, 10);
        TFTscreen.text("Grafikleri", 0, 25);
        TFTscreen.text("Azaltilacagi", 0, 78);
        TFTscreen.text("Gun", 0, 90);
        TFTscreen.text(ebcedazalacakgun, 0, 110);
      }
    }
  }
  if (buton3 == 1) {
    while (buton3 == 1) {
      buton3 = digitalRead(4);
    }
    if (yon != 1) {
      yon--;
    }
    if (yon == 1 && onay == 1) {
      yon2--;
      if (yon2 == 1) {
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text("Gunluk Icilen", 0, 50);
        TFTscreen.text(ebced2, 0, 65);
        TFTscreen.text("Icilen Sigara", 0, 10);
        TFTscreen.text("Grafikleri", 0, 25);
        TFTscreen.text("Azaltilacagi", 0, 78);
        TFTscreen.text("Gun", 0, 90);
        TFTscreen.text(ebcedazalacakgun, 0, 110);
      }
      if (yon2 == 2) {
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text("Azaltilacagi", 0, 78);
        TFTscreen.text("Gun", 0, 90);
        TFTscreen.text(ebcedazalacakgun, 0, 110);
        TFTscreen.stroke(100, 100, 100);
        TFTscreen.text("Gunluk Icilen", 0, 50);
        TFTscreen.text(ebced2, 0, 65);
        TFTscreen.text("Icilen Sigara", 0, 10);
        TFTscreen.text("Grafikleri", 0, 25);
      }
    }
  }
  if (buton2 == 1) {
    while (buton2 == 1) {
      buton2 = digitalRead(3);
    }
    onay++;
    if (yon == 1) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text("Bagimlilik", 0, 15);
      TFTscreen.line(0, 35, 500, 35);
      TFTscreen.line(0, 36, 500, 36);
      TFTscreen.text("Kalp Sagligi", 0, 45);
      TFTscreen.line(0, 67, 500, 67);
      TFTscreen.line(0, 68, 500, 68);
      TFTscreen.text("Hava Kalitesi", 0, 77);
      TFTscreen.line(0, 99, 500, 99);
      TFTscreen.line(0, 100, 500, 100);
      TFTscreen.text("Ag Baglantisi", 0, 109);
      TFTscreen.line(0, 131, 500, 121);
      TFTscreen.line(0, 131, 500, 122);
    }
    if (yon == 3) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text("Bagimlilik", 0, 15);
      TFTscreen.line(0, 35, 500, 35);
      TFTscreen.line(0, 36, 500, 36);
      TFTscreen.text("Kalp Sagligi", 0, 45);
      TFTscreen.line(0, 67, 500, 67);
      TFTscreen.line(0, 68, 500, 68);
      TFTscreen.text("Hava Kalitesi", 0, 77);
      TFTscreen.line(0, 99, 500, 99);
      TFTscreen.line(0, 100, 500, 100);
      TFTscreen.text("Ag Baglantisi", 0, 109);
      TFTscreen.line(0, 131, 500, 121);
      TFTscreen.line(0, 131, 500, 122);
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
        TFTscreen.text("Icilen Sigara ", 0, 80);
        TFTscreen.text("Grafikleri", 0, 95);
        TFTscreen.text("Gunluk Icilen", 0, 50);
        TFTscreen.text(ebced2, 0, 65);
        TFTscreen.text("Icilen Sigara", 0, 10);
        TFTscreen.text("Grafikleri", 0, 25);
        TFTscreen.text("Azaltilacagi", 0, 78);
        TFTscreen.text("Gun", 0, 90);
        TFTscreen.text(ebcedazalacakgun, 0, 110);
        TFTscreen.text("Azaltilacagi", 0, 78);
        TFTscreen.text("Gun", 0, 90);
        TFTscreen.text(ebcedazalacakgun, 0, 110);
        TFTscreen.text("Gunluk Icilen", 0, 50);
        TFTscreen.text(ebced2, 0, 65);
        TFTscreen.text("Icilen Sigara", 0, 10);
        TFTscreen.text("Grafikleri", 0, 25);
        TFTscreen.text("Hava Kalitesi", 0, 5);
        TFTscreen.line(0, 27, 160, 27);
        TFTscreen.line(7, 80, 57, 80);
        TFTscreen.line(7, 81, 57, 81);
        TFTscreen.line(7, 82, 57, 82);
        TFTscreen.line(7, 83, 57, 83);
        TFTscreen.line(7, 84, 57, 84);
        TFTscreen.line(7, 85, 57, 85);
        TFTscreen.line(7, 86, 57, 86);
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
        TFTscreen.setTextSize(3);
        TFTscreen.text("Normal", 30, 40);
        TFTscreen.text("Cok Iyi", 30, 40);
        TFTscreen.text("Kotu", 30, 40);
      }
      TFTscreen.setTextSize(2);
      onay = 0;
    }
  }
  if (yon == 1 && onay == 1) {
    if (yon2 == 2 || yon2 == 3) {
      if (buton4 == 1) {
        while (buton4 == 1) {
          buton4 = digitalRead(7);
        }
        if (yon2 != 3) {
          abc++;
          bca = abc;
          String z = String(bca);
          z.toCharArray(ebced2, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced, 0, 65);
        }
        if (yon2 == 3) {
          azalacakgun++;
          azalacakgun2 = azalacakgun;
          String s = String(azalacakgun);
          s.toCharArray(ebcedazalacakgun, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced3, 0, 110);
        }
      }
      if (buton5 == 1) {
        while (buton5 == 1) {
          buton5 = digitalRead(12);
        }
        if (yon2 != 3) {
          abc--;
          bca = abc;
          String z = String(bca);
          z.toCharArray(ebced2, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced, 0, 65);
          if (abc < 0) {
            abc++;
            bca = abc;
            String z = String(bca);
            z.toCharArray(ebced2, 4);

          }
          if (abc == 0) {
            TFTscreen.stroke(255, 255, 255);
            TFTscreen.text(ebced2, 0, 105);
            TFTscreen.stroke(0, 0, 0);
            TFTscreen.text(anebced, 0, 105);

          }
        }
        if (yon2 == 3) {
          azalacakgun--;
          azalacakgun2 = azalacakgun;
          String s = String(azalacakgun);
          s.toCharArray(ebcedazalacakgun, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced3, 0, 110);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced, 0, 105);
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
      TFTscreen.text("Icilen Sigara ", 0, 80);
      TFTscreen.text("Grafikleri", 0, 95);
      TFTscreen.stroke(100, 100, 100);
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
      TFTscreen.text("Icilen Sigara ", 0, 80);
      TFTscreen.text("Grafikleri", 0, 95);
    }
    if (yon2 == 2 && onay == 1 ) {
      Serial.println("9300");
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("Gunluk Icilen", 0, 50);
      TFTscreen.text(ebced2, 0, 65);
      TFTscreen.stroke(100, 100, 100);
      TFTscreen.text("Icilen Sigara", 0, 10);
      TFTscreen.text("Grafikleri", 0, 25);
      TFTscreen.text("Azaltilacagi", 0, 78);
      TFTscreen.text("Gun", 0, 90);
      TFTscreen.text(ebcedazalacakgun, 0, 110);
    }
    if (yon2 == 3 && onay == 1) {
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("Azaltilacagi", 0, 78);
      TFTscreen.text("Gun", 0, 90);
      TFTscreen.text(ebcedazalacakgun, 0, 110);
      TFTscreen.stroke(100, 100, 100);
      TFTscreen.text("Gunluk Icilen", 0, 50);
      TFTscreen.text(ebced2, 0, 65);
      TFTscreen.text("Icilen Sigara", 0, 10);
      TFTscreen.text("Grafikleri", 0, 25);
    }
  }
  if (yon == 3 && onay == 1) {
    if (yon == 3 && onay == 1) {
      if (duman > 300 &&  duman <= 400) {
        if (x != 1) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Normal", 40, 50);
          TFTscreen.text("Kotu", 0, 40);
          x = 1;
        }
        TFTscreen.setTextSize(3);
        Serial.println(duman);
        TFTscreen.stroke(0, 255, 0);
        TFTscreen.text("Cok Iyi", 30, 40);
        x = 1;
      }
      if (duman <= 300 && duman > 100) {
        if (x != 2) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Cok Iyi", 30, 40);
          TFTscreen.text("Kotu", 30, 40);
          x = 2;
        }
        TFTscreen.setTextSize(3);
        TFTscreen.stroke(0, 255, 255);
        TFTscreen.text("Normal", 30, 40);
        x = 2;
      }
      if (duman <= 100 && duman > 0) {
        if (x != 3) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Cok Iyi", 30, 40);
          x = 3;
        }
        TFTscreen.setTextSize(3);
        TFTscreen.stroke(0, 0, 255);
        TFTscreen.text("Kotu", 30, 40);
        x = 3;
      }
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
  }
  if (yon == 1 && onay == 0) {
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
  if (s.available() > 0)
  {
    s.write(nabiz);
    delay(100);
    s.write(sigara);
    delay(100);
    s.write(duman);
    delay(100);
    s.write(duzeneuyulamayangun);
    delay(100);
    s.write(azalacakgun);
    delay(100);
    s.write(abc);
    delay(100); 
  }
  t1 = millis();
}
