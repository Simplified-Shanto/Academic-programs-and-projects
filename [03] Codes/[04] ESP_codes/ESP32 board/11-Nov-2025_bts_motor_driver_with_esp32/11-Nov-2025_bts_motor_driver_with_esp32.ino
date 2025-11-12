#include <ESP32Servo.h>
#define M1LPWM_LEDC_CHANNEL 6  // LEDC channel to use
#define M1RPWM_LEDC_CHANNEL 7

#define motor1Lpwm 19
#define motor1Rpwm 18

#define M2LPWM_LEDC_CHANNEL 8  // LEDC channel to use
#define M2RPWM_LEDC_CHANNEL 9

#define motor2Lpwm 13  //5
#define motor2Rpwm 14  //17

#define M3LPWM_LEDC_CHANNEL 10  // LEDC channel to use
#define M3RPWM_LEDC_CHANNEL 11

#define motor3Lpwm 5   //13
#define motor3Rpwm 17  //14

#define M4LPWM_LEDC_CHANNEL 12  // LEDC channel to use
#define M4RPWM_LEDC_CHANNEL 13

#define motor4Lpwm 26   //13
#define motor4Rpwm 27  //14

#define buttonPin 25

#define relay1In  21 
#define relay2In  22

#define vulveRelayIn 23 





#define motorSpeed 200
int startFlag = 0 ; // Whether we have started the motor running sequence with button press.


void setup() {
  Serial.begin(115200); 
  ESP32PWM::allocateTimer(0);
  ledcSetup(M1LPWM_LEDC_CHANNEL, 1000, 8);  // Set LEDC channel, frequency, and resolution
  ledcSetup(M1RPWM_LEDC_CHANNEL, 1000, 8);

  ledcAttachPin(motor1Lpwm, M1LPWM_LEDC_CHANNEL);  // Attach the GPIO pin to the LEDC channel
  ledcAttachPin(motor1Rpwm, M1RPWM_LEDC_CHANNEL);

  ledcSetup(M2RPWM_LEDC_CHANNEL, 1000, 8);
  ledcSetup(M2RPWM_LEDC_CHANNEL, 1000, 8);

  ledcAttachPin(motor2Lpwm, M2LPWM_LEDC_CHANNEL);  // Attach the GPIO pin to the LEDC channel
  ledcAttachPin(motor2Rpwm, M2RPWM_LEDC_CHANNEL);


  ledcSetup(M3RPWM_LEDC_CHANNEL, 1000, 8);
  ledcSetup(M3LPWM_LEDC_CHANNEL, 1000, 8);

  ledcAttachPin(motor3Lpwm, M3LPWM_LEDC_CHANNEL);  // Attach the GPIO pin to the LEDC channel
  ledcAttachPin(motor3Rpwm, M3RPWM_LEDC_CHANNEL);

  ledcSetup(M4RPWM_LEDC_CHANNEL, 1000, 8);
  ledcSetup(M4LPWM_LEDC_CHANNEL, 1000, 8);

  ledcAttachPin(motor4Lpwm, M4LPWM_LEDC_CHANNEL);  // Attach the GPIO pin to the LEDC channel
  ledcAttachPin(motor4Rpwm, M4RPWM_LEDC_CHANNEL);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(relay1In,  OUTPUT); 
  pinMode(relay2In, OUTPUT); 
  pinMode(vulveRelayIn, OUTPUT); 
  digitalWrite(relay1In, HIGH); 
  digitalWrite(relay2In, HIGH); 
  digitalWrite(vulveRelayIn, HIGH); 

  // put your setup code here, to run once:
}



void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(500);  //Debounce delay
    Serial.println("Pressed!"); 
    startFlag = 1 - startFlag;
    if (startFlag == 0) {
      stopMotor1();
      stopMotor2();
      stopMotor3();
    }
  }

  if (startFlag == 1) {
    digitalWrite(relay1In, LOW); 
    delay(1000); 
    digitalWrite(relay1In, HIGH); 
    delay(1000); 
    digitalWrite(relay2In, LOW); 
    delay(1000); 
    digitalWrite(relay2In, HIGH); 
    delay(1000); 

    digitalWrite(vulveRelayIn, LOW); 
    delay(1000); 
    digitalWrite(vulveRelayIn, HIGH); 
 

    runMotor1(motorSpeed);
    delay(5000);
    stopMotor1();
    delay(10);

    // runMotor2(motorSpeed);
    // delay(5000);
    // stopMotor2();
    // delay(10);

    runMotor3(motorSpeed);
    delay(5000);
    stopMotor3();
    delay(10);

    runMotor4(motorSpeed);
    delay(5000);
    stopMotor4();
    delay(10);
    startFlag = 0; 

  }
}


void runMotor1(int Speed) {
  ledcWrite(M1LPWM_LEDC_CHANNEL, 0);
  ledcWrite(M1RPWM_LEDC_CHANNEL, Speed);
}

void stopMotor1() {
  ledcWrite(M1LPWM_LEDC_CHANNEL, 0);
  ledcWrite(M1RPWM_LEDC_CHANNEL, 0);
}

void runMotor2(int Speed) {
  ledcWrite(M2LPWM_LEDC_CHANNEL, 0);
  ledcWrite(M2RPWM_LEDC_CHANNEL, Speed);
}

void stopMotor2() {
  ledcWrite(M2LPWM_LEDC_CHANNEL, 0);
  ledcWrite(M2RPWM_LEDC_CHANNEL, 0);
}


void runMotor3(int Speed) {
  ledcWrite(M3LPWM_LEDC_CHANNEL, 0);
  ledcWrite(M3RPWM_LEDC_CHANNEL, Speed);
}

void stopMotor3() {
  ledcWrite(M3LPWM_LEDC_CHANNEL, 0);
  ledcWrite(M3RPWM_LEDC_CHANNEL, 0);
}


void runMotor4(int Speed) {
  ledcWrite(M4LPWM_LEDC_CHANNEL, 0);
  ledcWrite(M4RPWM_LEDC_CHANNEL, Speed);
}

void stopMotor4() {
  ledcWrite(M4LPWM_LEDC_CHANNEL, 0);
  ledcWrite(M4RPWM_LEDC_CHANNEL, 0);
}
