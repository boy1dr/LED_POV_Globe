// RGB LED Globe - demonstrator
// Simple 10 RGB LED common cathode
// no motor sync or control, just the blinking leds to display stuff
//to hell with the H-Sync, this is all about V-Sync

//Digital pins
int Gr0 = 11; // was 0, 0 is the hall effect interupt
int Gr1 = 1;
int Gr2 = 2;
int Gr3 = 3;
int Gr4 = 4;
int Gr5 = 5;
int Gr6 = 6;
int Gr7 = 7;

int R = 8;
int G = 9;
int B = 10;

int T1 = 100;
int T2 = 1;

int Count = 0;

int ShowNumber = 0;
int a = 0;
int c = 0;

void setup() {      
  delay(5000);  // crash protection
  pinMode(Gr0, OUTPUT);     
  pinMode(Gr1, OUTPUT);     
  pinMode(Gr2, OUTPUT);     
  pinMode(Gr3, OUTPUT);     
  pinMode(Gr4, OUTPUT); 
  pinMode(Gr5, OUTPUT); 
  pinMode(Gr6, OUTPUT); 
  pinMode(Gr7, OUTPUT); 
  
  pinMode(R, OUTPUT);     
  pinMode(G, OUTPUT);     
  pinMode(B, OUTPUT);
  
  ResetLeds();
  digitalWrite(R, LOW);
}

void ResetLeds(){
  digitalWrite(Gr0, LOW);
  digitalWrite(Gr1, LOW);
  digitalWrite(Gr2, LOW);
  digitalWrite(Gr3, LOW);
  digitalWrite(Gr4, LOW);
  digitalWrite(Gr5, LOW);
  digitalWrite(Gr6, LOW);
  digitalWrite(Gr7, LOW);
  
  digitalWrite(R, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
}


void loop() {
  ResetLeds();
  for( a=0; a<=3; a++){
    Display1();
  }
  delay(250); 
  ResetLeds();
  
  for( a=0; a<=5; a++){
    Display4();
  }
  delay(250);
  ResetLeds();
  
  for( a=0; a<=100; a++){
    Display2();
  }
  delay(250);
  
  
  for( a=0; a<=100; a++){
    Display5();
  }
  delay(250);
}


void Display1(){
 Count++;
  if(Count==3){Count=0;}
  //if((Count>=0)&&(Count<=7)){
  if(Count==0){
     digitalWrite(G, LOW);
     digitalWrite(R, HIGH); //off
  }
  //if((Count>=8)&&(Count<=12)){
  if(Count==1){
     digitalWrite(B, LOW);
     digitalWrite(G, HIGH); //off
  }
  //if((Count>=13)&&(Count<=17)){
  if(Count==2){
     digitalWrite(R, LOW);
     digitalWrite(B, HIGH); //off
  }
  
  //ResetLeds();
  digitalWrite(Gr0, LOW);
  digitalWrite(Gr1, HIGH);
  delay(T1); 
  digitalWrite(Gr1, LOW);
  digitalWrite(Gr2, HIGH);
  delay(T1); 
  digitalWrite(Gr2, LOW);
  digitalWrite(Gr3, HIGH);
  delay(T1); 
  digitalWrite(Gr3, LOW);
  digitalWrite(Gr4, HIGH);
  delay(T1);
  digitalWrite(Gr4, LOW);
  digitalWrite(Gr5, HIGH);
  delay(T1);
  digitalWrite(Gr5, LOW);
  digitalWrite(Gr6, HIGH);
  delay(T1);
  digitalWrite(Gr6, LOW);
  digitalWrite(Gr7, HIGH);
  delay(T1);
  digitalWrite(Gr7, LOW);
  digitalWrite(Gr0, HIGH);
  delay(T1); 
}


void Display2(){
   digitalWrite(G, LOW);
   //H
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   delay(T2);
   delay(T2);
   //E
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   delay(T2);
 
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
 
   delay(T2);
   delay(T2);
   
   //L
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   delay(T2);
 
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
 
   delay(T2);
   delay(T2);
   
   //L
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   delay(T2);
 
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
 
   delay(T2);
   delay(T2);
   
   //O
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, LOW);
   delay(T2);
 
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
 
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
 
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
  
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   delay(T2);
   delay(T2);
}


void Display3(){
   digitalWrite(G, HIGH);
   digitalWrite(B, LOW);
   
   //H
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   //clear leds
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   
   delay(T2);
   delay(T2);
   delay(T2);
   delay(T2);
   
   
   
   
   //I
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, HIGH);
   delay(T2);
   
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   delay(T2);
   
   //clear leds
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
   
   delay(T2);
   delay(T2);
   delay(T2);
   delay(T2);
   delay(T2);
   delay(T2);
}

void Display4(){
   digitalWrite(G, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(R, LOW); //on
   
   for(c=0;c<=300;c++){
     digitalWrite(Gr0, HIGH);
     digitalWrite(Gr1, HIGH);
     digitalWrite(Gr2, HIGH);
     digitalWrite(Gr3, HIGH);
     digitalWrite(Gr4, HIGH);
     digitalWrite(Gr5, HIGH);
     digitalWrite(Gr6, HIGH);
     digitalWrite(Gr7, HIGH);
     delay(T2);
     
     digitalWrite(Gr0, LOW);
     digitalWrite(Gr1, LOW);
     digitalWrite(Gr2, LOW);
     digitalWrite(Gr3, LOW);
     digitalWrite(Gr4, LOW);
     digitalWrite(Gr5, LOW);
     digitalWrite(Gr6, LOW);
     digitalWrite(Gr7, LOW);
     delay(T2);
   }
   
   
   digitalWrite(R, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(G, LOW); //on
   
   for(c=0;c<=300;c++){
     digitalWrite(Gr0, HIGH);
     digitalWrite(Gr1, HIGH);
     digitalWrite(Gr2, HIGH);
     digitalWrite(Gr3, HIGH);
     digitalWrite(Gr4, HIGH);
     digitalWrite(Gr5, HIGH);
     digitalWrite(Gr6, HIGH);
     digitalWrite(Gr7, HIGH);
     delay(T2);
     
     digitalWrite(Gr0, LOW);
     digitalWrite(Gr1, LOW);
     digitalWrite(Gr2, LOW);
     digitalWrite(Gr3, LOW);
     digitalWrite(Gr4, LOW);
     digitalWrite(Gr5, LOW);
     digitalWrite(Gr6, LOW);
     digitalWrite(Gr7, LOW);
     delay(T2);
   }
   
   digitalWrite(G, HIGH);
   digitalWrite(R, HIGH);
   digitalWrite(B, LOW); //on
   
   for(c=0;c<=300;c++){
     digitalWrite(Gr0, HIGH);
     digitalWrite(Gr1, HIGH);
     digitalWrite(Gr2, HIGH);
     digitalWrite(Gr3, HIGH);
     digitalWrite(Gr4, HIGH);
     digitalWrite(Gr5, HIGH);
     digitalWrite(Gr6, HIGH);
     digitalWrite(Gr7, HIGH);
     delay(T2);
     
     digitalWrite(Gr0, LOW);
     digitalWrite(Gr1, LOW);
     digitalWrite(Gr2, LOW);
     digitalWrite(Gr3, LOW);
     digitalWrite(Gr4, LOW);
     digitalWrite(Gr5, LOW);
     digitalWrite(Gr6, LOW);
     digitalWrite(Gr7, LOW);
     delay(T2);
   }
}


void Display5(){
   digitalWrite(G, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(R, LOW); //on
   
   for(c=0;c<=10;c++){
     digitalWrite(Gr0, HIGH);
     digitalWrite(Gr1, HIGH);
     digitalWrite(Gr2, HIGH);
     digitalWrite(Gr3, HIGH);
     digitalWrite(Gr4, HIGH);
     digitalWrite(Gr5, HIGH);
     digitalWrite(Gr6, HIGH);
     digitalWrite(Gr7, HIGH);
     delay(T2);
     
     digitalWrite(Gr0, LOW);
     digitalWrite(Gr1, LOW);
     digitalWrite(Gr2, LOW);
     digitalWrite(Gr3, LOW);
     digitalWrite(Gr4, LOW);
     digitalWrite(Gr5, LOW);
     digitalWrite(Gr6, LOW);
     digitalWrite(Gr7, LOW);
     delay(T2);
   }
   
   
   digitalWrite(R, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(G, LOW); //on
   
   for(c=0;c<=10;c++){
     digitalWrite(Gr0, HIGH);
     digitalWrite(Gr1, HIGH);
     digitalWrite(Gr2, HIGH);
     digitalWrite(Gr3, HIGH);
     digitalWrite(Gr4, HIGH);
     digitalWrite(Gr5, HIGH);
     digitalWrite(Gr6, HIGH);
     digitalWrite(Gr7, HIGH);
     delay(T2);
     
     digitalWrite(Gr0, LOW);
     digitalWrite(Gr1, LOW);
     digitalWrite(Gr2, LOW);
     digitalWrite(Gr3, LOW);
     digitalWrite(Gr4, LOW);
     digitalWrite(Gr5, LOW);
     digitalWrite(Gr6, LOW);
     digitalWrite(Gr7, LOW);
     delay(T2);
   }
   
   digitalWrite(G, HIGH);
   digitalWrite(R, HIGH);
   digitalWrite(B, LOW); //on
   
   for(c=0;c<=10;c++){
     digitalWrite(Gr0, HIGH);
     digitalWrite(Gr1, HIGH);
     digitalWrite(Gr2, HIGH);
     digitalWrite(Gr3, HIGH);
     digitalWrite(Gr4, HIGH);
     digitalWrite(Gr5, HIGH);
     digitalWrite(Gr6, HIGH);
     digitalWrite(Gr7, HIGH);
     delay(T2);
     
     digitalWrite(Gr0, LOW);
     digitalWrite(Gr1, LOW);
     digitalWrite(Gr2, LOW);
     digitalWrite(Gr3, LOW);
     digitalWrite(Gr4, LOW);
     digitalWrite(Gr5, LOW);
     digitalWrite(Gr6, LOW);
     digitalWrite(Gr7, LOW);
     delay(T2);
   }
}
