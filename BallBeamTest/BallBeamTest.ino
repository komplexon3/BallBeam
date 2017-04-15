#include <Tracker.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

// Configure Tracker

#define railsPin 1 // paceholder - must be analogPin
#define resistance 110 //Vive La Résistance!!
#define sampleCount 10
#define sampleSelect 3

//Configure Servo

#define servoPin 9
#define minAngle 30
#define maxAngle 150

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

Tracker tracker = Tracker(railsPin, resistance, sampleCount, sampleSelect);

void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);

  calibration();
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 180, 0);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value

  Serial.println(tracker.readPosition());

  delay(15);                           // waits for the servo to get there  //PENIS
}

void calibration() {
  myservo.write(minAngle);
  delay(5000);
  tracker.setMinResistance();

  myservo.write(90);
  delay(2000);

  myservo.write(maxAngle);
  delay(5000);
  tracker.setMaxResistance();

  myservo.write(0);
}
