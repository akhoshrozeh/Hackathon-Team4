#include <Stepper.h>
#include <Servo.h>
#include <SoftwareSerial.h>


// *** CONSTANTS ***
const byte BIG_SERVO_1_PIN = 9;
const byte BIG_SERVO_2_PIN; // TO BE CONFIGURED
const byte SMALL_SERVO_1_PIN = 6; 
const byte SMALL_SERVO_2_PIN; // TO BE CONFIGURED
 
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for motor
const int rolePerMinute = 15;
#define RX_PIN 0
#define TX_PIN 1


// *** OBJECT INITIALIZATION ***
Stepper myStepper_1(stepsPerRevolution, 10, 12, 11, 13);
Stepper myStepper_2(stepsPerRevolution, 2, 4, 3, 5); 
Servo bigServo_1;
Servo bigServo_2;
Servo smallServo_1;
Servo smallServo_2;
SoftwareSerial HM10 = SoftwareSerial(0, 1);

// *** VARIABLES ***
int bigServo1Pos = 90;
int bigServo2Pos = 90;
int smallServo1Pos = 90;
int smallServo2Pos = 90;
int pos = 0;
int stepCount = 0;  // number of steps the motor has taken



// *** SETUP ***
void setup() {
    
    bigServo_1.attach(BIG_SERVO_1_PIN);
    bigServo_1.write(90);
    bigServo_2.attach(BIG_SERVO_2_PIN);
    bigServo_2.write(90);

    // for small servos: closed is l.write(15) and r.write(115)
      // for opening small servos, l increases and right decreases
    smallServo_1.attach(SMALL_SERVO_1_PIN);
    smallServo_1.write(90);     // 110 is straight down for right and 20 is straight down for the left
    smallServo_2.attach(SMALL_SERVO_2_PIN);
    smallServo_2.write(90);

    
    myStepper_1.setSpeed(rolePerMinute);
    myStepper_2.setSpeed(rolePerMinute);
    

   
    Serial.begin(9600);
    HM10.begin(9600);
    
}


// ***FUNCTIONS***

// **BIG SERVOS**
void turnBigServo1Left() {
  if(bigServo_1.read() == 0)
    return;
  else{
    bigServo1Pos -= 10;
    bigServo_1.write(bigServo1Pos);
    }
    
}
  
void turnBigServo1Right() {
  if(bigServo_1.read() == 180)
    return;
    
  else{
    bigServo1Pos += 10;
    bigServo_1.write(bigServo1Pos);
  }
  
}

void turnBigServo2Left() {
  if(bigServo_2.read() == 0)
    return;
  else{
    bigServo2Pos -= 10;
    bigServo_2.write(bigServo2Pos);
    }
    
}
  
void turnBigServo2Right() {
  if(bigServo_2.read() == 180)
    return;
    
  else{
    bigServo2Pos += 10;
    bigServo_2.write(bigServo2Pos);
  }
  
}

// **SMALL SERVOS**  // THE CLAW
void openSmallServos() {
  
    
}
  
void closeSmallServos() {
  
  
}


// Steppers are now going be working synchronized!

// **STEPPERS**
void turnSteppersLeft(){
  myStepper_1.step(-stepsPerRevolution);
  myStepper_2.step(-stepsPerRevolution);
  }

void turnSteppersRight(){
    myStepper_1.step(stepsPerRevolution);
    myStepper_2.step(stepsPerRevolution);
  }


// ***GUIDE FOR INPUT (START/STOP)***
  // Steppers Left - 1/9 
  // Steppers Right - 2/10
  // Big Servo1 Left - 3/11
  // Big Servo1 Right - 4/12
  // Big Servo2 Left - 5/13
  // Big Servo2 Right - 6/14
  // Open Small Servos - 7/15
  // Close Small Servos - 8/0


void loop() {
 
    HM10.listen();
    while(HM10.available() > 0) {
      byte data = HM10.read();
      
      if(data == 1){
         while(1){
              if(HM10.read() == 9) break;
              else turnSteppersLeft();
          }
      }
      
      else if(data == 2){
        while(1){
            if(HM10.read() == 10) break;
            else turnSteppersRight();
          }
      }
          
          
      else if(data == 3){
         while(1){
            if(HM10.read() == 11) break;
            else turnBigServo1Left();
          }
      }

          
      
      else if(data == 4){
        while(1){
          if(HM10.read() == 12) break;
          else turnBigServo1Right();
          }
        }
   
      
      else if(data == 5){
        while(1){
          if(HM10.read() == 13) break;
          else turnBigServo2Left();
          }
        }
          
          
      
      else if(data == 6){
        while(1){
          if(HM10.read() == 14) break;
          else turnBigServo2Right();
          }
        }
          
      
      
      else if(data == 7){
        while(1){
          if(HM10.read() == 15) break;
          else openSmallServos();
          }
        }
       
       
      
      else if(data == 8){
        while(1){
          if(HM10.read() == 0) break;
          else closeSmallServos();
          }
        }

          

       else {
        // do nothing 
        }
          
    
    }

   
}
