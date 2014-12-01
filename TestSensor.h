/*
  TestSensor.h - TestSensor library
  Copyright (c) 2014 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef TestSensor_h
#define TestSensor_h

#include "Arduino.h"
#include "FileIO.h"
#include "Sensor.h"

class TestSensor : public Sensor {
  public:
    TestSensor(char aName) : Sensor(aName) {};

  protected:
    virtual void getData(char*);
};

#endif

