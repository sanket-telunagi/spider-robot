# include <Servo.h> 

Servo s[8] ;

            //          s0  s1  s2  s3  s4  s5  s6  s7
const int sleepV [8] = {50, 70, 20, 60, 55, 70, 10, 70} ;
const int standV [8] = {40, 30, 35, 30, 35, 30, 30, 30} ;

int curr [8] =   {0, 0, 0, 0 ,0, 0, 0, 0} ;

void servo_sleep() ;
void four_leg_dance() ;
void setup() {
  // put your setup code here, to run once:
  // -----------------
  // leg 1

  s[0].attach(2) ;
  delay(20) ;
  s[1].attach(3) ;
  delay(20) ;

// -----------------
  // leg 2

  s[2].attach(4) ;
  delay(20) ;
  s[3].attach(5) ;
  delay(20) ;  

// ----------------
  // leg 3
  s[4].attach(6) ;
  delay(20) ;
  s[5].attach(7) ;
  delay(20) ;

// -----------------
  // leg 4
  s[6].attach(8) ;
  delay(20) ;
  s[7].attach(9) ;
  delay(20) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  // servo_sleep() ;

  // int c = s[1].read() ;

  // for (int i = 70 ; i >= c; i-- ) {
  //     s[1].write(i) ;
  //     delay(10) ;
  // }

  four_leg_dance() ;
}

void servo_sleep() {

    for (int i = 0 ; i < 8; i++) {
        curr[i] = s[i].read() ;
        for (int j = curr[i]; j < sleepV[i]; j++) {

            s[i].write(j) ;
            delay(20) ;
        }
    }
}

void normal_sleep() {

    
}

void four_leg_dance() {
  for (int pos = 0; pos <= 180; pos += 1) { 

    for(int i = 1 ; i < 8; i+= 2) {
      s[1].write(pos) ;
      s[3].write(pos) ;             
      s[5].write(pos) ;
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //  for(int i = 1 ; i < 8; i+= 2) {
  //     s[i].write(pos);              // tell servo to go to position in variable 'pos'
  //     delay(15);                       // waits 15 ms for the servo to reach the position
  //   }
    s[1].write(pos) ;
    s[3].write(pos) ;
    s[5].write(pos) ;
    delay(15) ;
  }
}
