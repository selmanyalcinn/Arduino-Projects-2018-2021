#include <IRremote.h>;
#include<IRremoteInt.h>
const int RECV_PIN=2;
const int sagmotor1=5;
const int sagmotor2=6;
const int solmotor1=7;
const int solmotor2=8;
const int e1=9;
const int e2=10;
const int echoPin=11;
const int trig_Pin=12;
int VOL1;
int VOL2;
int buton2;
int buton3;
int buton4;
int buton5;
int buton0;
int hiz=255;


IRrecv irrecv(2);
decode_results results;





void setup() {
pinMode(sagmotor1, OUTPUT);
pinMode(sagmotor2 , OUTPUT);
pinMode(solmotor1 , OUTPUT);
pinMode(solmotor2 , OUTPUT);
pinMode(e1 , OUTPUT);
pinMode(e2 , OUTPUT);
pinMode(echoPin , INPUT);
pinMode(trig_Pin , OUTPUT);
digitalWrite(sagmotor1 , LOW);
digitalWrite(sagmotor2 , LOW);
digitalWrite(solmotor1 , LOW);
digitalWrite(solmotor2 , LOW);
digitalWrite(e1 , LOW);
digitalWrite(e2 , LOW);
Serial.begin(9600);
irrecv.enableIRIn();
}

void loop() {
 
 Serial.println(mesafe());
  if (mesafe() > 10)
 {
 if(irrecv.decode(&results))
  {
  if(hiz >= 0 && hiz<=255 && results.value == VOL1)
  {
  hiz=hiz+50;
  if(hiz == 255)
  hiz=255;   
  }
  if(hiz>= 0 && hiz<=255 && results.value ==VOL2)
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


void sol_motor(String dir, int spd);

  if ( dir == "ILERI")      
  {       
    digitalWrite(SolMotor1, HIGH);
    digitalWrite(SolMotor2, LOW);
    analogWrite(SolMotorEN, spd);
  }
  void sol_motor(String dir, int spd);
  if ( dir == "GERI");
  {       
    digitalWrite(SolMotor1, LOW);
    digitalWrite(SolMotor2, HIGH);
    analogWrite(SolMotorEN, spd);
  }


void sag_motor(String dir, int spd)
{ 
  if ( dir == "ILERI")             
  {
    digitalWrite(SagMotor1, HIGH);
    digitalWrite(SagMotor2, LOW);
    analogWrite(SagMotorEN, spd);
  }
void sol_motor(String dir, int spd);
  if ( dir == "GERI");
  {           
    digitalWrite(SagMotor1, LOW);
    digitalWrite(SagMotor2, HIGH);
    analogWrite(SagMotorEN, spd);
  }

void duzgit()
{
sagmotor(" ILERI " , hiz);
solmotor(" ILERI " ,hiz);
}
void sagadon()
{
sagmotor(" GERI " , hiz);
solmotor(" ILERI ", hiz);
}
void soladon()
{
sagmotor(" ILERI " ,hiz);
solmotor(" GERI ", hiz);
}
void gerigit()
{
  sagmotor(" GERI ",hiz);
  solmotor(" GERI ",hiz);
}
void dur()
{
  sagmotor(" ILERI ", 0);
  solmotor(" ILERI ", 0);
}
{
   int mesafe
{
  long duration, distance;
  digitalWrite(trig_pin , LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin , LOW);
  duration = pulseIn(echopin , HIGH);
  distance = duration / 58.2;
  delay(50);
  if(distance >= 50)
  return 50;
  return distance;
}


}
}
}
