#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "LinyitNet_yalcin"
#define STAPSK  "kamil1616"
#endif
#include <SoftwareSerial.h>
SoftwareSerial s(D6, D5);
int data;
const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const int led = 13;
String toplam;
String virgul=",";
int x;
int sz;
void handleRoot() {
  x = toplam.length();
  char toplamx[x];
  toplam.toCharArray(toplamx, x);
  digitalWrite(led, 1);
  server.send(200, "text/plain", toplamx);
  digitalWrite(led, 0);
}

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void) {
  s.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.begin(115200);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
s.write("s");
  if (s.available()>0)
  {
    data=s.read();
    Serial.println("z");
    Serial.println(data);
    delay(10);
    sz=s.read();
    Serial.println("S");
    Serial.println(sz);
    delay(10);
    int szx=s.read();
    Serial.println("W");
    Serial.println(szx);
    delay(10);
    int ceg=s.read();
    Serial.println("Q");
    Serial.println(ceg);
    delay(10);
    int heg=s.read();
    Serial.println("AS");
    Serial.println(heg);
    delay(10);
    toplam=String(data)+virgul+String(sz)+virgul+String(szx)+virgul+String(ceg)+virgul+String(heg);

  }
}
