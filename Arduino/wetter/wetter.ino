#include <Wire.h>
#define adresse 0x05
int zahl=0;
int winkel=0;
const byte interruptPin = 2;
int zeit=0;
long int counter=0;
long int tosend=0;
long int zeitring[10];
int indexzeit=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

//I2C 
 Wire.begin(adresse);
  Wire.onReceive(empfangeDaten);
  Wire.onRequest(sendeDaten);
//interrupt
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interrupt, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
float voltage= sensorValue * (5.0 / 1023.0);
delay(1000);
//Serial.println("hi");



if(voltage < 0.365)
{ winkel = 1125;}
else if( voltage <0.43)
{ winkel = 68;}
else if( voltage <0.535)
{ winkel = 90;}
else if( voltage <0.76)
{ winkel = 158;}
else if( voltage <1.045)
{ winkel = 136;}
else if( voltage <1.295)
{ winkel = 202;}
else if( voltage <1.69)
{ winkel = 180;}
else if( voltage <2.115)
{ winkel = 224;}
else if( voltage <2.59)
{ winkel = 44;}
else if( voltage <3.005)
{ winkel = 248;}
else if( voltage <3.255)
{ winkel = 224;}
else if( voltage <3.635)
{ winkel = 338;}
else if( voltage <3.94)
{ winkel = 0;}
else if( voltage <4.33)
{ winkel = 292;}
else if( voltage <4.7)
{ winkel = 270;}
else{ winkel=314;}
//Serial.println(winkel);


}

void empfangeDaten(int byteCount) {
  while (Wire.available()) {
    zahl = Wire.read();
    Serial.print("Daten erhalten: ");
    Serial.println(zeit);

    if (zahl == 1) {
        tosend=(6666/zeit);// in 10m/s
    } else {
         tosend=winkel/2;
    }
  }
}

void sendeDaten() {
  Wire.write(tosend);
 
  
  //Wire.write(240000/zeit + ' ' +  winkel);
}

void interrupt(){
 
zeitring[indexzeit]= millis() - counter;

 indexzeit+=1;
if(indexzeit==10){
  
  indexzeit=0;
  zeit=0;
  for(int i=0;i<10;i++){
    
    zeit+=zeitring[i];
    
  }
  Serial.println(indexzeit);
  zeit=zeit/10;
  Serial.println(zeit);
}
counter = millis();


}
