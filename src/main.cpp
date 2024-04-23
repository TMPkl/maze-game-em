#include <Arduino.h>
#include "MapPoint.h"
#include "mapa.h"
#include "ValueOfMapPoint.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "shared.h"
#include "ISRmovment.h"

byte SCREEN_WIDTH = 128;
byte SCREEN_HEIGHT = 32;

byte PLATER_WIDTH = 1;
byte PLAYER_HEIGHT = 1;

#define SCREEN_ADDRESS 0x3C //< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

byte buttonPin1 = 8;
byte buttonPin2 = 9;
byte buttonPin3 = 10;
byte buttonPin4 = 11;
byte externalInterruptPin = 2;
volatile byte movement = 0b000000000;


struct Point playerPoint;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  attachInterrupt(digitalPinToInterrupt(externalInterruptPin), ISRMovment, RISING); //interrupt for button
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
    struct Point test;
    test. x = 0;
    test.y = 0;
    Serial.println(isWall(test,bitmap_mapa));
    struct Point testPoint;
    testPoint.x = 31;
    testPoint.y = 31;
    Serial.println(isWall(testPoint,bitmap_mapa));

    playerPoint.x = 0;
    playerPoint.y = SCREEN_HEIGHT/2-2;
}



void loop() {
 while(true){
    if (movement == 0b0001 && playerPoint.x > 0)
    {
        playerPoint.x += 1;
    }
    if (movement == 0b0010 && playerPoint.x < SCREEN_WIDTH-PLATER_WIDTH)
    {
        playerPoint.x -= 1;
    }
    if (movement == 0b0100 && playerPoint.y < SCREEN_HEIGHT-PLAYER_HEIGHT)
    {
        playerPoint.y += 1;
    }
    if (movement == 0b1000 && playerPoint.y > 0)
    {
        playerPoint.y -= 1;
    }

    if (isWall(playerPoint,wall_map) == 1) 
        break;
    
    display.clearDisplay();
    display.drawBitmap(0, 0, bitmap_mapa, 128, 32, SSD1306_WHITE);
    display.fillRect(playerPoint.x, playerPoint.y, PLATER_WIDTH, PLAYER_HEIGHT ,SSD1306_WHITE);   //drawing on display
    display.display();

    delay(300);
    }
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(10, 10);
    display.println("GAME OVER!");
    display.display(); 
    for (;;); // Don't proceed, loop forever
    }
