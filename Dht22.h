/*
  DHT22.h - Implementation of DHT22 into ./robot Sensor library
  Copyright (c) 2014 dotslashrobot.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Dht22_h
#define Dht22_h

#include "Arduino.h"
#include "DHT.h"
#include "Sensor.h"

// works for the following dht types:
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

class Dht22 : public Sensor {
  public:
    Dht22(char aName, unsigned long res, byte dataPin) : Sensor(aName, res) {
      dht = new DHT(dataPin, DHTTYPE);
      dht->begin();
    };

    // The temperature readings are floats; we convert them to longs here,
    // saving one decimal point multiplying by 10; this needs to be redone
    // on server side.
    virtual void getData(char* chArray) {
      // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
      long h = dht->readHumidity() * 10;
      // Read temperature as Celsius
      long  t = dht->readTemperature() * 10;
      if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
      }
      sprintf(chArray, "%ld %ld", h, t);
    }

  private:
    DHT* dht;

};

#endif



