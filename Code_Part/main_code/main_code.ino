# include <Servo.h>

Servo s[8] ;

const int pins [8] = {3, 4, 5, 6, 7, 8, 9, 10} ;



const float length_a = 55;
const float length_b = 77.5;
const float length_c = 27.5;
const float length_side = 71;
const float z_absolute = -28;
/* Constants for movement ----------------------------------------------------*/


const float z_default = -50, z_up = -30, z_boot = z_absolute;
const float x_default = 62, x_offset = 0;
const float y_start = 0, y_step = 40;
const float y_default = x_default;
/* variables for movement ----------------------------------------------------*/
volatile float site_now[2][4];    //real-time coordinates of the end of each leg
volatile float site_expect[2][4]; //expected coordinates of the end of each leg
float temp_speed[2][4];   //each axis' speed, needs to be recalculated before each movement
float move_speed;     //movement speed
float speed_multiple = 1; //movement speed multiple
const float spot_turn_speed = 4;
const float leg_move_speed = 8;
const float body_move_speed = 3;
const float stand_seat_speed = 1;
volatile int rest_counter;      //+1/0.02s, for automatic rest
//functions' parameter
const float KEEP = 255;
//define PI for calculation
const float pi = 3.1415926;
/* Constants for turn --------------------------------------------------------*/
//temp length
const float temp_a = sqrt(pow(2 * x_default + length_side, 2) + pow(y_step, 2));
const float temp_b = 2 * (y_start + y_step) + length_side;
const float temp_c = sqrt(pow(2 * x_default + length_side, 2) + pow(2 * y_start + y_step + length_side, 2));
const float temp_alpha = acos((pow(temp_a, 2) + pow(temp_b, 2) - pow(temp_c, 2)) / 2 / temp_a / temp_b);
//site for turn
const float turn_x1 = (temp_a - length_side) / 2;
const float turn_y1 = y_start + y_step / 2;
const float turn_x0 = turn_x1 - temp_b * cos(temp_alpha);
const float turn_y0 = temp_b * sin(temp_alpha) - turn_y1 - length_side;
/* ---------------------------------------------------------------------------*/


void setup(void) {
  servo_attach() ;
}

void loop(void) {
  // for (int i = 0 ; i < 8; i++) {
  //   s[i].write(0) ;
  //   delay(10) ;
  // }

  for (int i = 0 ; i < 8; i++) {
    s[i].write(0) ;
    delay(10) ;
  }

  for (int i = 0 ; i < 8; i++) {
    s[i].write(90) ;
    delay(10) ;
  }
}

void servo_attach(void)
{
  for (int i = 0 ; i < 8; i++) {
    s[i].attach(pins[i]) ;
    delay(10) ;
  }
}

void servo_detach(void)
{
  for (int i = 0; i < 8; i++)
  {
   
      s[i].detach();
      delay(100);

  }
}