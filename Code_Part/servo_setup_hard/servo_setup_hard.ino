# include <Servo.h>

Servo s[8] ;

void zero() ;
void stand() ;

void setup() {
  // put your setup code here, to run once:
  // s[0].attach(10) ;
  // s[1].attach(9) ;
  // s[2].attach(8) ;
  // s[3].attach(7) ;
  // s[4].attach(6) ;
  // s[5].attach(5) ;
  s[0].attach(2) ;
  delay(20) ;
  s[1].attach(3) ;
  delay(20) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  // zero() ;
  stand() ;
}

void zero() {
  s[0].write(90) ; // base 1
  delay(100) ;
  s[1].write(90); // leg 1
  // s[2].write(45) ;
  // s[3].write(45) ;
  // s[4].write(0) ;
  // s[5].write(0) ;
}

void stand() {
  s[0].write(90) ; // base 1
  delay(100) ;
  s[1].write(80); // leg 1
}