#include <iostream>
#include <numeric>
#include <array>
#include "E101.h"

int main(){
    init(0);
    open_screen_stream();
    for (int col = 0; col < 320; col++) {
    //check the white pixels 
        int white = get_pixel(120, col, 3);
        std::cout<<white<<std::endl;
    }
    close_screen_stream();
}