#include <RTClib.h>
#include <Wire.h>
#include <LCD5110_Basic.h>
RTC_DS1307 RTC;
LCD5110 ekran(8, 9, 10, 11, 12);
#define ag_ismi "LinyitNet_yalcin"
#define ag_sifresi "kamil1616"
int buton1;
int buton2;
int buton3;
int buton4;
int tiklama;
int tiklama2;
int gunlukicilen;
int azaltilansigara;
int arttirilansure;
int icildi;
boolean clr_tik;
int gun;
int alev;
int duman;
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
void setup() {
  ekran.InitLCD();
  ekran.setContrast(50);
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
   Serial.begin(115200); //Seriport'u açıyoruz. Güncellediğimiz 
                        //ESP modülünün baudRate değeri 115200 olduğu için bizde Seriport'u 115200 şeklinde seçiyoruz
  Serial.println("AT"); //ESP modülümüz ile bağlantı kurulup kurulmadığını kontrol ediyoruz.
  
  delay(3000); //ESP ile iletişim için 3 saniye bekliyoruz.
 
  if(Serial.find("OK")){         //esp modülü ile bağlantıyı kurabilmişsek modül "AT" komutuna "OK" komutu ile geri dönüş yapıyor.
     Serial.println("AT+CWMODE=1"); //esp modülümüzün WiFi modunu STA şekline getiriyoruz. Bu mod ile modülümüz başka ağlara bağlanabilecek.
     delay(2000);
     String baglantiKomutu=String("AT+CWJAP=\"")+ag_ismi+"\",\""+ag_sifresi+"\"";
    Serial.println(baglantiKomutu);
    
     delay(5000);
 }
 
   Serial.print("AT+CIPMUX=1\r\n"); //modülümüzü TCP/UDP bağlantısına sokuyoruz.
   delay(200);
   Serial.print("AT+CIPSERVER=1,80\r\n"); //Sunucumuzu 80 portunda açıyoruz
   delay(1000);
}
void loop() {
  DateTime now = RTC.now();
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
  else if (tiklama == 2)
  {
    tiklama = 0;
  }
  if (tiklama == 0 && tiklama2 == 0)
  {
    ekran.setFont(SmallFont);
    ekran.invertText(true);
    ekran.print(">GunlukIcilen", 0, 8);
    ekran.setFont(SmallFont);
    ekran.printNumI(gunlukicilen, 0, 16);
    ekran.setFont(SmallFont);
    ekran.print(">KacGundeBir", 0, 24);
    ekran.print("Azalsin?", 0, 32);
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
    if (now.hour() == 24 && now.minute() == 00 && now.second() == 00   )
    {
      while (now.hour() == 24 && now.minute() == 00 && now.second() == 00  )
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
  }
  if (alev == LOW)
  {
    if (duman > 150)
    {
      while (duman > 150)
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
        String metin = "<head> <h1>Duzene Uyulmadı</h1> </head>";   // Sunucuya yazdırılacak yazı
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
if (tiklama == 1 && tiklama2 == 0)
{

  ekran.setFont(SmallFont);
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
  Serial.println(duman);
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
  if (now.hour() == 24 && now.minute() == 00 && now.second() == 00  )
  {
    while (now.hour() == 24 && now.minute() == 00 && now.second() == 00  )
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
    if (duman > 150)
    {
      while (duman > 150)
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
}
else if (icildi > gunlukicilen)
{
  if (Serial.available() > 0) { //Eğer gelen veri varsa gir
    if (Serial.find("+IPD,")) { //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
      String metin = "<head> <h1>Duzene Uyulmadı</h1> </head>";   // Sunucuya yazdırılacak yazı
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

