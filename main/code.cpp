#include <iostream>
#include "E101.h"

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
    open_screen_stream();
    
    // make 1000 runs  
	for (int countrun = 0; countrun < 1000; countrun++) {
		take_picture();
		update_screen();
		
		std::vector<int> whitepixels; 	//array to store white pixels 
    
		for (int row = 0 ; row == 120 ; row++) {	
			for (int col = 0; col < 320; col++) {
	
		
				whitepixels.push_back(get_pixel(row, col, 3));
			}
		}
	}
	close_screen_stream();
	return 0;
	
	
	
	
	//testesttest
	vector<int> pixels(240); 		//array to store pixels (0s and 1s)
	//vector<int> indexpixel(320); 	//array to store indexpixel (-160 to 160)
	
	int treshold = 40;
	
	open_screen_stream();
	take_picture();
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
		iota(//begin,end,-120)
		
		//define movement based on the error
		
		if(error > //threshold){
		//turn right
		else if(error < 1 && error > -1){
			//straight
		}
		else{
			//adjust left
	}
	close_screen_stream();
	return 0;
		
}

