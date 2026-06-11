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
  
  unsigned long songLoop = timeNow % 30000; 
  
 
  int phase = songLoop / 1500; 
  
  
  display.setCursor(0, 0); 
  
  if (phase == 0) {
    display.println("Girls"); display.println("just"); display.println("wanna"); display.println("dance");
  } else if (phase == 1) {
    display.println("Girls"); display.println("just"); display.println("wanna"); display.println("have");
  } else if (phase == 2) {
    display.setCursor(0, 10);
    display.println("F*ck your"); display.println("ex man,");
  } else if (phase == 3) {
    display.setCursor(0, 10);
    display.println("I'm the"); display.println("man now");
  } else if (phase == 4) {
    display.setCursor(0, 10);
    display.println("Think I"); display.println("feel bad?");
  } else if (phase == 5) {
    display.setCursor(0, 10);
    display.println("He was"); display.println("fanned out");
  } else if (phase == 6) {
    display.setCursor(0, 10);
    display.println("Do what"); display.println("you like,");
  } else if (phase == 7) {
    display.println("you've"); display.println("been too"); display.println("nice");
  } else if (phase == 8) {
    display.setCursor(0, 10);
    display.println("He didn't"); display.println("do right,");
  } else if (phase == 9) {
    display.setCursor(0, 10);
    display.println("that's too"); display.println("bad now");
  } else if (phase == 10) {
    display.println("I see that"); display.println("you worked"); display.println("all night");
  } else if (phase == 11) {
    display.println("you're"); display.println("just tryna"); display.println("cash out");
  } else if (phase == 12) {
    display.setCursor(0, 10);
    display.println("You & your"); display.println("friends,");
  } else if (phase == 13) {
    display.println("they're"); display.println("tryna"); display.println("lash out");
  } else if (phase == 14) {
    display.println("And I'm"); display.println("not the"); display.println("one");
  } else if (phase == 15) {
    display.setCursor(0, 10);
    display.println("to tell'em"); display.println("Stand down");
  } else if (phase == 16) {
    display.setCursor(0, 10);
    display.println("It's their"); display.println("world");
  } else if (phase == 17) {
    display.println("and they"); display.println("just wanna"); display.println("(Ayy)");
  } else if (phase == 18) {
    display.println("Girls"); display.println("just"); display.println("wanna"); display.println("dance");
  } else if (phase == 19) {
    display.println("Girls"); display.println("just"); display.println("wanna"); display.println("have fun");
  }


  bool showStickFigure = (phase == 0 || phase == 1 || phase == 18 || phase == 19);

  if (showStickFigure) {
    int danceBeat = (timeNow / 300) % 2; 
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

  int heart1_Y = 64 - ((timeNow / 40) % 70);
  int heart2_Y = 64 - (((timeNow + 1500) / 40) % 70); 
  
  display.drawBitmap(120, heart1_Y, heart_bmp, 5, 5, SSD1306_WHITE);
  display.drawBitmap(95,  heart2_Y, heart_bmp, 5, 5, SSD1306_WHITE);

  display.display();
}