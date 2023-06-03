#include <iostream>
#include "E101.h"
#include <numeric>
#include <cstring>
#include <array>
#include <algorithm>
#include "../include/motor_contorl.hpp"


#define RIGHT_MOTOR 1 
#define LEFT_MOTOR  5

using namespace std;
int center(double error, int count, string direction){
    bool not_centerd =true;
    while(not_centerd){
        if(count == 0 ){
            //turn 45 degrees
            if(direction == "right"){
            set_motors(LEFT_MOTOR, 56);
            set_motors(RIGHT_MOTOR, 40);
            hardware_exchange();
            sleep1(300);
            set_motors(LEFT_MOTOR, 56);
            set_motors(RIGHT_MOTOR, 56);
            hardware_exchange();
            sleep1(250);
            set_motors(LEFT_MOTOR, 48);
            set_motors(RIGHT_MOTOR, 48);
            hardware_exchange();                
            }
            else{//left
                set_motors(LEFT_MOTOR, 56);
                set_motors(RIGHT_MOTOR, 40);
                hardware_exchange();
                sleep1(300);
                set_motors(LEFT_MOTOR, 40);
                set_motors(RIGHT_MOTOR, 40);
                hardware_exchange();
                sleep1(250);
                set_motors(LEFT_MOTOR, 48);
                set_motors(RIGHT_MOTOR, 48);
                hardware_exchange();
            }
            count = 1;
        }
        else{
            if(direction == "right"){
                //if(error > 60){
                    set_motors(LEFT_MOTOR, 56);
                    set_motors(RIGHT_MOTOR, 56);
                    hardware_exchange();
                    sleep1(50);
                    set_motors(LEFT_MOTOR, 48);
                    set_motors(RIGHT_MOTOR, 48);
                    hardware_exchange();  
               // }
            }
            else{
                       
               // if(error < -60){
                    set_motors(LEFT_MOTOR, 40);
                    set_motors(RIGHT_MOTOR, 40);
                    hardware_exchange();
                    sleep1(50);
                    set_motors(LEFT_MOTOR, 48);
                    set_motors(RIGHT_MOTOR, 48);
                    hardware_exchange();
                  //  }
            }
        }
        if(error >=32){
            
            return 0;
        }
       // cout<<error<<endl;
        sleep1(400);
        take_picture();
        error  = 0;
        int middle_point = 15;
        int indexpixels[320];
        int bpix =0;
        int treshold = 100;
        iota(indexpixels, indexpixels+320, -160);
        for (int col = 0; col < 320; col++) {
			//check the white pixels 
			int white = get_pixel(middle_point, col, 3);
			
			if(white < treshold){
				//black
				indexpixels[col] = indexpixels[col] *1;
				bpix++;
			}
			else{
				//white
				indexpixels[col] = indexpixels[col] * 0;
			}
			
		
		}
        for(int i = 0; i < 320;i++){
            error += indexpixels[i]; 
        }
        if(bpix){
            error = error/bpix;
        }
       

    }
    

    

}
void quad3(){
    servo_full_down();
    int leftcolumb[240];
    int hori_line[320];
    int rightcolumb[240];
    int treshold = 100;
    int midpoint_lcolumb = 15;
    int midpoint2_horizontal = 15;
    int midpoint3_rcolumb = 300;
    bool q3 = true;
    int white;
    double kp = 0.04;
    int centerd = 0;
    int count = 0;

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
        for(int row = 0; row < 240; row++){//runs through pixels on captured image
            for (int col = 0; col<320; col++){
                if(col == midpoint_lcolumb){//finds black pixels and their position for the left columb array
                    white = get_pixel(row, midpoint_lcolumb, 3);
                    if (white < treshold){
                        leftcolumb[row] = leftcolumb[row] * 1;
                        bpix_left++;
                        
                    }
                    else{leftcolumb[row] = leftcolumb[row] * 0;}
                }
                else if(row == midpoint2_horizontal){//finds black pixels and position for horizontal array
                    white = get_pixel(midpoint2_horizontal, col, 3);
                    if (white < treshold){
                        hori_line[col] = hori_line[col] * 1;
                        bpix_horiz++;
                    }
                    else{hori_line[col] = hori_line[col] * 0;}

                }
                else if( col == midpoint3_rcolumb){//finds black pixels and position for left most vertical columb array
                    white = get_pixel(row, midpoint3_rcolumb, 3);
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
        if(bpix_horiz){
            error_horiz = error_horiz/bpix_horiz;
        }
        double left_m = 51;
		double right_m = 45;
     
       /*cout<<"horiz "<< error_horiz<<endl;
        cout<<"left "<<error_l<<endl;
        cout<<"right "<< error_l<<endl;
        */
        //cout<<"left tot "<<bpix_left<<" "<<"right tot"<<bpix_right<<" "<<"horiz"<<error_horiz<<endl;
        
	    if(bpix_left > 70 && bpix_right > 70 && (error_horiz<= -130 || (error_horiz <=20 && error_horiz>=0))){
            cout<<"inter"<<endl;
            if(count == 0){
                centerd =center(error_horiz,centerd, "right");

                count++;
            }
            else if (count == 1){
                centerd = center(error_horiz,centerd, "left");
                count++;
            }
            else if (count == 2){
                centerd = center(error_horiz,centerd, "left");
                count++;
            }
            else if (count == 3){
                centerd = center(error_horiz,centerd, "right");
                count++;
            }
        
            
        }
        else if(bpix_right<30 && bpix_left>60 && error_horiz <= -130 ){
          //  cout<<"left"<<endl;
            centerd = center(error_horiz, centerd, "left");
        }
        else if(bpix_right>60 && bpix_left<30 && error_horiz <= -130){
           // cout<<"right"<<endl;
            centerd = center(error_horiz, centerd, "right");
        }
        else{ //if (bpix_right< 30&& bpix_left<30){
          //  cout<<"straight"<<endl;
            if(bpix_horiz){
                double adjustment = kp * error_horiz;
                left_m = left_m + adjustment;
                right_m = right_m + adjustment;
                set_motors(LEFT_MOTOR,left_m );
                set_motors(RIGHT_MOTOR,right_m );
                hardware_exchange();
            }
            else{
                set_motors(LEFT_MOTOR,44 );
                set_motors(RIGHT_MOTOR,52 );

            }
		
        }
        //cout<<bpix_horiz<<endl;
        //sleep1(1000);
    }
}
