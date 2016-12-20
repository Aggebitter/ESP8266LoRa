



#include <SPI.h>
#include <sx127xRegs-LoRa.h>
#include <SX127x.h>
#include "config.h"

#define OLED_DC 4 //D2
#define OLED_CS 2 //D4
#include <SSD1306Ascii.h>
#include <SSD1306AsciiSpi.h>


SX127x SX127x(serialDebug); // in config.h Serial debug 1= debug, 0= No debug
SSD1306AsciiSpi oled;

long int payload = 1;
int adressModule = 129;
int payloadModule = 77;
int message;
const int W = 1; // Write register
const int R = 0; // Read register

void setup()
{
  oled.begin(&Adafruit128x64, OLED_CS, OLED_DC);
  oled.setFont(Adafruit5x7);  
  SX127x.init(15); // first module
 // SX127x.init(16); // second module
 // SX127x.init(2); // third module

}

void loop()
{ 
for (long int i=0; i <= 1024; i++){

message = SX127x.single(1, adressModule, payloadModule, W);
 Serial.println(message, HEX);
  //oled.clear(); 
  oled.setCursor(1,1); 
  oled.print("AGGE's mojj");
  oled.setCursor(1,2);
  oled.print("    ");
  oled.setCursor(1,2);
  oled.print(payloadModule);
  oled.setCursor(1,3);
  oled.print("    ");
  oled.setCursor(1,3);
  oled.println(message);
  oled.println();
  oled.print("messages:");
  
  oled.setCursor(64,6);
  oled.set2X();
  oled.print("      ");
  oled.setCursor(64,6);
  oled.println(i);
  oled.set1X();
 wdt_disable();
}




}
