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
  
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  display.clearDisplay();

  unsigned long timeNow = millis();
  
  // A 32-second loop to fit the iconic Billie Jean chorus perfectly
  unsigned long songLoop = timeNow % 32000; 
  
  // 117 BPM pacing: break the lyrics into exact 2-second chunks
  int phase = songLoop / 2000; 
  
  // --- 1. THE KINETIC LYRICS ---
  if (phase == 0) {
    display.setCursor(0, 10);
    display.println("Billie"); display.println("Jean is");
  } else if (phase == 1) {
    display.setCursor(0, 10);
    display.println("not my"); display.println("lover");
  } else if (phase == 2) {
    display.setCursor(0, 10);
    display.println("She's"); display.println("just a");
  } else if (phase == 3) {
    display.setCursor(0, 10);
    display.println("girl who"); display.println("claims");
  } else if (phase == 4) {
    display.setCursor(0, 10);
    display.println("that I"); display.println("am the");
  } else if (phase == 5) {
    display.setCursor(0, 20);
    display.println("one");
  } else if (phase == 6) {
    display.setCursor(0, 10);
    display.println("But the"); display.println("kid is");
  } else if (phase == 7) {
    display.setCursor(0, 10);
    display.println("not my"); display.println("son");
  } else if (phase == 8) {
    display.setCursor(0, 10);
    display.println("She says"); display.println("I am");
  } else if (phase == 9) {
    display.setCursor(0, 20);
    display.println("the one");
  } else if (phase == 10) {
    display.setCursor(0, 10);
    display.println("But the"); display.println("kid is");
  } else if (phase == 11) {
    display.setCursor(0, 10);
    display.println("not my"); display.println("son");
  } else if (phase == 12) {
    display.setCursor(0, 10);
    display.println("Billie"); display.println("Jean is");
  } else if (phase == 13) {
    display.setCursor(0, 10);
    display.println("not my"); display.println("lover");
  } else if (phase == 14) {
    display.setCursor(0, 10);
    display.println("She's"); display.println("just a");
  } else if (phase == 15) {
    display.setCursor(0, 20);
    display.println("girl..."); 
  }

  // --- 2. THE CHORUS ONLY STICK FIGURE ---
  // He ONLY dances during "Billie Jean is not my lover"
  bool showStickFigure = (phase == 0 || phase == 1 || phase == 12 || phase == 13);

  if (showStickFigure) {
    // 117 BPM Math: 256ms creates a fast, snappy eighth-note bounce!
    int danceBeat = (timeNow / 256) % 2; 
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