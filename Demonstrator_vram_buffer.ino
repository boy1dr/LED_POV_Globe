// RGB LED Globe - demonstrator :: inital tester for reed switch on D0. HIGH on magnet pass.
// Simple 10 RGB LED common cathode
// no motor sync or control, just the blinking leds to display stuff
//to hell with the H-Sync, this is all about V-Sync

//Font - characters {G,C,t,e,c,h}
      int fonty[6][5][8] = {
        {
          {0,1,1,1,1,1,0},
	  {1,0,0,0,0,0,1},
	  {1,0,0,0,0,0,1},
	  {1,0,1,0,0,0,1},
	  {0,1,1,0,0,1,0}
        },
        {
          {0,1,1,1,1,1,0},
          {1,0,0,0,0,0,1},
          {1,0,0,0,0,0,1},
          {1,0,0,0,0,0,1},
          {0,1,0,0,0,1,0}
        },
        { 
          {0,0,0,0,1,0,0},
          {0,1,1,1,1,1,1},
          {1,0,0,0,1,0,0},
          {1,0,0,0,0,0,0},
          {0,1,0,0,0,0,0}
        },
        { 
          {0,1,1,1,0,0,0},
          {1,0,1,0,1,0,0},
          {1,0,1,0,1,0,0},
          {1,0,1,0,1,0,0},
          {0,0,1,1,0,0,0}
        },
        { 
          {0,1,1,1,0,0,0},
          {1,0,0,0,1,0,0},
          {1,0,0,0,1,0,0},
          {1,0,0,0,1,0,0},
          {0,1,0,0,0,0,0}
        },
        { 
          {1,1,1,1,1,1,1},
          {0,0,0,1,0,0,0},
          {0,0,0,0,1,0,0},
          {0,0,0,0,1,0,0},
          {1,1,1,1,0,0,0}
        }
      };


//Digital pins
int Gr0 = 0; // 11
int Gr1 = 1;  // 1
int Gr2 = 2;  // 2
int Gr3 = 4;  // 0
int Gr4 = 5;  // 4
int Gr5 = 6;  // 5
int Gr6 = 7;  // 6
int Gr7 = 8;  // 7

int R = 9;    // 8
int G = 10;    // 9
int B = 11;   // 10

int a = 0;
int bb = 0;
int Count = 0;

int aa=0;
int secRun = 0;
int rotOffest = 0;

int vram[50][8];
int vramC[50];

int BUFFvram[50][8];
int BUFFvramC[50];

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
     vram[x][0] = 0;
     vram[x][1] = 0;
     vram[x][2] = 0;
     vram[x][3] = 0;
     vram[x][4] = 0;
     vram[x][5] = 0;
     vram[x][6] = 0;
     vram[x][7] = 0;
     vramC[x] = 0;
  }
  
  LoadBuffer1();
}

void ClearBuffer(){
  for(int x=0; x<width; x++){
     BUFFvram[x][0] = 0;
     BUFFvram[x][1] = 0;
     BUFFvram[x][2] = 0;
     BUFFvram[x][3] = 0;
     BUFFvram[x][4] = 0;
     BUFFvram[x][5] = 0;
     BUFFvram[x][6] = 0;
     BUFFvram[x][7] = 0;
     BUFFvramC[x] = 0;
  }  
}


void ResetLeds(){
  digitalWrite(Gr0, HIGH);
  digitalWrite(Gr1, HIGH);
  digitalWrite(Gr2, HIGH);
  digitalWrite(Gr3, HIGH);
  digitalWrite(Gr4, HIGH);
  digitalWrite(Gr5, HIGH);
  digitalWrite(Gr6, HIGH);
  digitalWrite(Gr7, HIGH);
  
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}


void WriteLine(int Colourr, int L1,int L2,int L3,int L4,int L5,int L6,int L7,int L8){
  if(Colourr==0){  //BLACK
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
  if(Colourr==1){  //RED
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
  if(Colourr==2){  //Yellow
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  }
  if(Colourr==3){  //Green
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  }
  if(Colourr==4){  //Cyan
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
  }
  if(Colourr==5){  //Blue
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  }
  if(Colourr==6){  //Magenta
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  }
  if(Colourr==7){  //White
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
  }
  
  if(L8==0){digitalWrite(Gr0, HIGH);}else{digitalWrite(Gr0, LOW);}
  if(L7==0){digitalWrite(Gr1, HIGH);}else{digitalWrite(Gr1, LOW);}
  if(L6==0){digitalWrite(Gr2, HIGH);}else{digitalWrite(Gr2, LOW);}
  if(L5==0){digitalWrite(Gr3, HIGH);}else{digitalWrite(Gr3, LOW);}
  if(L4==0){digitalWrite(Gr4, HIGH);}else{digitalWrite(Gr4, LOW);}
  if(L3==0){digitalWrite(Gr5, HIGH);}else{digitalWrite(Gr5, LOW);}
  if(L2==0){digitalWrite(Gr6, HIGH);}else{digitalWrite(Gr6, LOW);}
  if(L1==0){digitalWrite(Gr7, HIGH);}else{digitalWrite(Gr7, LOW);}
  
  pixelHold();
}


void loop(){
   if(digitalRead(intPin)==1){
     secRun = millis() / 1000;
     
     //if(secRun == 1){LoadBuffer1();}
     if((secRun>0)&&(secRun<10)){
       blink();
     }
     
     if(secRun == 10){LoadBuffer2();}
     if((secRun>9)&&(secRun<20)){
       blink2();
     }
     
     if(secRun == 20){LoadBuffer3();}
     if(secRun>19){
       blink2();
     }
     
     
     while(digitalRead(intPin)==1){
       //do nothing
     }
  }
}

void blink(){
  CopyBuffer();
  for(int x=0; x<width; x++){
      WriteLine(vramC[x],vram[x][0], vram[x][1], vram[x][2], vram[x][3], vram[x][4], vram[x][5], vram[x][6], vram[x][7]); //vramC[x]
  }
}

void blink2(){
  CopyBuffer();
  int localOffset = 0;
  for(int x=0; x<width; x++){
      localOffset = rotOffest + x;
      if(localOffset>=width){ localOffset = localOffset - width; }
      WriteLine(vramC[localOffset], vram[localOffset][0], vram[localOffset][1], vram[localOffset][2], vram[localOffset][3], vram[localOffset][4], vram[localOffset][5], vram[localOffset][6], vram[localOffset][7]); //vramC[localOffset]
  }
  rotOffest++;
  if(rotOffest>width){rotOffest=0;}
}

void blink3(){
  CopyBuffer();
  int localOffset = 0;
  for(int x=0; x<width; x++){
      localOffset = rotOffest + x;
      if(localOffset>=width){ localOffset = localOffset - width; }
      WriteLine(vramC[localOffset], vram[localOffset][0], vram[localOffset][1], vram[localOffset][2], vram[localOffset][3], vram[localOffset][4], vram[localOffset][5], vram[localOffset][6], vram[localOffset][7]); //vramC[localOffset]
  }
  rotOffest++;
  if(rotOffest>width){rotOffest=0;}
}


void LoadBuffer1(){
    ClearBuffer();
    int sizey = 0;
    int tt=0;
    int x1=0;
    int cCol = 0;
    float cColReal = 0;
    for(int x1 = 0; x1<width; x1++){
        cCol = (int)cColReal;
        if(cColReal>7){cColReal = 0;}
        BUFFvramC[x1+tt] = cCol;
        BUFFvram[x1+tt][0] = 1;
        BUFFvram[x1+tt][1] = 1;
        BUFFvram[x1+tt][2] = 1;
        BUFFvram[x1+tt][3] = 1;
        BUFFvram[x1+tt][4] = 1;
        BUFFvram[x1+tt][5] = 1;
        BUFFvram[x1+tt][6] = 1;
        BUFFvram[x1+tt][7] = 1;
        cColReal=cColReal+.5;
    }
}

void LoadBuffer2(){
    ClearBuffer();
    int sizey = 0;
    int tt=0;
    int x1=0;
    int cCol = 0;
    for(int x11 = 0; x11<8; x11++){
        cCol++;
        if(cCol>7){cCol=1;}
        BUFFvramC[x1+tt] = cCol;
        
        BUFFvram[x1+tt][0] = 0;
        BUFFvram[x1+tt][1] = 0;
        BUFFvram[x1+tt][2] = 0;
        BUFFvram[x1+tt][3] = 0;
        BUFFvram[x1+tt][4] = 0;
        BUFFvram[x1+tt][5] = 0;
        BUFFvram[x1+tt][6] = 0;
        BUFFvram[x1+tt][7] = 0;
        tt++;
      
        BUFFvramC[x1+tt] = cCol;
        BUFFvram[x1+tt][0] = 0;
        BUFFvram[x1+tt][1] = 0;
        BUFFvram[x1+tt][2] = 0;
        BUFFvram[x1+tt][3] = 1;
        BUFFvram[x1+tt][4] = 0;
        BUFFvram[x1+tt][5] = 0;
        BUFFvram[x1+tt][6] = 0;
        BUFFvram[x1+tt][7] = 0;
        tt++;
      
        BUFFvramC[x1+tt] = cCol;
        
        BUFFvram[x1+tt][0] = 0;
        BUFFvram[x1+tt][1] = 0;
        BUFFvram[x1+tt][2] = 0;
        BUFFvram[x1+tt][3] = 1;
        BUFFvram[x1+tt][4] = 0;
        BUFFvram[x1+tt][5] = 0;
        BUFFvram[x1+tt][6] = 0;
        BUFFvram[x1+tt][7] = 0;
        tt++;
      
        BUFFvramC[x1+tt] = cCol;
        
        BUFFvram[x1+tt][0] = 0;
        BUFFvram[x1+tt][1] = 0;
        BUFFvram[x1+tt][2] = 1;
        BUFFvram[x1+tt][3] = 1;
        BUFFvram[x1+tt][4] = 1;
        BUFFvram[x1+tt][5] = 0;
        BUFFvram[x1+tt][6] = 0;
        BUFFvram[x1+tt][7] = 0;
        tt++;
      
        BUFFvramC[x1+tt] = cCol;
        
        BUFFvram[x1+tt][0] = 0;
        BUFFvram[x1+tt][1] = 0;
        BUFFvram[x1+tt][2] = 0;
        BUFFvram[x1+tt][3] = 1;
        BUFFvram[x1+tt][4] = 0;
        BUFFvram[x1+tt][5] = 0;
        BUFFvram[x1+tt][6] = 0;
        BUFFvram[x1+tt][7] = 0;
        tt++;

        BUFFvramC[x1+tt] = cCol;
        
        BUFFvram[x1+tt][0] = 0;
        BUFFvram[x1+tt][1] = 0;
        BUFFvram[x1+tt][2] = 0;
        BUFFvram[x1+tt][3] = 1;
        BUFFvram[x1+tt][4] = 0;
        BUFFvram[x1+tt][5] = 0;
        BUFFvram[x1+tt][6] = 0;
        BUFFvram[x1+tt][7] = 0;
        tt++;
 
    }
}

void LoadBuffer3(){
  ClearBuffer();
  int tt=0;
  int x1 = 1;
  
  for(int bitX=0; bitX<5; bitX++){//G
      for(int bitY=0; bitY<8; bitY++){
        BUFFvram[x1+bitX][bitY] = fonty[0][bitX][bitY];
      }
      BUFFvramC[x1+bitX] = 5;
  }
  x1=x1+7;
  for(int bitX=0; bitX<5; bitX++){//C
      for(int bitY=0; bitY<8; bitY++){
        BUFFvram[x1+bitX][bitY] = fonty[1][bitX][bitY];
      }
      BUFFvramC[x1+bitX] = 5;
  }
  x1=x1+7;
  for(int bitX=0; bitX<5; bitX++){//t
      for(int bitY=0; bitY<8; bitY++){
        BUFFvram[x1+bitX][bitY] = fonty[2][bitX][bitY];
      }
      BUFFvramC[x1+bitX] = 2;
  }
  x1=x1+7;
  for(int bitX=0; bitX<5; bitX++){//e
      for(int bitY=0; bitY<8; bitY++){
        BUFFvram[x1+bitX][bitY] = fonty[3][bitX][bitY];
      }
      BUFFvramC[x1+bitX] = 2;
  }
  x1=x1+7;
  for(int bitX=0; bitX<5; bitX++){//c
      for(int bitY=0; bitY<8; bitY++){
        BUFFvram[x1+bitX][bitY] = fonty[4][bitX][bitY];
      }
      BUFFvramC[x1+bitX] = 2;
  }
  x1=x1+7;
  for(int bitX=0; bitX<5; bitX++){//h
      for(int bitY=0; bitY<8; bitY++){
        BUFFvram[x1+bitX][bitY] = fonty[5][bitX][bitY];
      }
      BUFFvramC[x1+bitX] = 2;
  }
}



void CopyBuffer(){
    for(int x=1; x<width; x++){
      vramC[x] = BUFFvramC[x];
      for(int y=0; y<8; y++){
        vram[x][y] = BUFFvram[x][y];
      }
    } 
}



void pixelHold(){
   pixelON();
   digitalWrite(Gr0, HIGH);
   digitalWrite(Gr1, HIGH);
   digitalWrite(Gr2, HIGH);
   digitalWrite(Gr3, HIGH);
   digitalWrite(Gr4, HIGH);
   digitalWrite(Gr5, HIGH);
   digitalWrite(Gr6, HIGH);
   digitalWrite(Gr7, HIGH);
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
