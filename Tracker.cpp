/*
  Tracker.cpp - Library for tracking the position of
  a steel ball on resistive rails
  Created by Laurent Rouvinez & Marc Widmer - 2017

  This text shall explain how Tracker tracks the ball.
  The basic idea is that the balls position is read by reading the voltage in
  the middle of the voltage divider. As these measurements are a mess
  (bad contact), this data has to be filtered. For this a ~sampleCount~
  measurements are conducted. From these measuerements, the lowerst
  ~sampleSelect~ are averaged and then used as the final value. See report to
  learn more about why the data is filtered this way. To get the actual position
  (from 0 to 100), the read resistance is mapped according to the resistance at
  min and max position.
*/

#include <Arduino.h>
#include "ArduinoSort.h"
#include "Tracker.h"

Tracker::Tracker(int analogPin, int resistor, int sampleCount, int sampleSelect) {
  //constructor -> see Tracker.h to learn more about the various parameters
  _analogPin = analogPin;
  _resistor = resistor;
  _sampleCount = sampleCount;
  _sampleSelect = sampleSelect;
}

double Tracker::readResistance() {
  //reading the resistance
  double voltages[_sampleCount];
  double voltageSum = 0;

  //taking the voltage measurement
  for(int i = 0; i < _sampleCount; i++){
    voltages[i] = analogRead(_analogPin) * 5 / 1024;
    delay(1);
  }

  //sorting the measurements from lowest to highest
  sortArray(voltages, sizeof(voltages));

  //adding the lowest ~sampleSelect~ measurements
  for(int i = 0; i < _sampleSelect; i++) {
    voltageSum += voltages[i];
  }

  //dividing the sum by the total number of measurements
  float vAverage = voltageSum / _sampleSelect;

  //converting voltage to resistance
  return vAverage * _resistor / (5 - vAverage);
}

double Tracker::readPosition() {
  //mapping the resistance to position
  return map(readResistance(), _minResistance, _maxResistance, 0.0, 100.0);
}

//setting min/maxResistance
void Tracker::setMinResistance() {_minResistance = readResistance();}
void Tracker::setMaxResistance() {_maxResistance = readResistance();}

//changing parameters
void Tracker::setSampleCount(int sampleCount) {_sampleCount = sampleCount;}
void Tracker::setSampleSelect(int sampleSelect) {_sampleSelect = sampleSelect;}

//getters for various variables
double Tracker::getMinResistance() {return _minResistance;}
double Tracker::getMaxResistance() {return _maxResistance;}

int Tracker::getSampleCount() {return _sampleCount;}
int Tracker::getSampleSelect() {return _sampleSelect;}
