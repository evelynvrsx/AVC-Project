#include "../include/motor_contorl.hpp"
#include "E101.h"
#include <iostream>

using namespace std;
//setting functions for quadrant 4
int scan_redcylinder(int redpixels) {
	//check whether there's a red cylinder or not
	if (redpixels < 300) {
		//move forward approaching the red cylinder
		move_forward(12);
		return 0;
	}
	else if (redpixels > 300) {
		sleep1(1000);
		move_back(12);
		turn(40);
		cout<<"finish red"<<endl;
		return 1;
	}	
}

int scan_greencylinder(int greenpixels) {
	//check whether there's a green cylinder or not
	if (greenpixels < 300) {
		//move forward approaching the green cylinder
		move_forward(12);
		return 0;
	}
	else if (greenpixels > 300) {
		stop();
		move_back(12);
		turn(40);
		return 1;
	}	
}

int scan_bluecylinder(int bluepixels) {
	//check whether there's a blue cylinder or not
	if (bluepixels < 300) {
		//move forward approaching the blue cylinder
		move_forward(12);
		return 0;
	}
	else if (bluepixels > 300) {
		stop();
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
	//int red_object_count = 0;
	int row = 120;
	
	//put the camera up
	servo_full_up();
while(true){
	for (int col = 0; col < 320; col++) {
		take_picture();

		//get red pixels and green pixels
		int red = (int)get_pixel(row, col, 0);
		int green = (int)get_pixel(row, col, 1);
		int blue = (int)get_pixel(row, col, 2);
		int alpha = (int)get_pixel(row, col, 3);
		
		
		//detect red green and blue pixels
		if (red > 2*green && red > 2*blue && alpha > 25) {
			redpixels++;
		}
		if (green > 2*red && green > 2*blue && alpha > 25) {
			greenpixels++;
		}
		if (blue > 2*red && blue > 2*green && alpha > 25) {
			bluepixels++;
		}
		
		
		//call functions to detect cylinders and red ball
		
	}

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