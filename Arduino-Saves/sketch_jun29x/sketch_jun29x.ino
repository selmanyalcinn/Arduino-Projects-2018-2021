#include<IRremote.h>
const int RECV_PIN=2;
const int Solmotor1=5;
const int Solmotor2=6;
const int Sagmotor1=7;
const int Sagmotor2=8;
const int e1=9;
const int e2=10;
const int echoPin=11;
const int trig_Pin=12;

int hiz=255;

IRrecv irrecv(2);
decode_results results;



void setup() {
pinMode(Solmotor1 , OUTPUT);
pinMode(Solmotor2 , OUTPUT);
pinMode(Sagmotor1 , OUTPUT);
pinMode(Sagmotor2 , OUTPUT);
pinMode(e1 , OUTPUT);
pinMode(e2 , OUTPUT);
pinMode(echoPin , INPUT);
pinMode(trig_Pin , OUTPUT);
digitalWrite(Solmotor1 , LOW);
digitalWrite(Solmotor2 , LOW);
digitalWrite(Sagmotor1 , LOW);
digitalWrite(Sagmotor2, LOW);
digitalWrite(e1 , LOW);
digitalWrite(e2 , LOW);
Serial.begin(9600);
irrecv.enableIRIn();
}

void loop() {
int mesafe;
 Serial.println(mesafe);
 if(mesafe > 10);
 {
 if(irrecv.decode(&results))
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
   duzgit();
  }
  if(results.value == buton3)
  {
    sagadon();
  }
  if(results.value == buton4)
  {
    soladon();
  }
  if(results.value == buton5)
  {
    gerigit();
  }
  if(results.value == buton0)
  {
    dur();
  }
  irrecv.resume();
  }
  else
  dur();
 }
 void in1(String dir,int spd)
 if(dir == " ILERI ")
 { 
  digitalWrite(Solmotor1, HIGH);
  digitalWrite(Solmotor2, LOW);
  analogWrite(en1, spd);
 }
 void in1(String dir,int spd)
 if(dir == " ILERI ")
 { 
  digitalWrite(Solmotor3, LOW);
  digitalWrite(Solmotor4, HIGH);
  analogWrite(en1, spd);
 }
void in1(String dir,int spd)
 if(dir == " ILERI ")
 { 
  digitalWrite(Sagmotor1, HIGH);
  digitalWrite(Sagmotor2, LOW);
  analogWrite(en2, spd);
}
void in1(String dir,int spd)
 if(dir == " ILERI ")
 { 
  digitalWrite(Sagmotor3, LOW);
  digitalWrite(Sagmotor4, HIGH);
  analogWrite(en2, spd);

void duzgit()
{
sagmotor(" ILERI ");
solmotor(" ILERI ");
}


int mesafe;






