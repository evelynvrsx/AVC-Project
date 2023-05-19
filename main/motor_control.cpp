#include "E101.h"


#define RIGHT_MOTOR 1 
#define LEFT_MOTOR  5
#define SERVO 3
#define MID_POINT 48

void move_forward(unsigned char speed ){
    int right = MID_POINT - speed;
    int left = MID_POINT + speed;
    set_motors(RIGHT_MOTOR, right);
    set_motors(LEFT_MOTOR, left);
    hardware_exchange();
}

void move_back(unsigned char speed){
    int right = MID_POINT + speed;
    int left = MID_POINT  - speed;
    set_motors(RIGHT_MOTOR, right);
    set_motors(LEFT_MOTOR, left);
    hardware_exchange();

}
void turn(unsigned char pwm , int time){
    set_motors(RIGHT_MOTOR, pwm);
    set_motors(LEFT_MOTOR, pwm);
    hardware_exchange();
    sleep1(time);
    set_motors(RIGHT_MOTOR, MID_POINT);
    set_motors(LEFT_MOTOR, MID_POINT);
    hardware_exchange();
}

void stop(){
    set_motors(RIGHT_MOTOR, MID_POINT);
    set_motors(LEFT_MOTOR, MID_POINT);
    hardware_exchange();
}

void servo_full_up(){
    set_motors(SERVO, 63); 
    hardware_exchange();
}

void servo_full_down(){
    set_motors(SERVO, 30);
    hardware_exchange();
}
