//Matt Haidet  

byte speaker = 1;

//Variables for rythm

int tempo = 1000;
int w = tempo;
int h = w/2;
int q = h/2;
//int e = q/2;
//int s = e/2;

int c = 261;
int d = 293;
int e = 330;
int f = 350;
int g = 392;
int a = 440;
int b = 494;
int c2 = 523;

void scaleUp(){
  int scale [] = {c,d,e,f,g,a,b,c2};
  
  for (int n = 0; n < 8; n++){
   tone(speaker, scale[n], q);
  delay(q); 
  }
  }
  
  void chord(byte start){
     int scale [] = {c,d,e,f,g,a,b,c2};
      for (int n = start; n < start+6; n+=2){
   tone(speaker, scale[n], e);
  delay(e); 
  }
  }
  
  void play(int n, int r){
   tone(speaker, n, r);
  delay(r); 
  }
  
  void twinkle(){
    play(c, q);
    play(c, q);
    play(g, q);
    play(g, q);
    play(a, q);
    play(a, q);
    play(g, q);
    delay(q);
    play(f, q);
    play(f, q);
    play(e, q);
    play(e, q);
    play(d, q);
    play(d, q);
    play(c, q*1.5);
    delay(q/2);
    play(g, q);
    play(g, q);
    play(f, q);
    play(f, q);
    play(e, q);
    play(e, q);
    play(d, q);
    delay(q);
    play(g, q);
    play(g, q);
    play(f, q);
    play(f, q);
    play(e, q);
    play(e, q);
    play(d, q);
    delay(q);
        play(c, q);
    play(c, q);
    play(g, q);
    play(g, q);
    play(a, q);
    play(a, q);
    play(g, q);
    delay(q);
    play(f, q);
    play(f, q);
    play(e, q);
    play(e, q);
    play(d, q);
    play(d, q);
    play(c, q*1.5);
    delay(q/2);
  }
  
  void blues(){
    
  }
  
  void setup(){
   pinMode(speaker, OUTPUT); 
  }
  
  void loop(){
    twinkle();
  }
  



