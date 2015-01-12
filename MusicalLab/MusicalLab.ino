//Matt Haidet  

byte speaker = 1;

//Variables for rythm

int tempo = 1000;
int w = tempo;
int h = w/2;
int q = h/2;
int e = q/2;
int s = e/2;

int c4 = 261;
int d4 = 293;
int e4 = 330;
int f4 = 350;
int g4 = 392;
int an4 = 440;
int b4 = 494;
int c5 = 523;

void scaleUp(){
  int scale [] = {c4,d4,e4,f4,g4,an4,b4,c5};
  
  for (int n = 0; n < 8; n++){
   tone(speaker, scale[n], q);
  delay(q); 
  }
  }
  
  void chord(byte start){
     int scale [] = {c4,d4,e4,f4,g4,an4,b4,c5};
      for (int n = start; n < start+6; n+=2){
   tone(speaker, scale[n], e);
  delay(e); 
  }
  }
  
  void blues(){
    
  }
  
  void setup(){
   pinMode(speaker, OUTPUT); 
  }
  
  void loop(){
    
  }
  



