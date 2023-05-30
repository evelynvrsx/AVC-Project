#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_contorl.hpp"
#include "../include/quad_change.hpp"

#define RIGHT_MOTOR 1 
#define LEFT_MOTOR  5

using namespace std;

int middle_point = 160; 

void quad4(){
	servo_full_up();
    //Quadrant 4 
    //array to store pixels 0s and 1s
    int indexpixels[320];	//array to store 0s and 1s minus the index
    int treshold = 100;
    double kp = 0.03;
    int count = 0;

    double middle_point = 120;
    
    bool q4 = true;
    
    while (q4) {
		int redpixels = 0;
		open_screen_stream();
		take_picture();
		update_screen();
		
		if (count == 0) {
			turn(56);
		}
		
		double error = 0;
		iota(indexpixels, indexpixels+320, -160);

		//check the line
		for (int col = 0; col < 320; col++) {
			//check the white pixels 
			int red = get_pixel(middle_point, col, 0);
			
			if(red < treshold){
				//other
				indexpixels[col] = indexpixels[col] *1;
				redpixels++;
			}
			else{
				//red
				indexpixels[col] = indexpixels[col] * 0;
			}
			
		
		}
		
		if (redpixels >= 200) {
			count = 1;
		}
		if (count = 1) {
			double left_m = 52;
			double right_m = 44;
			
			for (unsigned int i = 0; i < 320; i++) {
				error += indexpixels[i];
			}
			if (redpixels){
				error = error/redpixels;
				double adjustment = kp * error;
				left_m = left_m + adjustment;
				right_m = right_m + adjustment;
			}
			else{ 
				left_m = 44;
				right_m = 52;
			}
			set_motors(LEFT_MOTOR,left_m );
			set_motors(RIGHT_MOTOR,right_m );
			hardware_exchange();
			q4 = quad_change();
		}
	}
}  
