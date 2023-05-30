
#include <iostream>
#include <array>

#include <iterator>
#include <numeric>
#include <cstring>
#include <array>
#include "E101.h" 

#define RIGHT_MOTOR 1 
#define LEFT_MOTOR  5

using namespace std;	
int main(){
	init(0);
	open_screen_stream();
	bool t = true;
	
	
	set_motors(LEFT_MOTOR, 56);
	set_motors(RIGHT_MOTOR, 56);
	hardware_exchange();
	sleep1(300);
	set_motors(LEFT_MOTOR, 48);
	set_motors(RIGHT_MOTOR, 48);
	hardware_exchange();
	return 1;

}
