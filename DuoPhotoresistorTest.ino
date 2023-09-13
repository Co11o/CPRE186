int sensorValue1 = 0;//Variable for photoresistor 1
int sensorValue2 = 0;//Variable for photoresistor 2

void setup() {
  pinMode(A0, INPUT);//photoresistor 1
  pinMode(A1, INPUT);//photoresistor 2
  Serial.begin(750);//update speed
}

void loop() {
  // read the value from the sensor
  sensorValue1 = analogRead(A0);  //sets variable to photoresistor 1 value
  sensorValue2 = analogRead(A1);  //sets variable to photoresistor 2 value

  // print the sensor reading so you know its range
  Serial.print(sensorValue1);     //prints photoresistor 1 value
  Serial.print(", ");             //Formatting
  Serial.println(sensorValue2);   //prints photoresistor 2 value
}
