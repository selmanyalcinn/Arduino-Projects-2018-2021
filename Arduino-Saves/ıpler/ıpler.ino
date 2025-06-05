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
   WiFi.begin("Tan_Koleji","ozkocamantan16");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  Serial.println("bagalandı");
  Serial.println("softap:");
  Serial.print((WiFi.softAPIP()));
  Serial.println("local:");
  Serial.print((WiFi.localIP().toString()));
  Serial.println("gateway:");
  Serial.print((WiFi.gatewayIP().toString().c_str()));
  Serial.println("host name:");
  Serial.print((WiFi.hostname()));

}


void loop()
{


}