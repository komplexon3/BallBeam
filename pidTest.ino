/* 
   Test for PID implementation
   Createrd by Laurent Rouvinez and Marc Widmer - 2017   
*/

#include <Servo.h>
Servo servo;

int vIn = 0;
int servoOut = 3;

int avgCount = 10;

float servoVal;

float minPosVoltage;
float maxPosVoltage;
float V;
float vTot;
float vVal;

float pos;
float lastPos = 0;
float CV;
float Kp = 0.2;
float Kd = 0.2;

void setup() {
  Serial.begin(9600);
  servo.attach(servoOut);

  Serial.println("Calibrating...");
 
  servo.write(0);
  delay(5000);
  minPosVoltage = readVoltage();
  Serial.print(minPosVoltage); Serial.print(" minPos; ");
   
  servo.write(180);
  delay(5000);
  maxPosVoltage = readVoltage();
  Serial.print(maxPosVoltage); Serial.println(" maxPos; ");
  
  servo.write(90);
}

void loop() {   
  V = readVoltage();

  pos = map(V, minPosVoltage, maxPosVoltage, -100, 100);

  CV = pos * Kp + (pos - lastPos) * Kd;
   
  servoVal = map(CV, -100, 100, 180, 0);
  servo.write(servoVal);

  lastPos = pos;

  Serial.print(V); Serial.print(" voltage; ");
  Serial.print(servoVal); Serial.println(" servoVal; ");
  delay(3);
  
}

float readVoltage(){
  vTot = 0;  
  for(int i = 0; i < avgCount; i++){
   vVal = analogRead(vIn);
   vTot += vVal;
   delay(3);
  }
  return (vTot / avgCount);

 /* return analogRead(vIn);*/
}


