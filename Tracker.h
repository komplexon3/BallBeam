/*
  Tracker.h - Library for tracking the position of
  a steel ball on resistive rails
  Created by Laurent Rouvinez & Marc Widmer - 2017
*/

#ifndef Tracker_h
#define Tracker_h

class Tracker {
  public:
    Tracker(int analogPin, int resistor, int sampleCount, int sampleSelect);

    double readResistance();
    double readPosition();

    void setMinResistance();
    void setMaxResistance();

    void setSampleCount(int sampleCount);
    void setSampleSelect(int sampleSelect);

    double getMinResistance();
    double getMaxResistance();

    int getSampleCount();
    int getSampleSelect();

  private:
    const int _analogPin, _resistor;
    int _sampleCount, _sampleSelect; //max 50

    double _minResistance, _maxResistance;
}

#endif
