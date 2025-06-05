const byte ledPin = 13; // buildin LED
const byte threshold = 10; // adjust if needed
const byte sensorPos = A0;
const byte sensorNeg = A1;
int rawValue1; // holds A/D value from +output
int rawValue2; // holds A/D value from -output
int difference; // holds calculated result

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  rawValue1 = analogRead(sensorPos);
  rawValue2 = analogRead(sensorNeg);
  difference = rawValue1 - rawValue2;

  Serial.print("Pos: ");
  Serial.print(rawValue1);
  Serial.print("\tNeg: ");
  Serial.print(rawValue2);
  Serial.print("\tDifference: ");
  Serial.println(difference);

  if (difference > threshold) {
    digitalWrite(ledPin, HIGH);
    // buzzer 'on' code here
    // solenoid code here (one-shot)
  }
  else {
    digitalWrite(ledPin, LOW);
    // buzzer 'off' code here
  }
  delay(500); // added to slow down printing, so you can read it
}

