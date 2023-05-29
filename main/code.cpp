#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_control.hpp"
#include <ctime>

using namespace std;

int middle_point = 160; 

int main(){
	//Quadrant 1 - Opening the gate 
    int port  = 1024;
    char server_addr[] = "130.195.3.91";
    connect_to_server(server_addr, port);
    char please[] = "Please";
    send_to_server(please);
    char password[24];
    receive_from_server(password);
    send_to_server(password);
    
    
    //Quadrant 2 
    int pixels[320];		//array to store pixels 0s and 1s
    int indexpixels[320];	//array to store 0s and 1s minus the index
    int treshold = 100;
    double kp = 0.14;
    double kd = 0.05;
    double previous_error = time(NULL);
    double previous_time = 0;
    double error;
    double current_time;
    
    double middle_point = 120;
    //double middleIndex = 160;
    
    bool q2 = true;
    
    while (true) {
		open_screen_stream();
		take_picture();
		update_screen();
		current_time = time(NULL) +1;
		
		//check the line
		for (int col = 0; col < 320; col++) {
			//check the white pixels 
			int white = get_pixel(middle_point, col, 3);
			
			if(white < treshold){
				//black
				pixels[col] = 1;
			}
			else{
				//white
				pixels[col] = 0;
			}
			
			// middle image (gives a range from -160 to 159
			iota(indexpixels, indexpixels+320, -160);

			
			// Subtract middle index from each element of indexpixel
			//for (unsigned int i = 0; i < 320; i++) {
				//indexpixels[i]= i - middleIndex;
			//}
			
			// Taking the array of white pixels and multiply each element of it with middle index
			//int checkpixel[320];
			//for (unsigned int i = 0; i < 320; i++) {
				//indexpixels[i] = pixels[i] * indexpixels[i];
				//checkpixel[i] = pixels[i] * indexpixels[i];
			//}
			
			// Calculate the sum of multiplied elements
		}
		
		for (unsigned int i = 0; i < 320; i++) {
			//error += checkpixel[i];
			error += indexpixels[i];
		}
		std::cout << "Sum: " << error << std::endl;
		
		
		//current time = timefunction

		double adjustment = kp * error + kd * ((error - previous_error)/(current_time - previous_time)) ;
		previous_error = error;
		previous_time = current_time;
		
		//define movement based on adjustment
		if (adjustment == 0) {
			move_forward(16);
		}
		
	}
    
	
	//Check red rectangle (for switching quadrants)
	int totRed = 0;
	int totGreen = 0;
	int totBlue = 0;
	double redness = 0.0;
	double greenness = 0.0;
	double blueness = 0.0;
	int numberofredpixels = 0;
	
	for (int row = 0 ; row < 24 ; row++) {
		for (int col = 0; col < 320; col++) {
			totRed = (int)get_pixel(row, col, 0);
			totGreen = (int)get_pixel(row, col, 1);
			totBlue = (int)get_pixel(row, col, 2);
			
			//get the redness, blueness, and greenness
			redness = (double)totRed/((double)totRed + (double)totBlue + (double)totGreen);
			greenness = (double)totGreen/((double)totRed + (double)totBlue + (double)totGreen);
			blueness = (double)totBlue/((double)totRed + (double)totBlue + (double)totGreen);
			
			//get red pixels and green pixels
			int redpixels = (int)get_pixel(row, col, 0);
			int greenpixels = (int)get_pixel(row, col, 1);
			
			//ratio of red pixels to green pixels
			if((redpixels > 2*greenpixels) {
				numberofredpixels += 1;
			}
		}
	} 
	cout<<numberofredpixels<<endl;
	if (numberofredpixels >= 20 && numberofredpixels <= 50) {
		cout<<"Switching to next quadrant"<<endl;
	}
	
	
    close_screen_stream();
	return 0;

}

