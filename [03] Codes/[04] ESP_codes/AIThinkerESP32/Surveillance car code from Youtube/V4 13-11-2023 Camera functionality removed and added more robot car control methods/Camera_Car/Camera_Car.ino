

#include "esp_camera.h"
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <iostream>
#include <sstream>


#include "wheelMovement.h"  //For the functions controlling the movement of the vehicle. 
#include "htmlHomePage.h"
#include "SerialCommand.h"
#include "CommonVariables.h" //for holding the variables used
                              //by more than one sketches. 
#include "CameraServer.h"//Holds camera and webserver related functionalities. 



void setUpPinModes()
{
  //Set up PWM
  ledcSetup(PWMSpeedChannel, PWMFreq, PWMResolution);
  ledcSetup(PWMLightChannel, PWMFreq, PWMResolution);
      
  for (int i = 0; i < motorPins.size(); i++)
  {
    pinMode(motorPins[i].pinEn, OUTPUT);    
    pinMode(motorPins[i].pinIN1, OUTPUT);
    pinMode(motorPins[i].pinIN2, OUTPUT);  

    /* Attach the PWM Channel to the motor enb Pin */
    ledcAttachPin(motorPins[i].pinEn, PWMSpeedChannel);
  }
  moveCar(STOP);

  pinMode(LIGHT_PIN, OUTPUT);    
  ledcAttachPin(LIGHT_PIN, PWMLightChannel);
}


void setup(void) 
{
  setUpPinModes();
  Serial.begin(9600);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  if(wtd)
  {
  Serial.print("AP IP address: ");
  Serial.println(IP);
  }
  
  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);
      
  wsCamera.onEvent(onCameraWebSocketEvent);
  server.addHandler(&wsCamera);

  wsCarInput.onEvent(onCarInputWebSocketEvent);
  server.addHandler(&wsCarInput);

  server.begin();
  if(wtd)
  {
  Serial.println("HTTP server started");
  }

  
  ledcWrite(PWMLightChannel, 150); 
  delay(250); 
  ledcWrite(PWMLightChannel, 0); 
  delay(250); 
   ledcWrite(PWMLightChannel, 150); 
  delay(250); 
  ledcWrite(PWMLightChannel, 0); 
  delay(250); 
  
  setupCamera();
}


void loop() 
{
  wsCamera.cleanupClients(); 
  wsCarInput.cleanupClients(); 
  sendCameraPicture(); 
  if(wtd)
  {
  Serial.printf("SPIRam Total heap %d, SPIRam Free Heap %d\n", ESP.getPsramSize(), ESP.getFreePsram());
  }

  sendSerialCommands();//Sends commands to the serial monitor in the format "x:y."
  
}
