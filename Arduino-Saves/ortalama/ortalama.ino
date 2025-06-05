int a;
int b;
int ortalama;
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);

}

void loop() {
  if (i == 0) {
    a = analogRead(A0);
    Serial.println(a);
    delay(500);
    b = analogRead(A0);
    ortalama = (a + b) / 2;
    Serial.println("ortalama1:");
    Serial.println(ortalama);
    delay(500);
    i = 1;

  }
  if (i == 1) {
    a = analogRead(A0);
    ortalama = (ortalama + a) / 2;
    Serial.println("ortalama");
    Serial.println(ortalama);
    delay(500);
  }

}
