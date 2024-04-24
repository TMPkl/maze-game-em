#ifndef mapa_H
#define mapa_H
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
const unsigned char bitmap_mapa [] PROGMEM = {// 'walls_only', 128x32px
// 'walls_only', 128x32px
// 'walls_only', 128x32px
0x00, 0x00, 0x80, 0x10, 0x01, 0xf8, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x7e, 0x01, 0xc0, 0x62, 0x00, 
0x00, 0x00, 0x80, 0x10, 0x01, 0x08, 0x00, 0x80, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xc4, 0x00, 
0x00, 0x00, 0x80, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc1, 0x00, 0x8c, 0x00, 
0x00, 0x00, 0xfc, 0x10, 0x01, 0x01, 0xe0, 0x01, 0xc0, 0x20, 0x00, 0x00, 0x61, 0xc1, 0x9a, 0x00, 
0x00, 0x00, 0x84, 0x1c, 0x01, 0xe1, 0x3c, 0x07, 0xf0, 0x1f, 0xc0, 0x80, 0x30, 0x71, 0x10, 0x00, 
0x00, 0x00, 0x84, 0x06, 0x01, 0x31, 0x00, 0x0f, 0xf8, 0x00, 0x71, 0xc0, 0x10, 0x31, 0xf0, 0x00, 
0x00, 0x40, 0x84, 0x00, 0x01, 0x1d, 0x00, 0x1f, 0xfc, 0x00, 0x1d, 0x60, 0x00, 0x21, 0x80, 0x00, 
0x00, 0xc0, 0x84, 0x00, 0x00, 0x1d, 0xe0, 0xff, 0xff, 0x00, 0x07, 0x38, 0x00, 0x20, 0xe0, 0x00, 
0x00, 0x81, 0xc4, 0x00, 0x00, 0x05, 0xe0, 0x7f, 0xff, 0xe0, 0x00, 0x08, 0x00, 0x20, 0x34, 0x00, 
0x00, 0x80, 0x04, 0x7c, 0x00, 0x04, 0x20, 0x3e, 0x7f, 0xf0, 0x00, 0x0c, 0x00, 0x3c, 0x1e, 0x00, 
0x00, 0x80, 0x07, 0xc7, 0x80, 0x04, 0x30, 0x1c, 0x3f, 0xf8, 0x00, 0x04, 0x06, 0x64, 0x12, 0x00, 
0x00, 0x80, 0x04, 0x06, 0x03, 0xfc, 0x18, 0x0c, 0x1f, 0xf8, 0x00, 0x14, 0x02, 0xc0, 0x30, 0x00, 
0x00, 0x80, 0x04, 0x02, 0x00, 0x24, 0x1c, 0x08, 0x01, 0xf0, 0xf8, 0x34, 0x03, 0x00, 0x00, 0x00, 
0x00, 0xff, 0xfc, 0x02, 0x00, 0x24, 0x0c, 0x08, 0x03, 0xe1, 0x8c, 0x34, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x02, 0x00, 0x24, 0x04, 0x08, 0x07, 0xc1, 0x04, 0x7c, 0x03, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x02, 0x00, 0x24, 0x0c, 0x00, 0x0f, 0x81, 0x87, 0xc8, 0x02, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x02, 0x07, 0xfc, 0x04, 0x00, 0x07, 0xc0, 0x80, 0x00, 0x06, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x1e, 0x00, 0x8c, 0x0c, 0x00, 0x03, 0xe0, 0xc0, 0x00, 0x04, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x7c, 0x10, 0x00, 0x88, 0x1c, 0x04, 0x01, 0xf0, 0x40, 0x00, 0xc8, 0x00, 0x9a, 0x00, 
0x00, 0x80, 0xc0, 0x10, 0x00, 0x88, 0x18, 0x04, 0x1f, 0xf8, 0x40, 0x00, 0x48, 0x00, 0x8e, 0x00, 
0x00, 0x80, 0x80, 0x10, 0x10, 0x0b, 0xf8, 0x0e, 0x3f, 0xfd, 0xc0, 0xc0, 0xfc, 0x00, 0x98, 0x00, 
0x00, 0x80, 0x80, 0x10, 0x10, 0x0a, 0x30, 0x1e, 0x7f, 0xff, 0x01, 0xe7, 0x98, 0x07, 0x90, 0x00, 
0x00, 0xc0, 0x80, 0xf0, 0x11, 0xfe, 0x20, 0x1f, 0xff, 0xfc, 0x01, 0x26, 0x10, 0x04, 0xb0, 0x00, 
0x00, 0x40, 0x81, 0x80, 0x19, 0x08, 0x00, 0x1f, 0xff, 0xf8, 0x00, 0x24, 0x30, 0x04, 0x78, 0x00, 
0x00, 0x00, 0x80, 0x00, 0x37, 0x08, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x3c, 0x20, 0x07, 0xc8, 0x00, 
0x00, 0x00, 0x80, 0x00, 0xe1, 0x38, 0x00, 0x4f, 0xff, 0xc0, 0x00, 0x00, 0x60, 0x00, 0x08, 0x00, 
0x00, 0x00, 0x80, 0x00, 0x81, 0x00, 0x00, 0x47, 0xf1, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x08, 0x00, 
0x00, 0x00, 0x80, 0xff, 0x87, 0x00, 0x00, 0x47, 0xe1, 0x80, 0x20, 0x03, 0x80, 0xfc, 0x16, 0x00, 
0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x83, 0xc0, 0x83, 0x70, 0x00, 0x00, 0x44, 0x62, 0x00, 
0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x81, 0x87, 0xde, 0x00, 0x00, 0xc7, 0xc2, 0x00, 
0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x07, 0x04, 0x02, 0x00, 0x01, 0x80, 0x42, 0x00, 
0x00, 0xff, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x0c, 0x04, 0x03, 0xf8, 0x03, 0x00, 0x42, 0x00};

const unsigned char wall_map []= { // 128x32px for wall detection only- adafruti lib needs PROGMEM bitmap for some reasone
// 'walls_only', 128x32px
0x00, 0x00, 0x80, 0x10, 0x01, 0xf8, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x7e, 0x01, 0xc0, 0x62, 0x00, 
0x00, 0x00, 0x80, 0x10, 0x01, 0x08, 0x00, 0x80, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xc4, 0x00, 
0x00, 0x00, 0x80, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc1, 0x00, 0x8c, 0x00, 
0x00, 0x00, 0xfc, 0x10, 0x01, 0x01, 0xe0, 0x01, 0xc0, 0x20, 0x00, 0x00, 0x61, 0xc1, 0x9a, 0x00, 
0x00, 0x00, 0x84, 0x1c, 0x01, 0xe1, 0x3c, 0x07, 0xf0, 0x1f, 0xc0, 0x80, 0x30, 0x71, 0x10, 0x00, 
0x00, 0x00, 0x84, 0x06, 0x01, 0x31, 0x00, 0x0f, 0xf8, 0x00, 0x71, 0xc0, 0x10, 0x31, 0xf0, 0x00, 
0x00, 0x40, 0x84, 0x00, 0x01, 0x1d, 0x00, 0x1f, 0xfc, 0x00, 0x1d, 0x60, 0x00, 0x21, 0x80, 0x00, 
0x00, 0xc0, 0x84, 0x00, 0x00, 0x1d, 0xe0, 0xff, 0xff, 0x00, 0x07, 0x38, 0x00, 0x20, 0xe0, 0x00, 
0x00, 0x81, 0xc4, 0x00, 0x00, 0x05, 0xe0, 0x7f, 0xff, 0xe0, 0x00, 0x08, 0x00, 0x20, 0x34, 0x00, 
0x00, 0x80, 0x04, 0x7c, 0x00, 0x04, 0x20, 0x3e, 0x7f, 0xf0, 0x00, 0x0c, 0x00, 0x3c, 0x1e, 0x00, 
0x00, 0x80, 0x07, 0xc7, 0x80, 0x04, 0x30, 0x1c, 0x3f, 0xf8, 0x00, 0x04, 0x06, 0x64, 0x12, 0x00, 
0x00, 0x80, 0x04, 0x06, 0x03, 0xfc, 0x18, 0x0c, 0x1f, 0xf8, 0x00, 0x14, 0x02, 0xc0, 0x30, 0x00, 
0x00, 0x80, 0x04, 0x02, 0x00, 0x24, 0x1c, 0x08, 0x01, 0xf0, 0xf8, 0x34, 0x03, 0x00, 0x00, 0x00, 
0x00, 0xff, 0xfc, 0x02, 0x00, 0x24, 0x0c, 0x08, 0x03, 0xe1, 0x8c, 0x34, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x02, 0x00, 0x24, 0x04, 0x08, 0x07, 0xc1, 0x04, 0x7c, 0x03, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x02, 0x00, 0x24, 0x0c, 0x00, 0x0f, 0x81, 0x87, 0xc8, 0x02, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x02, 0x07, 0xfc, 0x04, 0x00, 0x07, 0xc0, 0x80, 0x00, 0x06, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x1e, 0x00, 0x8c, 0x0c, 0x00, 0x03, 0xe0, 0xc0, 0x00, 0x04, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x7c, 0x10, 0x00, 0x88, 0x1c, 0x04, 0x01, 0xf0, 0x40, 0x00, 0xc8, 0x00, 0x9a, 0x00, 
0x00, 0x80, 0xc0, 0x10, 0x00, 0x88, 0x18, 0x04, 0x1f, 0xf8, 0x40, 0x00, 0x48, 0x00, 0x8e, 0x00, 
0x00, 0x80, 0x80, 0x10, 0x10, 0x0b, 0xf8, 0x0e, 0x3f, 0xfd, 0xc0, 0xc0, 0xfc, 0x00, 0x98, 0x00, 
0x00, 0x80, 0x80, 0x10, 0x10, 0x0a, 0x30, 0x1e, 0x7f, 0xff, 0x01, 0xe7, 0x98, 0x07, 0x90, 0x00, 
0x00, 0xc0, 0x80, 0xf0, 0x11, 0xfe, 0x20, 0x1f, 0xff, 0xfc, 0x01, 0x26, 0x10, 0x04, 0xb0, 0x00, 
0x00, 0x40, 0x81, 0x80, 0x19, 0x08, 0x00, 0x1f, 0xff, 0xf8, 0x00, 0x24, 0x30, 0x04, 0x78, 0x00, 
0x00, 0x00, 0x80, 0x00, 0x37, 0x08, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x3c, 0x20, 0x07, 0xc8, 0x00, 
0x00, 0x00, 0x80, 0x00, 0xe1, 0x38, 0x00, 0x4f, 0xff, 0xc0, 0x00, 0x00, 0x60, 0x00, 0x08, 0x00, 
0x00, 0x00, 0x80, 0x00, 0x81, 0x00, 0x00, 0x47, 0xf1, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x08, 0x00, 
0x00, 0x00, 0x80, 0xff, 0x87, 0x00, 0x00, 0x47, 0xe1, 0x80, 0x20, 0x03, 0x80, 0xfc, 0x16, 0x00, 
0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x83, 0xc0, 0x83, 0x70, 0x00, 0x00, 0x44, 0x62, 0x00, 
0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x81, 0x87, 0xde, 0x00, 0x00, 0xc7, 0xc2, 0x00, 
0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x07, 0x04, 0x02, 0x00, 0x01, 0x80, 0x42, 0x00, 
0x00, 0xff, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x0c, 0x04, 0x03, 0xf8, 0x03, 0x00, 0x42, 0x00};
#endif