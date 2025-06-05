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
  Serial.println("bagalandi");
  Serial.println("maske:");
  Serial.println((WiFi.subnetMask().toString().c_str()));

}


void loop()<
{


}
