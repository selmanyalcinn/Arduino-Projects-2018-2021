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
int sag = 1;
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
int x = 1;
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
int karin;
String q = "";
String yazi2;
char ebcedyazi2[11];
int xas;
int uzunluk;
void setup() {

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  pinMode(3, OUTPUT);
  pinMode(6, INPUT);
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
  q.toCharArray(ebcedyazi2, 11);
  buton1 = digitalRead(2);
  buton2 = digitalRead(12);
  buton3 = digitalRead(4);
  buton4 = digitalRead(5);
  buton5 = digitalRead(7);
  if (buton1 == 1) {
    while (buton1 == 1) {
      buton1 = digitalRead(2);
    }
    if (yon2 == 1 && onay == 2 && yon == 4) {
      anan++;
      if (anan == 2) {
        anan = 0;
      }
    }
    if (onay == 0) {
      yon++;
    }
    if (yon == 4 && onay == 1 && yon2 != 3 || yon == 1 && onay == 1) {
      yon2++;
      if (yon == 4 && onay == 1 && yon2 == 3) {
        yon2 = 0;
      }
      if (yon != 4) {
        if (yon2 == 2 && yon != 4) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("<  Bagimlilik", 0, 0);
          TFTscreen.line(0, 25, 200, 25);
          TFTscreen.line(0, 26, 200, 26);
          TFTscreen.text("Bugun Icilen:", 0, 35);
          TFTscreen.text(ebcedsigara, 0, 55);
          TFTscreen.text("Icilen Sigara ", 0, 80);
          TFTscreen.text("Grafikleri", 0, 95);
          TFTscreen.line(0, 10, 200, 10);
          TFTscreen.line(0, 11, 200, 11);
          TFTscreen.stroke(100, 100, 100);
          TFTscreen.text("Bugun Icilen:", 0, 15);
          TFTscreen.text(ebcedsigara, 0, 30);
          TFTscreen.text("Icilen Sigara ", 0, 53);
          TFTscreen.text("Grafikleri", 0, 67);
        }
        if (yon2 == 3 && onay == 1) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Bugun Icilen:", 0, 15);
          TFTscreen.text(ebcedsigara, 0, 30);
          TFTscreen.text("Icilen Sigara ", 0, 53);
          TFTscreen.text("Grafikleri", 0, 67);
          TFTscreen.line(0, 5, 200, 5);
          TFTscreen.line(0, 6, 200, 6);
          TFTscreen.text("Gunluk Icilen", 0, 90);
          TFTscreen.text(ebced2, 0, 105);
          TFTscreen.stroke(100, 100, 100);
          TFTscreen.text("Icilen Sigara", 0, 0);
          TFTscreen.text("Grafikleri", 0, 20);
          TFTscreen.text("Gunluk Icilen", 0, 45);
          TFTscreen.text(ebced2, 0, 60);
        }
        if (yon2 == 4) {
          yon2 = 0;
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Icilen Sigara", 0, 0);
          TFTscreen.text("Grafikleri", 0, 20);
          TFTscreen.text("Gunluk Icilen", 0, 45);
          TFTscreen.text(ebced2, 0, 50);
          TFTscreen.text("Azaltilacagi", 0, 78);
          TFTscreen.text("Gun", 0, 90);
          TFTscreen.text(ebced2, 0, 110);
        }
      }
    }
  }
  if (buton3 == 1 && anan != 1) {
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
        TFTscreen.line(0, 5, 200, 5);
        TFTscreen.line(0, 6, 200, 6);
        TFTscreen.text("Bugun Icilen:", 0, 15);
        TFTscreen.text(ebcedsigara, 0, 30);
        TFTscreen.text("Icilen Sigara ", 0, 53);
        TFTscreen.text("Grafikleri", 0, 67);
        TFTscreen.text("Gunluk Icilen", 0, 90);
        TFTscreen.text(ebced2, 0, 105);
      }
      if (yon2 == 2) {
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text("Icilen Sigara", 0, 0);
        TFTscreen.text("Grafikleri", 0, 20);
        TFTscreen.text("Gunluk Icilen", 0, 45);
        TFTscreen.text(ebced2, 0, 50);
        TFTscreen.text("Azaltilacagi", 0, 78);
        TFTscreen.text("Gun", 0, 90);
        TFTscreen.text(ebcedazalacakgun, 0, 110);
        TFTscreen.stroke(100, 100, 100);
        TFTscreen.text("Bugun Icilen:", 0, 15);
        TFTscreen.text(ebcedsigara, 0, 30);
        TFTscreen.text("Icilen Sigara ", 0, 53);
        TFTscreen.text("Grafikleri", 0, 67);
      }
    }
  }
  if (buton2 == 1 && anan != 1) {
    while (buton2 == 1) {
      buton2 = digitalRead(12);
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
    if (yon == 4 && anan != 1) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text("Bagimlilik", 0, 15);
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
    if (yon == 4 && onay == 1 && yon2 == 0 || yon == 4 && onay == 1 && yon2 == 1 && anan != 1) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text("Bagimlilik", 0, 15);
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
    if (onay == 2 && yon2 != 1 && yon != 4) {
      onay = 0;
      yon2 = 0;
      if (yon2 == 0 || yon2 == 1) {
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
      if (yon2 == 2) {
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text("Bugun Icilen:", 0, 15);
        TFTscreen.text(ebcedsigara, 0, 30);
        TFTscreen.text("Icilen Sigara ", 0, 53);
        TFTscreen.text("Grafikleri", 0, 67);
        TFTscreen.line(0, 5, 200, 5);
        TFTscreen.line(0, 6, 200, 6);
        TFTscreen.text("Gunluk Icilen", 0, 90);
        TFTscreen.text(ebced2, 0, 105);
        yon2 = 0;
      }
      if (yon2 == 3 && yon != 4) {
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text("Icilen Sigara", 0, 0);
        TFTscreen.text("Grafikleri", 0, 20);
        TFTscreen.text("Gunluk Icilen", 0, 45);
        TFTscreen.text(ebced2, 0, 60);
        TFTscreen.text("Azaltilacagi", 0, 78);
        TFTscreen.text("Gun", 0, 90);
        TFTscreen.text(ebcedazalacakgun, 0, 110);
        yon2 = 0;
      }
    }
    if (yon == 4 && onay == 2 && yon2 == 1) {
      TFTscreen.stroke(255, 255, 255);
      TFTscreen.text("< Ag Baglantisi", 0, 5);
      TFTscreen.line(0, 25, 200, 25);
      TFTscreen.line(0, 26, 200, 26);
      TFTscreen.text("Ag Adi >", 0, 40);
      TFTscreen.text("Ag Sifresi >", 0, 70);
    }
  }
  if (yon == 1 && onay == 1) {
    if (yon2 == 2 || yon2 == 3) {
      if (yon2 == 2) {

        if (abc == 0 && azalacakgun == 0) {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced2, 0, 105);
          String an = "Sayi Giriniz";
          an.toCharArray(anebced, 30);
          TFTscreen.stroke(100, 100, 100);
          TFTscreen.text(anebced, 0, 105);
        }
      }
      if (buton4 == 1) {
        while (buton4 == 1) {
          buton4 = digitalRead(5);
        }
        if (yon2 != 3) {
          abc++;
          bca = abc;
          String z = String(bca);
          z.toCharArray(ebced2, 4);
          TFTscreen.stroke(0, 0, 0);
          TFTscreen.text("Gunluk Icilen", 0, 90);
          if (abc != 0 && abc != 1) {
            TFTscreen.stroke(255, 255, 255);
            TFTscreen.text(ebced, 0, 105);
          }
          if (abc == 1) {
            TFTscreen.stroke(255, 255, 255);
            TFTscreen.text(anebced, 0, 105);
          }
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
          buton5 = digitalRead(7);
        }
        if (yon2 != 3) {
          abc--;
          bca = abc;
          String z = String(bca);
          z.toCharArray(ebced2, 4);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text(ebced, 0, 105);
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
    if (yon2 == 1 && yon != 4) {
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
      TFTscreen.stroke(100, 100, 100);
    }
    if (yon2 == 2 && yon != 4) {
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.line(0, 5, 200, 5);
      TFTscreen.line(0, 6, 200, 6);
      TFTscreen.text("Gunluk Icilen", 0, 90);
      TFTscreen.text(ebced2, 0, 105);
    }
    if (yon2 == 3 && yon != 4) {
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("Azaltilacagi", 0, 78);
      TFTscreen.text("Gun", 0, 90);
      TFTscreen.text(ebcedazalacakgun, 0, 110);
    }
  }
  if (yon == 4 && onay == 1 || onay == 2) {
    if (buton4 == 1 || buton5 == 1 && anan == 1 && karin == 0) {
      Serial.println("asdas");
      if (buton4 == 1) {
        while (buton4 == 1) {
          buton4 = digitalRead(5);
        }
        sag++;
        Serial.println(sag);
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text(anebced, 0, 40);
        TFTscreen.text("A", 0, 40);
      }
      if (buton5 == 1) {
        while (buton5 == 1) {
          buton5 = digitalRead(7);
        }
        sag--;
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text(anebced, 0, 40);
        TFTscreen.text("a", 0, 40);
        if (sag < 0) {
          sag = 0;
        }
      }
      if (sag == 1) {
        an = "A";
        an2 = an;
      }
      if (sag == 2) {
        an = "a";
        an2 = an;
      }
      if (sag == 3) {
        an = "B";
        an2 = an;
      }
      if (sag == 4) {
        an = "b";
        an2 = an;
      }
      if (sag == 5) {
        an = "C";
        an2 = an;
      }
      if (sag == 6) {
        an = "c";
        an2 = an;
      }

      if (sag == 7) {
        an = "D";
        an2 = an;
      }

      if (sag == 8) {
        an = "d";
        an2 = an;
      }

      if (sag == 9) {
        an = "E";
        an2 = an;
      }

      if (sag == 10) {
        an = "e";
        an2 = an;
      }

      if (sag == 11) {
        an = "F";
        an2 = an;
      }

      if (sag == 12) {
        an = "f";
        an2 = an;
      }

      if (sag == 13) {
        an = "G";
        an2 = an;
      }

      if (sag == 14) {
        an = "g";
        an2 = an;
      }

      if (sag == 15) {
        an = "H";
        an2 = an;
      }

      if (sag == 16) {
        an = "h";
        an2 = an;
      }

      if (sag == 17) {
        an = "I";
        an2 = an;
      }

      if (sag == 18) {
        an = "i";
        an2 = an;
      }

      if (sag == 19) {
        an = "J";
        an2 = an;
      }

      if (sag == 20) {
        an = "j";
        an2 = an;
      }

      if (sag == 21) {
        an = "K";
        an2 = an;
      }

      if (sag == 22) {
        an = "k";
        an2 = an;
      }

      if (sag == 23) {
        an = "L";
        an2 = an;
      }

      if (sag == 24) {
        an = "l";
        an2 = an;
      }

      if (sag == 25) {
        an = "M";
        an2 = an;
      }

      if (sag == 26) {
        an = "m";
        an2 = an;
      }
      if (sag == 27) {
        an = "N";
        an2 = an;
      }
      if (sag == 27) {
        an = "N";
        an2 = an;
      }
      if (sag == 28) {
        an = "n";
        an2 = an;
      }
      if (sag == 29) {
        an = "O";
        an2 = an;
      }
      if (sag == 30) {
        an = "o";
        an2 = an;
      }
      if (sag == 31) {
        an = "P";
        an2 = an;
      }
      if (sag == 32) {
        an = "p";
        an2 = an;
      }
      if (sag == 33) {
        an = "Q";
        an2 = an;
      }
      if (sag == 34) {
        an = "q";
        an2 = an;
      }
      if (sag == 35) {
        an = "R";
        an2 = an;
      }
      if (sag == 36) {
        an = "r";
        an2 = an;
      }
      if (sag == 37) {
        an = "S";
        an2 = an;
      }
      if (sag == 38) {
        an = "s";
        an2 = an;
      }
      if (sag == 39) {
        an = "T";
        an2 = an;
      }
      if (sag == 40) {
        an = "t";
        an2 = an;
      }
      if (sag == 41) {
        an = "U";
        an2 = an;
      }
      if (sag == 42) {
        an = "u";
        an2 = an;
      }
      if (sag == 43) {
        an = "V";
        an2 = an;
      }
      if (sag == 44) {
        an = "v";
        an2 = an;
      }
      if (sag == 45) {
        an = "W";
        an2 = an;
      }
      if (sag == 46) {
        an = "w";
        an2 = an;
      }
      if (sag == 47) {
        an = "X";
        an2 = an;
      }
      if (sag == 48) {
        an = "x";
        an2 = an;
      }
      if (sag == 49) {
        an = "Y";
        an2 = an;
      }
      if (sag == 50) {
        an = "y";
        an2 = an;
      }
      if (sag == 51) {
        an = "Z";
        an2 = an;
      }
      if (sag == 52) {
        an = "z";
        an2 = an;
      }
    }
    if (yon2 == 0) {
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("< Ag Baglantisi", 0, 5);
      TFTscreen.line(0, 25, 200, 25);
      TFTscreen.line(0, 26, 200, 26);
      TFTscreen.stroke(100, 100, 100);
      TFTscreen.text("Ag Adi >", 0, 40);
      TFTscreen.text("Ag Sifresi >", 0, 70);
    }
    if (yon2 == 1 && onay == 1) {
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text("< Ag Baglantisi", 0, 5);
      TFTscreen.line(0, 25, 200, 25);
      TFTscreen.line(0, 26, 200, 26);
      TFTscreen.text("Ag Adi >", 0, 40);
      TFTscreen.stroke(100, 100, 100);
      TFTscreen.text("Ag Sifresi >", 0, 70);
    }
    if (yon2 == 1 && onay == 2) {
      if (anan == 0) {
        TFTscreen.stroke(0, 0, 0);
        TFTscreen.text("<", 0, 5);
        TFTscreen.text("Ag Adi", 40, 5);
        TFTscreen.stroke(100, 100, 100);
        TFTscreen.text("Ag Adi Girin", 0, 25);
        an2.toCharArray(anebced2, 11);
      }
      if (anan == 1) {
        TFTscreen.stroke(255, 255, 255);
        TFTscreen.text("<", 0, 5);
        TFTscreen.stroke(0, 0, 0);
        TFTscreen.text("Ag Adi", 40, 5);
        yazi.toCharArray(ebcedyazi, 15);
        an2.toCharArray(anebced2, 11);
        TFTscreen.stroke(0, 0, 0);
        TFTscreen.text(anebced2, 0, 40);
        TFTscreen.stroke(100, 100, 100);
        if (xas == 0) {
          TFTscreen.text("Ag Adi Girin", 0, 25);
        }
        if (sag == 1) {
          an2 = "A";
          an2.toCharArray(anebced2, 11);
        }
        if (buton2 == 1) {
          while (buton2 == 1) {
            buton2 = digitalRead(12);
          }
          xas++;
          if (sag == 1 ) {
            an = "A";
          }
          String yazi2;
          yazi2 = "Ag Adi Girin";
          char ebcedyazi2[11];
          q = q + an;
          yazi = q;
          q.toCharArray(ebcedyazi2, 11);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Ag Adi Girin", 0, 25);
          TFTscreen.text(ebcedyazi, 0, 25);
          TFTscreen.stroke(0, 0, 0);
          TFTscreen.text(ebcedyazi2, 0, 25);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Ag Adi Girin", 0, 25);
          TFTscreen.text(ebcedyazi, 0, 25);
          TFTscreen.stroke(0, 0, 0);
          TFTscreen.text(ebcedyazi2, 0, 25);
          digitalWrite(3, HIGH);
          karin = 0;
        }
        if (buton3 == 1) {
          while (buton3 == 1) {
            buton3 = digitalRead(4);
          }
          xas++;
          if (sag == 1 ) {
            an = "A";
          }
          String yazi2;
          yazi2 = "Ag Adi Girin";
          char ebcedyazi2[11];
          uzunluk = q.length();
          q = q.substring(0, uzunluk - 1);
          yazi = q;
          q.toCharArray(ebcedyazi2, 11);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Ag Adi Girin", 0, 25);
          TFTscreen.text(ebcedyazi, 0, 25);
          TFTscreen.stroke(0, 0, 0);
          TFTscreen.text(ebcedyazi2, 0, 25);
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.text("Ag Adi Girin", 0, 25);
          TFTscreen.text(ebcedyazi, 0, 25);
          TFTscreen.stroke(0, 0, 0);
          TFTscreen.text(ebcedyazi2, 0, 25);
          karin = 0;
          digitalWrite(6, HIGH);
        }
        digitalWrite(6,LOW);
        digitalWrite(3,LOW);
      }
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
}
