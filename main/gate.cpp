#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <cstring>
#include <array>
#include "../include_files/E101.h"

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
    
    