#include <Stepper.h>
#include <Servo.h>


// *** CONSTANTS ***
const int BIG_SERVO_PIN = 9;
const int SMALL_SERVO_PIN = 6; 
const int stepsPerRevolution = 300;  // change this to fit the number of steps per revolution for motor
const int rolePerMinute = 15;



// *** OBJECT INITIALIZATION ***
Stepper myStepper_1(stepsPerRevolution, 10, 12, 11, 13);
Stepper myStepper_2(stepsPerRevolution, 2, 4, 3, 5); 
Servo bigServo;
Servo smallServo;


// *** VARIABLES ***
int bigServoPos = 90;
int smallServoPos = 90;
int pos = 0;
int stepCount = 0;  // number of steps the motor has taken



// ***FUNCTIONS***-------------------------------------------------------------

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

// **STEPPER_1**---------------------------------------------------------------
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


// *** SETUP ***-------------------------------------------------------------------------------------------------
void setup() {
    bigServo.attach(BIG_SERVO_PIN);
    bigServo.write(12);
    smallServo.attach(SMALL_SERVO_PIN);
    smallServo.write(12);
    myStepper_1.setSpeed(rolePerMinute);
    myStepper_2.setSpeed(rolePerMinute);
}


//---------------------------------------------------------------------------------------------------------------------
void loop() {
turnStepper1_left();
turnStepper2_left();
turnBigServoRight();
turnSmallServoRight();
delay(10);
turnStepper1_right();
turnStepper2_right();
turnBigServoLeft();
turnSmallServoLeft();
delay(10);
}
