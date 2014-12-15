//ClassWork: LED Patterns
//Matt Haidet
//All work here is honestly obtained and is my own


/*
2-D arrays hold the values for patterns
 each set of numbers represents the lights lit in each increment
 I did this in place of seperate functions
 */
byte lottery[][8] = { 
  {
    2,4,6,8,0,0,0,0      }
  ,{
    1,3,5,7,9,0,0,0      }
};

byte flashy[][8] = {
  {
    2,8,0,0,0,0,0,0    }
  ,
  {
    3,7,0,0,0,0,0,0    }
  ,
  {
    4,6,0,0,0,0,0,0    }
  ,
  {
    5,0,0,0,0,0,0,0    }
};

byte boom[][8] = 
  {{2,3,4,5,6,7,8,9}, {0,0,0,0,0,0,0,0}};

byte upHill[][8] = {
  {
    2,0,0,0,0,0,0,0  }
  , 
  {
    3,0,0,0,0,0,0,0  }
  ,
  {
    4,0,0,0,0,0,0,0  }
  ,
  {
    5,0,0,0,0,0,0,0  }
  ,
  {
    6,0,0,0,0,0,0,0  }
  ,
  {
    7,0,0,0,0,0,0,0  }
  ,
  {
    8,0,0,0,0,0,0,0  }
      ,
  {
    9,0,0,0,0,0,0,0  }
};



void runPattern(byte p[][8], int time, byte max){
  for(int a = 0; a <= max; a++){
    for(int b = 0; b <= 8; b++){
      digitalWrite(p[a][b],HIGH);
    }
    delay(time);
    allOff();
  }
}

void allOff(){
  for(byte i = 0; i <10; i++){
    digitalWrite(i, LOW); 
  }
}

void setup(){
  for(byte i = 0; i <10; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
runPattern(upHill, 500, 6);
runPattern(lottery, 200, 2);
runPattern(lottery, 200, 2);
runPattern(lottery, 200, 2);
runPattern(lottery, 100, 2);
runPattern(lottery, 100, 2);
runPattern(flashy, 200, 4);
runPattern(flashy, 200, 4);
runPattern(boom, 400, 2);
runPattern(boom, 300, 2);
runPattern(boom, 200, 2);
runPattern(boom, 100, 2);
runPattern(boom, 50, 2);
runPattern(boom, 20, 2);
}



