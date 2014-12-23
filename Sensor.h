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
    Sensor(char aName, B* aB) : name(aName),b(aB) {}

    // Creates a dataPoint of format "(<sensorName> <timestamp> <value>)" and
    // asks the given Board instance to write it.
    void collectData() {
      if (b->checkCounter()) {
        char dataPoint[MAX_DATAPOINT_SIZE] = { OPEN_DATAPOINT, name, '\0' };
        strcat(dataPoint, SEPARATOR);
        strcat(dataPoint, b->unixTimestamp);
        strcat(dataPoint, SEPARATOR);
        char chArray[MAX_VALUE_SIZE];
        getData(chArray);
        strcat(dataPoint, chArray);
        strcat(dataPoint, CLOSE_DATAPOINT);
        b->write(dataPoint, MAX_DATAPOINT_SIZE);
      }
    }

  protected:
    char name;
    B* b;

    // Write a number `n` (long) to a string array;
    // Also updates the `valueSize` data member with the actual
    // number of digits of `n`.
    void longToChArray(long n, char* chArray) {
      sprintf(chArray, "%ld", n);
    }


    // to be implemented by subclasses
    virtual void getData(char*) = 0;
};


#endif
