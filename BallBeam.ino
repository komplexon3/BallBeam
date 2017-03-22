#import <Tracker.h>
#import <PID.h>
#import <Servo.h>

#define servoPin 10 // placeholder
#define railsPin 11 // paceholder - must be analogPin
#define calibrationButtonPin 12 // placeholder
#define runButtonPin 13 // placeholder

// Configure Tracker

#define resistance 220 //Vive La Résistance!!
#define sampleCount 10
#define sampleSelect 3

// Configure PID

#define target 15
#define integralBound 3
#define kp 0.5
#define ki 0.5
#define kp 0.5

double feedback;

Servo servo;
Tracker tracker = new Tracker(railsPin, resistance, sampleCount, sampleSelect);
PID pid = new PID(&feedback, target, integralBound, kp, ki, kp);

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);

}

void loop() {

}

void pidLoop() {

}

void calibration() {

}
