/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

WiFiServer server();

WiFiClient client;

void setup()
{
Serial.begin(9600);

  WiFi.disconnect();
  delay(1000);
  WiFi.begin();
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  Serial.println("");
  Serial.println((WiFi.localIP()));
  server.begin(80);

}


void loop()
{

    client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println(analogRead(0));
    client.println("</html>");
    client.stop();
    delay(1);

  analogRead(0)

}
