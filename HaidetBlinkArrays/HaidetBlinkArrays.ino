//Haidet LED Blink Arrays

void pattern(){
  byte pins[] = {2,3,4,5,6,7,8,9};
  for(byte i = 1; i < 7; i++){
    blink(pins[i]);
  }
    for(byte i = 7; i >=1 ; i--){
    blink(pins[i]);
  }
}

void blink(byte i){
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i,LOW);
}

void setup(){
  for(byte i = 2; i <10; i++){
   pinMode(i, OUTPUT);
  }
}

void loop(){
  pattern();
}
