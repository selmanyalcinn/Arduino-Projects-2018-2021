int alev=2;
int yangin;
int led1;
void setup() {
pinMode(alev, INPUT);
Serial.begin(9600);
}
void loop(){
yangin=digitalRead(alev);
if(yangin == LOW)
{
  Serial.println("yanıyorsun fuat abiğğğğğ");
}
else
{
Serial.println("yangınyok");
Serial.println("sorun da yok");
}
delay(1000);
}
