#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_contorl.hpp"

using namespace std;

int middle_point = 160; 

void quad2(){
	servo_full_down();
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
    int pixels[320];
	int pix;		//array to store pixels 0s and 1s
    int indexpixels[320];	//array to store 0s and 1s minus the index
    int treshold = 100;
    //double kp = 0.01;
    //double kd = 0;
    //double adjustment = kp * error;
    double middle_point = 120;
    //double middleIndex = 160;
    
    
    iota(indexpixels, indexpixels+320, -160);
    //check the line
    for (int col = 0; col < 320; col++) {
		//check the white pixels 
		int white = get_pixel(middle_point, col, 3);
		cout<<white<<endl;
		if(white < treshold){
			//black
			indexpixels[col] = 1 * indexpixels[col];
		}
		else{
			//white
			indexpixels[col] = 0 * indexpixels[col];
			
		}
		
		// middle image (gives a range from -160 to 159
		

		
		// Subtract middle index from each element of indexpixel
		//for (unsigned int i = 0; i < 320; i++) {
			//indexpixels[i]= i - middleIndex;
		//}
		
		// Taking the array of white pixels and multiply each element of it with middle index
		//int checkpixel[320];
		/*for (unsigned int i = 0; i < 320; i++) {
			indexpixels[i] = pixels[i] * indexpixels[i];
		
		}
		*/
		
		// Calculate the sum of multiplied elements
		int error = 0;
		for (unsigned int i = 0; i < 320; i++) {
			
			error += indexpixels[i];
		}
		//std::cout << "error" << error << std::endl;
		
		//define movement based on error
		/*if (error >= -10 || error <= 10) {
			move_forward(16);
		}*/
		
	}
	
    
	

}
		

