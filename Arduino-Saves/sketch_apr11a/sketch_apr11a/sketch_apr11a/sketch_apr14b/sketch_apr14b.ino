#include <Wire.h>
int x=1;
char q;
int uzunluk;
char c;
void setup() {
  Serial.begin(9600); /* begin serial for debug */
  Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
}

void loop() {
  Wire.beginTransmission(8); /* begin with device address 8 */
  Wire.endTransmission();    /* stop transmitting */

  Wire.requestFrom(8, x); /* request & read data of size 13 from slave */
  while (Wire.available()) {
    c = Wire.read();
    q=c;
  }
  if(c=="."){
    while(c=="."){
    x++;
    Wire.write("ka");
    c="..";
  }
  Serial.println(ebced2);
  delay(1000);
}
