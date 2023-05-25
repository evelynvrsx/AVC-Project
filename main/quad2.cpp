#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_contorl.hpp"
#include <ctime>

using namespace std;

int middle_point = 160; 

void quad2(){
	servo_full_down();
    //Quadrant 2 
    //array to store pixels 0s and 1s
    int indexpixels[320];	//array to store 0s and 1s minus the index
    int treshold = 100;
    double kp = 0.10;
    double kd = 0.03;
    double previous_error=0;
    double previous_time  = time(NULL);
    
    double current_time;
    
    double middle_point = 120;
    //double middleIndex = 160;
    
    bool q2 = true;
    
    while (true) {
		open_screen_stream();
		take_picture();
		update_screen();
		current_time = time(NULL) +1;
		double error = 0;
		iota(indexpixels, indexpixels+320, -160);

		//check the line
		for (int col = 0; col < 320; col++) {
			//check the white pixels 
			int white = get_pixel(middle_point, col, 3);
			
			if(white < treshold){
				//black
				indexpixels[col] = indexpixels[col] *1;
			}
			else{
				//white
				indexpixels[col] = indexpixels[col] * 0;
			}
			
				
			// Taking the array of white pixels and multiply each element of it with middle index
			//int checkpixel[320];
		
			
			// Calculate the sum of multiplied elements
		}
		
		for (unsigned int i = 0; i < 320; i++) {
			//error += checkpixel[i];
			error += indexpixels[i];
		}
	
		
		//current time = timefunction

		double adjustment = kp * error + kd * ((error - previous_error)/(current_time - previous_time)) ;
		previous_error = error;
		previous_time = current_time;
		
		//define movement based on adjustment
		/*if (adjustment == 0) {
			move_forward(16);
		}*/
		/*
		if(adjustment >= -10 && adjustment <= 10){
			cout<<"forward"<<endl;
		}
		//else if (adjustment < 0 ){
			//cout<<"right"<<endl;
		//}
		else if (adjustment > 10 || adjustment < -10){
			cout<<"left & right"<<endl;
		}
		*/
		cout<<adjustment<<endl;
		sleep1(1000);
		
	}
}  
	
	/*//Quadrant 3 
	//check whether theres a
	if ((error == 0) && (pixels[col] = 1)) {
		turn(47,100); //turn left
	}
	else if ((error == 0) && (pixels[col] = 1)) {
		turn(20,1000);
	}
	
	
    close_screen_stream();
	return 0;

}*/
