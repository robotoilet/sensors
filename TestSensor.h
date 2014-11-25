/*
  TestSensor.h - TestSensor library
  Copyright (c) 2014 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef TestSensor_h
#define TestSensor_h

#include "Arduino.h"
#include "Process.h"
#include "FileIO.h"

class TestSensor
{
  public:
    TestSensor(byte);

    byte name; // name of the sensor

    void collectData(File);
};

#endif

