# include <Servo.h>

Servo s1, s2 ;

void setup() {

  // put your setup code here, to run once:
  s1.attach(6) ;
  delay(20) ;
  s2.attach(7) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  s1.write(0) ;
  delay(1000) ;
  s1.write(90) ;
  delay(1000) ;
  // s2.write(45) ;
  // delay(1000) ;
  // s2.write(135) ;
  // delay(1000) ;
}
