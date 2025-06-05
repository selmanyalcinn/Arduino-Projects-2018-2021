int buzzer = 3; //buzzer to arduino pin 9
//float sensoroutput;  //using sensoroutput as the difference between two values
float finaldiffvol;  //final difference voltage needed
float millivolt1;  //using millivolt as quantity read from S+
float millivolt2;  //using millivolt2 as quantity from S-
int sensorpos=A0;  //using S+ 
int sensorneg=A1;  //using S-
int sensorposval;
int sensornegval;

void setup(){
pinMode(sensorpos,INPUT);  //set sensorval1 as first output(input1 to the arduino)
pinMode(sensorneg,INPUT);  //set sensorval2 as second ouput(input2 to the arduino)
pinMode(buzzer, OUTPUT);  // Set buzzer - pin 3 as an output
Serial.begin(9600);
}

void loop(){
sensorposval=analogRead(sensorpos);  //reading the input voltage at 9
sensornegval=analogRead(sensorneg);  //reading the input voltage at 8
millivolt1=sensorposval * (5.0 / 1023.0);
millivolt2=sensornegval * (5.0 / 1023.0);
finaldiffvol = (millivolt1 + millivolt2);

}
}
