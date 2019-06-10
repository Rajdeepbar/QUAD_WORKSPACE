// need more modification
//arduino have only 3 software interrupt vector
//upgrade processor for more interrupt vector
#if 0

#include "includefile.h"

volatile unsigned long time_rising[4];
volatile int time[4];
int interruptedPin;

struct RX_SIGNAL {
    volatile int yaw,pitch,roll,throttle;
}rx_signal;

rx_signal.yaw = time[0];
rx_signal.pitch = time[1];
rx_signal.roll = time[2];
rx_signal.throttle = time[3];

void reciever_init(){
    pinMode(yaw_pin,INPUT_PULLUP);
    pinMode(pitch_pin,INPUT_PULLUP);
    pinMode(roll_pin,INPUT_PULLUP);
    pinMode(throttle_pin,INPUT_PULLUP);
    
    PCintPort::attachInterrupt(yaw_pin,&rising,RISING);
    PCintPort::attachInterrupt(pitch_pin,&rising,RISING);
    PCintPort::attachInterrupt(roll_pin,&rising,RISING);
    PCintPort::attachInterrupt(throttle_pin,&rising,RISING);
}

void rising(){
    interruptedPin = PCintPort::arduinoPin;
    time_rising[interruptedPin-2]=micros;
    PCintPort::attachInterrupt(interruptedPin,&falling,FALLING);
}

void falling(){
    interruptedPin = PCintPort::arduinoPin;
    time[interruptedPin-2]=time_rising[interrupted_pin-2]-micros;
    PCintPort::attachInterrupt(interruptedPin,&falling,FALLING);
}

#endif