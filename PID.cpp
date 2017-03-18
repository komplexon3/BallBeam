/*
  PID.cpp - Simple implementation of a PID controller
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

//add I restrictions

#include <Arduino.h>
#include <PID.h>

PID::PID(double* feedback, double target, double kp, double ki, double kd) {
  *_feedback = feedback;
  _target = target;
  _integralBound = integralBound;

  _kp = kp;
  _ki = ki;
  _kd = kd;

  _minDeltaTime = 100;

  _lastTime = millis();
  _lastFeedback = feedback;
}

int PID::compute() {
  unsigned long now = millis;
  unsigned long deltaTime = now - _lastTime;

  if(deltaTime >= _minDeltaTime) {
    _lastTime = now;

    double currentFeedback = *_feedback;
    double error = _target - currentFeedback;

    if(abs(error) >= _integralBound) {
      _integralError += error;
    }

    double deltaX = currentFeedback - _lastFeedback;
    _lastFeedback = currentFeedback;
    _output = _kp * error + _ki * _integralError * deltaTime - _kd * deltaX / deltaTime
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
double PID::getMinDeltaTime() {return _minDeltaTime;}

void PID::setIntegralBound(double integralBound) {_integralBound = integralBound;}
double PID::getIntegralBound() {return _integralBound;}
