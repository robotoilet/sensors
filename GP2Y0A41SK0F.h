/*
GP2Y0A41SK0F.h - Implementation of Sharp GP2Y041SK0F distance sensor into ./robot Sensor library
  Copyright (c) 2014 dotslashrobot.  All right reserved.
*/

// ensure this library description is only included once
#ifndef GP2Y0A41SK0F_h
#define GP2Y0A41SK0F_h

#include "Arduino.h"
#include "Sensor.h"

class GP2Y0A41SK0F : public Sensor {
  public:
    GP2Y0A41SK0F(char aName, unsigned long res, byte aPin) : Sensor(aName, res) {
      analogPin = aPin;                      //Analog input pin
      pinMode(analogPin, INPUT);
    };

    virtual void getData(char* chArray) {
      long duration, distance;
      distance = analogRead(analogPin);
      Sensor:longToChArray(distance, chArray);
    }

  private:
    byte analogPin;

};

#endif


