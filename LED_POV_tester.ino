/*
http://www.arduino.cc/en/Reference/PortManipulation

D (digital pins 0 to 7) 
B (digital pin 8 to 13) 

DDRD = B11111110;  // sets Arduino pins 1 to 7 as outputs, pin 0 as input
DDRD = DDRD | B11111100;  // this is safer as it sets pins 2 to 7 as outputs
	                  // without changing the value of pins 0 & 1, which are RX & TX 

PORTD = B10101000; // sets digital pins 7,5,3 HIGH

*/

int led_on_time = 10000; // microseconds to show one LED
int led_off_time = 10000; // microseconds until next led LED

int LEDS[23][14] = {
  
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void setup(){
  delay(3000);

  for( int x=0; x < 14; x++){
   pinMode(x, OUTPUT);
  }
}

void loop(){
 for( int x=0; x < 24; x++){
    WriteLine(x);
    delayMicroseconds(1000000); 
 }
 delay(4);
}


void WriteLine(int thePos){
  int theLEDval = 0;
  for( int w=0; w < 14; w++){
    if(LEDS[thePos][w]==1){theLEDval=0;}else{theLEDval=1;}
   digitalWrite( w, theLEDval);
  }
}


