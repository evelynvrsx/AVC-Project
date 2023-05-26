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

void quad2(){
	servo_full_down();
    //Quadrant 2 
    //array to store pixels 0s and 1s
    int indexpixels[320];	//array to store 0s and 1s minus the index
    int treshold = 100;
    double kp = 0.05;
 
    

    
    double middle_point = 120;
    //double middleIndex = 160;
    
    bool q2 = true;
    
    while (q2) {
		int bpix = 0;
		open_screen_stream();
		take_picture();
		update_screen();
		
		double error = 0;
		iota(indexpixels, indexpixels+320, -160);

		//check the line
		for (int col = 0; col < 320; col++) {
			//check the white pixels 
			int white = get_pixel(middle_point, col, 3);
			
			if(white < treshold){
				//black
				indexpixels[col] = indexpixels[col] *1;
				bpix++;
			}
			else{
				//white
				indexpixels[col] = indexpixels[col] * 0;
			}
			
		
		}
		double left_m = 52;
		double right_m = 44;
		
		for (unsigned int i = 0; i < 320; i++) {
			//error += checkpixel[i];
			error += indexpixels[i];

		}
		if (bpix){
			error = error/bpix;
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
		q2 = quad_change();

	}
}  
	



