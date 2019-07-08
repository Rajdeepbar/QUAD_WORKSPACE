//config file for quadcopter
//created on : 17/05/2019
//Author : Rajdeep

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
#define roll_pin 2 //channel 1
#define pitch_pin 3 //channel 2
#define throttle_pin 4  //channel 3
#define yaw_pin 5   //channel 4

#define NO_PORTB_PINCHANGES
#define NO_PORTC_PINCHANGES

//----------------esc-------------------------------------------
#define max_speed 2000
#define min_speed 1000

//---------------rx---------------------------------------------
#define RX1_MIN 1125
#define RX1_MAX 1870
#define RX1_MID 1480

#define RX2_MIN 1170
#define RX2_MAX 1825
#define RX2_MID 1472

#define RX3_MIN 1180 
#define RX3_MAX 1790
#define RX3_MID 1450

#define RX4_MIN 1120
#define RX4_MAX 1850
#define RX4_MID 1488
