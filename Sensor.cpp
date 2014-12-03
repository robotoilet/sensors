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

#define MAX_VALUE_SIZE 10

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
  char chArray[MAX_VALUE_SIZE];
  getData(chArray);
  for (byte i=0;i<valueSize;i++) {
    f.print(chArray[i]);
  }
  f.print(CLOSE_DATAPOINT);
}

// Helper function that can be used to write a number `n` (long) to a string
// array;
// It also updates the `valueSize` data member with the actual
// number of digits of `n`.
void Sensor::longToChArray(long n, char* chArray) {
  valueSize = getDigitsOfLong(n);
  sprintf(chArray, "%ld", n);
}

int Sensor::getDigitsOfLong(long number) {
  int digits = 0;
  do { number /= 10; digits++; } while (number != 0);
  return digits;
}
