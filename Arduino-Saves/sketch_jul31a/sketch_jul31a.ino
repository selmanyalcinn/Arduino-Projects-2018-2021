#include <RTClib.h>
#include <Wire.h>
#include <LCD5110_Basic.h>
RTC_DS1307 RTC;
LCD5110 ekran(8, 9, 10, 11, 12);
int buton1;
int buton2;
int buton3;
int buton4;
int tiklama;
int tiklama2;
int gunlukicilen;
int azaltilansigara;
int arttirilansure;
boolean clr_tik;
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
void setup() {
  ekran.InitLCD();
  ekran.setContrast(50);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}
  void loop() {
    buton1 = digitalRead(2);
    buton2 = digitalRead(3);
    buton3 = digitalRead(4);
    buton4 = digitalRead(5);
    if (buton1 == HIGH)
    {
      while (buton1 == HIGH)
      {
        buton1 = digitalRead(2);
      }
      tiklama++;
      clr_tik = 1;
      Serial.println(tiklama);
    }
    if (buton4 == HIGH)
    {
      while (buton4 == HIGH)
      {
        buton4 = digitalRead(5);
      }
      tiklama2++;
      clr_tik = 1;
      Serial.println(tiklama2);
    }
    if (clr_tik == 1) {
      clr_tik = 0;
      ekran.clrScr();
    }
    if (tiklama == 0 && tiklama2 == 0)
    {
      ekran.setFont(SmallFont);
      ekran.invertText(true);
      ekran.print(">GunlukIcilen", 0, 8);
      ekran.setFont(SmallFont);
      ekran.printNumI(gunlukicilen, 0, 16);
      ekran.setFont(SmallFont);
      ekran.print("KacGundeBir", 0, 24);
      ekran.print("Azalsin", 0, 32);
      ekran.setFont(SmallFont);
      ekran.printNumI(azaltilansigara, 0, 40);
      if (buton2 == HIGH)
      {
        while (buton2 == HIGH)
        {
          buton2 = digitalRead(3);
        }
        gunlukicilen++;
      }
      else if (buton3 == HIGH)
      {
        while (buton3 == HIGH)
        {
          buton3 = digitalRead(4);
        }
        gunlukicilen--;
      }
    }
    if (tiklama == 0 && tiklama2 == 1)
    {
      ekran.invertText(false);
      ekran.setFont(SmallFont);
      ekran.print(">GunlukIcilen", 0, 8);
      ekran.setFont(SmallFont);
      ekran.printNumI(gunlukicilen, 0, 16);
      ekran.setFont(SmallFont);
      ekran.invertText(true);
      ekran.print("KacGundeBir", 0, 24);
      ekran.print("Azalsin", 0, 32);
      ekran.invertText(false);
      ekran.setFont(SmallFont);
      ekran.printNumI(azaltilansigara, 0, 40);
      if (buton2 == HIGH)
      {
        while (buton2 == HIGH)
        {
          buton2 = digitalRead(3);
        }
        azaltilansigara++;
      }
      else if (buton3 == HIGH)
      {
        while (buton3 == HIGH)
        {
          buton3 = digitalRead(4);
        }
        azaltilansigara--;
      }
      else if (tiklama2 == 2)
      {
        tiklama2 = 0;
      }
    }
      if (tiklama == 1 && tiklama2 == 0)
      {

        ekran.setFont(SmallFont);
        ekran.invertText(true);
        ekran.print(">GunlukIcilen", 0, 8);
        ekran.setFont(SmallFont);
        ekran.printNumI(gunlukicilen, 0, 16);
        ekran.setFont(SmallFont);
        ekran.print(">ArtanDakika", 0, 24);
        ekran.setFont(SmallFont);
        ekran.printNumI (arttirilansure            , 0, 32);
        if (buton2 == HIGH)
        {
          while (buton2 == HIGH)
          {
            buton2 = digitalRead(3);
          }
          gunlukicilen++;
        }
        else if (buton3 == HIGH)
        {
          while (buton3 == HIGH)
          {
            buton3 = digitalRead(4);
          }
          gunlukicilen--;
        
        }
       }
        if (tiklama == 1 && tiklama2 == 1)
        {
          ekran.setFont(SmallFont);
          ekran.invertText(false);
          ekran.print(">GunlukIcilen", 0, 8);
          ekran.setFont(SmallFont);
          ekran.printNumI(gunlukicilen, 0, 16);
          ekran.setFont(SmallFont);
          ekran.invertText(true);
          ekran.print("ArtanDakika", 0, 24);
          ekran.invertText(false);
          ekran.setFont(SmallFont);
          ekran.printNumI(arttirilansure           , 0, 32);
          if (buton2 == HIGH)
          {
            while (buton2 == HIGH)
            {
              buton2 = digitalRead(3);
            }
            arttirilansure++;
          }
          else if (buton3 == HIGH)
          {
            while (buton3 == HIGH)
            {
              buton3 = digitalRead(4);
            }
            arttirilansure--;
          }
          else if (tiklama == 2)
          {
            tiklama = 0;
          }
        }
      }
        

