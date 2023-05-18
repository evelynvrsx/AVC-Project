#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <cstring>
#include <array>
#include "E101.h"
#include "code_hpp/gate.hpp"

int main(){
    
    int error = init(0);
    std::cout<< "Error count: " << error <<std::endl;

    //camera functions
    open_screen_stream();//only needed to be called once
    //once we test the wiggly lines, we can see how off is the iota from the center 
    take_picture();
    update_screen();
    //end of camera code
    gate_open();
    /*check motors
    set_motors(1, 47);
    set_motors(2, 47);
    set_motors(3, 47);w
    set_motors(4, 47);
    set_motors(5, 47);
    hardware_exchange();
    //PLEASE REMOVE AFTER USE
    //WARNING!! DO NOT UNPLUG THE MOTOR CABLES AFTER THE HARDWARE IS DONE!!
    */
    stoph(); // do not move this anywhere in the system.
    return 0;   
}
//using namespace std;

/*void quad2(){
	vector<int> pixels(240); 		//array to store pixels (0s and 1s)
	//vector<int> indexpixel(320); 	//array to store indexpixel (-160 to 160)
	int pixel[320];
	int treshold = 40;

	for (int col = 0; col < 240; col++) {
		//set pixel to black if its less than treshold
		if(get_pixel(120, col, 3) < treshold){
			pixels[col] = 1; 
			//indexpixel[col] = 1;
		}
		else {
			pixels[col] = 0; 
			//indexpixel[col] = 0;
		}
		//iota();//begin,end,-120)
		
		//define movement based on the error
		
		if(error > x ){ //x = threshold
		//turn right
		}
		else if(error < 1 && error > -1){
			//straight
		}
		else{
			//adjust left
	}
    }
}
void gate_open(){
	//Quadrant 1 - Opening the gate 
    int port  = 1024;
    char server_addr[] = "130.195.3.91";
    int connection = connect_to_server(server_addr, port);

    
    char please[] = "Please";
    send_to_server(please);
    char password[24];
    receive_from_server(password);
    send_to_server(password);

    if (connection > 0){
        std::cout<<"gate opened successfully"<<std::endl;
        //return 1;
    } else{

        std::cout<<"gate failed to open"<<std::endl;
        //return 0;
    }
    
}
   

*/
