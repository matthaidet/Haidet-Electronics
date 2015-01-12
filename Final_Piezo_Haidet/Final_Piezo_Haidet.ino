//Piezo Music Project

//Variables
byte speaker = 1;

int tempo = 1000;
int w = tempo;
int h = w/2;
int q = h/2;
int et = q/2;

int r = 0;
int c = 261;
int d = 293;
int e = 311;
int f = 350;
int g = 392;
int a = 440;
int b = 233;
int c2 = 523;
int lg = 196;

void setup(){
    pinMode(speaker, OUTPUT); 
}

//plays each note
void play(int n, int r){
  tone(speaker, n, r);
  delay(r); 
}

void updateValues(){
 tempo = analogRead(0)*3;
w = tempo;
 h = w/2;
 q = h/2;
 et = q/2;
}

void loop(){
  song();  
  updateValues();
}

void song(){
  int notes[] = {c2,r,g,r,e,d,c,r,c,d,e,c,b,c,lg,r,c2,r,g,r,e,d,c,c,d,e,f,d,b,c,lg,c,r,r,r,r};
  int rythms[]= {q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,et,et,q,q,q,q,q,q,h,q,q,q};
  
    for(byte n = 0; n < 36; n++){
    play(notes[n], rythms[n]);
    //Update value each note
    updateValues();
   // Serial.println(analogRead(0));
  }   
  
}
