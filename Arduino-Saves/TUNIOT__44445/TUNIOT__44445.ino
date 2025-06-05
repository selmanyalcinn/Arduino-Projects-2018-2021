/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
   WiFi.begin("LinyitNet_yalcin","kamil1616");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  Serial.println("bagalandı");
  Serial.println("softap:");
  Serial.println((WiFi.softAPIP()));
  Serial.println("local:");
  Serial.println((WiFi.localIP().toString()));
  Serial.println("gateway:");
  Serial.println((WiFi.gatewayIP().toString().c_str()));
  Serial.println("host name:");
  Serial.println((WiFi.hostname()));

}


void loop()
{


}
