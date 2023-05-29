	
	//Quadrant 4
	int redpixels = 0;
	int greenpixels = 0;
	int bluepixels = 0;
	int red_object_count = 0;
	
	//put the camera up
	servo_full_up();
	
	for (int col = 0; col < 320; col++) {
		take_picture();

		//get red pixels and green pixels
		int red = (int)get_pixel(row, col, 0);
		int green = (int)get_pixel(row, col, 1);
		int blue = (int)get_pixel(row, col, 2);
		int alpha = (int)get_pixel(row, col, 3);
		
		//detect red green and blue pixels
		if (red > 2*green && red > 2*blue && alpha > 25) {
			redpixels++;
		}
		else if (green > 2*red && green > 2*blue && alpha > 25) {
			greenpixels++;
		}
		else if (blue > 2*red && blue > 2*green && alpha > 25) {
			bluepixels++;
		}
		
		//check whether there's a red cylinder or not
		if (redpixels < 300) {
			//move forward approaching the red cylinder
			move_forward(14);
		}
		else if (redpixels > 300) {
			red_object_count += 1;
			stop();
			move_back(12);
			turn(40); 
			//stop
			//reverse
			//scan to the left for green cylinder
		}
		
		//check whether there is a green cylinder or not
		if (greenpixels < 300) {
			//move forward approaching the green cylinder
			move_forward(14);
		}
		else if (greenpixels > 300) {
			stop();
			move_back(12);
			turn(56);
			//stop
			//reverse
			//scan to the right for blue cylinder
		}
		
		//check whether there is a blue cylinder or not
		if (bluepixels < 300) {
			//move forward approaching the blue cylinder
			move_forward(14);
		}
		else if (bluepixels > 300) {
			stop();
			move_back(12);
			turn(40);
			//stop
			//reverse
			//scan to the left for red ball
		}
		
	}
