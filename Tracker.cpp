/*
  Tracker.cpp - Library for tracking the position of
  a steel ball on resistive rails
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

#include <Arduino.h>
#include <Tracker.h>

Tracker::Tracker(int analogPin, int resistor, int sampleCount, double voltageTreshold) {
  _analogPin = analogPin;
  _sampleCount = sampleCount;
  _voltageTreshold = voltageTreshold;
  _resistor = resistor
}

double Tracker::readResistance() {
  float vSum = 0;
  float vCount = 0;

  for(int i = 0; i < _sampleCount; i++){
      if(int v = (analogRead(_analogPin) * 5 / 1024) <= _voltageTreshold) {
        vSum += v;
        vCount++;
      }
      delay(1);
  }

  float vAverage = vSum / vCount;
  return trackResistance = vAverage * _resistor / (5 - vAverage);
}

double Tracker::readPosition() {
  return map(readResistance(), _minResistance, _maxResistance, 0.0, 100.0);
}

void Tracker::setMinResistance() {_minResistance = readResistance();}
void Tracker::setMaxResistance() {_maxResistance = readResistance();}

void Tracker::setSampleCount(int sampleCount) {_sampleCount = sampleCount;}
void Tracker::setMaxVoltage(double maxVoltage) {_maxVoltage = maxVoltage;}

double Tracker::getMinResistance() {return _minResistance;}
double Tracker::getMaxResistance() {return _maxResistance;}

int Tracker::getSampleCount() {return _sampleCount;}
double Tracker::getMaxvoltage() {return _maxVoltage;}
