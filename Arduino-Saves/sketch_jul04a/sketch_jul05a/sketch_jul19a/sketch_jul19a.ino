void setup() {
 Serial.begin(9600);
}

void loop() {
  int sensordegeri = analogRead(A0);
  Serial.println(sensordegeri);
}
