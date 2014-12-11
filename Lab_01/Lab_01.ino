// Matt haidet Lab 01

void function1() {
 Serial.println("I am an Arduino and I communicate at");
 Serial.println("960 Baud rate. Ports 0 and 1 are used");
 Serial.println("for serial communication.");
 Serial.println("");
 Serial.println("Serial communication works well for debugging");
 Serial.println("and monitering sensor values during the");
 Serial.println("execution of a program.");
}

void function2a(int x, int y){
 Serial.println((x/2)*y); 
}

void function2b(int x, int y){
  Serial.println(2*x + x*y);
}

void function3(String names[], int arraySize){
  for(int i = 0; i < arraySize; i++){
   Serial.println(names[i]); 
  }
}
void function3(int names[], int arraySize){
  for(int i = 0; i < arraySize; i++){
   Serial.println(names[i]); 
  }
}

void function4(){
int a1[] = {1,2,3,4,5,6,7,8};
 for(int i = 0; i < 8; i++){
  Serial.println(a1[i]); 
 }
 for(int i = 7; i >= 0; i--){
  Serial.println(a1[i]); 
 }
 for(int i = 1; i < 8; i+=2){
  Serial.println(a1[i]);
 }
 for(int i = 0; i < 8; i+=2){
  Serial.println(a1[i]); 
 }
 for(int i = 6; i >= 0; i-=2){
   Serial.println(a1[i]);
 }
 for(int i = 7; i >= 0; i-=2){
   Serial.println(a1[i]);
 }
}

void function5(){
 char notes[] = {'C','D','E','F','G','A','B','C'};
 
 for(int i = 0; i <= 7; i++){
   Serial.println(notes[i]);
 }
 for(int i  = 7; i>=0; i--){
   Serial.println(notes[i]);
 }
 
}

void printFibo(int n){
   long previous = 0;
   long current = 1;
   long next = 0;
   
  for(int i = 0; i < n; i++ ){
    next = current + previous;
    Serial.println(next);
    previous = current;
    current = next;
 }
}

float calculateArea(int w, int h){
  return w*h;
}

void function8(){
 for(int i = 0; i < 100000; i++){
  Serial.println(i*10);
 } 
}
//I expect the numbers to increase by ten every incrament until they get to 100000
//After the numbers hit 32,767 they become negative and continue in a negative pattern.
//This is becuase the integer data time used as the incrementer in the "for" loop can only
//hold values from -32,767 to 32,767.  To fix this, we can simply change our int to the long data type

void function9(int target){
  int sum = 0;
  int previous = 0;
  for(int i = 0; previous < target-3; i++){
    previous = 3*i;
    sum += previous;
  }
  previous = 0;
  for(int i = 0; previous < target-5; i++){
   previous = 5*i; 
   sum += previous;
  }
  Serial.println(sum);
}

void ramble(int amount){
 String words[] = {"the", "nugget", "biscuit", "cat", "Nick", "Conor", "crimson", "leaves"};
 String suffixes[] = {"","ly", "ed", "er", "est", "-like", "ing"};
 Serial.println(""); //next line
 for(int i = 0; i < amount; i++){
   String w =  words[random(7)] + suffixes[random(5)]; //EXTRA CREDIT!!!
   Serial.print(w); 
   Serial.print(" "); //space
 }
  
}

void setup(){
  Serial.begin(9600); //init
function1();
function2a(120, 512);
function2b(97, 32);
String characters[] = {"C3P0", "R2D2", "Luke SkyWalker", "Hane Solo", "Doctor Who"};
function3(characters, 5);
function4();
function5();
printFibo(10);
Serial.println(calculateArea(10,34));
//function8();
//function9(10);
ramble(3);

}


void loop(){

}


