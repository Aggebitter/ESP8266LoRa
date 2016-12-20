



#include <SPI.h>
#include <sx127xRegs-LoRa.h>
#include <SX127x.h>
#include "config.h"
SX127x SX127x(serialDebug); // = Serial debug (0) No debug

long int payload = 1;
int adressModule = 1;
int payloadModule = 1;
const int W = 1; // Write register
const int R = 0; // Read register

void setup()
{
  // we have to define the NSS pins in set up, It will not get set in init
  //pinMode(2, OUTPUT);
  //pinMode(sx127xSelectPin_A, OUTPUT);
  //pinMode(sx127xSelectPin_B, OUTPUT);
  SX127x.init(15); // first module
  SX127x.init(16); // second module
  SX127x.init(2); // third module

  //SX127x.init(sx127xSelectPin_B);

//digitalWrite (2, LOW);
 delay(1000);  
// digitalWrite (2, HIGH);
   /*
   
        pinMode(2, OUTPUT);
        digitalWrite (15, 2);
        pinMode(15, OUTPUT);
        digitalWrite (15, HIGH);   
        
        SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    //SPI.setFrequency(5000000); // for ESP8266 5MHz
    SPI.setFrequency(10000000); // for ESP8266 5MHz
    SPI.setDataMode(SPI_MODE1);
    */
}

void loop()
{

    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setFrequency(5000000); // for ESP8266
    SPI.setDataMode(SPI_MODE0);
  

SX127x.single(1, adressModule, payloadModule, W);
delay(1000);

wdt_disable();
/*
delay(3);
digitalWrite (15, LOW);
//Serial.println(SPI.transfer16(testy), BIN);
//SPI.transfer16(payload);
digitalWrite (15,HIGH);
*/ 

}
