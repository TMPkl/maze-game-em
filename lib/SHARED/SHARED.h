#ifndef SHARED_H
#define SHARED_H

#include <Arduino.h>

extern byte SCREEN_WIDTH;             // OLED display width, in pixels
extern byte SCREEN_HEIGHT;               // OLED display height, in pixels
extern byte PLATER_WIDTH;
extern byte PLAYER_HEIGHT;

extern byte buttonPin1;
extern byte buttonPin2; 
extern byte buttonPin3; 
extern byte buttonPin4;
extern byte externalInterruptPin;
volatile extern byte movement; 
#endif // SHARED_H
