#ifndef PID_h
#define PID_h

class PID {
  public:
    PID(double* feedback, double target, double kp, double ki, double kd);
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

  private:
    double *_feedback;
    double _target, _lastFeedback, _iError, _kp, _ki, _kd;

    unsigned long _minDeltaTime, _lastTime
}
