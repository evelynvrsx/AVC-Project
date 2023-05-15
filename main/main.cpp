#include "gate.hpp"
#include "E101.h"
#include <iostream>

using namespace std;

int main(){

    int error = init(0);
    cout<< "Error count: " << error <<endl;

    //camera functions
    open_screen_stream;//only needed to be called once
    //once we test the wiggly lines, we can see how off is the iota from the center 
    take_picture();
    update_screen();
    //end of camera code

    gate_open();

    //check motors
    set_motors(1, 47);
    set_motors(2, 47);
    set_motors(3, 47);
    set_motors(4, 47);
    set_motors(5, 47);
    hardware_exchange();
    //PLEASE REMOVE AFTER USE
    //WARNING!! DO NOT UNPLUG THE MOTOR CABLES AFTER THE HARDWARE IS DONE!!

    stoph(); // do not move this anywhere in the system.
    return 0;   
}
