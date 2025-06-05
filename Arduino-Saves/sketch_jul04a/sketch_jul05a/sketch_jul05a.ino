

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
}
