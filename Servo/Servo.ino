//servo test

#include <Servo.h>

Servo leftWheel;
Servo rightWheel;

void stopAll(){
 leftWheel.write(95);
 rightWheel.write(95); 
}

void setup(){
 leftWheel.attach(9); 
rightWheel.attach(10);

leftWheel.write(0);
delay(2000);
stopAll();

rightWheel.write(0);
delay(2000);
stopAll();

leftWheel.write(180);
rightWheel.write(180);
delay(4000);
stopAll();

leftWheel.write(0);
rightWheel.write(0);
delay(3000);
stopAll();

rightWheel.write(180);
delay(1000);
stopAll();

leftWheel.write(180);
delay(1000);
stopAll();

}

void loop(){
  Serial.println(analogRead(0));
  
  if(analogRead(0) > 550){
  rightWheel.write(0);
  leftWheel.write(180);  
}
if(analogRead(0) < 550){
 rightWheel.write(90);
 leftWheel.write(90); 
} 
}

