#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// pin definition for the Leonardo
// #define cs   7
// #define rst  1

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen
char duman2[4];
int duman;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(255, 255, 255);

  // write the static text to the screen
  // set the font color to white
  // set the font size
  TFTscreen.setTextSize(3);
  // write the text to the top left corner of the screen
}

void loop() {
  // put your main code here, to run repeatedly:
duman=analogRead(A0);
String dumanstring=String(duman);
dumanstring.toCharArray(duman2,4);
if(duman>300&&  duman<=400){
  
  Serial.println(duman);
  TFTscreen.stroke(0,255,0);
  TFTscreen.text("Cok Iyı",30,30);
  delay(100);
 TFTscreen.stroke(255,255,255);
  TFTscreen.text("Cok Iyı",30,30);
}

if(duman<=300 && duman>100){
  Serial.println(duman);
  TFTscreen.stroke(0,255,255);
  TFTscreen.text("Normal",30,30);
  delay(100);
 TFTscreen.stroke(255,255,255);
  TFTscreen.text("Normal",30,30);
}

if(duman<=100 && duman>0){
  Serial.println(duman);
  TFTscreen.stroke(0,0,255);
  TFTscreen.text("Kotu",30,30);
  delay(100);
 TFTscreen.stroke(255,255,255);
  TFTscreen.text("Kotu",30,30);
}
  TFTscreen.stroke(0,255,0);
  TFTscreen.line(5,60,60,60);
  TFTscreen.stroke(0,255,255);
  TFTscreen.line(60,60,115,60);
  TFTscreen.stroke(0,0,255);
  TFTscreen.line(115,60,160,60);
  
}
