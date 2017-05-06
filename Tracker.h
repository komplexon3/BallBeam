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

    /*
      analogPin: pin to which the voltage divider is connected
      resistor: resistor used in voltage divider
      sampleCount: number of measurements taken per reading
      sampleSelect: number of lowest measurements of which the average is calculated
    */

    //read the resistance/position
    //min/max resistance have to be set before position readings
    double readResistance();
    double readPosition();

    //set min/max resistance - ball has to be at corresponding position
    void setMinResistance();
    void setMaxResistance();

    //set sampleCount: number of measurements taken per reading
    void setSampleCount(int sampleCount);
    //set sampleSelect: number of lowest measurements of which the average is calculated
    void setSampleSelect(int sampleSelect);

    //
    double getMinResistance();
    double getMaxResistance();

    int getSampleCount();
    int getSampleSelect();

  private:
    int _analogPin, _resistor;
    int _sampleCount, _sampleSelect; //max 50

    double _minResistance, _maxResistance;
};

#endif
