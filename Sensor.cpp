/*
  Sensor.h - Sensor library for Wiring - implementation
  Copyright (c) 2014 John Doe.  All right reserved.
*/

#include "Arduino.h"

// include this library's description file
#include "Sensor.h"
#include "FileIO.h"

#define OPEN_DATAPOINT '('
#define CLOSE_DATAPOINT ')'
#define SEPARATOR ' '

#define VALUE_SIZE 10

// Constructor
Sensor::Sensor(char aName) : name(aName) {}

void Sensor::collectData(File f, char* timestamp) {
  // "(<sensorName> "
  f.print(OPEN_DATAPOINT);
  f.print(name);
  f.print(SEPARATOR);

  // (..)"<timestamp>
  for (byte i=0;i<10;i++) {
    char c = timestamp[i];
    if(c != '\n')
      f.print(c);
  }
  f.print(SEPARATOR);
  char chArray[VALUE_SIZE];
  getData(chArray);
  for (byte i=0;i<VALUE_SIZE;i++) {
    f.print(chArray[i]);
  }
  f.print(random(255));
  f.print(CLOSE_DATAPOINT);
}

void Sensor::longToChArray(long n, char* chArray) {
   sprintf(chArray, "%ld", n);
}
