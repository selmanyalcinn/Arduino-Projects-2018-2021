#include <RTClib.h>//saat modülü kütüphanesini dahil ediyoruz.
#include <Wire.h>//saat modülünün çalışması için wire kütüphanesini dahil ediyoruz.
#include <LCD5110_Basic.h>//5110 lcd'sinin çalışması için gerekli kodu dahil ediyoruz.
RTC_DS1307 RTC;//saat modülü başlangıç kodu.
#define ag_ismi "Tan_Koleji"//esp 8266 wi-fi modülünün tweet atabilmesi için internet ağının adını giriyoruz.
#define ag_sifresi "ozkocamantan16"//esp 8266 wi-fi modülünün tweet atabilmesi için internet ağının şifresini giriyoruz.
#define IP "184.106.153.149" //esp 8266 wifi modülünün thingspeak sitesiine erişip tweet atabilmesi için ıp adresini giriyoruz sitenin.   
LCD5110 ekran(8, 9, 10, 11, 12);//5110 lcd ekranın pin bağlantılarını giriyoruz.
int buton1;//1.butonu tanımlıyoruz.
int buton2;//2.butonu tanımlıyoruz.
int buton3;//3.butonu tanımlıyoruz.
int tiklama;//ekranda menünün çalışması için arttırılıp azaltılan değişkeni tanımlıyoruz.
int tiklama2;//ekranda menünün çalışması için arttırılıp azaltılan değişkeni tanımlıyoruz.
int gunlukicilen;//kişinin günde içitiği sigara sayısını girdiği değişkeni tanımlıyoruz.
int azaltilansigara;//kaç günde bir günlük içilen değerinin azalmasını istediğimizi girdiğimiz değişkeni tanımlıyoruz.
boolean clr_tik; //ekrandaki yazıları temizlemek için arttırlıp azaltılann değişkeni tanımlıyoruz.
int gun;//bir gün geçince arttırılıp "kaç günde bir azalsın"a eşit olduğunda "günlük içilen"değerini azaltmaya yarayan değişkeni tanımlıyoruz.
int alev;//alev sensöründen gelen verilerin kaydedildiği değişkeni tanımlıyoruz.
int duman;//duman sensöründen gelen verilerin kaydedildği değişkeni tanımlıyoruz.
int icildi;//o gün içinde içilen sigara sayısının kaydedildiği değişkeni tanımlıyoruz.
extern uint8_t SmallFont[];//lcd ekranın yazı fontlarını tanımlıyoruz.
extern uint8_t MediumNumbers[];//lcd ekranın yazı fontlarını tanımlıyoruz.
extern uint8_t BigNumbers[];//lcd ekranın yazı fontlarını tanımlıyoruz.
void setup() {
  ekran.InitLCD();//ekranı başlatma kodunu giriyoruz.
  ekran.setContrast(55);//ekranın parlaklığını ayarlıyoruz.
  Serial.begin(9600);//seri portu açıyoruz.
  Wire.begin();//saat modülünün çalışması için wire kütüphanesini başlatıyoruz.
  RTC.begin(); //saat modülünün çalışması için rtc kütüphanesini başlatıyoruz.
  pinMode(7, INPUT);//7. pini giriş yapıyoruz
  pinMode(A0, INPUT);//analog sıfır pinini giriş yapıyoruz
  if (! RTC.isrunning()) {  //saat modülünün çalışıp çalışmadığını kontrol ediyoruz
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
  DateTime now = RTC.now();//saat modülündeki saati ayarlıyoruz.
  alev   = digitalRead(7);//7.pini alev sensörüne veriyoruz
  duman  = analogRead(A0);//analog sıfır pinini duman sensörüne veriyoruz
  buton1 = digitalRead(5);//1.butonu 5.pine veriyoruz
  buton2 = digitalRead(3);//2.butonu 3.pine veriyoruz
  buton3 = digitalRead(4);//3.butonu 4.pine veriyoruz.
  if (buton1 == HIGH)//eğer 1.butona basılırsa
  {
    while (buton1 == HIGH)//basıldığı süre boyunca bekle(basılınca sürekli arttırmaması için)
    {
      buton1 = digitalRead(5);
    }
    tiklama++;//elimizi butondan çekince tıklama değişkenini arttır.
    clr_tik = 1;//clr_tik değişkenini 1 yap
    Serial.println(tiklama);
  }
  if (clr_tik == 1) { //eğer clr_tik 1 olursa clr_tik değişkenini sıfır yap ve ekranı temizle(böylece her yeni değeri seçtiğimizde ekran temizlenmiş olacak ve yazılar doğru okunacak.)
    clr_tik = 0;
    ekran.clrScr();//ekranı temizleme kodu
  }
  if (tiklama == 2)//eğer tıklama 2 olursa tıklamayı 0 yap(iki değer arasında seçim yaparken son değeri seçtikten sonra tekrar tıklayınca tekrar ilk değere dönmek için)
  {
    tiklama = 0;
  }
  if (tiklama == 0 && tiklama2 == 0)//eğer tiklama ve tiklama2 değişkeni 0'a eşitse
  {
    ekran.setFont(SmallFont);//yazı tipini smallfont yap.
    ekran.printNumI(now.hour(), 0, 0);//ekranda saati yazdır.
    ekran.print(":", 12, 0);//saat ile dakika arasına iki nokta koy.
    ekran.printNumI(now.minute(), 15, 0);//ekranda dakikayı yazdır
    ekran.invertText(true);//"GunlukIcılen"değerinin seçili olduğunu belli etmek için siyahla yazma komutu.
    ekran.print(">GunlukIcilen", 0, 8);//ekrana "GunlukIcılen" yaz.
    ekran.invertText(false);//yazı rengini siyahtan normale getir
    ekran.printNumI(gunlukicilen, 0, 16);//"GunlukIıcılen"e girdiğimiz değeri ekranda yaz.
    ekran.print("KacGundeBir", 0, 24);//ekrana "KacGundeBırAzalsın"yaz.
    ekran.print("Azalsin", 0, 32);
    ekran.printNumI(azaltilansigara, 0, 40);//"KacGundeBırAzalsın"a girdiğimiz değeri yaz ekranda.
    ekran.print("icilen", 20, 40);//ekrana "icilen" yaz.
    ekran.printNumI(icildi, 60, 40);//"icilen" yazısının yanına kişinin  o gün içinde kaç tane sigara içtiğini görmesi için içtiği sigara sayısını yaz.
    if (buton2 == HIGH)//eğer 2.butona basılırsa
    {
      while (buton2 == HIGH)//değerin sürekli artmaması için basıldığı süre boyunca bekle.
      {
        buton2 = digitalRead(3);
      }
      gunlukicilen++;//kullanıcı butondan elini çektiğinde "GunlukIcılen"değerini bir arttır.
      ekran.clrScr();//değerin doğru gözükmesi için ekrandaki yazıları temizle.
    }
    else if (buton3 == HIGH)//eğer 3.butona basılırsa
    {
      while (buton3 == HIGH)//değerin sürekli artmaması için basıldığı süre boyunca bekle.
      {
        buton3 = digitalRead(4);
      }
      gunlukicilen--;//kullanıcı butondan elini çektiğinde "GunlukIcılen"değerini bir azalt.
      ekran.clrScr();//değerin doğru gözükmesi için ekrandaki yazıları temizle.
    }
    else if (now.hour() == 24 && now.minute() == 00 && now.second() == 0  )//eğer saat 24'e dakika 00'a saniye de 0'a eşit olursa
    {
      while (now.hour() == 24 && now.minute() == 00 && now.second() == 0  )//saat 24'e dakika 00'a saniye de 0'a eşit olduğu süre boyunca bekle
      {
      }
      gun++;//eşitlik bozulduktan sonra "gun"değişkenini bir arttır(saniye arttıktan sonra tekrar saniye 0'a eşit olsa bile dakika eşit olmayacak ve dakika eşit olunca saat eşit olmayacağı için de bu döngüye sadece bir kere girilerek "gun"değişkeninin birden fazla kez çalışması önlenecek.)
      if (gun == azaltilansigara)//eğer "gun" değeri "KacGundeBırAzalsın"a girilen sayıya eşit olursa.
      {
        while (gun == azaltilansigara)//birden fazla kez azalmaması için "gun" değeri "KacGundeBırAzalsın"a girilen sayıya eşit olduğu sürece bekle.
        {
        }
        gunlukicilen--;//eşitlik bozulduktan sonra "KacGundeBırAzalsın"a girilen sayıyı bir azalt.
        gun = 0;//"gun" değişkenini de sıfıra eşitle.
      }
    }
    if (alev == LOW)//eğer alev sensörü çakmakla sigaranın yakıldığını algılarsa.
    {
      Serial.println("cakmak yakıldı");//ekrana "cakmakyakıldı"yazdır.
      if (duman > 400)//eğer duman 400 değerinden daha büyük olursa 
      {
        while (duman > 400)//duman 400 değerinden büyük olduğu sürece bekle.
        {
          duman = analogRead(A0);//beklerken de değer değişirse de duman değerini de kontrol et.
        }
        icildi++;//duman değeri 400 den küçük olunca "kişinin o gün içinde içtiği sigara sayısını bir arttır.
        Serial.println("Sigara icildi");//ekrana "Sigaraicildi"yaz ve döngüden çık.(burda kişi bir sigara içerken sadece bir kere sigarayı yakmak için kullanacağından çakmağı sadece bir kere ateş algılanacak ve bir daha duman da algılanıp bir kere değer arttırıldıktan sonra döngüden çıkılarak her duman olduğunda fazla arttırılması ya da başka dumanlardan etkilenerek yanlış ölçüm yapması engellenecek.)
      }
    }
    else if (icildi > gunlukicilen)//eğer "GunlukIcılen" değerine girilen sayıdan daha fazla sigara içilirse 
    {
      tweet();//doktorunuza ya da aile bireylerinize veya yakınlarınıza bugün düzene uymadığınızı tweet olarak atıyoruz.
      delay(60000);//bekleme komutu tweetin düzgün gitmesi için.
    }
  }
  if (tiklama == 1 && tiklama2 == 0)//tıklama ve tıklama2 değişkenleri 0'a eşitse
  {
    ekran.setFont(SmallFont);//yazı tipini smallfont yap.
    ekran.printNumI(now.hour(), 0, 0);//ekranda saati yazdır.
    ekran.print(":", 12, 0);//saat ile dakika arasına iki nokta koy.
    ekran.printNumI(now.minute(), 15, 0);//ekranda dakikayı yazdır.
    ekran.invertText(false);//bu sefer "GunlukIcılen seçili olmadığı için artık yazı rengini normalde kullanıyoruz.
    ekran.print(">GunlukIcilen", 0, 8);//ekrana "GunlukIcılen"yaz. 
    ekran.printNumI(gunlukicilen, 0, 16);//"GunlukIıcılen"e girdiğimiz değeri ekranda yaz
    ekran.invertText(true);//değerin seçildiğini belli etmek için rengi siyah yap.
    ekran.print("KacGundeBir", 0, 24);//ekrana "KacGundeBırAzalsın" yaz.
    ekran.print("Azalsin", 0, 32);
    ekran.invertText(false);//yazı rengini nomale getir.
    ekran.printNumI(azaltilansigara, 0, 40);//"KacGundeBırAzalsın"a girdiğimiz değeri yaz ekranda.
    ekran.print("icilen", 20, 40);//"icilen" yazısının yanına kişinin  o gün içinde kaç tane sigara içtiğini görmesi için içtiği sigara sayısını yaz.
    ekran.printNumI(icildi, 60, 40);//"icilen" yazısının yanına kişinin  o gün içinde kaç tane sigara içtiğini görmesi için içtiği sigara sayısını yaz.
    if (buton2 == HIGH)//eğer 2.buotna basılırsa
    {
      while (buton2 == HIGH)//değerin sürekli artmaması için basıldığı süre boyunca bekle.
      {
        buton2 = digitalRead(3);
      }
      azaltilansigara++;//kişi elini butondan çekince "KacGundeBırAzalsın"a girilen değeri bir arttır.
      ekran.clrScr();//girilen değerlerin doğru gözükmesi için erkandaki yazıları temizle.
    }
    else if (buton3 == HIGH)//eğer 3.butona basılırsa
    {
      while (buton3 == HIGH)//değerin sürekli artmaması için basıldığı süre boyunca bekle.
      {
        buton3 = digitalRead(4);
      }
      azaltilansigara--;//kişi elini butondan çekince "KacGundeBırAzalsın"a girilen değeri bir azalt.
      ekran.clrScr();//ekrandaki değerlerin doğru gözükmesi için ekrandaki yazıalrı temizle.
    }
    if (now.hour() == 24 && now.minute() == 00 && now.second() == 0  )//eğer saat 24'e dakika 00'a saniye de 0'a eşit olursa
    {
      while (now.hour() == 24 && now.minute() == 00 && now.second() == 0 )//saat 24'e dakika 00'a saniye de 0'a eşit olduğu süre boyunca bekle
      {
      }
      gun++;//eşitlik bozulduktan sonra "gun"değişkenini bir arttır(saniye arttıktan sonra tekrar saniye 0'a eşit olsa bile dakika eşit olmayacak ve dakika eşit olunca saat eşit olmayacağı için de bu döngüye sadece bir kere girilerek "gun"değişkeninin birden fazla kez çalışması önlenecek.)
      if (gun == azaltilansigara)//eğer "gun" değeri "KacGundeBırAzalsın"a girilen sayıya eşit olursa.
      {
        while (gun == azaltilansigara)//birden fazla kez azalmaması için "gun" değeri "KacGundeBırAzalsın"a girilen sayıya eşit olduğu sürece bekle.
        {
        }
        gunlukicilen--;//eşitlik bozulduktan sonra "KacGundeBırAzalsın"a girilen sayıyı bir azalt.
        gun = 0;//"gun" değişkenini de sıfıra eşitle.
      }
    }
    if (alev == LOW)//eğer alev sensörü çakmakla sigaranın yakıldığını algılarsa.
    {
      Serial.println("Cakmak yakıldı");//ekrana "cakmakyakıldı"yazdır.
      if (duman > 400)//eğer duman 400 değerinden daha büyük olursa 
      {
        while (duman > 400)//duman 400 değerinden büyük olduğu sürece bekle.
        {
          duman = analogRead(A0);//beklerken de değer değişirse de duman değerini de kontrol et.
        }
        icildi++;//duman değeri 400 den küçük olunca "kişinin o gün içinde içtiği sigara sayısını bir arttır.
        Serial.println("Sigara icildi");//ekrana "Sigaraicildi"yaz ve döngüden çık.(burda kişi bir sigara içerken sadece bir kere sigarayı yakmak için kullanacağından çakmağı sadece bir kere ateş algılanacak ve bir daha duman da algılanıp bir kere değer arttırıldıktan sonra döngüden çıkılarak her duman olduğunda fazla arttırılması ya da başka dumanlardan etkilenerek yanlış ölçüm yapması engellenecek.
      }
    }
    else if (icildi > gunlukicilen)//eğer "GunlukIcılen" değerine girilen sayıdan daha fazla sigara içilirse 
    {
      tweet();//doktorunuza ya da aile bireylerinize veya yakınlarınıza bugün düzene uymadığınızı tweet olarak atıyoruz.
      delay(60000);//bekleme komutu tweetin düzgün gitmesi için.
    }
  }
}
void tweet() {  //tweet atma fonsiyonunu tanımlıyoruz.
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






