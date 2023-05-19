/*//Quadrant 2 
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
	
	*/
#include <iostream>
#include <array>
#include <vector> /*will delet this in the future becuase arrays will be easier to use 
and the fact that it doesn't need to change means no reason for vectors
*/
#include <iterator>
#include <numeric>
#include <cstring>
#include <array>
#include "E101.h" 

using namespace std;	
void quad2(){
	//testesttest
	vector<int> pixels(240); 		//array to store pixels (0s and 1s)
	//vector<int> indexpixel(320); 	//array to store indexpixel (-160 to 160)
	
	int treshold = 40;
	int pix[240];
	
	
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
	close_screen_stream();
	//return 0;
		
}