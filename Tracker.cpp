/*
  Tracker.cpp - Library for tracking the position of
  a steel ball on resistive rails
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

#include <Arduino.h>
#include <ArduinoSort.h>
#include <Tracker.h>

Tracker::Tracker(int analogPin, int resistor, int sampleCount, int sampleSelect) {
  _analogPin = analogPin;
  _resistor = resistor;
  _sampleCount = sampleCount;
  _sampleSelect = sampleSelect;
}

double Tracker::readResistance() {
  double voltages[_sampleCount];
  double voltageSum = 0;

  for(int i = 0; i < _sampleCount; i++){
    voltages[i] = analogRead(_analogPin) * 5 / 1024;
    delay(1);
  }

  sortArray(voltages, sizeof(voltages));

  for(int i = 0; i < _sampleSelect; i++) {
    voltageSum += voltages[i];
  }

  float vAverage = voltageSum / _sampleSelect;
  return vAverage * _resistor / (5 - vAverage);
}

double Tracker::readPosition() {
  return map(readResistance(), _minResistance, _maxResistance, 0.0, 100.0);
}

void Tracker::setMinResistance() {_minResistance = readResistance();}
void Tracker::setMaxResistance() {_maxResistance = readResistance();}

void Tracker::setSampleCount(int sampleCount) {_sampleCount = sampleCount;}
void Tracker::setSampleSelect(int sampleSelect) {_sampleSelect = sampleSelect;}

double Tracker::getMinResistance() {return _minResistance;}
double Tracker::getMaxResistance() {return _maxResistance;}

int Tracker::getSampleCount() {return _sampleCount;}
int Tracker::getSampleSelect() {return _sampleSelect;}
