/*
  PID.h - Simple implementation of a PID controller
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

#ifndef PID_h
#define PID_h

class PID {
  public:
    PID(double* feedback, double target, double integralBound, double kp, double ki, double kd);

    int Compute();

    void setWeights(double kp, double ki, double kd);
    void setKp(double kp);
    void setKi(double ki);
    void setKd(double kd);
    double getKp();
    double getKi();
    double getKp();

    void setMinDeltaTime(unsigned long minDeltaTime);
    unsigned long getMinDeltaTime();

    void setIntegralBound(double integralBound);
    double getIntegralBound();

  private:
    double _feedback;
    const double _target;
    double _lastFeedback, _integralError, _integralBound, _kp, _ki, _kd;

    unsigned long _minDeltaTime, _lastTime
}
