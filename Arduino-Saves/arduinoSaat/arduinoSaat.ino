#include <LCD5110_Basic.h>

LCD5110 myGLCD(8,9,10,11,12);


extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
extern uint8_t mnk[];
extern uint8_t lrt[];

unsigned long zaman    = 0;   
unsigned long ilkSayac = 0;   

byte dakika = 15;              
byte saat   = 9;    
byte ilk=5;       
int gun;   
const byte arttirButon = 7;
const byte azaltButon  = 6;
const byte anahtar     = 5;
const byte dakikaButon = 4;

int anahtarDurum = 0;
int saatArttir   = 0;
int saatAzalt    = 0;
int dakikaDurum  = 0;
                      


void setup() {

  Serial.begin(250000);
  pinMode( arttirButon , INPUT);
  pinMode( azaltButon , INPUT);
  pinMode( anahtar , INPUT);
  pinMode( dakikaButon , INPUT);
  
  myGLCD.InitLCD();
  myGLCD.setContrast(50);
  myGLCD.clrScr();
  
}

void loop() {

  
  anahtarDurum = digitalRead(anahtar);

  while(ilk==5)
  { 
  myGLCD.clrScr();  
  myGLCD.drawBitmap(0,0,mnk,84,48);
  delay(3000);
   myGLCD.clrScr();  
  myGLCD.drawBitmap(0,0,lrt,84,48);
  delay(3000);
  ilk=0;
  }
    
    
  
  while(anahtarDurum == HIGH)
  {
   dakikaDurum = digitalRead(dakikaButon);
   saatArttir = digitalRead(arttirButon);
   saatAzalt  = digitalRead(azaltButon);

    myGLCD.clrScr();
    myGLCD.setFont(SmallFont);
    myGLCD.print("SAAT",CENTER,0);
    myGLCD.print("AYARI",CENTER,8);
    myGLCD.print(".",34,32);   
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumI(saat,10,24);
    myGLCD.printNumI(dakika,40,24);
    delay(50);


   
   if(saatArttir == HIGH&&dakikaDurum == LOW)
   {
    saat++;
    delay(200);
    Serial.print("SAAT:  ");
    Serial.print(saat);
    Serial.print(":");
    Serial.println(dakika);
    myGLCD.clrScr();   
    myGLCD.setFont(SmallFont);
    myGLCD.print("SAAT",CENTER,0);
    myGLCD.print("AYARI",CENTER,8);
    myGLCD.print(".",34,32);   
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumI(saat,10,24);
    myGLCD.printNumI(dakika,40,24);
    delay(50);
   }

  else  if(saatAzalt == HIGH&&dakikaDurum == LOW)
   {
    saat--;
    delay(200);
    Serial.print("SAAT:  ");
    Serial.print(saat);
    Serial.print(":");
    Serial.println(dakika);  
    myGLCD.clrScr(); 
    myGLCD.setFont(SmallFont);
    myGLCD.print("SAAT",CENTER,0);
    myGLCD.print("AYARI",CENTER,8);
    myGLCD.print(".",34,32);   
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumI(saat,10,24);
    myGLCD.printNumI(dakika,40,24);
    delay(50);
   }
   

  else if(dakikaDurum == HIGH && saatArttir == HIGH)
   {
    dakika++;
    delay(200);
    Serial.print("SAAT:  ");
    Serial.print(saat);
    Serial.print(":");
    Serial.println(dakika); 
    myGLCD.clrScr();
    myGLCD.setFont(SmallFont);  
    myGLCD.print("SAAT",CENTER,0);
    myGLCD.print("AYARI",CENTER,8);
    myGLCD.print(".",34,32);   
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumI(saat,10,24);
    myGLCD.printNumI(dakika,40,24);
    delay(50);
   }
    
   

   else if(dakikaDurum == HIGH && saatAzalt == HIGH)
   {
    dakika--;
    delay(200);
    Serial.print("SAAT:  ");
    Serial.print(saat);
    Serial.print(":");
    Serial.println(dakika);
    myGLCD.clrScr();
    myGLCD.setFont(SmallFont);  
    myGLCD.print("SAAT",CENTER,0);
    myGLCD.print("AYARI",CENTER,8);
    myGLCD.print(".",34,32);   
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumI(saat,10,24);
    myGLCD.printNumI(dakika,40,24);
    delay(50);
   }
   if(saat==24)
   {
    saat=0;
   }
   if(dakika==60)
   {
    dakika=0;
    saat++;
   }
   if(dakika==255)
   {
    dakika=59;
   }
   
  anahtarDurum = digitalRead(anahtar);
  
  }


  
  zaman=millis();
  ilkSayac=zaman%60000;
  Serial.print("SAAT   ");
  Serial.print(saat);
  Serial.print(":");
  Serial.print(dakika);
  Serial.print("          ");
  Serial.print((zaman%60000)/1000);
  Serial.print(". saniye\n");

    myGLCD.clrScr();
    myGLCD.setFont(SmallFont);  
    myGLCD.print(".",22,32);   
    myGLCD.print("saniye",36,32);
    myGLCD.print(":",40,8);
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumI(saat,14,0);
    myGLCD.printNumI(dakika,46,0);
    myGLCD.printNumI((zaman%60000)/1000,LEFT,24);
    delay(40);
  
  if(ilkSayac>59930)
  {
    dakika++;
  }
  if(dakika == ilkdeger+artandakika)
  {
   ekran.print("İcebilirsiniz",0,40); 
  }
  if(dakika==60)
  {
    saat++;
    dakika=0;
  }

  if(saat==24)
  {
    saat=0;
    gun++;
  }
  if(gun == KacGundeBirAzaltılsın?)
  {
    gun=0;
    GunlukIcilen--;
  }
}
