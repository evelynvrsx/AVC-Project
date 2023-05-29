#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_contorl.hpp"

#define RIGHT_MOTOR 1 
#define LEFT_MOTOR  5

using namespace std;
void quad3(){
    servo_full_down();
    int leftcolumb[240];
    int hori_line[320];
    int rightcolumb[240];
    int treshold = 100;
    int midpoint_lcolumb = 15;
    int midpoint2_horizontal = 15;
    int midpoint3_rcolumb = 300;
    bool q3 = true;
    int white;
    double kp = 0.05;

    while(q3){
        take_picture();
        int bpix_left = 0;
        int bpix_horiz = 0;
        int bpix_right = 0;
        int error_l = 0;
        int error_horiz = 0;
        int count = 0;
        int error_r = 0;
        iota(leftcolumb, leftcolumb+240, -120);
        iota(hori_line, hori_line+320, -160);
        iota(rightcolumb, rightcolumb+240, -120);
        for(int row = 0; row < 240; row++){//runs through pixels on captured image
            for (int col = 0; col<320; col++){
                if(col == midpoint_lcolumb){//finds black pixels and their position for the left columb array
                    white = get_pixel(row, midpoint_lcolumb, 3);
                    if (white < treshold){
                        leftcolumb[row] = leftcolumb[row] * 1;
                        bpix_left++;
                        
                    }
                    else{leftcolumb[row] = leftcolumb[row] * 0;}
                }
                else if(row == midpoint2_horizontal){//finds black pixels and position for horizontal array
                    white = get_pixel(midpoint2_horizontal, col, 3);
                    if (white < treshold){
                        hori_line[col] = hori_line[col] * 1;
                        bpix_horiz++;
                    }
                    else{hori_line[col] = hori_line[col] * 0;}

                }
                else if( col == midpoint3_rcolumb){//finds black pixels and position for left most vertical columb array
                    white = get_pixel(row, midpoint3_rcolumb, 3);
                    if (white < treshold){
                        rightcolumb[row] = rightcolumb[row] * 1;
                        bpix_right++;
                    }
                    else{rightcolumb[row]= rightcolumb[row] * 0;}
                }
                
                
                
            }
        }
        for(int i = 0; i < 320;i++){
            error_horiz += hori_line[i]; 
        }
        for (int i = 0; i<240; i++){
            error_l += leftcolumb[i];
            error_r += rightcolumb[i];

        }
        if(bpix_horiz){
            error_horiz = error_horiz/bpix_horiz;
        }
        double left_m = 52;
		double right_m = 44;
     
       /*cout<<"horiz "<< error_horiz<<endl;
        cout<<"left "<<error_l<<endl;
        cout<<"right "<< error_l<<endl;
        */
        cout<<"left tot "<<bpix_left<<" "<<"right tot"<<bpix_right<<" "<<"horiz"<<error_horiz<<endl;
        
	    /*if(bpix_left > 90 && bpix_right > 90){
            cout<<"h";
            if(count == 0){
                set_motors(LEFT_MOTOR, 48);
                hardware_exchange();
                sleep1(400);
                count++;
            }
            else if(count == 1){
                set_motors(LEFT_MOTOR, 48);
                hardware_exchange();
                sleep1(400);
                count++;
            }
            else if (count ==2){
                set_motors(RIGHT_MOTOR, 48);
                hardware_exchange();
                sleep1(400);
                count++;
            }
        }*/
        if(bpix_left>(2*bpix_right) && error_horiz == -140 ){
            cout<<"left"<<endl;
            set_motors(LEFT_MOTOR, left_m);
            set_motors(RIGHT_MOTOR, right_m);
            sleep1(600);
            set_motors(LEFT_MOTOR, 48);
            set_motors(RIGHT_MOTOR, 40);
            hardware_exchange();
            sleep1(700);
        }
        else if(bpix_right>(2*bpix_left)&& error_horiz == -140){
            cout<<"right"<<endl;
            set_motors(LEFT_MOTOR, )
        }
        else{ //if (bpix_right< 30&& bpix_left<30){
            cout<<"straight"<<endl;
         
            double adjustment = kp * error_horiz;
			left_m = left_m + adjustment;
			right_m = right_m + adjustment;
            set_motors(LEFT_MOTOR,left_m );
            set_motors(RIGHT_MOTOR,right_m );
            hardware_exchange();
            
		
        }
    }
}
