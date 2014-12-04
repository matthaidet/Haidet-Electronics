int ledPortNumber = 13;

void setup() {
 pinMode(ledPortNumber, OUTPUT); // make pin pin 
}

void loop(){
 digitalWrite(ledPortNumber, HIGH); //turn LED 13 on
 delay(1000);
 digitalWrite(ledPortNumber, LOW); //turn it off
 delay(1000);
  
  
}
