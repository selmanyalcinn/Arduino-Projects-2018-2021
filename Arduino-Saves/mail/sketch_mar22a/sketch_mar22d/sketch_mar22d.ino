int mysens[]={124};
int sz;
int x;
void setup() {
  Serial.begin(9600);
  

}

void loop() {
  Serial.println(mysens[0]);
  sz=mysens[0];
  Serial.println(sz);
}
