//Ekranın bağlantıları arduinoya tanıtılıyor ve bazı kütüphaneler projeye ekleniyor.
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#if defined(ARDUINO_FEATHER_ESP32)
#define TFT_CS         14
#define TFT_RST        15
#define TFT_DC         32

#elif defined(ESP8266)
#define TFT_CS         4
#define TFT_RST        16
#define TFT_DC         5

#else
#define TFT_CS        10
#define TFT_RST        8
#define TFT_DC         9
#endif
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
//Projemizde ihtiyaç duyulan dğişkenler tanımlanıyor ve gerekli kütüphaneler projeye ekleniyor
#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial s(5, 6);
int zaman;
int gun;
unsigned char nabizortalamasi;
int a;
unsigned char c2(DEC);
unsigned char nabiz(DEC);
int b;
float p = 3.1415926;
int gonder = 0;
int yon = 0;
int yon2 = 0;
int buton1;
int buton2;
int buton3;
int onay = 0;
int icilensigara;
int gunlukicilensigara;
int azaltilacagigun;
int kritik;
int gunx = 0;
int data;
int hava;
int sayac;
int sigaratespit;
int duman;
int guntimer;
void setup() {
  s.begin(9600);//Arduino ile NodeMCU arasında seri haberleşme açılıyor
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
  Wire.begin();
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);//Ekran yataya getirilerek daha rahat bir kullanım sağlanıyor
}

void loop() {
  buton1 = digitalRead(2);//Butonlardan gelen sinyal okunuyor
  buton2 = digitalRead(3);
  buton3 = digitalRead(4);

  if (buton1 == 1) {//Buton kullanılarak kullanıcının ana menüde gezinmesi sağlanıyor
    while (buton1 == 1) {
      buton1 = digitalRead(2);
    }
    if (onay == 0) {
      yon = yon + 1;
    }
    if (onay == 1) {
      yon2 = yon2 + 1;
    }
  }
  if (buton2 == 1) {//Buton kullanılarak kullanıcının seçtiği sayfanın açılması sağlanıyor
    while (buton2 == 1) {
      buton2 = digitalRead(3);
    }
    onay = onay + 1;
  }

  if (buton3 == 1) {//Buton kullanılarak kullanıcının girilmesi istenilen değerleri girmesi sağlanıyor
    while (buton3 == 1) {
      sayac = sayac + 1;
      delay(100);
      buton3 = digitalRead(4);
    }
    if (sayac < 10 && yon == 2 && onay == 1 && yon2 == 0) {
      gunlukicilensigara = gunlukicilensigara + 1;
    }
    if (sayac >= 10 && yon == 2 && onay == 1 && yon2 == 0) {
      gunlukicilensigara = gunlukicilensigara - 1;
    }
    if (sayac < 10 && yon2 == 2) {
      azaltilacagigun = azaltilacagigun + 1;
    }
    if (sayac >= 10 && yon2 == 2) {
      azaltilacagigun = azaltilacagigun - 1;
    }
    kritik = kritik + 1;
    sayac = 0;
  }

  if (yon == 0 && onay == 0) {//Ana menüde gezinirken "Bagimlilik" sayfasının seçili olduğu gösteriliyor.
    tft.fillScreen(ST77XX_WHITE);
    tft.setCursor(5, 17);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println("> Bagimlilik");
    tft.drawLine(0, 42, 500, 42, ST7735_BLACK);
    tft.drawLine(0, 43, 500, 43, ST7735_BLACK);
    tft.setCursor(5, 57);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println("Kalp Saglik");
    tft.drawLine(0, 82, 500, 82, ST7735_BLACK);
    tft.drawLine(0, 83, 500, 83, ST7735_BLACK);
    tft.setCursor(5, 97);
    yon = yon + 1;//Arduinonun aynı yazıları sürekli yazmasını engellemek ve ekranda gidip gelen bir görüntü oluşmasını engellemek için bu satırdaki kod yardımıyla "Eğer" durumundan çıkılıyor.

  }
  if (yon == 2 && onay == 0) {//Ana menüde gezinirken "Kalp Sagligi" sayfasının seçili olduğu gösteriliyor.
    tft.fillScreen(ST77XX_WHITE);
    tft.setCursor(5, 17);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println("Bagimlilik");
    tft.drawLine(0, 42, 500, 42, ST7735_BLACK);
    tft.drawLine(0, 43, 500, 43, ST7735_BLACK);
    tft.setCursor(0, 57);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println("> Kalp Saglik");
    tft.drawLine(0, 82, 500, 82, ST7735_BLACK);
    tft.drawLine(0, 83, 500, 83, ST7735_BLACK);
    tft.setCursor(5, 97);
    yon = yon + 1;//Arduinonun aynı yazıları sürekli yazmasını engellemek ve ekranda gidip gelen bir görüntü oluşmasını engellemek için bu satırdaki kod yardımıyla "Eğer" durumundan çıkılıyor.
  }
  if (yon > 5) {
    yon = 0;
  }
  if (onay > 1) {
    onay = 0;
  }
  if (kritik > 1) {
    kritik = 0;
  }
  if (yon2 > 2) {
    yon = 1;
    yon2 = 0;
  }
  if (yon == 1 && onay == 1) {//Bu satırda eğer menüde "Bagimlilik" sayfası seçilip sayfa açma butonuna basılırsa "Bagimlilik" ekranına geçiliyor ve ekranda da "Bagimlilik" sayfasına ait yazılar yazıyor.
    tft.fillScreen(ST77XX_WHITE);
    tft.setCursor(5, 5);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println("> Bagimlilik");
    tft.drawLine(0, 25, 500, 25, ST7735_BLACK);
    tft.drawLine(0, 26, 500, 26, ST7735_BLACK);
    tft.setCursor(2, 40);
    tft.println("Bugun Icilen:");
    tft.setCursor(2, 57);
    tft.println(icilensigara);
    tft.setCursor(2, 75);
    tft.println("Gunluk Icilen");
    tft.setCursor(2, 93);
    tft.println("Sigara :");
    tft.setCursor(130, 93);
    tft.print("+");
    yon = yon + 1;//Arduinonun aynı yazıları sürekli yazmasını engellemek ve ekranda gidip gelen bir görüntü oluşmasını engellemek için bu satırdaki kod yardımıyla "Eğer" durumundan çıkılıyor.
  }
  if (yon == 1 && onay == 1 && kritik == 0 && yon2 == 0 or yon == 2 && onay == 1 && kritik == 0 && yon2 == 0) {//Kullanıcıdan girmesi istenilen değerler ekrana yazılıyor.
    tft.setTextColor(ST77XX_WHITE);//Girilen değerler bir siyah bir beyaz yazılarak silinip tekrar yazılıyor ve bu şekilde değerlerin güncellenmesi sağlanıyor
    tft.setCursor(100, 93);
    tft.print(gunlukicilensigara - 1);
    tft.setCursor(100, 93);
    tft.print(gunlukicilensigara + 1);
    tft.setTextColor(ST77XX_BLACK);
    tft.setCursor(100, 93);
    tft.print(gunlukicilensigara);//Günlük içtiği sigara sayısını kullanıcı butonlar yardımıyla akıllı saate giriyor ve bu değerler ekrana yazdırılarak kullanıcının girdiği değerleri ekranda görmesi sağlanıyor.
    kritik = kritik + 1;//Arduinonun aynı yazıları sürekli yazmasını engellemek ve ekranda gidip gelen bir görüntü oluşmasını engellemek için bu satırdaki kod yardımıyla "Eğer" durumundan çıkılıyor.

  }
  if (yon2 == 1 && onay == 1) {//"Bagimlilik" sayfasının geri kalan kısımlarını da görmek için aşağı inme tuşuna basıldığında ekrana sayfanın geri kalan kısımları yazılıyor
    tft.fillScreen(ST77XX_WHITE);
    tft.setCursor(2, 5);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println("Bugun Icilen:");
    tft.setCursor(2, 22);
    tft.println(icilensigara);
    tft.setCursor(2, 40);
    tft.println("Gunluk Icilen");
    tft.setCursor(2, 58);
    tft.println("Sigara :");
    tft.setCursor(95, 95);
    tft.print("+");
    tft.setCursor(2, 80);
    tft.println("Azaltilacagi Gun :");
    yon2 = yon2 + 1;//Arduinonun aynı yazıları sürekli yazmasını engellemek ve ekranda gidip gelen bir görüntü oluşmasını engellemek için bu satırdaki kod yardımıyla "Eğer" durumundan çıkılıyor.

  }
  if ( yon2 == 2 && onay == 1 && kritik == 0) { //Kullanıcıdan girmesi istenilen değerler ekrana yazılıyor
    tft.setTextColor(ST77XX_WHITE);//Girilen değerler bir siyah bir beyaz yazılarak silinip tekrar yazılıyor ve bu şekilde değerlerin güncellenmesi sağlanıyor
    tft.setCursor(70, 95);
    tft.print(azaltilacagigun - 1);
    tft.setCursor(70, 95);
    tft.print(azaltilacagigun + 1);
    tft.setTextColor(ST77XX_BLACK);
    tft.setCursor(70, 95);
    tft.print(azaltilacagigun);//Günlük içtiği sigara sayısının kaç günde bir azalmasını istediğini kullanıcı akıllı saate giriyor ve bu değer ekrana yazıyor
    kritik = kritik + 1; //Arduinonun aynı yazıları sürekli yazmasını engellemek ve ekranda gidip gelen bir görüntü oluşmasını engellemek için bu satırdaki kod yardımıyla "Eğer" durumundan çıkılıyor.
  }
  //Kalp SagliK Ekran
  if (yon == 3 && onay == 1) { //Bu satırda eğer menüde "Kalp Saglik" sayfası seçilip sayfa açma butonuna basılırsa "Kalp Saglik" ekranına geçiliyor ve ekranda da "Kalp Saglik" sayfasına ait yazılar yazıyor.
    tft.fillScreen(ST77XX_WHITE);
    tft.setCursor(2, 5);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println("> Kalp Saglik");
    tft.drawLine(0, 25, 500, 25, ST7735_BLACK);
    tft.drawLine(0, 26, 500, 26, ST7735_BLACK);
    tft.setCursor(2, 40);
    tft.println("Nabziniz:");
    yon = yon + 1; //Arduinonun aynı yazıları sürekli yazmasını engellemek ve ekranda gidip gelen bir görüntü oluşmasını engellemek için bu satırdaki kod yardımıyla "Eğer" durumundan çıkılıyor.
  }
  if (yon == 3 && onay == 1 or yon == 4 && onay == 1) { //Nabız sensöründen gelen değerler ekrana yazdırılıyor
    tft.setTextColor(ST77XX_WHITE); // Nabız sensöründen gelen değerler bir siyah bir beyaz yapılarak silinip tekrar yazılıyor bu şekilde nabız değerleri gücelleniyor
    tft.setCursor(110, 40);
    tft.println(nabiz);
    tft.setTextColor(ST77XX_BLACK);
    tft.setCursor(110, 40);
    tft.println(nabiz);
  }
  duman = analogRead(A0);//Duman sensöründen değerler okunuyor
  if (duman >= 150) { //Duman sensöründen gelen değerler eğer 150'nin üzerine çıkarsa
    Serial.println("duman");
    if (nabiz >= 85) { // Ve nabız değerleri 85'in üzerine çıkarsa ekrana sigara içildi yazılıyor ve sigara içildiği algılanıyor
      Serial.println("Sigara İcildi");
      sigaratespit = 1;
    }
  }

  if (duman <= 150 && nabiz <= 85 && sigaratespit == 1) { //Sigara içildiği algılandıktan sonra eğer sigara dumanı yoksa ve nabız değerleri de normale dönmüşse sigaranın bittiği algılanıyor icilensigara değişkeni bir arttırılıyor böylece gün içinde içtiğiniz sigara sayısı takip ediliyor.
    icilensigara = icilensigara + 1;
    Serial.println(icilensigara);

  }
  Wire.requestFrom(0xA0 >> 1, 1);    // Bu satırda nabız sensörüden veri isteniyor
  while (Wire.available()) {
    nabiz = Wire.read();                //Nabız sensöründen gelen veriler okunuyor
    Serial.println(nabiz);
    if (a == 0) {                  //Nabız sensöründen gelen ilk değer kaydediliyor
      c2 = nabiz;
      a = a + 1;
    }
    if (a == 1) {       //Nabız sensöründen gelen ikinci değer de kaydedilip ilk değerle ortalaması alınıyor
      if (b == 0) {
        nabizortalamasi = (c2 + nabiz) / 2;
        b = b + 1;
      }
      if (b == 1) {  //Son olarak da ilk iki değerin ortalaması ile daha sonra gelen nabız değerlerinin ortalaması alınarak tüm değerlerin ortalaması bulunuyor
        nabizortalamasi = (nabizortalamasi + nabiz) / 2;
        Serial.println(nabizortalamasi);
      }
    }
  }
  delay(1);
  guntimer = guntimer + 1;//Her bir milisaniyede bir guntimer değişkeni bir arttırılıyor ve 86400000'a eşit olduğunda sayaç ve içilensigara sıfırlanıyor ve günlük nabız ortlaması ile günşül içilen sigara sayısı veritabanına gönderilmek üzere seri haberleşme ile NodeMCU'ya gönderiliyor.
  if (guntimer == 86400000) {
  if (s.available() > 0)
  {
    if (data == 0) {
      s.write(gonder);
      data = data + 1;
    }
    if (data == 1) {
      s.write(icilensigara);
      data = data + 1;
    }
    if (data == 2) {
      s.write(nabizortalamasi);
      data = data + 1;

    }
    guntimer = 0;
    icilensigara=0;
  }
  Serial.println(azaltilacagigun);
}