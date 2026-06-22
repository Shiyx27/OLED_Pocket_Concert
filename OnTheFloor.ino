#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const unsigned char heart_bmp[] PROGMEM = {
  0b01010000,
  0b11111000,
  0b11111000,
  0b01110000,
  0b00100000
};

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); 
  }
  
  // LARGE FONT
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  display.clearDisplay();

  unsigned long timeNow = millis();
  
  // 130 BPM Club pacing: 1.8 second chunks for a 28.8 second perfect loop
  unsigned long songLoop = timeNow % 28800; 
  int phase = songLoop / 1800; 
  
  // --- 1. THE LARGE KINETIC LYRICS ---
  if (phase == 0) {
    display.setCursor(0, 8);
    display.println("If you"); display.println("go hard"); display.println("you gotta");
  } else if (phase == 1) {
    display.setCursor(0, 8);
    display.println("get on"); display.println("the"); display.println("floor");
  } else if (phase == 2) {
    display.setCursor(0, 8);
    display.println("If you're"); display.println("a party"); display.println("freak");
  } else if (phase == 3) {
    display.setCursor(0, 8);
    display.println("then step"); display.println("on the"); display.println("floor");
  } else if (phase == 4) {
    display.setCursor(0, 16);
    display.println("If you're"); display.println("an animal");
  } else if (phase == 5) {
    display.setCursor(0, 8);
    display.println("then tear"); display.println("up the"); display.println("floor");
  } else if (phase == 6) {
    display.setCursor(0, 0);
    display.println("Break a"); display.println("sweat on"); display.println("the"); display.println("floor");
  } else if (phase == 7) {
    display.setCursor(0, 0);
    display.println("Yeah we"); display.println("work on"); display.println("the"); display.println("floor");
  } else if (phase == 8) {
    display.setCursor(0, 0);
    display.println("Don't"); display.println("stop"); display.println("keep it"); display.println("moving");
  } else if (phase == 9) {
    display.setCursor(0, 16);
    display.println("put your"); display.println("drinks up");
  } else if (phase == 10) {
    display.setCursor(0, 8);
    display.println("Pick your"); display.println("body up"); display.println("and drop");
  } else if (phase == 11) {
    display.setCursor(0, 8);
    display.println("it on"); display.println("the"); display.println("floor");
  } else if (phase == 12) {
    display.setCursor(0, 8);
    display.println("Let the"); display.println("rhythm"); display.println("change");
  } else if (phase == 13) {
    display.setCursor(0, 0);
    display.println("your"); display.println("world on"); display.println("the"); display.println("floor");
  } else if (phase == 14) {
    display.setCursor(0, 8);
    display.println("You know"); display.println("we run it"); display.println("tonight");
  } else if (phase == 15) {
    display.setCursor(0, 16);
    display.println("on the"); display.println("floor");
  }

  // --- 2. THE CHORUS ONLY STICK FIGURE ---
  // He ONLY drops in when they say the word "FLOOR"
  bool showStickFigure = (phase == 1 || phase == 3 || phase == 5 || phase == 6 || phase == 7 || phase == 11 || phase == 13 || phase == 15);

  if (showStickFigure) {
    // 130 BPM Math: 230ms for a fast, club-style eighth-note bounce!
    int danceBeat = (timeNow / 230) % 2; 
    int guyX = 110; 
    int guyY = 25 + (danceBeat == 1 ? -4 : 0);  
    
    display.drawCircle(guyX, guyY, 4, SSD1306_WHITE); 
    display.drawLine(guyX, guyY + 4, guyX, guyY + 16, SSD1306_WHITE); 

    if (danceBeat == 1) {
      display.drawLine(guyX, guyY + 8, guyX - 10, guyY - 2, SSD1306_WHITE);      
      display.drawLine(guyX, guyY + 8, guyX + 10, guyY - 2, SSD1306_WHITE);      
      display.drawLine(guyX, guyY + 16, guyX - 8, guyY + 28, SSD1306_WHITE); 
      display.drawLine(guyX, guyY + 16, guyX + 8, guyY + 28, SSD1306_WHITE); 
    } else {
      display.drawLine(guyX, guyY + 8, guyX - 8, guyY + 16, SSD1306_WHITE); 
      display.drawLine(guyX, guyY + 8, guyX + 8, guyY + 16, SSD1306_WHITE); 
      display.drawLine(guyX, guyY + 16, guyX - 6, guyY + 24, SSD1306_WHITE); 
      display.drawLine(guyX - 6, guyY + 24, guyX - 2, guyY + 30, SSD1306_WHITE); 
      display.drawLine(guyX, guyY + 16, guyX + 6, guyY + 24, SSD1306_WHITE); 
      display.drawLine(guyX + 6, guyY + 24, guyX + 2, guyY + 30, SSD1306_WHITE); 
    }
  }

  // --- 3. THE HEARTS ---
  int heart1_Y = 64 - ((timeNow / 40) % 70);
  int heart2_Y = 64 - (((timeNow + 1500) / 40) % 70); 
  
  display.drawBitmap(120, heart1_Y, heart_bmp, 5, 5, SSD1306_WHITE);
  display.drawBitmap(95,  heart2_Y, heart_bmp, 5, 5, SSD1306_WHITE);

  display.display();
}