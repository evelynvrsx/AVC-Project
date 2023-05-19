#include <iostream>

int main(){
    int i = 0;
    int b = 5;
    for (int row = 0; row <240; row++){
        for (int col = 0; col < 320; col++){
            if(row == 120)
                
                std::cout<<i<<" ";
        }
        if(row != 120)
            std::cout<<b<<std::endl;
    }
}