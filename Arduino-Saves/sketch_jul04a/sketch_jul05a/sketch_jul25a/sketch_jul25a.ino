int tiklama;
int buton1=;
int buton2=;
int buton3;
int duman;
int dumandedektoru=A0;
int yangin;
int alevsensoru=7;
int gundebirdusulendeger;
int icilendeger;
int arttırılansure;
void setup() {
 pinMode(1,INPUT);
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 pinMode(7,INPUT);
 pinMode(A0,INPUT); 
}

void loop() {
  buton1=digitalRead(1);
  buton2=digitalRead(2);
  buton3=digitalRead(3);
 if(buton1 == HIGH)
 {
  while(buton1 == HIGH)
  {
    buton1=digitalRead(1); 
  }
  tiklama==1;
  else if(tiklama == 1)
  {
    buton2=digitalRead(2);
    if(buton2 == HIGH)
    {
     while(buton2 == HIGH);
     {
      buton2=digitalRead(2); 
    }
    gundebirdusulendeger++;
    }
   
    
     
     
    
    
    yangin=digitalRead(alevsensoru);
    duman=analogRead(dumandedektoru);
    if(yangin == LOW)
    {
      if(duman > 90=)
      {
        while(duman > 90)
        {
          duman=analogRead(dumandedektoru);
        }
        icilendeger++;
      }
    }
  }
 }
}
 

}
