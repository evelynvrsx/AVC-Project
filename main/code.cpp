#include <iostream>
#include "E101.h"
#include <iterator>
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>

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
    int pixels[240];		//array to store pixels 0s and 1s
    
    int treshold = 60;
    
    open_screen_stream();
    take_picture();
    update_screen();
    
    //check the line
    for (int row = 0; row < 240; row++) {
		//check the white pixels 
		int white = get_pixel(row, middle_point, 3);
		
		if(white < treshold){
			//black
			return 1;
		}
		else{
			//white
			return 0;
		}
		
		// middle image 
		//std::iota(pixels.begin(), pixels.end(), -120);
		iota(begin(pixels), end(pixels), -120);

		
		// Subtract middle index from each element of indexpixel
		//for (int i = 0; i < indexpixel.size(); i++) {
			//indexpixel[i] -= middleIndex;
		//}
		
		// Taking the array of white pixels and multiply each element of it with middle index
		//int checkpixel[] = ;
		//for (int i = 0; i < pixels.size(); i++) {
			//checkpixel.push_back(pixels[i] * pixels[i]);
		//}
		
		// Calculate the sum of multiplied elements
		//int sum = accumulate(checkpixel.begin(), checkpixel.end(), 0);
		//std::cout << "Sum: " << sum << std::endl;
		
		//define movement based on error

	}
	
    close_screen_stream();
	return 0;

}

