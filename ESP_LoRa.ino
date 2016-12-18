
// #include "config.h"


#include <SPI.h>
#include <sx127xRegs-LoRa.h>
#include <SX127x.h>


SX127x SX127x(1);
 long int payload = 1;
const int W = 1; // Write register
const int R = 0; // Read register
void setup()
{
   //pinMode(15, OUTPUT);
 // Serial.begin(115200); // to match ESP8266 default baudrate
}

void loop()
{
  int state;
  state= SX127x.init(1,REG_LR_FIFOTXBASEADDR,payload,W); 
   delay(100);
  state= SX127x.init(1,REG_LR_FIFOTXBASEADDR,payload,R); 
        //ackModule = SPI.transfer(0);
        //digitalWrite (15, HIGH);
  wdt_disable();
  delay(200);
  
}
