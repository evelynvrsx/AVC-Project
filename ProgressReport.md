# Road map
| Start date | Task description                  | Responsible team member     | End date | Outcome                | Actual progress as per 22 of May | 
| ------     | ------                            | ------                      | ------   |  ------                | ------ |
| 08/05      | AVC project plan                   | Evelyn, Riana               | 12/05    | Completed  | Completed on time (12/05)Algorithms, plans and tasks constructed and allocated to selected team members. Project broken down into different quadrants with completion dates.      |
| 08/05      | Connect gate to server and open by exchange with the server over WiFi | Evelyn, James               | 12/05    | Completed  | Completed on time (12/05) Successfully connects to server and opens gate with entered password.    |
| 08/05      | Construct hardware - design robot body and attachments. need to make 3D brackets to connect the wheels/motors to body and two brackets for back and front of Pi to saftly connect it to main body.                | Ran, James                  | 19/05    | Completed | Completed on time (19/05). Body of the robot ended up being constructed out of wooden paddl epop sticks to manage time. 3D brackets were designed and printed to connect the Raspberry Pi to the main body. |
| 12/05      | Quadrant 2 code - To follow the line, we detect the black pixels by getting the (000) and (111), store in an array, Error is 0 if line is in the middle of the screen. Positive if line is to the left of the centre, negative otherwise.    | Evelyn, James, Ran, Riana   | 19/05    | In progress  | Motor control function was completed on 19/05. Design of the algorithm is complete: robot can calculate where the black line is on the image and distance from the centre of the image. Still required: need to code quadrant 2 so that it can use the movement controls.   |
| 19/05      | Quadrant 3 code - Approach 2 way intersection, if white is detected, turn 180 degrees           | Evelyn, James, Ran, Riana   | 24/05    |  .  |  To be completed.   |
| 26/05      | Quadrant 4 code - Scan for the amount of red pixels, if it exceeds certain amount approach and stop at certain distance. Same process with green and blue pole. Same algorithm for red ball, if approaches, push off the table.                  | Evelyn, James, Ran, Riana   | 30/05    |  .  |  To be completed.   |
| 12/05      | Progress report                   | Evelyn, Riana               | 23/05    |  .  |     |
| 31/05      | Final testing                     |                             | 31/05    |  .  |     |

What went according to plan. What did not. ==
The connection to the server and opening the gate went according to plan and was completed on time. The construction of the hardware went well and was completed on time. Initially we intended to use a scrap 3D printed piece for the main body of the robot. We intended to design and print the parts required to complete the model. However, we ended up 3D printing the parts that connect to the Raspberry Pi and constructed the rest out of paddle pop sticks to be manage time. The code for quadrant 2 was difficult to begin and was taking longer than expected but has been mostly completed at this stage. We still need to code for quadrant 2 to use the motor controls and begin coding for quadrant 3 and 4. 

What are bottlenecks, what is slowing the development ==
On the 22/05, the wifi server went down making it difficult to test and is therfore slowing the development. Some mof the robot's pieces are not measured correctly which is therefore slowing down the testing of the code. 

Team recommendation on how to advance the Project ==
