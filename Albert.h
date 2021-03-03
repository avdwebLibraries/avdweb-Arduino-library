#ifndef ALBERT_H
#define ALBERT_H

#include <Arduino.h>

#if defined(__arm__)
  #define Serial SerialUSB
#endif

#define arrayLenght(array) sizeof(array)/sizeof(array[0]) // compile-time calculation

void openDrain(byte pin, bool value);
void blinkLed(byte pin, int n=3, bool onLevel=1);
void maxLoops(const unsigned long loops);

//---------------------------------------------------------------------------------------------------------------------------------------------------------

template<class T> 
inline Print &operator ,(Print &stream, const T arg) 
{ stream.print(" ");
  stream.print(arg); 
  return stream; 
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

class SimpleSoftPWM // only for LEDs and heating
{ public:
    bool pwm(byte value); // 0 ... 255

  private:
    unsigned long start_us, periodTime_us=19890; // minimum frequency to prevent LED flickering = 50Hz
};

#endif


