//Matt Haidet  
//Jingle bells assesment

byte speaker = 1;

//Variables for rythm

int tempo = 1000;
int w = tempo;
int h = w/2;
int q = h/2;
//int e = q/2;
//int s = e/2;

int r = 0;
int c = 261;
int d = 293;
int e = 330;
int f = 350;
int g = 392;
int a = 440;
int b = 494;
int c2 = 523;

void play(int n, int r){
  tone(speaker, n, r);
  delay(r); 
}

void setup(){
  pinMode(speaker, OUTPUT); 
}

void loop(){
  jingle();
}

void jingle(){
  int notes[] = {
    e,e,e,e,e,e,e,g,c,d,e,f,f,f,f,f,e,e,e,e,d,d,e,d,g,e,e,e,e,e,e,e,g,c,d,e,f,f,f,f,f,e,e,e,g,g,e,d,c  };
  int rythms[] ={
    q,q,h,q,q,h,q,q,q,q,w,q,q,q,q,q,q,q,q,q,q,q,q,h,h,q,q,h,q,q,h,q,q,q,q,w,q,q,q,q,q,q,q,q,q,q,q,q,w  };

  for(byte n = 0; n < 49; n++){
    play(notes[n], rythms[n]);
  }   
}

