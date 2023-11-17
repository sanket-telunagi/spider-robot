/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo s[8];  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  // s.attach(3);  // attaches the servo on pin 9 to the servo object

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
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    for (int i = 0 ; i < 8; i++) {
      s[i].write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    for (int i = 0 ; i < 8; i++) {
      s[i].write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }              // tell servo to go to position in variable 'pos'
  }
}
