/*
  UltasonicSR04.h - Implementation of UtrasonicSR04 into ./robot Sensor library
  Copyright (c) 2014 dotslashrobot.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"
#include "Sensor.h"

class UltrasonicSR04 : public Sensor {
  public:
    UltrasonicSR04(char aName, unsigned long res, byte tPin, byte ePin) : Sensor(aName, res) {
      trigPin = tPin;
      echoPin = ePin;
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    };

    virtual void getData(char* chArray) {
      long duration, distance;
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      Sensor:longToChArray((pulseIn(echoPin, HIGH) / 2) / 29.1, chArray);
    }

  private:
    byte trigPin, echoPin;

};

#endif


