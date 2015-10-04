// RGB LED Globe - demonstrator :: inital tester for reed switch on D0. HIGH on magnet pass.
// Simple 10 RGB LED common cathode
// no motor sync or control, just the blinking leds to display stuff
//to hell with the H-Sync, this is all about V-Sync

//Digital pins
int Gr0 = 11; // was 0, 0 is the hall effect interupt
int Gr1 = 1;
int Gr2 = 2;
int Gr3 = 0;
int Gr4 = 4;
int Gr5 = 5;
int Gr6 = 6;
int Gr7 = 7;

int R = 8;
int G = 9;
int B = 10;

int a = 0;
int bb = 0;
int Count = 0;

int aa=0;
int secRun = 0;
int rotOffest = 0;

int vram[50][8];
int vramC[50];

int intPin = 3;
int width = 50;

void setup() {      
  delay(1250);  // crash protection
  //attachInterrupt(1, blink, RISING );
  pinMode(intPin, INPUT);
  //memset(vram, 0, 8*width);
  for(int y=0; y<8; y++){
    for(int x=1; x<width; x++){
       vram[x][y] = 0;
    }
  }
  randomSeed(analogRead(0));
      
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

  for(int x=0; x<width; x++){
     vram[x][0] = 1;
     vram[x][1] = 0;
     vram[x][2] = 0;
     vram[x][3] = 0;
     vram[x][4] = 0;
     vram[x][5] = 0;
     vram[x][6] = 0;
     vram[x][7] = 0;
     vramC[x] = 4;
  }
  
  setScreen();
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


void WriteLine(int Colourr, int L1,int L2,int L3,int L4,int L5,int L6,int L7,int L8){
  if(Colourr==1){digitalWrite(R, LOW);}else{digitalWrite(R, HIGH);}
  if(Colourr==2){digitalWrite(G, LOW);}else{digitalWrite(G, HIGH);}
  if(Colourr==3){digitalWrite(B, LOW);}else{digitalWrite(B, HIGH);}
  
  if(Colourr==4){
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
  if(L1==0){digitalWrite(Gr0, LOW);}else{digitalWrite(Gr0, HIGH);}
  if(L2==0){digitalWrite(Gr1, LOW);}else{digitalWrite(Gr1, HIGH);}
  if(L3==0){digitalWrite(Gr2, LOW);}else{digitalWrite(Gr2, HIGH);}
  if(L4==0){digitalWrite(Gr3, LOW);}else{digitalWrite(Gr3, HIGH);}
  if(L5==0){digitalWrite(Gr4, LOW);}else{digitalWrite(Gr4, HIGH);}
  if(L6==0){digitalWrite(Gr5, LOW);}else{digitalWrite(Gr5, HIGH);}
  if(L7==0){digitalWrite(Gr6, LOW);}else{digitalWrite(Gr6, HIGH);}
  if(L8==0){digitalWrite(Gr7, LOW);}else{digitalWrite(Gr7, HIGH);}
  pixelHold();
  
  
}


void loop(){
   if(digitalRead(intPin)==1){
     secRun = millis() / 1000;
     
     if((secRun>0)&&(secRun<10)){
       blink();
     }
     if((secRun>9)&&(secRun<20)){
       blink2();
     }
     if(secRun>19){
       blink2();
     }
     
     while(digitalRead(intPin)==1){
       //do nothing
     }
  }
}

void blink(){
  for(int x=0; x<width; x++){
      WriteLine(vramC[x],vram[x][0], vram[x][1], vram[x][2], vram[x][3], vram[x][4], vram[x][5], vram[x][6], vram[x][7]);
  }
}

void blink2(){
  int localOffset = 0;
  for(int x=0; x<width; x++){
      localOffset = rotOffest + x;
      if(localOffset>=width){ localOffset = localOffset - width; }
      WriteLine(vramC[localOffset], vram[localOffset][0], vram[localOffset][1], vram[localOffset][2], vram[localOffset][3], vram[localOffset][4], vram[localOffset][5], vram[localOffset][6], vram[localOffset][7]);
  }
  rotOffest++;
  if(rotOffest>width){rotOffest=0;}
}




void setScreen(){
    int sizey = 0;
    int tt=0;
    int x1=0;
    int cCol = 0;
    for(int x11 = 0; x11<8; x11++){
        cCol++;
        if(cCol==1){vramC[x1+tt] = 1;}
        if(cCol==2){vramC[x1+tt] = 2;}
        if(cCol==3){vramC[x1+tt] = 3;  }
        
        vram[x1+tt][0] = 0;
        vram[x1+tt][1] = 0;
        vram[x1+tt][2] = 0;
        vram[x1+tt][3] = 0;
        vram[x1+tt][4] = 0;
        vram[x1+tt][5] = 0;
        vram[x1+tt][6] = 0;
        vram[x1+tt][7] = 0;
        tt++;
      
        if(cCol==1){vramC[x1+tt] = 1;}
        if(cCol==2){vramC[x1+tt] = 2;}
        if(cCol==3){vramC[x1+tt] = 3; }
        vram[x1+tt][0] = 0;
        vram[x1+tt][1] = 0;
        vram[x1+tt][2] = 0;
        vram[x1+tt][3] = 1;
        vram[x1+tt][4] = 0;
        vram[x1+tt][5] = 0;
        vram[x1+tt][6] = 0;
        vram[x1+tt][7] = 0;
        tt++;
      
        if(cCol==1){vramC[x1+tt] = 1;}
        if(cCol==2){vramC[x1+tt] = 2;}
        if(cCol==3){vramC[x1+tt] = 3;  }
        
        vram[x1+tt][0] = 0;
        vram[x1+tt][1] = 0;
        vram[x1+tt][2] = 0;
        vram[x1+tt][3] = 1;
        vram[x1+tt][4] = 0;
        vram[x1+tt][5] = 0;
        vram[x1+tt][6] = 0;
        vram[x1+tt][7] = 0;
        tt++;
      
        if(cCol==1){vramC[x1+tt] = 1;}
        if(cCol==2){vramC[x1+tt] = 2;}
        if(cCol==3){vramC[x1+tt] = 3; }
        
        vram[x1+tt][0] = 0;
        vram[x1+tt][1] = 0;
        vram[x1+tt][2] = 1;
        vram[x1+tt][3] = 1;
        vram[x1+tt][4] = 1;
        vram[x1+tt][5] = 0;
        vram[x1+tt][6] = 0;
        vram[x1+tt][7] = 0;
        tt++;
      
        if(cCol==1){vramC[x1+tt] = 1;}
        if(cCol==2){vramC[x1+tt] = 2;}
        if(cCol==3){vramC[x1+tt] = 3;  }
        
        vram[x1+tt][0] = 0;
        vram[x1+tt][1] = 0;
        vram[x1+tt][2] = 0;
        vram[x1+tt][3] = 1;
        vram[x1+tt][4] = 0;
        vram[x1+tt][5] = 0;
        vram[x1+tt][6] = 0;
        vram[x1+tt][7] = 0;
        tt++;
      
        if(cCol==1){vramC[x1+tt] = 1;}
        if(cCol==2){vramC[x1+tt] = 2;}
        if(cCol==3){vramC[x1+tt] = 3; }
        
        vram[x1+tt][0] = 0;
        vram[x1+tt][1] = 0;
        vram[x1+tt][2] = 0;
        vram[x1+tt][3] = 1;
        vram[x1+tt][4] = 0;
        vram[x1+tt][5] = 0;
        vram[x1+tt][6] = 0;
        vram[x1+tt][7] = 0;
        tt++;
      
        if(cCol==1){vramC[x1+tt] = 1;}
        if(cCol==2){vramC[x1+tt] = 2;}
        if(cCol==3){vramC[x1+tt] = 3; cCol = 0; }
    }
}



void pixelHold(){
   pixelON();
   digitalWrite(Gr0, LOW);
   digitalWrite(Gr1, LOW);
   digitalWrite(Gr2, LOW);
   digitalWrite(Gr3, LOW);
   digitalWrite(Gr4, LOW);
   digitalWrite(Gr5, LOW);
   digitalWrite(Gr6, LOW);
   digitalWrite(Gr7, LOW);
   pixelAdvance();
}

void pixelON(){
  for(a=0;a<600;a++){  //800
     //do nothing
   }
}

void pixelAdvance(){
  for(a=0;a<2000;a++){ //2800
     //do nothing
   }
}
