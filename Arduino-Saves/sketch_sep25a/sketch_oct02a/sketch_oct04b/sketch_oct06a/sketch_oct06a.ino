#include <RTClib.h>
#include <Wire.h>
#include <LCD5110_Basic.h>
RTC_DS1307 RTC;
#define ag_ismi "Tan_Koleji"
#define ag_sifresi "ozkocamantan16"
#define IP "184.106.153.149"    //thingspeak.com IP adresi
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
  Serial.begin(115200); //Seriport'u açıyoruz. Güncellediğimiz
  //ESP modülünün baudRate değeri 115200 olduğu için bizde Seriport'u 115200 şeklinde seçiyoruz

  Serial.println("AT"); //ESP modülümüz ile bağlantı kurulup kurulmadığını kontrol ediyoruz.

  delay(3000); //EPSP ile iletişim için 3 saniye bekliyoruz.

  if (Serial.find("OK")) {       //esp modülü ile bağlantıyı kurabilmişsek modül "AT" komutuna "OK" komutu ile geri dönüş yapıyor.
    Serial.println("AT+CWMODE=1"); //esp modülümüzün WiFi modunu STA şekline getiriyoruz. Bu mod ile modülümüz başka ağlara bağlanabilecek.
    delay(2000);
    String baglantiKomutu = String("AT+CWJAP=\"") + ag_ismi + "\",\"" + ag_sifresi + "\"";
    Serial.println(baglantiKomutu);

    delay(5000);
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
    ekran.print("icilen", 20, 40);
    ekran.printNumI(icildi, 60, 40);
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
      Serial.println("cakmak yakıldı");
      if (duman > 400)
      {
        while (duman > 400)
        {
          duman = analogRead(A0);
        }
        icildi++;
        Serial.println("Sigara icildi");
      }
    }
    else if (icildi > gunlukicilen)
    {
      sicaklik_yolla();
      delay(60000);
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
    ekran.print("icilen", 20, 40);
    ekran.printNumI(icildi, 60, 40);
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
      Serial.println("Cakmak yakıldı");
      if (duman > 400)
      {
        while (duman > 400)
        {
          duman = analogRead(A0);
        }
        icildi++;
        Serial.println("Sigara icildi");
      }
    }
    else if (icildi > gunlukicilen)
    {
      sicaklik_yolla();
      delay(60000);
    }
  }
}
void sicaklik_yolla() {
  Serial.println(String("AT+CIPSTART=\"TCP\",\"") + IP + "\",80");  //thingspeak sunucusuna bağlanmak için bu kodu kullanıyoruz.
  //AT+CIPSTART komutu ile sunucuya bağlanmak için sunucudan izin istiyoruz.
  //TCP burada yapacağımız bağlantı çeşidini gösteriyor. 80 ise bağlanacağımız portu gösteriyor
  delay(1500);
  String tweet = "POST /apps/thingtweet/1/statuses/update HTTP/1.1\n";
  tweet += "Host: api.thingspeak.com\n";
  tweet += "Connection: close\n";
  tweet += "Content-Type: application/x-www-form-urlencoded\n";
  tweet += "Content-Length:50\r\n\r\napi_key=";
  tweet += String("8D9RD53P0RMOZAKR");                           //ThingSpeak'den aldığımız Twitter API KEY'ini buraya yazıyoruz.
  tweet += String("&status=");
  tweet += String("Duzene uyulmadi #esp8266");                         // Yollamak istediğimiz tweeti buraya yazıyoruz.

  Serial.print("AT+CIPSEND=");                    //veri yollayacağımız zaman bu komutu kullanıyoruz. Bu komut ile önce kaç tane karakter yollayacağımızı söylememiz gerekiyor.
  delay(100);
  Serial.println(tweet.length());

  if (Serial.find(">")) {                         //eğer sunucu ile iletişim sağlayıp komut uzunluğunu gönderebilmişsek ESP modülü bize ">" işareti ile geri dönüyor.
    // arduino da ">" işaretini gördüğü anda sıcaklık verisini esp modülü ile thingspeak sunucusuna yolluyor.
    Serial.println(tweet);
    Serial.println("AT+CIPCLOSE=0");
    delay(100);

  }
  else {
    Serial.println("AT+CIPCLOSE=0");
  }
}


