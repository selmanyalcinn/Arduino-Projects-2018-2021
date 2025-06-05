void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buton;
  int buton1;
  int buton2;
  buton = digitalRead(2);
  buton = digitalRead(3);
  buton = digitalRead(4);
  if (buton == 1) {
    while (buton == 1) {
      buton = digitalRead(2);
    }
    Serial.println("Buton");
  }
 if (buton1 == 1) {
    while (buton1 == 1) {
      buton1 = digitalRead(3);
    }
    Serial.println("Buton1");
  }
   if (buton2 == 1) {
    while (buton2 == 1) {
      buton2 = digitalRead(4);
    }
    Serial.println("Buton3");
  }
  delay(200);

}
