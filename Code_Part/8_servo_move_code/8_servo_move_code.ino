#include <Servo.h>

const int num = 8 ;
Servo s[num]; // s object

// Zero Position

const int zero_pos [num+1] PROGMEM = {  135,  45, 135,  45,  45, 135,  45, 135,  400  } ;
  // P02, P03, P05, P15, P07, P08, P11, P16,  ms


void setup() {
  // put your setup code here, to run once:
  s[0].attach(5);
  // s[0].write(90);
  s[1].attach(6);
  // s[1].write(90);
  s[2].attach(7);
  // s[2].write(90);
  s[3].attach(8);
  // s[3].write(90);
  s[4].attach(9);
  // s[4].write(90);
  s[5].attach(10);
  // s[5].write(90);
  s[6].attach(11);
  // s[6].write(90);
  s[7].attach(12);
  // s[7].write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  // for (int i =0 ; i < 8; i++ ) {
  //   s[i].write(90) ;
  //   delay(zero_pos[8]) ;
  // }
  s[0].write(90) ;
  delay(300) ;
  s[0].write(45) ;
  delay(300) ;
}




