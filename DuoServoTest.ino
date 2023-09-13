#include <Servo.h> 
//Declared Variables
int sensorValue = 0;    //Variable for photoresitor value
int servoRotation = 0;  //Variable for servo angle
int directionModifier = 1;
int position = 0;
int left = 0;
int right = 0;
int numButtonPresses = 0;

void setup() {
  pinMode(A0, INPUT); //Photoresistor 1
  pinMode(A1, INPUT); //Photoresistor 2
  pinMode(A2, OUTPUT); //Servo 1
  pinMode(A3, OUTPUT); //Servo 2
  pinMode(8, INPUT); //Push button
  pinMode(7, INPUT); //LED
  Serial.begin(750); //update speed
}

static void rotate(int servoRotation){
position = servoRotation;
analogWrite(A2, position); //Rotates servo 1 to new rotation value
analogWrite(A3, position); //Rotates servo 2 to new rotation value
}

void loop() {

  if (digitalRead(8)==HIGH){
  numButtonPresses += 1;
  }

  while ((numButtonPresses+1) % 2 == 0){
  servoRotation = 0;                //Sets rotation to 0 (defualt position)
if(digitalRead(7) == HIGH){
  rotate(0);
  while (digitalRead(7) != LOW) { 

    sensorValue = analogRead(A0);   //Sets sensorValue to current photoresistor value
    Serial.print(sensorValue);      //Prints photoresistor value
    Serial.print(", ");             //Formatting
    Serial.println(servoRotation);  //Prints servo angle

    while (sensorValue < 750) {       //When photoresistor reads dark
      sensorValue = analogRead(A0);   //Sets sensorValue to current photoresistor value while in loop
      Serial.println(sensorValue);      //Prints photoresistor value
      servoRotation += 45;            //Increments rotation value
      if (servoRotation >= 180 || servoRotation <= -180) {       //Limits rotation value 
      //Resets rotation value
        if(servoRotation >= 180){
          servoRotation = 180;
          directionModifier = -1;
        }
        if(servoRotation <= 0){
          servoRotation = 0;
          directionModifier = 1;
        }
      }
      rotate(servoRotation);
      delay(100);                     //Wait time
    }
   } 
   }
}
if (digitalRead(8)==HIGH){
  numButtonPresses += 1;
}
}