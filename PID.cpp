/*
  PID.cpp - Simple implementation of a PID controller
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

#include <Arduino.h>
#include "PID.h"

PID::PID(double target, double *input, double integralBound, double outputAmplitude, double kp, double ki, double kd) {
  //constructor -> see PID.h to learn more about the various parameters
  _target = target;
  _integralBound = integralBound;
  _outputAmplitude = outputAmplitude;

  _kp = kp;
  _ki = ki;
  _kd = kd;

  _minDeltaTime = 100;

  _lastTime = millis();
  _output = 0;
}

int PID::compute() {
  //see paper for reference
  unsigned long now = millis();
  unsigned long deltaTime = now - _lastTime;

  if(deltaTime >= _minDeltaTime) {
    _lastTime = now;
    double currentPosition = *_input;
    double error = _target - currentPosition;

    if(abs(error) >= _integralBound) {
      _integralError += error;
    } else {
      _integralError = 0;
    }

    double deltaX = currentPosition - _lastPosition;
    _lastPosition = currentPosition;
    _output = _kp * error + _ki * _integralError * deltaTime - _kd * deltaX / deltaTime;

    _output = _output >= _outputAmplitude ? _outputAmplitude : _output;
    _output = _output <= -_outputAmplitude ? -_outputAmplitude : _output;

    return _output;
  } else {
    return _output;
  }
}

void PID::setWeights(double kp, double ki, double kd) {
  _kp = kp == -1.0 ? _kp : kp;
  _ki = ki == -1.0 ? _ki : ki;
  _kd = kd == -1.0 ? _kd : kd;
}

void PID::setKp(double kp) {_kp = kp;}
void PID::setKi(double ki) {_ki = ki;}
void PID::setKd(double kd) {_kd = kd;}

double PID::getKp() {return _kp;}
double PID::getKi() {return _ki;}
double PID::getKd() {return _kd;}

void PID::setMinDeltaTime(unsigned long minDeltaTime) {_minDeltaTime = minDeltaTime;}
unsigned long PID::getMinDeltaTime() {return _minDeltaTime;}

void PID::setIntegralBound(double integralBound) {_integralBound = integralBound;}
double PID::getIntegralBound() {return _integralBound;}

void PID::setoutputAmplitude(double outputAmplitude) {_outputAmplitude = outputAmplitude;}
double PID::getoutputAmplitude() {return _outputAmplitude;}
