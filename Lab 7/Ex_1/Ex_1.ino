#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define a 2
#define b 3

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay(); // clears the screen and buffer
  display.drawPixel(127, 63, WHITE);

  //display.drawLine(0, 63, 127, 63, WHITE);
  //display.drawCircle(110, 50, 12, WHITE);
  //display.fillCircle(45, 50, 8, WHITE);
  //display.drawTriangle(70, 60, 90, 60, 80, 46, WHITE);
  //display.setTextSize(1);
  //display.setTextColor(WHITE);
  //display.setCursor(0,0);
  //display.println("Welcome");
  //display.setTextSize(2);
  //display.println("KRAI");
  //display.setTextColor(BLACK, WHITE);
  //display.setTextSize(1);
  //display.println("www.krai.io");
  //display.setTextColor(WHITE, BLACK);
         //display.display();

  pinMode(a,INPUT);
  pinMode(b,INPUT);
}

void loop() {
  //clear the display
  // draw the two circles
  //take input from switch
  //check condition and fill the required circle

    display.clearDisplay();
    display.setCursor(0,25);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("SW1");
    display.setCursor(0,55);
    display.println("SW2");
    display.drawCircle(45, 25, 8, WHITE);
    display.drawCircle(45, 55, 8, WHITE);
   
  if(digitalRead(a)==0){
    display.fillCircle(45, 25, 8, WHITE);
  }
  if(digitalRead(b)==0){
    display.fillCircle(45, 55, 8, WHITE);
  }
  display.display();
}
