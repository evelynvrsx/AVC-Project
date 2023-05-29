#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>

#include <ctime>

using namespace std;
	//Check red rectangle (for switching quadrants)
bool quad_change(){
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
			if((redpixels > 2*greenpixels)) {
				numberofredpixels += 1;
			}
		}
	} 
	cout<<numberofredpixels<<endl;
	if (numberofredpixels >= 200) {
		cout<<"Switching to next quadrant"<<endl;
        return false;
	}
	
	
    close_screen_stream();
	return true;

}


