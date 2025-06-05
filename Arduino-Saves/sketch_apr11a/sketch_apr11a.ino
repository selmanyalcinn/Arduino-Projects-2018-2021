int x;
int z;
void setup() {
  Serial.begin(9600);
  pinMode(D6,INPUT);
  pinMode(D5,INPUT);
}
void loop() {
x=digitalRead(D6);
z=digitalRead(D5);
delay(500);
if(x==1 || z==1){
  Serial.println("anan");
}
}
