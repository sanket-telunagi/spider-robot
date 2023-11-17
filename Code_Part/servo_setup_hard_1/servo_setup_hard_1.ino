# include <Servo.h>



Servo s[8] ;
            //          s0  s1  s2  s3  s4  s5  s6  s7
const int sleepV [8] = {50, 70, 20, 60, 55, 70, 10, 70} ;
const int standV [8] = {40, 30, 35, 30, 35, 30, 30, 30} ;
 int curr_angle[8] = {0,0,0,0,0,0,0,0};

const int numberOfServos = 8 ;
const int numberOfACE = 9 ;
int servoCal[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int servoPrgPeriod = 20; // ms
int servoPos[] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // Servo current position



int step = 1;
int Xstand [][numberOfACE] = {
  // P02, P03, P05, P15, P07, P08, P11, P16,  ms
  { 50, 70, 20, 60, 55, 70, 10, 70, 200}, // servo center point
  { 40, 70, 35, 60, 35, 70, 30, 70, 200}, // standby
};

void runServoPrg(int servoPrg[][numberOfACE], int step)
{
  for (int i = 0; i < step; i++) { // Loop for step

    int totalTime = servoPrg[i][numberOfACE - 1]; // Total time of this step

    // Get servo start position
    for (int it = 0; it < numberOfServos; it++) {
      servoPos[it] = s[it].read() - servoCal[it];
    }

    for (int j = 0; j < totalTime / servoPrgPeriod; j++) { // Loop for time section
      for (int k = 0; k < numberOfServos; k++) { // Loop for servo
        s[k].write((map(j, 0, totalTime / servoPrgPeriod, servoPos[k], servoPrg[i][k])) + servoCal[k]);
      }
      delay(servoPrgPeriod);
    }
  }
}

void zero() ;
void stand() ;
void sleep_fun() {
  for(int i =0 ; i < 8 ; i++) {
    s[i].write(sleepV[i]) ;
    delay(10) ;
  }
} 
void push_up() ;

void setup() {
  // put your setup code here, to run once:
  // s[0].attach(10) ;
  // s[1].attach(9) ;
  // s[2].attach(8) ;
  // s[3].attach(7) ;
  // s[4].attach(6) ;
  // s[5].attach(5) ;

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

void run_angle(int angle, int motor) {
  // curr_angle[motor] = s[motor].read() ;
  if(curr_angle[motor] <= 45) {

    for(int i= curr_angle[motor]; i < angle; i+= 1 ) {
      s[motor].write(i) ;
      delay(15);
    }
  }else {
    for(int i = curr_angle[motor] ; i >= 0; i-=1) {
    s[motor].write(i) ;
    delay(15) ;
  }
  }
  curr_angle[motor] = angle ;
  return ;
}



void loop() {
  // put your main code here, to run repeatedly:
  // zero() ;
  // s[1].write(-180) ;
  // stand() ;
  // for (int i = 0 ; i < 40 ; i++) {
  //   s[1].write(i) ;
  //   s[3].write(i) ;
  //   s[5].write(i) ;
  //   s[7].write(i) ;

  //   delay(10) ;
  // }
  // stand() ;
  // delay(1000) ;
  
  // sleep_fun() ;
  // stand() ;
  // delay(1000) ;

  // runServoPrg(Xstand, step) ;
  // for (int i = s[1].read(); i < sleepV[1]; i++) {
  //   s[1].write(i) ;
  // }
  // stand() ;
  // push_up() ;

  // sleep_fun() ;
  // stand() ;
  // s[0].write(45) ;
  // delay(100) ;
  // s[0].write(0);
  // delay(100) ;


//   // new moment


//   // s[1].write(70) ;
//   run_angle(70, 1) ;
//   curr_angle[1] = 70 ;
//   // for(int i = 0 ; i < 70; i+=5) {
//   //   s[1].write(i) ;
//   //   delay(30) ;
//   // }
//   delay(100) ;
//   // s[0].write(45) ;
//     run_angle(45, 0) ;
//     curr_angle[0] = 45 ;

//   delay(100) ;
//   // s[1].write(0) ;
//     run_angle(0, 1) ;
//     curr_angle[1] = 0 ;
// // for(int i = 70 ; i >= 0; i-=5) {
// //     s[1].write(i) ;
// //     delay(30) ;
// //   }
//   delay(100) ;
//   // s[0].write(0) ;
//     run_angle(0, 0) ;
//     curr_angle[0] = 0 ;

//   delay(100) ;

  // for (int i = 0 ; i < 180; i+=5) {
  //   s[1].write(i) ;
  //   delay(15) ;
  // }
  // for (int i = 180 ; i > 0; i-=5) {
  //   s[1].write(i) ;
  //   delay(15) ;
  // }
  // run_angle(70,1) ;
  // run_angle(70, 3) ;
  // run_angle(70,5) ;
  // run_angle(0,1) ;
  // run_angle(0, 3) ;
  // run_angle(0, 5) ;

  stand_fun() ;
 
}

void zero() {
  s[0].write(90) ; // base 1
  delay(100) ;
  s[1].write(45); // leg 1
  // s[2].write(45) ;
  // s[3].write(45) ;
  // s[4].write(0) ;
  // s[5].write(0) ;
}

// void sleep() {
//    for(int i =0 ; i < 8; i+=1) {
//     s[i].write(sleepV[i]) ;
//   }
// }



void stand_fun() {

  // -------- leg 1
  // s[0].write(20) ; // base 1
  // delay(100) ;
  // s[1].write(45); // leg 1

  // -------- leg 2
  // s[2].write(40) ; // base 1
  // delay(100) ;
  // s[3].write(0); // leg 1

  // front two legs 
  // s[1].write(45) ;
  // s[3].write(0) ;

  // delay(100) ;
  // s[0].write(20) ;
  // s[2].write(45) ;
  // s[0].write(20) ;

  for(int i = 0; i< 45; i+= 1) {
    s[0].write(i) ;
    s[2].write(i) ;
    s[4].write(i) ;
    s[6].write(i) ;
    delay(15) ;
  }

   for(int i = 0 ; i < 70; i+=1) {
    s[1].write(i) ;
    s[3].write(i) ;
    s[5].write(i) ;
    s[7].write(i) ;
    delay(15) ;
  }

  for(int i = 45; i>= 0; i-= 1) {
    s[0].write(i) ;
    s[2].write(i) ;
    s[4].write(i) ;
    s[6].write(i) ;
    delay(15) ;
  }
  for(int i = 70 ; i >= 0; i-=1) {
    s[1].write(i) ;
    s[3].write(i) ;
    s[5].write(i) ;
    s[7].write(i) ;
    delay(15) ;
  }
  // for(int i =1 ; i < 8; i+=2) {
  //   s[i].write(20) ;
  // }

  
  // for (int i = 0 ; i < 8 ; i+= 2) {
  //   for(int j = s[i].read(); j <= standV[i]; j++) {
  //     s[i].write(j) ;
  //     delay(20) ;
  //   }
  //   delay(20) ;
  // }
  // for (int i = 1 ; i < 8 ; i+= 2) {
  //   for(int j = s[i].read(); j <= sleepV[i]; j++) {
  //     s[i].write(j) ;
  //     delay(20) ;
  //   }
  //   delay(20) ;
  // }
  
}

// void sleep() 
//{

  // -------- leg 1

  // s[0].write(50) ; // leg 1
  // delay(100) ;
  // s[1].write(70);


  // -------- leg 2

  
  // s[2].write(50) ;
  // delay(100) ;
  // s[3].write(70);

  // --------- leg 3
  // s[4].write(20) ;
  // delay(100) ;
  // s[5].write(70) ;


  // --------- leg 4
  // for (int i =0 ; i <= 40; i++) {

  //   s[6].write(i) ;
  //   delay(100) ;
  // }
  // s[6].write(10) ;
  // delay(100) ;
  // s[7].write(70) ;
  // s[0].write(50) ;

  // two front legs 
  // s[0].write(45) ; // leg 1
  // s[2].write(20) ;

  // delay(100) ;

  // s[1].write(0) ;
  // s[3].write(55) ;

  // s[0].write(50) ;
  // delay(10) ;
  // s[4].write(50) ;
  // delay(10) ;
  // s[2].write(10) ;
  // delay(10) ;
  // s[6].write(10) ;
  // delay(10) ;
  // delay(100) ;
  // for(int i = 0 ; i < 8; i+= 1) {
  //   s[i].write(sleepV[i]) ;
  //   delay(10) ;
  // }

  // for (int i = 0 ; i < 8 ; i+= 2) {
  //   Serial.println(s[i].read()) ;
  //   for(int j = s[i].read(); j <= sleepV[i]; j++) {
  //     s[i].write(j) ;
  //     delay(20) ;
  //   }
  //   delay(20) ;
  // }

  // for (int i = 1 ; i < 8 ; i+= 2) {
  //   // for(int j = s[i].read(); j <= sleepV[i]; j++) {
  //   //   s[i].write(j) ;
  //   //   delay(20) ;
  //   // }
  //   // delay(20) ;

  //   int cur = s[i].read() ;

  //   for (int a = cur ; a <= sleepV[i]; a++) {
  //     s[i].write(a) ;
  //     delay(20) ;
  //   }
  //   delay(20) ;
  // }

  // for(int i = 0 ; i < 8; i++) {
  //   s[i].write(sleepV[i]) ;
  //   delay(10) ;
  // }

// }

void push_up() {
    s[3].write(40) ;
    s[5].write(40) ;
    delay(20) ;
    s[3].write(70) ;
    s[5].write(70) ;


    s[1].write(50);
    s[7].write(50) ;

    
}