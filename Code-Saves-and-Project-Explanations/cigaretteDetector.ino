int sayac;
int sensor=1;
int sensorcikis=2;
int duman;
int sayac2;
int y=1000;
int gunsayaci;
void setup()
{
Serial.begin(9600);
pinMode(sensor , OUTPUT);
pinMode(sensorcikis ,INPUT);
}

void loop() {
duman=digitalRead(sensorcikis);
for(int gunsayaci=0;gunsayaci<1000;gunsayaci++)//bir yıl saniye süresi
{
Serial.println(gunsayaci);
delayMicroseconds(1000);
if(gunsayaci<1000)// 1. ay süresi
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000); //1. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++) // 1. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac == 999)
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 

  break;

}
}
if(gunsayaci<1000)// 2. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 2. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++) //2. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 

  break;

}
}
if(gunsayaci<1000)// 3. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 3. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++)//3. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 

  break;

}
}
if(gunsayaci<1000)// 4. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 4. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++)//4. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 

  break;

}
}
if(gunsayaci<1000)// 5. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 5. ay içilen süre
  if(duman == LOW)
  {
    break;
  } 
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++)//5. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac == 1000)
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else

  break;

}
}
if(gunsayaci<1000)// 6. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 6. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
 
 break;
  
}
for(int sayac=0; sayac<y;sayac++)//6. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 
  
  break;

}
}
if(gunsayaci<1000)// 7. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 7. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++)//7. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 

  break;

}
}
if(gunsayaci<1000)// 8. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 8. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++)//8. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else

  break;

}
}
if(gunsayaci<1000)// 9. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 9. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++)//9. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
} 

else 

  break;

}
}
if(gunsayaci<1000)// 10. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 10. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++)//10. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 

  break;

}
}
if(gunsayaci<1000)// 11. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);// 11. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
  
    break;
  
}
for(int sayac=0; sayac<y;sayac++)//11. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 

  break;

}
}
if(gunsayaci<1000)//12. ay 
{
while(duman == HIGH)
 { 
  sayac++;
  Serial.println(sayac);
  delayMicroseconds(1000);//12. ay içilen süre
  if(duman == LOW)
  {
    break;
  }
  else 
break;
}
for(int sayac=0; sayac<y;sayac++)//12. ay içmeme süresi
{
Serial.println(sayac);
delayMicroseconds(1000);
if(sayac ==1000 )
{
  break;
}
if(duman == HIGH)
{
  break;
  
}
else 
  break;
}
}
}
}
