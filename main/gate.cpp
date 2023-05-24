#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <cstring>
#include <array>
#include "E101.h"
#include "../include/motor_contorl.hpp"

/*Pings gate server and requests to open gate */
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
    sleep1(200);
    move_forward(15);
    sleep1(200);
    stop();



    
}
    
    