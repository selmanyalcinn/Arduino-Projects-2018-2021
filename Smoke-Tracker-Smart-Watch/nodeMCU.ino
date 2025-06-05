//Projemiz için gerekli olan değişkenler tanımlanıyor ve gerekli kütüphaneler koda ekleniyor
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial s(D6, D5);
#define FIREBASE_HOST "https://nodemcu-14a94-default-rtdb.firebaseio.com/"//Veritabanı ile Nodemcu arasında iletişim sağlanabilmesi için veritabanı linki nodemcuya veriliyor 
#define FIREBASE_AUTH "sV2sqSee9xqvKhSbCPHgT0x8saaLzIzEkgopKhvY"//Veritabanı ile Nodemcu arasında iletişim sağlanabilmesi için veritabanı şifresi nodemcuya veriliyor 
#define WIFI_SSID "LinyitNet_yalcin"//İnternet adı internete bağlanması için nodemcuya veriliyor
#define WIFI_PASSWORD "kamil1616"//İnternet şifresi internete bağlanması için nodemcuya veriliyor
FirebaseData Data;
int gonderilennabizdegeri;
int gonderilensigaradegeri;
int gonderilenhavadegeri;
int gelen;
String gonderilensigaradegeri2;
int rando = 1;
int data;
int gonder;
int icilensigara;
int nabiz;
int hava;
int gun;
int ay = 0;
int ayortalamanabiz;
int aysigarasayisi;
int aydegersigara;
int aysigarakayitsayi;
int yil;
int yildegersigara;
int yilsigarasayisi;
int yilsigarakayitsayi;
int aydegernabiz;
int aynabizsayisi;
int aynabizkayitsayi;
int yildegernabiz;
int yilnabizsayisi;
int yilnabizkayitsayi;

void setup() {
  //Nodemcu internete bağlanıyor
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  //Nodemcu internete bağlandıktan sonra veritabanına bağlanıyor
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  pinMode(14, OUTPUT); //D5 led_pin
  digitalWrite(14, LOW);
  s.begin(9600);
  Serial.begin(9600);
}
void loop() {
  s.write("s");
  if (s.available() > 0)//Arduinodan nabız ortalamaları ve içilen sigara sayıları alınıyor
  {
    if (data == 0) {
      gonder = s.read();
      Serial.println("gonder");
      Serial.println(gonder);
      if (gonder == 1) {
        data = data + 1;
        Serial.println("dataaaaaa");
      }

    }
    if (data == 1) {
      icilensigara = s.read();
      if (icilensigara >= 0) {
        data = data + 1;
        Serial.println("sigara");
        Serial.println(icilensigara);
      }
    }
    if (data == 2) {
      nabiz = s.read();
      if (nabiz >= 0) {
        data = data + 1;
        Serial.println("nabiz");
        Serial.println(nabiz);
      }
    }
    if (data == 3) {
      hava = s.read();
      if (hava >= 0) {
        data = data + 1;
        Serial.println("hava");
        Serial.println(hava);
      }
    }
    if (data == 4) {
      gun = s.read();
      if (gun >= 0) {
        data = data + 1;
        Serial.println("gun");
        Serial.println(gun);
      }
    }
  }
  if (gonder == 1 && data == 5) {
    //Kullanıcının içtiği sigara sayıları veritabanına gönderiliyor
    Firebase.getInt(Data, "gonderilensigaradegeri", gonderilensigaradegeri);
    gonderilensigaradegeri++;
    Firebase.setInt(Data, "Sigaradeger" + String(gonderilensigaradegeri, DEC), icilensigara);
    Firebase.setInt(Data, "gonderilensigaradegeri", gonderilensigaradegeri);
    //Elde edilen nabız ortalamaları veritabanına gönderiliyor
    Firebase.getInt(Data, "gonderilennabizdegeri", gonderilennabizdegeri);
    gonderilennabizdegeri++;
    Serial.println(gonderilennabizdegeri);
    Firebase.setInt(Data, "Nabizdeger" + String(gonderilennabizdegeri, DEC), nabiz);
    Firebase.setInt(Data, "gonderilennabizdegeri", gonderilennabizdegeri);
    if (gonderilensigaradegeri == 30 or gonderilensigaradegeri == 60 or gonderilensigaradegeri == 90 or gonderilensigaradegeri == 120 or gonderilensigaradegeri == 150 or gonderilensigaradegeri == 180 or gonderilensigaradegeri == 210 or gonderilensigaradegeri == 240 or gonderilensigaradegeri == 270 or gonderilensigaradegeri == 300 or gonderilensigaradegeri == 330 or gonderilensigaradegeri == 360)
    {
      for (ay < 31; ay++;) { //İçilen sigara sayıları aylık olarak veritabanına kaydediliyor
        Firebase.getInt(Data, "Sigaradeger" + String(gonderilensigaradegeri - ay, DEC), aydegersigara);
        aysigarasayisi = aydegersigara + aysigarasayisi;
        Firebase.getInt(Data, "KaydedilenAylikDegerSayisi", aysigarakayitsayi);
      }
      if (ay == 30) {
        Firebase.setInt(Data, "AylikİcilenSigaraSayisi" + String(aysigarakayitsayi, DEC), aysigarasayisi);
        ay = 0;
      }
    }
    if (gonderilensigaradegeri == 365 or gonderilensigaradegeri == 730 or gonderilensigaradegeri == 1095 or gonderilensigaradegeri == 1460 or gonderilensigaradegeri == 1865 )
    {
      //İçilen sigara sayılarının beş yıllık kaydı veritabanında oluşturuluyor
      for (yil < 366; yil++;) { //İçilen sigara sayıları aylık olarak veritabanına kaydediliyor
        Firebase.getInt(Data, "Sigaradeger" + String(gonderilensigaradegeri - ay, DEC), yildegersigara);
        yilsigarasayisi = yildegersigara + yilsigarasayisi;
        Firebase.getInt(Data, "KaydedilenYillikDegerSayisi", yilsigarakayitsayi);
      }
      if (yil == 365) {
        Firebase.setInt(Data, "YillikİcilenSigaraSayisi" + String(yilsigarakayitsayi, DEC), yilsigarasayisi);
        yil = 0;
      }
    }
    if (gonderilennabizdegeri == 30 or gonderilennabizdegeri == 60 or gonderilennabizdegeri == 90 or gonderilennabizdegeri == 120 or gonderilennabizdegeri == 150 or gonderilennabizdegeri == 180 or gonderilennabizdegeri == 210 or gonderilennabizdegeri == 240 or gonderilennabizdegeri == 270 or gonderilennabizdegeri == 300 or gonderilennabizdegeri == 330 or gonderilennabizdegeri == 360 )
    {
      for (ay < 31; ay++;) { //Ortalama nabiz değerleri aylık olarak veritabanına kaydediliyor
        Firebase.getInt(Data, "Nabizdeger" + String(gonderilennabizdegeri - ay, DEC), aydegernabiz);
        aynabizsayisi = aydegernabiz + aynabizsayisi;
        Firebase.getInt(Data, "KaydedilenAylikDeger2Sayisi", aynabizkayitsayi);
      }
      if (ay == 30) {
        Firebase.setInt(Data, "AylikOrtalamaNabizSayisi" + String(aynabizkayitsayi, DEC), aynabizsayisi/30);
        ay = 0;
      }
      if (gonderilennabizdegeri == 365 or gonderilennabizdegeri == 730 or gonderilennabizdegeri == 1095 or gonderilennabizdegeri == 1460 or gonderilennabizdegeri == 1865 )
      {
        //Ortalama nabız değerlerinin beş yıllık kaydı veritabanında oluşturuluyor
        for (yil < 366; yil++;) { //İçilen sigara sayıları aylık olarak veritabanına kaydediliyor
          Firebase.getInt(Data, "Nabizdeger" + String(gonderilennabizdegeri - ay, DEC), yildegernabiz);
          yilnabizsayisi = yildegernabiz + yilnabizsayisi;
          Firebase.getInt(Data, "KaydedilenYillikDeger2Sayisi", yilnabizkayitsayi);
        }
        if (yil == 365) {
          Firebase.setInt(Data, "YillikOrtalamaNabizSayisi" + String(yilnabizkayitsayi, DEC), yilnabizsayisi/365);
          yil = 0;
        }
      }
    }
  }
}