#include <Servo.h> 
Servo fan;

int servoPin=9;
int buttonPin=2;

int resetAng=5;
int angle=0;
int fanSpeed=20;
int maxAng=180,minAng=0;

void setup(){
  fan.attach(servoPin); 
  pinMode(buttonPin,INPUT);
}
void loop(){
  
 while(angle<maxAng){
   if(digitalRead(buttonPin)==HIGH){
     maxAng=angle;
     delay(100);
     angle-=2;
   }
   angle+=1;
   fan.write(angle);
   delay(fanSpeed);

 } 
 
 while(angle>minAng){
   if(digitalRead(buttonPin)==HIGH){
     minAng=angle;
     delay(100);
     angle+=2;
     
   }
   angle-=1;
   fan.write(angle);
   delay(fanSpeed);
 }
 if(abs(minAng-maxAng)<=resetAng){
   maxAng=180;
   minAng=0;
 }
 
}




