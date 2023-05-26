#include "E101.h"


bool quad_change(){
    int red = 0;
   
 for (int row = 0 ; row < 5 ; row++) {			
		for (int col = 0; col < 320; col++) {
            int R = (int)get_pixel(row, col, 0);
			int G = (int)get_pixel(row, col, 1);
			int B = (int)get_pixel(row, col, 2);

            if (R > 2*G && R>2*B ) {
                red++;
	
			}
        }
}
if(red >15){
    return false;
}
return true;
}