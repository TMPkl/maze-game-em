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

byte counter = 0;
bool blink_color = false;
byte isCollected =0b0000000;  // 0b00000000 - nothing, 0b00000001 - first collected, 0b00000010 - second collected, 0b00000100 - third collected, 0b00000111 - all collected, 0b00001000 - finish line

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

    playerPoint.x = 2;
    playerPoint.y = SCREEN_HEIGHT/2-2;
}


void loop() {

    while (movement==0)
    {
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(0, 15);
        display.println("Press button to start");
        display.display();
        delay(100);
    }
    
    while (true) {
        if (counter == 4)
        { 
            blink_color = !blink_color;
            counter = 0;
        }
        counter++;
        if (movement == 0b0001 && playerPoint.x < SCREEN_WIDTH - PLATER_WIDTH) {
            playerPoint.x += 1;
        }
        if (movement == 0b0010 && playerPoint.x > 0) {
            playerPoint.x -= 1;
        }
        if (movement == 0b0100 && playerPoint.y < SCREEN_HEIGHT - PLAYER_HEIGHT) {
            playerPoint.y += 1;
        }
        if (movement == 0b1000 && playerPoint.y > 1) {
            playerPoint.y -= 1;
        }

        if (isWall(playerPoint, wall_map) == 1) {
            break;
        }
        if (bitRead(isCollected, 0) == 0 && playerPoint.x>=32 && playerPoint.x<=35 && playerPoint.y>=0 && playerPoint.y<=3) {
            isCollected = isCollected | 0b00000001;
        }
        if (bitRead(isCollected, 1) == 0 && playerPoint.x>=62 && playerPoint.x<=65 && playerPoint.y>=13 && playerPoint.y<=16) {
            isCollected = isCollected | 0b00000010;
        }
        if (bitRead(isCollected, 2) == 0 && playerPoint.x>=86 && playerPoint.x<=88 && playerPoint.y>=9 && playerPoint.y<=11) {
            isCollected = isCollected | 0b00000100;
        }
        if (bitRead(isCollected, 3) == 0 && playerPoint.x==123 && playerPoint.y>=0 && playerPoint.y<=31) {
            isCollected = isCollected | 0b00001000;
            break;
        }
        display.clearDisplay();
        display.drawBitmap(0, 0, bitmap_mapa, 128, 32, SSD1306_WHITE);
        display.fillRect(playerPoint.x, playerPoint.y, PLATER_WIDTH, PLAYER_HEIGHT, SSD1306_WHITE);   //drawing on display
        if(bitRead(isCollected, 0) == 0)
            display.fillRect(33,1,3,3,blink_color ? SSD1306_WHITE : SSD1306_BLACK); //drawing on display
        if(bitRead(isCollected, 1) == 0)
            display.fillRect(63,14,3,3,blink_color ? SSD1306_WHITE : SSD1306_BLACK); //drawing on display
        if(bitRead(isCollected, 2) == 0)
            display.fillRect(87,10,2,2,blink_color ? SSD1306_WHITE : SSD1306_BLACK); //drawing on display
        if (bitRead(isCollected, 3) == 0)
            display.drawLine(124,0,124,31,blink_color ? SSD1306_WHITE : SSD1306_BLACK); //drawing on display
        
        display.display();

        Serial.print(blink_color);
        Serial.print(" ");
        Serial.print(counter);
        delay(500);
    }
    if (bitRead(isCollected, 3) == 0)
    {
       display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(12, 5);
        display.println("GAME OVER");
        display.setTextSize(1);
        display.setCursor(40, 22);
        display.println("YOU LOSE");
        display.display(); 
        for (;;); //wait for reset
    }
    else
    {
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(25, 5);
        display.println("YOU WIN");
        display.setTextSize(1);
        display.setCursor(28, 23);
        display.print("COLLECTED:");
        display.print((bitRead(isCollected, 0) + bitRead(isCollected, 1) + bitRead(isCollected, 2)));
        display.print("/3");
        display.display(); 
        for (;;); //wait for reset
    }
    
}
