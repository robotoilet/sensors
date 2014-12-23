/*
  TestSensor.h - TestSensor library
  Copyright (c) 2014 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef TestSensor_h
#define TestSensor_h

#include "Arduino.h"
#include "Sensor.h"

template<typename B>

class TestSensor : public Sensor<B> {
  public:
    TestSensor(char aName, B* aB) : Sensor<B>(aName, aB) {};

  protected:
    virtual void getData(char* chArray) {
      Sensor<B>::longToChArray(random(255), chArray);
    }
};

#endif

