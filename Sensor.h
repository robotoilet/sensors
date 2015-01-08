/*
  Sensor.h - Sensor library
  Copyright (c) 2014 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"


class Sensor {

  public:
    Sensor(char aName, long res) : name(aName),resolution(res) {}

    char name;

    bool wantsToReport(unsigned long seconds) {
      return seconds % resolution == 0;
    }

    // to be implemented by subclasses
    virtual void getData(char*) = 0;

  protected:
    long resolution;

    // Write a number `n` (long) to a string array;
    // Also updates the `valueSize` data member with the actual
    // number of digits of `n`.
    void longToChArray(long n, char* chArray) {
      sprintf(chArray, "%ld", n);
    }

};


#endif
