#include <iostream>
#include "../include/gate.hpp"
#include "../include/quad2.hpp"
#include "E101.h"

/* main will hold a switch case to switch between algorithims*/
int main(){
    
    int error = init(0);
    std::cout<< "Error count: " << error <<std::endl;

    //camera functions
    open_screen_stream();//only needed to be called once

    //end of camera code
    

    int quad = 0;
    /* switch case to change between algorithims*/
    switch (quad){
        case 0:
            gate_open();
            quad = 1;
        case 1:
            quad2();

   
    }
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
