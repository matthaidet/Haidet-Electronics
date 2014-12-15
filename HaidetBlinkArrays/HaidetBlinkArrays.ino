//Classwork: LED Array Assessment
//Matt Haidet
//All work here is honestly obtained and is my own
  byte pins[] = {2,3,4,5,6,7,8,9};
  
  void pattern(){

  for(byte i = 0; i <= 7; i++){
    flash(pins[i]);
  }
    for(byte i = 7; i >=1 ; i--){
    flash(pins[i]);
  }
}

void flash(byte i){
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i,LOW);
}


void setup(){
  for(byte i = 0; i <10; i++){
   pinMode(i, OUTPUT);
  }
}

void loop(){
pattern();
}
