/*
  TestSensor.h - TestSensor library for Wiring - implementation
  Copyright (c) 2014 John Doe.  All right reserved.
*/

#include "Arduino.h"
#include "FileIO.h"
#include "TestSensor.h"
#include "Sensor.h"

#define OPEN_DATAPOINT '('
#define CLOSE_DATAPOINT ')'
#define SEPARATOR ' '


void TestSensor::getData(char* chArray) {
  longToChArray(random(255), chArray);
}
