#include "pinout.h"

#ifndef SENSORS
#define SENSORS
class Sensors {
    public: 
        void setup();
        float front_ultrasonic();
        float read_ir(uint8_t pin);
        bool block_blue();
};
#endif