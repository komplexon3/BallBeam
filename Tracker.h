/* 
  Tracker.h - Library for tracking the position of
  a steel ball on resistive rails
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

#ifndef Tracker_h
#define Tracker_h

class Tracker {
  public:
    Tracker(int analogPin, int sampleCount, double maxVoltage);

    double readResistance();
    double readPosition();

    void setMinResistance();
    void setMaxResistance();

    void setSampleCount(int sampleCount);
    void setMaxVoltage(double maxVoltage);

    double getMinResistance();
    double getMaxResistance();

    int getSampleCount();
    double getMaxvoltage();

  private:
    int _analogPin, _resistor, _sampleCount;
    double _maxVoltage, _minResistance, _maxResistance;
}

#endif
