int dumandedektoru=A0;
int duman;
int alev=13;
int yangin;
int sayac;
int icilensigara;
void setup() {
  Serial.begin(9600);
  pinMode(A0 , INPUT);
  pinMode(alev , INPUT);
}
void loop() {
  duman=analogRead(A0);
  yangin=digitalRead(13);
  if(yangin == LOW)
  {
    if(duman >200)
    icilensigara++;
    
  }
}
