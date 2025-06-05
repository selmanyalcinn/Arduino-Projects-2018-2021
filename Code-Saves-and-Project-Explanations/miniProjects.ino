int b1 =9;
int b2 =8;
int b3 =7;
int b4 =6;
int b5 =5;
int led1 =4;
int led2 =3;
int led3 =2;
int butondurumu1;
int butondurumu2;
int butondurumu3;
int butondurumu4;
int butondurumu5;

void setup() {
pinMode(b1 , INPUT);
pinMode(b2 , INPUT);
pinMode(b3 , INPUT);
pinMode(b4 , INPUT);
pinMode(b5 , INPUT);
pinMode(led1 , OUTPUT);
pinMode(led2 , OUTPUT);
pinMode(led3 , OUTPUT);
}

void loop() {
butondurumu1 = digitalRead(b1);
butondurumu2 = digitalRead(b2);
butondurumu3 = digitalRead(b3);
butondurumu4 = digitalRead(b4);
butondurumu5 = digitalRead(b5);

if(butondurumu1 == HIGH)
digitalWrite(led1 ,  HIGH);
 else if(butondurumu2 == HIGH)
 {
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , HIGH);
 }
else if(butondurumu3 == HIGH)
{
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , HIGH);
  digitalWrite(led3 , HIGH);
}
else if(butondurumu4 == HIGH)
{
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , HIGH);
  digitalWrite(led3 , HIGH);
 
}
else if(butondurumu5 == HIGH)
{
  digitalWrite(led1 , HIGH);
  delay(1000);
  digitalWrite(led1 , LOW);
  delay(1000);
  digitalWrite(led2 , HIGH);
  delay(1000);
  digitalWrite(led2 , LOW);
  delay(1000);
  digitalWrite(led3 , HIGH);
  delay(1000);
  digitalWrite(led3 , LOW);
  delay(1000); 
}


else
{
  digitalWrite(led1 , LOW);
  digitalWrite(led1 , LOW);
   digitalWrite(led1 , LOW); 

}

}



const int arttirma=0;
const int azaltma=1;
const int dongu=2;
int sayac=0;
int durum_arttirma;
int durum_azaltma;
int durum_dongu;

void setup() {
pinMode(arttirma , INPUT);
pinMode(azaltma , INPUT);
pinMode(dongu , INPUT);
Serial.begin(9600); 
}
void loop() 
{
 durum_dongu=digitalRead(dongu);
 while(durum_dongu == HIGH)
 {
durum_arttirma = digitalRead(0);
durum_azaltma = digitalRead(1);

if(durum_arttirma == HIGH)
{
  sayac=sayac+1;
  Serial.println(" sayac ");
  Serial.println(sayac);
  delay(150);
}

else if(durum_azaltma == HIGH)
{
  sayac=sayac-1;
  Serial.println(" sayac ");
  Serial.println(sayac);
  delay(150);
}
durum_dongu=digitalRead(dongu);
}
switch(sayac)
{
 case 1:
 Serial.println(" ekmek verildi ");
 break;
 
 case 2:
 Serial.println(" çokolat verildi ");
 break;
 
 case 3:
 Serial.println(" içecek verildi ");
 break;
 default:
 Serial.println(" üzgünüz bu tuş hiçbir fonksiyona sahip değil ");
 

}
}

const int RECV_PIN=2;
const int in1=5;
const int in2=6;
const int in3=7;
const int in4=8;
const int e1=9;
const int e2=10;
const int echoPin=11;
const int trig_Pin=12;

int hiz=255;

IRrecv irrecv(2);
decode_results results;

#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define 
#define
#define 
#define 
#define 
#define 


void setup() {
pinMode(in1 , OUTPUT);
pinMode(in2 , OUTPUT);
pinMode(in3 , OUTPUT);
pinMode(in4 , OUTPUT);
pinMode(e1 , OUTPUT);
pinMode(e2 , OUTPUT);
pinMode(echoPin , INPUT);
pinMode(trigPin , OUTPUT);
digitalWrite(in1 , LOW);
digitalWrite(in2 , LOW);
digitalWrite(in3 , LOW);
digitalWrite(in4 , LOW);
digitalWrite(e1 , LOW);
digitalWrite(e2 , LOW);
Serial.begin(9600);
irrecv.enableIRIn();
}

void loop() {
 Serial.println(mesafe());
 if(mesafe>10);
 {
 if(irrecv.decode(&results)
  {
  if(hiz >= 0 && hiz<=255 && results.value == VOL1)
  {
  hiz=hiz+50;
  if(hiz == 255)
  hiz=255;   
  }
  if(hiz>= 0 && hiz<=255 && rsults.value ==VOL2)
  {
    hiz=hiz+50;
    if(hiz == 255)
    hiz=255;
  }
  if(results.value == buton2)
  {
   
  }
  if(results.value == buton3)
  {
    
  }
  if(results.value == buton4)
  {
    
  }
  if(results.value == buton5)
  {
    
  }
  if(results.value == buton0)
  {
    stop();
  }
  irrecv.resume();
  }
  else
  stop();
 }
  
  
  
  
 }


}






#include <IRremote.h>

IRrecv irrecv(2);
decode_results results;


void setup() {
Serial.begin(9600);
irrecv.enableIRIn();

}

void loop() {
if(irrecv.decode(&results))
Serial.println(results.value, HEX);
irrecv.resume();
}




int veri;
const int Analogcikis=A0;
float voltaj;
void setup() {
Serial.begin(9600);
}
void loop() {
  veri=analogRead(A0);
  Serial.print(veri);
Serial.println("voltaj");
Serial.println(veri * 5/1023.0);
delay(500);
}

/*
 * IRremote: IRrecvDump - dump details of IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * JVC and Panasonic protocol added by Kristian Lauszus (Thanks to zenwheel and other people at the original blog post)
 * LG added by Darryl Smith (based on the JVC protocol)
 */

#include <IRremote.h>

/* 
*  Default is Arduino pin D11. 
*  You can change this to another available Arduino Pin.
*  Your IR receiver should be connected to the pin defined here
*/
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}


void dump(decode_results *results) {
  // Dumps out the decode_results structure.
  // Call this after IRrecv::decode()
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");

  }
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  }
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  }
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->address, HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
    Serial.print("Decoded LG: ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("Decoded JVC: ");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("Decoded AIWA RC T501: ");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Decoded Whynter: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 1; i < count; i++) {
    if (i & 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.write('-');
      Serial.print((unsigned long) results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    dump(&results);
    irrecv.resume(); // Receive the next value
  }
}


