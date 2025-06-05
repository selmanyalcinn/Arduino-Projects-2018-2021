int buton;
int buton1;
int buton2;
int buton3;
int buton4;
int buton5;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  buton = digitalRead(2);
  buton1 = digitalRead(3);
  buton2 = digitalRead(4);
  buton3 = digitalRead(5);
  buton4 = digitalRead(6);
  buton5 = digitalRead(7);
  if (buton == 1) {
    while (buton == 1) {
      buton = digitalRead(2);
    }
    Serial.println("1");
  }
  if (buton1 == 1) {
    while (buton1 == 1) {
      buton1 = digitalRead(3);
    }
    Serial.println("2");
  }
  if (buton2 == 1) {
    while (buton2 == 1) {
      buton2 = digitalRead(4);
    }
    Serial.println("3");
  }
  if (buton3 == 1) {
    while (buton3 == 1) {
      buton3 = digitalRead(5);
    }
    Serial.println("4");
  }
  if (buton4 == 1) {
    while (buton4 == 1) {
      buton4 = digitalRead(6);
    }
    Serial.println("5");
  }
  if (buton5 == 1) {
    while (buton5 == 1) {
      buton5 = digitalRead(7);
    }
    Serial.println("6");
  }
}
