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
int kalp;
int sigara;
int gunlukicilen;
int azaltilacagigun;
int duzeneuyulamayangun;
int havakalitesi;
String virgul = ",";
int x;
String toplam2;
String toplam3;
String toplam4;
String toplam5;
String toplam6;
String toplam7;
String toplam8;
String toplam9;
String toplam10;
String toplam11;
String toplam12;
String toplam13;

void handleRoot() {
  toplam2 = kalp + virgul;
  toplam3 = sigara + virgul;
  toplam4 = havakalitesi + virgul;
  toplam5 = duzeneuyulamayangun + virgul;
  toplam6 = azaltilacagigun + virgul;
  toplam7 = gunlukicilen + virgul;
  toplam8 = toplam2 + toplam3;
  toplam9 = toplam4 + toplam5;
  toplam10 = toplam6 + toplam7;
  toplam11 = toplam8 + toplam9;
  toplam12 = toplam10;
  toplam13 = toplam11 + toplam12;
  x = toplam13.length();
  char toplamx[x];
  toplam13.toCharArray(toplamx, x);
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
  if (s.available() > 0)
  {
    kalp = s.read();
    delay(100);
    sigara=s.read();
    delay(100);
    havakalitesi=s.read();
    delay(100);
    duzeneuyulamayangun=s.read();
    delay(100);
    azaltilacagigun=s.read();
    delay(100);
    gunlukicilen=s.read();
    delay(100);
  }
}
