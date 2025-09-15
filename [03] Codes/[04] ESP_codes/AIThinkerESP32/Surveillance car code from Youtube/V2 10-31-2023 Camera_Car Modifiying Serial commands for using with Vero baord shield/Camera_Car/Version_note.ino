/*
 * 
 * Version: V2 10-31-2023 Camera_Car Modifiying Serial commands for using with Vero baord shieldmode
 * Modification starts: 10/31/2023 
 * Modifications ends:  11/01/2023
 * Targeted board: Ai Thinker ESP32 CAM Module
 * Modified by: Md. Nayeem Islam Shanto (islamshafiul283@gmail.com)
 * 
 * 
 * YT Video link of the code: 
 * https://www.youtube.com/watch?v=HfQ7lhhgDOk
 * 
 * 
 * What's new in V2? 
 *  We'll modify the serial prints. only print the  
 *  serial outputs when we are not debugging, rest 
 *  of the time we'll only print Serial output of the format
 *  "x:y."
 *  
 *  Linked y with the slider value from the websocket. 
 *  
 *  Next targets: 
 *  To implement long press thus the websocket keeps sending 
 *  those values and we can deploy the cam module the car. 
 *  Since a continuous channel is established between the 
 *  ESP and the Web, I think it's possible to continuously 
 *  send the data. 
 *  
 *  I think the process is rather easy, we'll not change any of the webcode. 
 *  In the current state, we get a data from when the button has been touched, 
 *  and another data when the button is touched up. So, we can perform 
 *  the task of recurring serial print here in the microntrontroller code, 
 *  isntead of the webcode. 
 *  
 *
 * 
 */
