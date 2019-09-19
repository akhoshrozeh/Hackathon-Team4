#include <Stepper.h>
#include <Servo.h>


// *** CONSTANTS ***
const int BIG_SERVO_PIN = 9;
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for motor
const int rolePerMinute = 15;

// *** OBJECT INITIALIZATION ***
Stepper myStepper_1(stepsPerRevolution, 10, 12, 11, 13);
// Stepper myStepper_2(stepsPerRevolution, , , , );
Servo bigServo;
//Servo smallServo;


// *** VARIABLES ***
int bigServoPos = 90;
int pos = 0;
int stepCount = 0;  // number of steps the motor has taken



// ***FUNCTIONS***

// BIG SERVO
void turnBigServoLeft() {
  if(bigServo.read() == 0)
    return;
  else{
    bigServoPos -= 10;
    bigServo.write(bigServoPos);
    }
    
}
  
void turnBigServoRight() {
  if(myServo.read() == 180)
    return;
    
  else{
    bigServoPos += 10;
    myServo.write(bigServoPos);
  }
  
}

// SMALL SERVO


// STEPPER_1
void turnStepper1_left() {
  myStepper_1.step(-stepsPerRevolution);
}

void turnStepper1_right() {
  myStepper_1.step(stepsPerRevolution);
}

// STEPPER_2




void setup() {
  // nothing to do inside the setup
    bigServo.attach(BIG_SERVO_PIN);
    bigServo.write(0);
    myStepper_1.setSpeed(rolePerMinute);
}


void loop() {
  
  

   
}
