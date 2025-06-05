int gun;
int ay;
int yil=2018;
String gun2;
String ay2;
String yil2;
String yay="/";
String a="+sigara";
String virgul=",";
void setup() {
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

String yil3=virgul+ay2+yay+gun2+yay+yil2+a;
if(gun==1){
  gun2="01";
}
if(gun==2){
  gun2="02";
}
if(gun==3){
  gun2="03";
}if(gun==4){
  gun2="04";
}if(gun==5){
  gun2="05";
}if(gun==6){
  gun2="06";
}if(gun==7){
  gun2="07";
}if(gun==8){
  gun2="08";
}if(gun==9){
  gun2="09";
}if(gun==10){
  gun2="10";
}if(gun==11){
  gun2="11";
}if(gun==12){
  gun2="12";
}if(gun==13){
  gun2="13";
}if(gun==14){
  gun2="14";
}if(gun==15){
  gun2="15";
}if(gun==16){
  gun2="16";
}if(gun==17){
  gun2="17";
}if(gun==18){
  gun2="18";
}if(gun==19){
  gun2="19";
}if(gun==20){
  gun2="20";
}if(gun==21){
  gun2="21";
}if(gun==22){
  gun2="22";
}if(gun==23){
  gun2="23";
}if(gun==24){
  gun2="24";
}if(gun==25){
  gun2="25";
}if(gun==26){
  gun2="26";
}if(gun==27){
  gun2="28";
}if(gun==29){
  gun2="29";
}if(gun==30){
  gun2="31";
}if(gun==31){
  gun2="31";
}
if(ay==1){
  ay2="01";
}
if(ay==2){
  ay2="02";
}if(ay==3){
  ay2="03";
}if(ay==4){
  ay2="04";
}if(ay==5){
  ay2="05";
}if(ay==6){
  ay2="06";
}if(ay==7){
  ay2="07";
}if(ay==8){
  ay2="08";
}if(ay==9){
  ay2="09";
}if(ay==10){
  ay2="10";
}if(ay==11){
  ay2="11";
}if(ay==12){
  ay2="12";
}
if(gun==31){
  ay++;
  gun=0;
}
if(ay>12){
  yil++;
  ay=0;
}
yil2=yil;
Serial.println(yil3);
gun++;
}
