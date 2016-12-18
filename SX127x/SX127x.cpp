#include <Arduino.h>
#include <SPI.h>
#include <HardwareSerial.h>
#include "SX127x.h"


SX127x::SX127x(uint8_t NumberOfModules)//! Set the chip selects and if used interrupts

{
    _NumberOfModules = NumberOfModules;


    if (_NumberOfModules == 0)
    {
        Serial.println("Number of Modules not set");
    }

    else if (_NumberOfModules == 1)
    {
        _sx1276SelectPin_A = sx1276SelectPin_A;
        _DIO0_A = DIO0_A;
        _DIO5_A = DIO5_A;
        pinMode(_sx1276SelectPin_A, OUTPUT);
        pinMode(_DIO0_A, INPUT);
        pinMode(_DIO5_A, INPUT);
        Serial.print("Module A:");
        //Serial.println(sx1276SelectPin_A);
    }

    else if (_NumberOfModules == 2)
    {
        _sx1276SelectPin_A = sx1276SelectPin_A;
        _DIO0_A = DIO0_A;
        _DIO5_A = DIO5_A;
        _sx1276SelectPin_B = sx1276SelectPin_B;
        _DIO0_B = DIO0_B;
        _DIO5_B = DIO5_B;

        pinMode(_sx1276SelectPin_A, OUTPUT);
        pinMode(_DIO0_A, INPUT);
        pinMode(_DIO5_A, INPUT);
        pinMode(_sx1276SelectPin_B, OUTPUT);
        pinMode(_DIO0_B, INPUT);
        pinMode(_DIO5_B, INPUT);
        Serial.print("Module A and B");
        //Serial.println(sx1276SelectPin_A);
    }
    //SPISettings settingsSX127x(2000000, MSBFIRST, SPI_MODE0);
    Serial.begin(115200); // to match ESP8266 default baudrate


    if (SX1272_debug_mode == 1)
    {
        Serial.print("SX127x::SX127x  :");
    }
}

uint8_t SX127x::single(uint8_t moDule, uint8_t address, uint8_t value, uint8_t ReadOrWrite)//! (Module#, address byte, data byte, (R)ead or (W)rite)
{

    if (SX1272_debug_mode == 1 )
    {
        //Serial.println(" SX127x.init Failed! use (N,xxxx,xxxx) as N in number of modules");
        Serial.print("Starting init SX127x.init ");
    }
    if (_moDule == 1)
    {
        Serial.println("Module 1");
    }
    _moDule = moDule;
    if (_moDule == 0)
    {
        if (SX1272_debug_mode == 1 )
        {
            //Serial.println(" SX127x.init Failed! use (N,xxxx,xxxx) as N in number of modules");
            Serial.println("SX127x.init Failed! Use (N,xxxx,xxxx) as N in number of modules");
        }
        state = 3; // no module to init
        return state;
    }

    if (_moDule == 1)
    {
        _sx1276SelectPin = _sx1276SelectPin_A;
    }
    if (_moDule == 2)
    {
        _sx1276SelectPin = _sx1276SelectPin_B;
    }
    //! Set up SPI for SX127x
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setFrequency(1000000); // for ESP8266
    SPI.setDataMode(SPI_MODE0);

    //! Enable SX127x
    digitalWrite (_sx1276SelectPin, HIGH);
    delay(35); //! NSS setup time, From NSS falling edge to SCK rising edge. 30ns SX1276-79 spec

    //! Do the transfer on SPI
    if (ReadOrWrite == 1)
    {
        bitSet(address, 7);			//! Bit 7 Write to registers
    }

    //! Create an 16bit message for SPI data form address and value
    uint16_t message = ( address << 8) | value  ; // Register settings first

    Serial.print("Sent message 16 bit:");
    Serial.print(message, BIN);
    Serial.print("    Got reply:");
    Serial.println(SPI.transfer16(message), BIN);
    delay(105); //! NSS hold time, From SCK falling edge to NSS rising edge, normal mode 100ns SX1276-79 spec

    // ackModule = SPI.transfer(0);        delay(100);
    //! Release SX127x
    digitalWrite (_sx1276SelectPin, LOW);

    if (SX1272_debug_mode == 1 )
    {
        Serial.print("init Module:");
        Serial.print(_moDule);
        Serial.print(" with: 0x");
        Serial.print(address, HEX);
        Serial.print(", ");
        Serial.print(value, HEX);
        Serial.print(" Response :");
        Serial.println(ackModule, HEX);

    }
    state = 1; // Init Module #


    SPI.end();
    return state;
    delay(25);
}

uint8_t SX127x::burst()
{
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0)); // set up hardware SPI for SX127x
    if (SX1272_debug_mode == 1)
    {
        Serial.println("SX127x::TX  :");
    }
    state = 1;
    delay(250);
    return state;
}
uint8_t SX127x::fifo()
{
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0)); // set up hardware SPI for SX127x
    delay(250);
    state = 1;
    delay(250);
}


