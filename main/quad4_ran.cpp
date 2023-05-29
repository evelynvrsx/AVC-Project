#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_contorl.hpp"
#include <ctime>

#define RIGHT_MOTOR 1 
#define LEFT_MOTOR  5
using namespace std;

void quad4(){
    servo_full_up();
    int midpoint = 120;
    int threshold = 0.5;
    bool q4 = true;
    bool red_p = true;
    bool green_p = true;
    int pix[320];
    bool blue_p = true;
    iota(pix, pix+320, -160);


    while (red_p) {
        take_picture();
        int red_ratio;
        int redpix = 0;
        double error = 0;
        int left_m = 52;
        int right_m = 44;
        for (int col = 0; col<320; col++){
            double Red = (int)get_pixel(midpoint, col, 0);
            double Green = (int)get_pixel(midpoint, col, 1);
            double Blue = (int)get_pixel(midpoint, col, 2);
            red_ratio = (Red/(Red + Green + Blue));
            if (red_ratio > threshold){
                pix[col]=pix[col]*1;
                redpix++;
                cout<<red_ratio<<"ratio"<<endl;
                cout<<redpix<<"redpix"<<endl;
            }
            else{
                pix[col]=pix[col]*0;
            }
            for (int i = 0; i <320;i++){
                error += pix[i];
                cout<<error<<"error"<<endl;
            }
            if(redpix>60){
                error= error/redpix;
                double adjustment = kp * error;
                left_m = left_m + adjustment;
                right_m = right_m + adjustment;
            }
            else{
                left_m = 49;
                right_m = 49;
            }
            set_motors(LEFT_MOTOR, left_m);
            set_motors(RIGHT_MOTOR, right_m);
            hardware_exchange();
            if(redpix>3000){
                sleep1(1000);
                move_back(12);
                sleep1(1500);
                red_p = false;
            }   
        }
    }
}
