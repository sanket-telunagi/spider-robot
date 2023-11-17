# include <Servo.h>

Servo s1, s2, s3, s4, s5, s6 , s7, s8;

void setup() {
  // put your setup code here, to run once:
  s1.attach(5) ;
  s2.attach(6);
  s3.attach(7) ;
  s4.attach(8) ;
  s5.attach(9) ;
  s6.attach(10) ;
  s7.attach(3) ;
  s8.attach(4) ;
}

void loop() {
  // put your main code hereU, to run repeatedly:
  s1.write(0) ;
  delay(100) ;
  s2.write(30) ;
  delay(100) ;
  s3.write(20) ;
  delay(100) ;
  s4.write(10) ;
  delay(100) ;
  s5.write(30) ;

  s7.write(20) ;
  delay(100) ;
  s8.write(30) ;
  delay(100) ;
  s7.write(60) ;
  delay(100) ;
  s8.write(90) ;
  delay(100) ;
}
