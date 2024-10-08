#include <iostream>
#include "E101.h"
#include "../include/gate.hpp"
#include "../include/quad2.hpp"
#include "../include/quad3.hpp"
#include "../include/quad4_evelyn.hpp"


/* main will hold a switch case to switch between algorithims*/
int main(){
    
    int error = init(0);
    std::cout<< "Error count: " << error <<std::endl;

    //camera functions
    open_screen_stream();//only needed to be called once
    bool a = true;

    //end of camera code
    

    int quad = 0;
    /* switch case to change between algorithims*/
    while(a){
        switch (quad){
            case 0:
                gate_open();
                quad = 1;
            case 1:
                quad2();
                quad = 2;
            case 2:
                quad3();
            case 3:
                quad4_b();
      
    
        }
    }
    stoph(); // do not move this anywhere in the system.
    return 0;   
}

