/*
  Sensor.h - Sensor library
  Copyright (c) 2014 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"
#include "FileIO.h"

class Sensor
{
  public:
    Sensor(char);

    void collectData(File, char*);

  protected:
    char name;
    virtual void getData(char*) = 0;
    void longToChArray(long, char*);
    int getDigitsOfLong(long);
    int valueSize;
};

#endif

