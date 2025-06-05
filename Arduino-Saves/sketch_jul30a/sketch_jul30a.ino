#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
int gun;
int GunlukIcilen=10;
int saat;
int dakika;
int saniye;
void setup () {
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}
void loop () {
  DateTime now = RTC.now();
  saat = now.hour();
  dakika = now.minute();
  saniye = now.second();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
  if (saat == 24 && dakika == 00 && saniye == 00)
  {
    while (saat == 24 && dakika == 00 && saniye == 00)
    {
      saat = now.hour();
      dakika = now.minute();
      saniye = now.second();
    }
    gun++;
    Serial.println(gun);
    delay(200);
  }
  if(gun == 1)
  {
   GunlukIcilen--;
   Serial.println(GunlukIcilen);
   delay(200);
   while(1){}
   }  
  }

