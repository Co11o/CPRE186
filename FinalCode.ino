#include <Servo.h>

//Declared Variables
int sensorValueL = 0;  //Variable for left photoresitor value
int sensorValueR = 0;  //Variable for right photoresitor value
int numButtonPresses = 1;
Servo servoL;
Servo servoR;

void setup() {
  pinMode(A0, INPUT);  //Photoresistor 1
  pinMode(A1, INPUT);  //Photoresistor 2
  servoL.attach(A4);   //Servo 1
  servoR.attach(A5);   //Servo 2
  pinMode(8, OUTPUT);  //Push button
  pinMode(7, OUTPUT);  //LED
  Serial.begin(750);   //update speed
}

void loop() {
  //code on start
  servoL.write(94);      // no servo movement
  servoR.write(93);      // no servo movement
  digitalWrite(7, LOW);  // Not tracking (LED Off)
  // Updates buttonPresses if button is pressed
  if (digitalRead(8) == HIGH) {
    numButtonPresses += 1;
  }
  delay(200);  //Buffer time
  //if even number of pressees
  if ((numButtonPresses % 2) == 0) {
    //Nothing
  }
  //Odd presses = run
  while ((numButtonPresses % 2) == 1) {
    digitalWrite(7, HIGH);  //Shows code is running (LED On)

    //Button Pressed in loop
    if (digitalRead(8) == HIGH) {
      numButtonPresses += 1;
      delay(200);
    }
    //If photoresitors have different values
    if (abs(sensorValueL - sensorValueR) > 100) {
      //Light is more intense on left sensor
      if (sensorValueL > sensorValueR) {
        servoL.write(250);  // Left servo counter clockwise
        servoR.write(0);    // Right servo clockwise
        delay(50);          // rotating for 50 milliseconds
      }
      //Light is more intense on left sensor
      else {
        servoL.write(0);    // Left servo clockwise
        servoR.write(250);  // right servo Counter clockwise
        delay(50);          // rotating for 50 milliseconds
      }
    }
    servoL.write(94);               // stop left servo
    servoR.write(93);               // stop right servo
    sensorValueL = analogRead(A0);  //Reads and updates photoresistor values
    sensorValueR = analogRead(A1);  //Reads and updates photoresistor values
    delay(500);
  }
}
