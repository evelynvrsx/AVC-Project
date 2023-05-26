#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_contorl.hpp"

using namespace std;
void quad3(){
    servo_full_down();
    int leftcolumb[240];
    int hori_line[320];
    int rightcolumb[240];
    int treshold = 100;
    int midpoint_lcolumb = 20;
    int midpoint2_horizontal = 20;
    int midpoint3_rcolumb = 300;
    bool q3 = true;
    int white;

    while(q3){
        take_picture();
        int bpix_left = 0;
        int bpix_horiz = 0;
        int bpix_right = 0;
        int error_l = 0;
        int error_horiz = 0;
        int error_r = 0;
        iota(leftcolumb, leftcolumb+240, -120);
        iota(hori_line, hori_line+320, -160);
        iota(rightcolumb, rightcolumb+240, -120);
        for(int row = 0; row < 240; row++){
            for (int col = 0; col<320; col++){
                if(col == midpoint_lcolumb){
                    white = get_pixel(row, midpoint_lcolumb, 3);
                    cout<<"left "<<white<<endl;
                    if (white < treshold){
                        leftcolumb[row] = leftcolumb[row] * 1;
                        bpix_left++;
                        
                    }
                    else{leftcolumb[row] = leftcolumb[row] * 0;}
                }
                else if(row == midpoint2_horizontal){
                    white = get_pixel(midpoint2_horizontal, col, 3);
                    cout<<"mid "<<white<<endl;
                    if (white < treshold){
                        hori_line[col] = hori_line[col] * 1;
                        bpix_horiz++;
                    }
                    else{hori_line[col] = hori_line[col] * 0;}

                }
                else if( col == midpoint3_rcolumb){
                    white = get_pixel(row, midpoint3_rcolumb, 3);
                    cout<<"right "<<white<<endl;
                    if (white < treshold){
                        rightcolumb[row] = rightcolumb[row] * 1;
                        bpix_right++;
                    }
                    else{rightcolumb[row]= rightcolumb[row] * 0;}
                }
                
                
                
            }
        }
        for(int i = 0; i < 320;i++){
            error_horiz += hori_line[i]; 
        }
        for (int i = 0; i<240; i++){
            error_l += leftcolumb[i];
            error_r += rightcolumb[i];

        }
        error_horiz = error_horiz/bpix_horiz;
        error_l = error_l/bpix_left;
        error_r = error_r/bpix_right;
       /*cout<<"horiz "<< error_horiz<<endl;
        cout<<"left "<<error_l<<endl;
        cout<<"right "<< error_l<<endl;
        */
        sleep1(1000);
    }
}