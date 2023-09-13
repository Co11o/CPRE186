#include <Servo.h>

Servo servoL;//left servo
Servo servoR;//Right Servo

void setup() {
  servoL.attach(A4);   //Left Servo 
  servoR.attach(A5);   //Right Servo 
  Serial.begin(750);   //update speed
}

void loop() {
  
  //Stops for 1 sec
  servoL.write(94);      // no left servo movement
  servoR.write(93);      // no right servo movement
  delay(2000);            //Stops for 2 sec

  //Moves for half second
  servoL.write(45);      // left servo half speed clockwise
  servoR.write(135);      // right servo half speed counter clockwise
  delay(500);            //Runs for 1/2 sec

  //Stops for 1 sec
  servoL.write(94);      // no left servo movement
  servoR.write(93);      // no right servo movement
  delay(1000);            //Stops for 1 sec

  //Moves for half second
  servoL.write(135);      // left servo half speed counter clockwise
  servoR.write(45);      // right servo half speed clockwise
  delay(500);            
}
