/*
  PID.h - Simple implementation of a PID controller
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

#ifndef PID_h
#define PID_h

class PID {
  public:
    PID(double target, double integralBound, double feedbackAmplitude, double kp, double ki, double kd);

    int compute();

    void setWeights(double kp, double ki, double kd);
    void setKp(double kp);
    void setKi(double ki);
    void setKd(double kd);
    double getKp();
    double getKi();
    double getKd();

    void setMinDeltaTime(unsigned long minDeltaTime);
    unsigned long getMinDeltaTime();

    void setIntegralBound(double integralBound);
    double getIntegralBound();

    void setFeedbackAmplitude(double feedbackAmplitude);
    double getFeedbackAmplitude();

  private:
    double _feedback, _target;
    double _lastFeedback, _integralError, _integralBound, _feedbackAmplitude, _kp, _ki, _kd;

    unsigned long _minDeltaTime, _lastTime;
};

#endif
