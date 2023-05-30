#include "../include/motor_contorl.hpp"
#include "E101.h"
#include <iostream>

using namespace std;
//setting functions for quadrant 4
int scan_redcylinder(int redpixels) {
	//turn to the right and scan for red cylinder
	turn(56);
	cout<<"Amount of red pixels: "<<redpixels<<endl;
	//check whether there's a red cylinder or not
	if (redpixels < 100) {
		//move forward approaching the red cylinder
		move_forward(12);
		return 0;
	}
	else if (redpixels >= 100) {
		move_back(12);
		turn(40); //scan to the left
		sleep1(1000);
		return 1;
	}	
}

int scan_greencylinder(int greenpixels) {
	cout<<"Amount of green pixels: "<<greenpixels<<endl;
	//check whether there's a green cylinder or not
	if (greenpixels < 100) {
		//move forward approaching the green cylinder
		move_forward(12);
		return 0;
	}
	else if (greenpixels >= 100) {
		sleep1(1000);
		move_back(12);
		turn(56);
		return 1;
	}	
}

int scan_bluecylinder(int bluepixels) {
	cout<<"Amount of blue pixels: "<<bluepixels<<endl;
	//check whether there's a blue cylinder or not
	if (bluepixels < 100) {
		//move forward approaching the blue cylinder
		move_forward(12);
		return 0;
	}
	else if (bluepixels >= 100) {
		sleep1(1000);
		move_back(12);
		turn(40);
		return 1;
	}	
}

int scan_redball(int redpixels) {
	//check whether there's a red cylinder or not
	if (redpixels >= 1) {
		//move forward approaching the red cylinder
		move_forward(12);
		return 0;
	}
	else {
		stop();
		return 1;
	}
}


void quad4_b(){	
	//Quadrant 4
	int count = 0;
	int redpixels = 0;
	int greenpixels = 0;
	int bluepixels = 0;
	int row = 120;
	
	//put the camera up
	servo_full_up();
	
	for (int col = 0; col < 320; col++) {
		take_picture();

		//get red pixels and green pixels
		int red = (int)get_pixel(row, col, 0);
		int green = (int)get_pixel(row, col, 1);
		int blue = (int)get_pixel(row, col, 2);
		int alpha = (int)get_pixel(row, col, 3);
		
		
		//detect red green and blue pixels
		if (red > 1.8*green && red > 1.8*blue && alpha > 25) {
			redpixels++;
		}
		if (green > 1.25*red && green > 1.58*blue && alpha > 25) {
			greenpixels++;
		}
		if (blue > 1.3*red && blue > 1.2*green && alpha > 25) {
			bluepixels++;
		}
		
		
		//call functions to detect cylinders and red ball
		if (count == 0) {
			count += scan_redcylinder(redpixels);
		}
		else if (count == 1) {
			count += scan_greencylinder(greenpixels);
		}
		else if (count == 2) {
			count += scan_bluecylinder(bluepixels);
		}
		else if (count == 3) {
			count += scan_redball(redpixels);
		}
	}
}
