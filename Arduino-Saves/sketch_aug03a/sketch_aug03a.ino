#include <RTClib.h> // saat modülü kütüphanesini ekliyoruz
#include <Wire.h> //saat modülü için wire kütüphanesini ekliyoruz
#include <LCD5110_Basic.h> //ekran kütüphanesini ekliyoruz
RTC_DS1307 RTC; //saat modülünün çalışması için gerekli kod
LCD5110 ekran(8, 9, 10, 11, 12); //ekranın pin bağlantıları
#define ag_ismi "NetMASTER Uydunet-6218" //wireless modülğn çalışması için ağ adını girme komutu
#define ag_sifresi "c4739eb4" //wireless modülün bağlanması için ağ şifr4esini girme komutu
int buton1; //buton tanımlaması
int buton2;//buton tanımlaması
int buton3;//buton tanımlaması
int buton4;//buton tanımlaması
int tiklama;//ekranın stabil olarak çalışması için arttırılıp azaltılan değişkenin tanımlanması
int tiklama2;
int gunlukicilen;//kişini kaç tane içtiğini girdiği değişken
int azaltilansigara;//kişinin kaç günde bir içtiği değerin azalmasını istediğinin girildiği değişken
int arttirilansure;
int icildi;//gün boyunca kişinin içitği sigara sayısının kaydedildiği değişken
boolean clr_tik;//ekranın stabil çalışması için arttırılıp azaltılan değişken
int gun;//geçen gün sayısı( kullanıcının kaç günde bir azaltılmasını istediğini girdiği zaman günü sayıp ona göre azaltmak için)
int alev;//çakmak alevi algılanırsa algılandığının bilgisinin kaydedildiği değişken
int duman;//duman algılanırsa duman düzeyinin girildiği değişken
extern uint8_t SmallFont[];//ekranda kullanılacak yazı tipleri
extern uint8_t MediumNumbers[];//ekranda kullanılacak yazı tipleri
extern uint8_t BigNumbers[];//ekranda kullanılacak yazı tipleri
void setup() {
  ekran.InitLCD();//ekranı başlatma kodu
  ekran.setContrast(50);//ekran parlaklığını ayarlıyoruz
  Wire.begin();//wire kütüphanesini başlatıyoruz saat modülü için
  RTC.begin();//saat modülü için rtc kütüphanesini başlatıyorum
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
  DateTime now = RTC.now();//saat modülün saatini başlatıyoruz
  buton1 = digitalRead(5);//butonların pin bağlantıları
  buton2 = digitalRead(3);//butonların pin bağlantıları
  buton3 = digitalRead(4);//butonların pin bağlantıları
  if (buton1 == HIGH)           //eğer buton 1 e basılırsa tıklama değişkenini bir arttır ve clr_tik değişkenini bir yap
  {
    while (buton1 == HIGH)
    {
      buton1 = digitalRead(5);
    }                            
    tiklama++;
    clr_tik = 1;
    Serial.println(tiklama);
  }
  if (clr_tik == 1) {//eğer clr_tik değişkeni bir olursa ekranı temizle ve clr_tik değişkenini 0 yap
    clr_tik = 0;
    ekran.clrScr();
  }
  else if (tiklama == 2)//eğer tıklama 2 olursa tekrar başa dönmek için tıklama değişkenini 0 yap
  {
    tiklama = 0;
  }
  if (tiklama == 0 && tiklama2 == 0)//tıklama  ve tıklama2 değişkenleri 0 ise koyu renkle "GunlukIcilen" yazıp seçildiğini belirt ve arttırıp azalt değişkenlerine basıldığı zaman gunlukicilen değişkenine kaydet ve değişkenin değerini ekranda yaz    
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
    if (buton2 == HIGH)//eğer ikinci butona basılı ise gunlukicilen değişkenini 1 arttır
    {
      while (buton2 == HIGH)
      {
        buton2 = digitalRead(3);
      }
      gunlukicilen++;
    }
    else if (buton3 == HIGH)//eğer buton 3 e basılırsa günlük içileni bir eksilt
    {
      while (buton3 == HIGH)
      {
        buton3 = digitalRead(4);
      }
      gunlukicilen--;
    }
    if (now.hour() == 24 && now.minute() == 00 && now.second() == 00   )//eğer saat dakika ve saniye 24 00 00 eşit olursa gün değişkenini bir arttır
    {
      while (now.hour() == 24 && now.minute() == 00 && now.second() == 00  )
      {
      }
      gun++;
      if (gun == azaltilansigara)//eğer gün değişkeni kişinin girdiği kaç günde bir azalsın değişkenine eşitse kişinin içtiği günlük sigara sayısını azalt
      {
        while (gun == azaltilansigara)
        {
        }
        gunlukicilen--;
      }
    }
  }
  if (alev == LOW)//eğer çakmak ateşi algılandıktan sonra duman da gelirse o gün içinde kişinin içtiği sigara sayısının kaydedildiği değişkeni bir arttır
  {
    if (duman > 150)
    {
      while (duman > 150)
      {
        duman = analogRead(A0);
      }
      icildi++;
    }
    if (icildi <= gunlukicilen)//eğer kişinin o gün içinde içtiği sigara sayısı ilk başta girdiği günlük içilen değişkeninde azsa sunucuya Duzene uyuldu bilgisini gönder
    {
    if(Serial.available()>0){  //Eğer gelen veri varsa gir
    if(Serial.find("+IPD,")){  //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
      String metin = "<head> <h1>Merhaba Dunya</h1> </head>";   // Sunucuya yazdırılacak yazı
      String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
      yollanacak_komut +="0";
      yollanacak_komut +=",";
      yollanacak_komut += metin.length(); //yollayacağımız yazının uzunluğunu belirliyor.
      yollanacak_komut += "\r\n";
      Serial.print(yollanacak_komut);
      delay(500);
      Serial.println(metin);
      delay(1000);
      Serial.println("AT+CIPCLOSE=0"); //Server'ı kapatıyoruz.
    }
    else if (icildi > gunlukicilen)
    {
      if(Serial.available()>0){  //Eğer gelen veri varsa gir
    if(Serial.find("+IPD,")){  //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
      String metin = "<head> <h1>Merhaba Dunya</h1> </head>";   // Sunucuya yazdırılacak yazı
      String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
      yollanacak_komut +="0";
      yollanacak_komut +=",";
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
      if (icildi <= gunlukicilen)
      {
        if(Serial.available()>0){  //Eğer gelen veri varsa gir
    if(Serial.find("+IPD,")){  //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
      String metin = "<head> <h1>Merhaba Dunya</h1> </head>";   // Sunucuya yazdırılacak yazı
      String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
      yollanacak_komut +="0";
      yollanacak_komut +=",";
      yollanacak_komut += metin.length(); //yollayacağımız yazının uzunluğunu belirliyor.
      yollanacak_komut += "\r\n";
      Serial.print(yollanacak_komut);
      delay(500);
      Serial.println(metin);
      delay(1000);
      Serial.println("AT+CIPCLOSE=0"); //Server'ı kapatıyoruz.
      }
      else if (icildi > gunlukicilen)
      {
        if(Serial.available()>0){  //Eğer gelen veri varsa gir
    if(Serial.find("+IPD,")){  //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
      String metin = "<head> <h1>Merhaba Dunya</h1> </head>";   // Sunucuya yazdırılacak yazı
      String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
      yollanacak_komut +="0";
      yollanacak_komut +=",";
      yollanacak_komut += metin.length(); //yollayacağımız yazının uzunluğunu belirliyor.
      yollanacak_komut += "\r\n";
      Serial.print(yollanacak_komut);
      delay(500);
      Serial.println(metin);
      delay(1000);
      Serial.println("AT+CIPCLOSE=0"); //Server'ı kapatıyoruz.
      }
    }
    if (duman > 150)
    {
      while (duman > 150)
      {
        duman = analogRead(A0);
      }
      icildi++;
    }
    if (icildi <= gunlukicilen)
    {
      if(Serial.available()>0){  //Eğer gelen veri varsa gir
    if(Serial.find("+IPD,")){  //Gelen verinin içerisinde "+IPD" komutu geçiyorsa gir
      String metin = "<head> <h1>Merhaba Dunya</h1> </head>";   // Sunucuya yazdırılacak yazı
      String yollanacak_komut = "AT+CIPSEND=";  //yollayacağımız komutun boyutunu söylediğimiz kısım.
      yollanacak_komut +="0";
      yollanacak_komut +=",";
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
      // bilgi gonder
    }
    else if (tiklama2 == 2)
    {
      tiklama2 = 0;
    }

  }
}


