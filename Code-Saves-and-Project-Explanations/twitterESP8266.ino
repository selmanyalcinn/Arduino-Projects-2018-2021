#define ag_ismi "LinyitNet_yalcin"
#define ag_sifresi "kamil1616"
#define IP "184.106.153.149"    //thingspeak.com IP adresi
 
int lm35_pini = A0;
 
void setup()
{
  Serial.begin(115200); //Seriport'u açıyoruz. Güncellediğimiz 
                        //ESP modülünün baudRate değeri 115200 olduğu için bizde Seriport'u 115200 şeklinde seçiyoruz
  
  Serial.println("AT"); //ESP modülümüz ile bağlantı kurulup kurulmadığını kontrol ediyoruz.
  
  delay(3000); //EPSP ile iletişim için 3 saniye bekliyoruz.
 
  if(Serial.find("OK")){         //esp modülü ile bağlantıyı kurabilmişsek modül "AT" komutuna "OK" komutu ile geri dönüş yapıyor.
     Serial.println("AT+CWMODE=1"); //esp modülümüzün WiFi modunu STA şekline getiriyoruz. Bu mod ile modülümüz başka ağlara bağlanabilecek.
     delay(2000);
     String baglantiKomutu=String("AT+CWJAP=\"")+ag_ismi+"\",\""+ag_sifresi+"\"";
    Serial.println(baglantiKomutu);
    
     delay(5000);
 }
}

void loop(){
 sicaklik_yolla();
 delay(60000);
}
void sicaklik_yolla(){
 Serial.println(String("AT+CIPSTART=\"TCP\",\"") + IP + "\",80");  //thingspeak sunucusuna bağlanmak için bu kodu kullanıyoruz. 
                                                                   //AT+CIPSTART komutu ile sunucuya bağlanmak için sunucudan izin istiyoruz. 
                                                                   //TCP burada yapacağımız bağlantı çeşidini gösteriyor. 80 ise bağlanacağımız portu gösteriyor
 delay(1500);
 String tweet = "POST /apps/thingtweet/1/statuses/update HTTP/1.1\n";
    tweet+="Host: api.thingspeak.com\n";
    tweet+="Connection: close\n";
    tweet+="Content-Type: application/x-www-form-urlencoded\n";
    tweet+="Content-Length:50\r\n\r\napi_key=";
    tweet+=String("24PU0SZTOFTXPN67");                             //ThingSpeak'den aldığımız Twitter API KEY'ini buraya yazıyoruz.
    tweet+=String("&status=");
    tweet+=String("Duzene uyuldu #esp8266");                           // Yollamak istediğimiz tweeti buraya yazıyoruz.

 Serial.print("AT+CIPSEND=");                    //veri yollayacağımız zaman bu komutu kullanıyoruz. Bu komut ile önce kaç tane karakter yollayacağımızı söylememiz gerekiyor.
 delay(100);
 Serial.println(tweet.length());
 
 if(Serial.find(">")){                           //eğer sunucu ile iletişim sağlayıp komut uzunluğunu gönderebilmişsek ESP modülü bize ">" işareti ile geri dönüyor.
                                                 // arduino da ">" işaretini gördüğü anda sıcaklık verisini esp modülü ile thingspeak sunucusuna yolluyor.
 Serial.println(tweet);
 Serial.println("AT+CIPCLOSE=0");
 delay(100);

 }
 else{
 Serial.println("AT+CIPCLOSE=0");
 }
}
