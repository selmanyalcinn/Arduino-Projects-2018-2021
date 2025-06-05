#include <IRremote.h>
#include <IRremoteInt.h>  //İndirdiğimiz IR kütüphanelerini programımıza dahil ediyoruz

const int RECV_PIN = 2;      // Kızılötesi alıcımızın pinini belirliyoruz.

//L298N Bağlantısı
const int SolMotor1  = 5;  // L298N'in IN1 Girişi
const int SolMotor2  = 6;  // L298N'in IN2 Girişi
const int SolMotorEN  = 9; // L298N'in ENA Girişi
const int SagMotor1  = 7;  // L298N'in IN3 Girişi
const int SagMotor2 = 8; // L298'in IN4 Girişi
const int SagMotorEN = 10; // L298'in ENB Girişi

//HC-SR04 Bağlantısı
const int echoPin = 11; 
const int trigPin = 12;

int Hiz = 255;  // Motorumuzun hız değişkenini tanımlıyoruz

IRrecv irrecv(RECV_PIN);
decode_results results;

#define CH1 0xFFA25D           // Kumandamızın butonlarından gelen sinyalleri hex olarak tanımlıyoruz.
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTON0 0xFF6897
#define BUTON100 0xFF9867
#define BUTON200 0xFFB04F
#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF
#define BUTON5 0xFF38C7
#define BUTON6 0xFF5AA5
#define BUTON7 0xFF42BD
#define BUTON8 0xFF4AB5
#define BUTON9 0xFF52AD

void setup()
{
  pinMode(SolMotorEN, OUTPUT);
  pinMode(SagMotorEN, OUTPUT);
  pinMode(SolMotor1, OUTPUT);
  pinMode(SagMotor1, OUTPUT);
  pinMode(SolMotor2, OUTPUT);
  pinMode(SagMotor2, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  digitalWrite(SolMotorEN, LOW);
  digitalWrite(SagMotorEN, LOW);
  digitalWrite(SolMotor1, LOW);
  digitalWrite(SagMotor1, LOW);
  digitalWrite(SolMotor2, LOW);
  digitalWrite(SagMotor2, LOW);

  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  Serial.println(mesafe());
  if (mesafe() > 10)
  {

    if (irrecv.decode(&results))  //kumandadan sinyal geldiğinde,
    {
      if (Hiz >= 0 && Hiz <= 255 && results.value == VOL1) // Vol1 (-) tuşuna bastığımızda hızın değeri 50 düşsün.
      {
        Hiz = Hiz - 50;
        if (Hiz < 0)
          Hiz = 0;
      }
      if (Hiz >= 0 && Hiz <= 255 && results.value == VOL2) // Vol2 (+) tuşuna bastığımızda hızın değeri 50 artsın.
      {
        Hiz = Hiz + 50;
        if (Hiz > 255)
          Hiz = 255;
      }
      if (results.value == BUTON2) // Buton2'ye bastığımızda robot ileri yönde hareket etsin.
      {
        duzgit();
      }
      if (results.value == BUTON8) // Buton8'e bastığımızda robot geri yönde hareket etsin.
      {
        gerigit();
      }
      if (results.value == BUTON4) // Buton4'e bastığımızda robot sola doğru hareket etsin.
      {
        soladon();
      }
      if (results.value == BUTON6) // Buton6'ya bastığımızda robot sağa doğru hareket etsin.
      {
        sagadon();
      }
      if (results.value == BUTON0) // Buton0'a bastığımızda robot dursun.
      {
        dur();
      }
      irrecv.resume();
    }
  } 
  else
  dur();
}

void sol_motor(String dir, int spd) // sol motor kontrolü
{ // yön(dir) ve hız(spd) için değişkenler.
  if ( dir == "ILERI")             // FORWARD komutu ileri hareket için.
  {
    digitalWrite(SolMotor1, HIGH);
    digitalWrite(SolMotor2, LOW);
    analogWrite(SolMotorEN, spd);
  }
  if ( dir == "GERI")           //BACKWARD komutu geriye hareket için.
  {
    digitalWrite(SolMotor1, LOW);
    digitalWrite(SolMotor2, HIGH);
    analogWrite(SolMotorEN, spd);
  }
}

void sag_motor(String dir, int spd)// sağ motor kontrolü
{ // yön(dir) ve hız(spd) için değişkenler.
  if ( dir == "ILERI")             // FORWARD komutu ileri hareket için.
  {
    digitalWrite(SagMotor1, HIGH);
    digitalWrite(SagMotor2, LOW);
    analogWrite(SagMotorEN, spd);
  }

  if ( dir == "GERI")           //BACKWARD komutu geriye hareket için.
  {
    digitalWrite(SagMotor1, LOW);
    digitalWrite(SagMotor2, HIGH);
    analogWrite(SagMotorEN, spd);
  }
}

void duzgit() // Robot ileri gitsin.
{
  sag_motor("ILERI", Hiz); // Sağ ve sol motorlar ileri yönde 200 hızında
  sol_motor("ILERI", Hiz);
}
void sagadon() // Robot sağa dönsün.
{
  sag_motor("GERI", Hiz); //Sağ motor 200 hızında geri
  sol_motor("ILERI", Hiz); //Sol motor 200 hızında ileri
}

void gerigit() // Robot geri gitsin.
{
  sag_motor("GERI", Hiz); //Sağ motor 200 hızında geri
  sol_motor("GERI", Hiz); //Sol motor 200 hızında geri
}

void soladon()
{
  sag_motor("ILERI", Hiz);
  sol_motor("GERI", Hiz);
}

void dur()
{
  sag_motor("ILERI", 0);
  sol_motor("ILERI", 0);
}

int mesafe()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);
  if (distance >= 50)
    return 50;
  return distance;
}


#include<IRremote.h>
IRrecv irrecv(2);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {
  if(irrecv.decode(&results))
  Serial.println(results.value , HEX);
  irrecv.resume();
}







