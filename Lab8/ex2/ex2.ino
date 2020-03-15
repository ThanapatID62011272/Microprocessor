#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  pinMode(14,INPUT);
  Serial.begin(9600);
  while(!Serial){ ; }

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay(); // clears the screen and buffer
  display.drawPixel(127, 63, WHITE);
}

void loop() {
  int x = analogRead(14);
  Serial.print(x);

  if(Serial.available()){
    char a = Serial.read();
    display.clearDisplay();
    display.setCursor(0,25);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println(a);
  }
}
