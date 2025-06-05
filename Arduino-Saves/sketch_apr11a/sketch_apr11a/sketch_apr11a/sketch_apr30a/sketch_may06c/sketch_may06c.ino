#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

#define cs   10
#define dc   9
#define rst  8

TFT TFTscreen = TFT(cs, dc, rst);

char sensorPrintout[4];
const int sensor = A1;
int periyot = 20;
double alfa = 0.75;
double yenileme = 0.0;
int ritim2;
const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;
int ritim3;
int duman2;
int duman;
unsigned long t1;
unsigned long t2;
int icilensigara;
void setup(void)
{
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);
  TFTscreen.setTextSize(2);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
void loop(void)
{
  t1 = millis();
  static double oncekideger = 0;
  static double oncekiyenileme = 0;
  int ritim = analogRead(sensor);
  double deger = alfa * oncekideger + (0 - alfa) * ritim;
  yenileme = deger - oncekideger;
  ritim2 = ritim / 10;
  Serial.println("Nabiz Degeri");
  Serial.println(ritim2);
  oncekideger = deger;
  oncekiyenileme = yenileme;
  total = total - readings[readIndex];
  readings[readIndex] = ritim2;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  average = total / numReadings;
  delay(periyot * 10);
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text("<Kalp Sagligi", 0, 5);
  TFTscreen.text("Grafikler:", 0, 30);
  TFTscreen.text("Gunluk >", 5, 53);
  TFTscreen.line(0,70,60,70);
  TFTscreen.stroke(100, 100, 100);
  TFTscreen.text("Haftalik", 5, 73);
  TFTscreen.text("Aylik", 5, 93);
  TFTscreen.text("Yillik", 5, 113);
}
