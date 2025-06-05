#include <LCD5110_Basic.h>
LCD5110 ekran(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void setup() {
ekran.InitLCD();
ekran.setContrast(0);
Serial.begin(9600);
}

void loop() {
ekran.setFont(SmallFont);
ekran.print("Seni çok seviyorum",0,0);
ekran.print("HER ŞEYİMMM",0,8);
delay(1000);
ekran.clrScr();
ekran.print("En kötü hissettiğim anda",0,0);
ekran.print("En mutlu olduğum anda",0,8);
ekran.print("Hep yanımda oldun",0,16);
delay(1000);
ekran.clrScr();
ekran.print("Çölüme yağmur",0,0);
ekran.print("Geceme gündüz",0,8);
ekran.print("Kışıma yorgan",0,16);
ekran.print("Canıma yoldaş oldun",0,24);
delay(1000);
ekran.clrScr();
ekran.print("Seni çok seviyorum HER ŞEYİMM",0,0);
ekran.print("Senle olduğum an yetmiyor",0,8);
ekran.print("Sensiz zaman geçmiyor",0,16);
ekran.print("Birlikte nice senelere <3",0,24);
delay(1000);
ekran.clrScr();
ekran.print("Sonsuza kadar her sene",0,0);
ekran.print("Benimle birlikte olur musun ?",0,8);
delay(1000);
}
