#include <RTClib.h>
#include <Wire.h>
RTC_DS1307 RTC;
int gun;
int icildi;
int alevsensoru=7;
int alev;
int dumansensoru=A0;
int duman;
int gunlukicilen;
int azaltilangun;
void setup () {
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  pinMode(7,INPUT);
  pinMode(A0,INPUT);
}
void loop () {
  DateTime now = RTC.now();
  alev=digitalRead(7);
  duman=digitalRead(A0);
  if (alev == LOW)
  {
    if(duman < 90)
    {
      while(duman<90)
      {
        duman=digitalRead(A0);
      }
      icildi++;
    }
    if(icildi<gunlukicilen)
    {
      //bildirim gonderme
    }
    if (now.hour() == 17 && now.minute() == 45 && now.second() == 00  ){
      {
        while(now.hour() == 17 && now.minute() == 45 && now.second() == 00  )
      {
      }
       gun++;
       if(gun == azaltilangun)
       {
        while(gun == azaltilangun)
        {
        }
        gunlukicilen--;
        }
       }
    }
   
}
}
#include <Wire.h>
#include <RTClib.h>
RTC_DS1307 RTC;
int gun;
int icildi;
int alevsensoru = 7;
int alev;
int dumansensoru = A0;
int duman;
int gunlukicilen;
int azaltilangun;
int artandakika=5;
void setup () {
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  pinMode(7, INPUT);
  pinMode(A0, INPUT);
}
void loop () {
  DateTime now = RTC.now();
  alev = digitalRead(7);
  duman = digitalRead(A0);
  if (alev == LOW)
  {
    if (duman > 90)
    {
      while (duman > 90)
      {
        duman = digitalRead(A0);
      }
      icildi++;
      Serial.println(icildi);
    }
    if (icildi <= gunlukicilen)
    {
      //bildirim gonderme
    }
    if (now.hour() == 24 && now.minute() == 00 && now.second() == 00  ) {
      {
        while (now.hour() == 24  && now.minute() == 00 && now.second() == 00  )
        {
        }
        gun++;
        Serial.println(gun);
        if (gun == azaltilangun)
        {
          while (gun == azaltilangun)
          {
          }
          gunlukicilen--;
        }
      }
    }
  }
  else if (alev ==  LOW)
  {
    if (duman > 90)
    {
      while (duman > 90)
      {
        duman = digitalRead(A0);
      }
      icildi++;
      Serial.println(icildi);
    }
     if (icildi <= gunlukicilen)
    {
      //bildirim gonderme
    }
     while(alev == LOW && duman<90 && dakika<baslangıcdakikası)
    {
      dakika++;
      delay(60000);
    }
    ekran.print("icebilirsiniz",0,40);
    if (now.hour() == 24 && now.minute() == 00 && now.second() == 00  ) {
      {
        while (now.hour() == 24  && now.minute() == 00 && now.second() == 00  )
        {
        }
        baslangicdakikası=baslangicdakikası+artandakika;
  }
}
