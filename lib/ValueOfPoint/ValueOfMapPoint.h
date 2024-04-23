#ifndef VALUEOFMAPPOINT_H
#define VALUEOFMAPPOINT_H
#include <Arduino.h>
#include <MapPoint.h>
#include "shared.h"


struct AdressBitmap {
    unsigned int index;
    unsigned int reminder;
};

struct AdressBitmap GetAdressOfPixel(Point p) {
    struct AdressBitmap adress;
    unsigned int position = 0;

    position += p.y * SCREEN_WIDTH;
    position += p.x;
    //Serial.println(position);
    adress.index = position / 8;
    adress.reminder = ((position % 8)-7)*-1;  //-7 and *-1 bc the position is indexed in reverse to what my Point is indexed
    // Serial.print(adress.index);
    // Serial.print("<- adress.index   ");
    // Serial.print(adress.reminder);
    // Serial.print("<- adress.reminder   ");
    // Serial.print(bitmap_mapa[adress.index],BIN);
    // Serial.print("<- pitmapa pod tym adresem  ");
    // Serial.print("   ");
    // Serial.print(p.x);
    // Serial.print("   ");
    // Serial.println(p.y);
    return adress;
}

bool isWall(Point p,const unsigned char* bitmapa ){
        struct AdressBitmap adress = GetAdressOfPixel(p);
        //Serial.println(adress.index);
        //Serial.println(adress.reminder);
        if (bitRead(bitmapa[adress.index], adress.reminder) == 1)
        {   
            return 1;
        }
        return 0;
}
#endif