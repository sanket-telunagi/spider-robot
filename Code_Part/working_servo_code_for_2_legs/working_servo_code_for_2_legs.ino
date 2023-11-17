/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo s1, s3, s5, s7 ;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void check() {
  s5.attach(7) ;
  delay(10) ;
  s7.attach(9) ;
  delay(10) ;
}

void add(int pos) {
  s5.write(pos) ;
  s7.write(pos) ;
}

void setup() {
  s1.attach(3) ;  // attaches the servo on pin 9 to the servo object
  s3.attach(5) ;
  // delay(100) ;
  // s5.attach(7) ;  
  // s7.attach(9) ;
  // check() ;
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    s1.write(pos);              // tell servo to go to position in variable 'pos'
    s3.write(pos) ;
    // add(pos) ;
    // s5.write(pos) ;
    
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    s1.write(pos);              // tell servo to go to position in variable 'pos'
    s3.write(pos) ;
    // add(pos) ;
    // s5.write(pos) ;
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
