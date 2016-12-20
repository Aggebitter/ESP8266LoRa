



#include <SPI.h>
#include <sx127xRegs-LoRa.h>
#include <SX127x.h>
#include "config.h"
SX127x SX127x(serialDebug); // in config.h Serial debug 1= debug, 0= No debug

long int payload = 1;
int adressModule = 129;
int payloadModule = 77;
const int W = 1; // Write register
const int R = 0; // Read register

void setup()
{

  SX127x.init(15); // first module
  SX127x.init(16); // second module
  SX127x.init(2); // third module

}

void loop()
{

SX127x.single(1, adressModule, payloadModule, W);

wdt_disable();

}
