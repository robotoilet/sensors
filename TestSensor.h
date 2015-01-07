/*
  TestSensor.h - TestSensor library
  Copyright (c) 2014 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef TestSensor_h
#define TestSensor_h

#include "Arduino.h"
#include "Sensor.h"


class TestSensor : public Sensor {
  public:
    TestSensor(char aName, unsigned long res) : Sensor(aName, res) {};

    virtual void getData(char* chArray) {
      Sensor::longToChArray(random(255), chArray);
    }
};

#endif

