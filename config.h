//config file for quadcopter
//created on : 17/05/2019
//@uthor : Rajdeep

//-----------------motor pins definations-----------------------
#define motor_pin_0 6
#define motor_pin_1 9
#define motor_pin_2 10
#define motor_pin_3 11

#define motor_FL m0
#define motor_FR m1
#define motor_BR m2
#define motor_BL m3

//----------------interrupt pin for reciever -------------------
#define yaw_pin 5   //channel 4
#define pitch_pin 3 //channel 2
#define roll_pin 2 //channel 1
#define throttle_pin 4  //channel 3

#define NO_PORTB_PINCHANGES
#define NO_PORTC_PINCHANGES

//----------------esc-------------------------------------------
#define max_speed 2000
#define min_speed 1000
