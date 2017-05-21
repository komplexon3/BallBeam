/*
  PID.h - Simple implementation of a PID controller
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

#ifndef PID_h
#define PID_h

class PID {
  public:
    PID(double target, double *input, double integralBound, double outputAmplitude, double kp, double ki, double kd);

    /*
      target: target position (setpoint)
      integralBound: how close the ball has to be to the target for integralTerm to increase
      outputAmplitude: maximum output from pid algorithm
      kp, ki, kd: set the corresponding terms
    */

    int compute(); //compute one pid loop

    // methods to change and get the corresponding varibles

    void setWeights(double kp, double ki, double kd); //change pids (-1 for terms you don't want to change)
    void setKp(double kp);
    void setKi(double ki);
    void setKd(double kd);
    double getKp();
    double getKi();
    double getKd();

    void setMinDeltaTime(unsigned long minDeltaTime); //minDeltaTime: time before another pid loop may take place (because of motor latency)
    unsigned long getMinDeltaTime();

    void setIntegralBound(double integralBound);
    double getIntegralBound();

    void setoutputAmplitude(double outputAmplitude);
    double getoutputAmplitude();

  private:
    double *_input;
    double _output, _target;
    double _lastPosition, _integralError, _integralBound, _outputAmplitude, _kp, _ki, _kd;

    unsigned long _minDeltaTime, _lastTime;
};

#endif
