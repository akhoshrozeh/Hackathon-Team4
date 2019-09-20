#include <Stepper.h>
#include <Servo.h>
#include <SoftwareSerial.h>



// *** CONSTANTS ***
const int BIG_SERVO_PIN = 9;
const int SMALL_SERVO_PIN = 6; 
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for motor
const int rolePerMinute = 15;
#define RX_PIN 0
#define TX_PIN 1


// *** OBJECT INITIALIZATION ***
Stepper myStepper_1(stepsPerRevolution, 10, 12, 11, 13);
Stepper myStepper_2(stepsPerRevolution, 2, 4, 3, 5); 
Servo bigServo;
Servo smallServo;
SoftwareSerial HM10 = SoftwareSerial(0, 1);

// *** VARIABLES ***
int bigServoPos = 90;
int smallServoPos = 90;
int pos = 0;
int stepCount = 0;  // number of steps the motor has taken



// ***FUNCTIONS***

// **BIG SERVO**
void turnBigServoLeft() {
  if(bigServo.read() == 0)
    return;
  else{
    bigServoPos -= 10;
    bigServo.write(bigServoPos);
    }
    
}
  
void turnBigServoRight() {
  if(bigServo.read() == 180)
    return;
    
  else{
    bigServoPos += 10;
    bigServo.write(bigServoPos);
  }
  
}

// **SMALL SERVO**
void turnSmallServoLeft() {
  if(smallServo.read() == 0)
    return;
  else{
    smallServoPos -= 10;
    smallServo.write(smallServoPos);
    }
    
}
  
void turnSmallServoRight() {
  if(smallServo.read() == 180)
    return;
    
  else{
    smallServoPos += 10;
    smallServo.write(smallServoPos);
  }
  
}

// **STEPPER_1**
void turnStepper1_left() {
  myStepper_1.step(-stepsPerRevolution);
}

void turnStepper1_right() {
  myStepper_1.step(stepsPerRevolution);
}

// **STEPPER_2**
void turnStepper2_left() {
  myStepper_2.step(-stepsPerRevolution);
}

void turnStepper2_right() {
  myStepper_2.step(stepsPerRevolution);
}




   
// *** SETUP ***
void setup() {

    Serial.begin(9600);
    HM10.begin(9600);
    
    bigServo.attach(BIG_SERVO_PIN);
    bigServo.write(0);
    smallServo.attach(SMALL_SERVO_PIN);
    smallServo.write(0);
    myStepper_1.setSpeed(rolePerMinute);
    myStepper_2.setSpeed(rolePerMinute);

   
   // pinMode(0, INPUT);
   // pinMode(1, OUTPUT);
    
    
}

// GUIDE FOR INPUT 
// Hand Up - 1
// Hand Down - 2
// Elbow Up - 3
// Elbow Down - 4
// Wrist CCW - 5
// Wrist CW - 6
// Arm Left - 7
// Arm Right - 8

void loop() {
    HM10.listen();
    while(HM10.available() > 0) {
      byte data = HM10.read();

      if(data == 1)
          Serial.println("hand up");
      else if(data == 2)
          Serial.println("hand down");
      else if(data == 3)
          Serial.println("elbow up");
      else if(data == 4)
          Serial.println("elbow down");
      else if(data == 5)
          Serial.println("wrist ccw");
      else if(data == 6)
          Serial.println("wrist cw");
      else if(data == 7)
          Serial.println("arm left");
      else if(data == 8)
          Serial.println("arm right");

       else {
        // do nothing 
        }
          
    
    }
   
}
