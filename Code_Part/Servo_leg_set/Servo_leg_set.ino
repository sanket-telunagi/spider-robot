# include <Servo.h>

Servo servo[2][4];
//define servos' ports
const int servo_pin[2][4] = { {10, 9, 8, 7}, {6, 5, 4, 3}};

void setup() {
  // put your setup code here , to run once:
  for (int i =0 ; i <= 1; i++) {
    for (int j =0 ; j <= 3; j++) {
      servo[i][j].attach(servo_pin[i][j]) ;
      delay(15) ;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i =0 ; i <= 1; i++) {
    for (int j =0 ; j <= 3; j++) {
      servo[i][j].write(90) ;
      delay(15) ;
    }
  }
}
