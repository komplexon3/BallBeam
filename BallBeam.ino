#import <Tracker.h>
#import <PID.h>
#import <Servo.h>

// Cnnfigure Buttons

#define calibrationButtonPin 12 // placeholder
#define runButtonPin 13 // placeholder

// Configure Servo

#define servoPin 10 // placeholder
#define minAngle 60 // placeholder
#define maxAngle 120 // placeholder

// Configure Tracker

#define railsPin 11 // paceholder - must be analogPin
#define resistance 220 //Vive La Résistance!!
#define sampleCount 10
#define sampleSelect 3

// Configure PID

#define target 15
#define integralBound 3
#define feedbackAmplitude 100
#define kp 0.5
#define ki 0.5
#define kp 0.5


double feedback;
bool run = false;
bool calibrated = false;

Servo servo;
Tracker tracker = Tracker(railsPin, resistance, sampleCount, sampleSelect);
PID pid = PID(target, integralBound, feedbackAmplitude, kp, ki, kp);

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);

  pinMode(calibrationButtonPin, INPUT_PULLUP);
  pinMode(runButtonPin, INPUT_PULLUP);

  servo.write(90);

  while(digitalRead(calibrationButtonPin))
    delay(10);

  calibration();
}

void loop() {

  run = !digitalRead(runButtonPin) ? !run : run;

  if(digitalRead(calibrationButtonPin))
    calibration();

  if(run)
    pidLoop();

  delay(10);
}

void pidLoop() {
  int angle = map(pid.compute(), -feedbackAmplitude, feedbackAmplitude, minAngle, maxAngle);
  servo.write(angle);
}

void calibration() {
  servo.write(minAngle);
  delay(5000);
  tracker.setMinResistance();

  servo.write(90);
  delay(2000);

  servo.write(maxAngle);
  delay(5000);
  tracker.setMaxResistance();

  servo.write(0);
}
