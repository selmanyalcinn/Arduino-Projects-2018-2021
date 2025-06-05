#include <RTClib.h>
#include <Wire.h>
#include <LCD5110_Basic.h>
RTC_DS1307 RTC;
#define ag_ismi "Tan_Koleji"
#define ag_sifresi "ozkocamantan16"
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
int gun;
int alev;
int duman;
int icildi;
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
void setup() {
  ekran.InitLCD();
  ekran.setContrast(55);
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  pinMode(7, INPUT);
  pinMode(A0, INPUT);
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}
void loop() {
  DateTime now = RTC.now();
  alev   = digitalRead(7);
  duman  = analogRead(A0);
  buton1 = digitalRead(5);
  buton2 = digitalRead(3);
  buton3 = digitalRead(4);
  if (buton1 == HIGH)
  {
    while (buton1 == HIGH)
    {
      buton1 = digitalRead(5);
    }
    tiklama++;
    clr_tik = 1;
    Serial.println(tiklama);
  }
  if (clr_tik == 1) {
    clr_tik = 0;
    ekran.clrScr();
  }
  if (tiklama == 2)
  {
    tiklama = 0;
  }
  if (tiklama == 0 && tiklama2 == 0)
  {
    ekran.setFont(SmallFont);
    ekran.printNumI(now.hour(), 0, 0);
    ekran.print(":", 12, 0);
    ekran.printNumI(now.minute(), 15, 0);
    ekran.invertText(true);
    ekran.print(">GunlukIcilen", 0, 8);
    ekran.setFont(SmallFont);
    ekran.invertText(false);
    ekran.printNumI(gunlukicilen, 0, 16);
    ekran.setFont(SmallFont);
    ekran.print("KacGundeBir", 0, 24);
    ekran.print("Azalsin", 0, 32);
    ekran.setFont(SmallFont);
    ekran.printNumI(azaltilansigara, 0, 40);
    Serial.println(alev);
    Serial.println(duman);
    Serial.println(icildi);
    if (buton2 == HIGH)
    {
      while (buton2 == HIGH)
      {
        buton2 = digitalRead(3);
      }
      gunlukicilen++;
      ekran.clrScr();
    }
    else if (buton3 == HIGH)
    {
      while (buton3 == HIGH)
      {
        buton3 = digitalRead(4);
      }
      gunlukicilen--;
      ekran.clrScr();
    }
    else if (now.hour() == 24 && now.minute() == 00 && now.second() == 0  )
    {
      while (now.hour() == 24 && now.minute() == 00 && now.second() == 0  )
      {
      }
      gun++;
      if (gun == azaltilansigara)
      {
        while (gun == azaltilansigara)
        {
        }
        gunlukicilen--;
      }
    }
    if (alev == LOW)
    {
      if (duman > 90)
      {
        while (duman > 90)
        {
          duman = analogRead(A0);
        }
        icildi++;
      }
    }
    if (icildi <= gunlukicilen)
    {
      if (Serial.available() > 0) { //Eğer gelen veri varsa gir
        if (Serial.find("+IPD,")) { //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
          String metin = "<head> <h1>Duzene Uyuldu</h1> </head>";   // Sunucuya yazdırılacak yazı
          String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
          yollanacak_komut += "0";
          yollanacak_komut += ",";
          yollanacak_komut += metin.length(); //yollayacağımız yazının uzunluğunu belirliyor.
          yollanacak_komut += "\r\n";
          Serial.print(yollanacak_komut);
          delay(500);
          Serial.println(metin);
          delay(1000);
          Serial.println("AT+CIPCLOSE=0"); //Server'ı kapatıyoruz.
        }
      }
    }
    else if (icildi > gunlukicilen)
    {
      if (Serial.available() > 0) { //Eğer gelen veri varsa gir
        if (Serial.find("+IPD,")) { //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
          String metin = "<head> <h1>Duzene Uyulmadi</h1> </head>";   // Sunucuya yazdırılacak yazı
          String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
          yollanacak_komut += "0";
          yollanacak_komut += ",";
          yollanacak_komut += metin.length(); //yollayacağımız yazının uzunluğunu belirliyor.
          yollanacak_komut += "\r\n";
          Serial.print(yollanacak_komut);
          delay(500);
          Serial.println(metin);
          delay(1000);
          Serial.println("AT+CIPCLOSE=0"); //Server'ı kapatıyoruz.
        }
      }
    }
  }
  if (tiklama == 1 && tiklama2 == 0)
  {
    ekran.setFont(SmallFont);
    ekran.printNumI(now.hour(), 0, 0);
    ekran.print(":", 12, 0);
    ekran.printNumI(now.minute(), 15, 0);
    ekran.invertText(false);
    ekran.print(">GunlukIcilen", 0, 8);
    ekran.setFont(SmallFont);
    ekran.printNumI(gunlukicilen, 0, 16);
    ekran.setFont(SmallFont);
    ekran.invertText(true);
    ekran.print("KacGundeBir", 0, 24);
    ekran.print("Azalsin", 0, 32);
    ekran.setFont(SmallFont);
    ekran.invertText(false);
    ekran.printNumI(azaltilansigara, 0, 40);
    Serial.println(alev);
    Serial.println(duman);
    Serial.println(icildi);
    if (buton2 == HIGH)
    {
      while (buton2 == HIGH)
      {
        buton2 = digitalRead(3);
      }
      azaltilansigara++;
      ekran.clrScr();
    }
    else if (buton3 == HIGH)
    {
      while (buton3 == HIGH)
      {
        buton3 = digitalRead(4);
      }
      azaltilansigara--;
      ekran.clrScr();
    }
    if (now.hour() == 24 && now.minute() == 00 && now.second() == 0  )
    {
      while (now.hour() == 24 && now.minute() == 00 && now.second() == 0 )
      {
      }
      gun++;
      if (gun == azaltilansigara)
      {
        while (gun == azaltilansigara)
        {
        }
        gunlukicilen--;
      }
    }
    if (alev == LOW)
    {
      if (duman > 90)
      {
        while (duman > 90)
        {
          duman = analogRead(A0);
        }
        icildi++;
      }
    }
    if (icildi <= gunlukicilen)
    {
      if (Serial.available() > 0) { //Eğer gelen veri varsa gir
        if (Serial.find("+IPD,")) { //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
          String metin = "<head> <h1>Duzene Uyuldu</h1> </head>";   // Sunucuya yazdırılacak yazı
          String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
          yollanacak_komut += "0";
          yollanacak_komut += ",";
          yollanacak_komut += metin.length(); //yollayacağımız yazının uzunluğunu belirliyor.
          yollanacak_komut += "\r\n";
          Serial.print(yollanacak_komut);
          delay(500);
          Serial.println(metin);
          delay(1000);
          Serial.println("AT+CIPCLOSE=0"); //Server'ı kapatıyoruz.
        }
      }
    }
    else if (icildi > gunlukicilen)
    {
      if (Serial.available() > 0) { //Eğer gelen veri varsa gir
        if (Serial.find("+IPD,")) { //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
          String metin = "<head> <h1>Duzene Uyulmadi</h1> </head>";   // Sunucuya yazdırılacak yazı
          String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
          yollanacak_komut += "0";
          yollanacak_komut += ",";
          yollanacak_komut += metin.length(); //yollayacağımız yazının uzunluğunu belirliyor.
          yollanacak_komut += "\r\n";
          Serial.print(yollanacak_komut);
          delay(500);
          Serial.println(metin);
          delay(1000);
          Serial.println("AT+CIPCLOSE=0"); //Server'ı kapatıyoruz.
        }
      }
    }
  }
}



