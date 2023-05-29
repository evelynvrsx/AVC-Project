#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_contorl.hpp"
#include <ctime>

using namespace std;

void quad4(){
    servo_full_up;
    int midpoint = 120;
    int threshold = 0.5;
    bool q4 = true;
    bool red_p = true;
    bool green_p = true;
    bool blue_p = true;
    iota(pix, pix+320, -160);


    while (red_p) {
        take_piture();
        int redpix = 0;
        double error = 0;
        for (int col = 0; col<320; col++){
            double Red = (int)get_pixel(midpoint, col, 0);
            double Green = (int)get_pixel(midpoint, col, 1);
            double Blue = (int)get_pixel(midpoint, col, 2);
            red_ratio = (Red/(Red + Green + Blue))
            if (red_ratio > threshold){
                pix[col]=pix[col]*1;
                redpix++;
                cout
            }
            else{
                pix[col]=pix[col]*0;
            }
            for (int i = 0; i <320;i++){
                error += pix[i];
            }
            if(redpix>30){
                error= error/redpix;
                double adjustment = kp * error;
                left_m = left_m + adjustment;
                right_m = right_m + adjustment;
            }
            else{
                left_m = 45;
                right_m = 45;
            }
            set_motors(LEFT_MOTOR, left_m);
            set_motors(RIGHT_MOTOR, right_m);
            hardware_exchange();
            if(redpix>3000){
                move_back(12);
                sleep(1500);
                red_p = false;
            }   
        }
    }
}
