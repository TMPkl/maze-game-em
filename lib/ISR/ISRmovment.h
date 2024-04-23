#ifndef ISRMovment_h
#define ISRMovment_h
#include <Arduino.h>
#include "shared.h"
#include "SHARED.h"

void ISRMovment(){
    if (digitalRead(buttonPin1) == HIGH)
    {
        movement = 0b00000001;
        return;
    }
    if (digitalRead(buttonPin2) == HIGH)
    {
        movement = 0b00000010;
        return;
    }
    if (digitalRead(buttonPin3) == HIGH)
    {
        movement = 0b00000100;
        return;
    }
    if (digitalRead(buttonPin4) == HIGH)
    {
        movement = 0b00001000;
        return;
    }
}








#endif