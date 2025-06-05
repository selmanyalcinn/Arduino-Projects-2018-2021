/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>
String x;
void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
   WiFi.begin("TanKat01","tankat01");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  Serial.println("baglandı");
  Serial.println((WiFi.localIP().toString()));
  x=(WiFi.localIP().toString());
}


void loop()
{
  Serial.println(x);
  delay(500);
}
