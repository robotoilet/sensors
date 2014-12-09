/*
  Sensor.h - Sensor library
  Copyright (c) 2014 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"
#include "Board.h"

#define OPEN_DATAPOINT '('
#define CLOSE_DATAPOINT ")"
#define SEPARATOR " "

#define MAX_VALUE_SIZE 10
#define TIMESTAMP_SIZE 10
#define MAX_DATAPOINT_SIZE MAX_VALUE_SIZE + TIMESTAMP_SIZE + 3


template<typename B>

class Sensor {

  public:
    Sensor(char aName) : name(aName) {}

    // Creates a dataPoint of format "(<sensorName> <timestamp> <value>)" and
    // asks the given Board instance to write it.
    void collectData(char* filePath, byte filePathLength, char* timestamp, B b) {
      char dataPoint[MAX_DATAPOINT_SIZE] = { OPEN_DATAPOINT, name };
      strcat(dataPoint, SEPARATOR);
      strcat(dataPoint, timestamp);
      strcat(dataPoint, SEPARATOR);
      char chArray[MAX_VALUE_SIZE];
      getData(chArray);
      strcat(dataPoint, chArray);
      strcat(dataPoint, CLOSE_DATAPOINT);
      b.write(filePath, dataPoint, MAX_DATAPOINT_SIZE);
    }

  protected:
    char name;
    int valueSize;

    // Write a number `n` (long) to a string array;
    // Also updates the `valueSize` data member with the actual
    // number of digits of `n`.
    void longToChArray(long n, char* chArray) {
      valueSize = getDigitsOfLong(n);
      sprintf(chArray, "%ld", n);
    }

    int getDigitsOfLong(long number) {
      int digits = 0;
      do { number /= 10; digits++; } while (number != 0);
      return digits;
    }

    // to be implemented by subclasses
    virtual void getData(char*) = 0;
};


#endif
