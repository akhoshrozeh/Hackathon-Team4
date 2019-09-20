#include <Stepper.h>
#include <Servo.h>
#include <SoftwareSerial.h>



// *** CONSTANTS ***
const int BIG_SERVO_PIN = 9;

const int left_pin= 7; 
const int right_pin= 6; 
const int stepsPerRevolution = 300;  // change this to fit the number of steps per revolution for motor
const int rolePerMinute = 15;
#define RX_PIN 0
#define TX_PIN 1

;  // change this to fit the number of steps per revolution for motor



// *** OBJECT INITIALIZATION ***
Stepper myStepper_1(stepsPerRevolution, 10, 12, 11, 13);
// Stepper myStepper_2(stepsPerRevolution, , , , );
Servo bigServo;

Servo smallServo1;
Servo left;
Servo right;
SoftwareSerial HM10 = SoftwareSerial(0, 1);

//Servo smallServo;


// *** VARIABLES ***
int bigServoPos = 90;
int pos = 0;
int stepCount = 0;  // number of steps the motor has taken



// ***FUNCTIONS***-------------------------------------------------------------
const int left_pin_close = 15;
const int right_pin_close = 115;

void openClaw(){
  left.write(left_pin_close + 55);
  right.write(right_pin_close - 55);
}

void closeClaw(){ 
  int x = left_pin_close + 55;
  int y = right_pin_close - 55;
  for(int i = 0;i <55;i++){ 
    left.write(x--);
    right.write(y++);
    delay(15);
  }
}


  

// BIG SERVO
//void turnBigServoLeft() {
//  if(bigServo.read() == 0)
//    return;
//  else{
//    bigServoPos -= 10;
//    bigServo.write(bigServoPos);
//    }
//    
//}
  
//void turnBigServoRight() {
//  if(myServo.read() == 180)
//    return;
//    
//  else{
//    bigServoPos += 10;
//    myServo.write(bigServoPos);
//  }
//  
//}

// SMALL SERVO



// **STEPPER_1**---------------------------------------------------------------

// STEPPER_1

void turnStepper1_left() {
  myStepper_1.step(-stepsPerRevolution);
}

void turnStepper1_right() {
  myStepper_1.step(stepsPerRevolution);
}

// STEPPER_2




// *** SETUP ***-------------------------------------------------------------------------------------------------

   


    

// *** SETUP ***

void setup() {
   left.attach(9);
  right.attach(8);
  left.write(15);
  right.write(115);
  
    bigServo.attach(BIG_SERVO_PIN);
//    bigServo.write(12);
//    smallServo.write(12);
    myStepper_1.setSpeed(rolePerMinute);
//    myStepper_2.setSpeed(rolePerMinute);

    bigServo.write(0);
    myStepper_1.setSpeed(rolePerMinute);
}

   
    //Serial.begin(9600);
//    HM10.begin(9600);
   // pinMode(0, INPUT);
   // pinMode(1, OUTPUT);
    
    



// GUIDE FOR INPUT 
// Hand Up - 1
// Hand Down - 2
// Elbow Up - 3
// Elbow Down - 4
// Wrist CCW - 5
// Wrist CW - 6
// Arm Left - 7
// Arm Right - 8

//---------------------------------------------------------------------------------------------------------------------
void loop() {
//
//turnStepper1_left();
//turnStepper2_left();
//turnBigServoRight();
//turnSmallServoRight();
//delay(10);
//turnStepper1_right();
//turnStepper2_right();
//turnBigServoLeft();
//turnSmallServoLeft();
//delay(10);


//    HM10.listen();
//    while(HM10.available() > 0) {
//      byte data = HM10.read();
//
//      if(data == 1)
//          Serial.println("hand up");
//      else if(data == 2)
//          Serial.println("hand down");
//      else if(data == 3)
//          Serial.println("elbow up");
//      else if(data == 4)
//          Serial.println("elbow down");
//      else if(data == 5)
//          Serial.println("wrist ccw");
//      else if(data == 6)
//          Serial.println("wrist cw");
//      else if(data == 7)
//          Serial.println("arm left");
//      else if(data == 8)
//          Serial.println("arm right");
//
//       else {
//        // do nothing 
//        }
//        /////sdfsdfsdf
//          
//    
//    }
  openClaw();
  delay(500);
  closeClaw();
  delay(500);
  


}
