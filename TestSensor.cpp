/*
  TestSensor.h - TestSensor library for Wiring - implementation
  Copyright (c) 2014 John Doe.  All right reserved.
*/

#include "Arduino.h"
#include "Process.h"

// include this library's description file
#include "TestSensor.h"
#include "FileIO.h"

#define OPEN_DATAPOINT '('
#define CLOSE_DATAPOINT ')'
#define SEPARATOR ' '

// Constructor
TestSensor::TestSensor(byte name)
{
  name = name;
}

void TestSensor::collectData(File f) {
  // the name of the sensor
  f.print(OPEN_DATAPOINT + name + SEPARATOR);

  // the timestamp
  Process time;
  time.begin("date");
  time.addParameter("+%s"); // as seconds since 1970
  time.run();

  int i = 0;
  while(time.available()>0) {
    char c = time.read();
    if(c != '\n')
      f.print(c);
  }
  f.print(SEPARATOR);
  f.print(random(255));
  f.print(CLOSE_DATAPOINT);
}
