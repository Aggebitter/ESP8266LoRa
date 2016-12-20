#include "Arduino.h"
#include <SPI.h>
#include <HardwareSerial.h>
#include "SX127x.h"


SX127x::SX127x(uint8_t serialDebug)
//! don't know why no serial print out if debug enable. Serial.begins works!
{
    _sx1276SelectPinCounter = 0;
    _serialDebug = serialDebug;
    //_sx1276SelectPin = 255; // start up setting
    //! reserves and resets 8 pins for modules
    _SelectPins[0] = 255; // unused , use as counter ?
    _SelectPins[1] = 255; // first initiated  module
    _SelectPins[2] = 255;
    _SelectPins[3] = 255;
    _SelectPins[4] = 255;
    _SelectPins[5] = 255;
    _SelectPins[6] = 255;
    _SelectPins[7] = 255;
    _SelectPins[8] = 255; // eight initiated Module


    if (serialDebug == 1 )
    {
        //delay(1000); // wait a bit for ESP boot process serial printout
        Serial.begin(115200);
        Serial.println("Starting serial debug"); // don't know why this part does not work in Arduino setup()

    }


    /*
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
        */
}


uint8_t SX127x::init(uint8_t sx1276SelectPin)
//! Use SX127x.init(NSSpin max 8 modules is supported by the driver
{

    if (_serialDebug == 1)
    {
        Serial.println();
        Serial.println("Starting init function: ");
    }
    if (_SelectPins[0] == 9) // max amount of modules without expanding the array
    {
        //! this is a faulty state, will it ever happen ?


    }
    else if ( _SelectPins[0] == 255 ) // first modeule init
    {
        //! First module init
        _SelectPins[0] = 1;

        if (_serialDebug == 1)
        {
            Serial.print("First init _SelectPins[0]= ");
            Serial.print(_SelectPins[0],DEC);
        }

        _SelectPins[_SelectPins[0]] = sx1276SelectPin ;

        pinMode(_SelectPins[_SelectPins[0]], OUTPUT);
        digitalWrite (_SelectPins[_SelectPins[0]], LOW);

        if (_serialDebug == 1)
        {
            Serial.print(" pinMode and digitalWrite LOW on pin: ");
            Serial.println(_SelectPins[_SelectPins[0]],DEC);
        }

    }

    else if (_SelectPins[0] <= 8) // Adding pin for each module init
    {
        _SelectPins[0] ++;

        if (_serialDebug == 1)
        {
            Serial.print("Next init  _SelectPins[0]= ");
            Serial.print(_SelectPins[0],DEC);
        }

        _SelectPins[_SelectPins[0]] = sx1276SelectPin ;
        pinMode(_SelectPins[_SelectPins[0]], OUTPUT);
        digitalWrite (_SelectPins[_SelectPins[0]], LOW);

        if (_serialDebug == 1)
        {
            Serial.print(" pinMode and digitalWrite LOW on pin: ");
            Serial.println(_SelectPins[_SelectPins[0]],DEC);
        }

    }

}

uint8_t SX127x::single(uint8_t moDule, uint8_t address, uint8_t value, uint8_t Write)
//! (Module#, address byte, data byte, (R)ead or (W)rite)
{
    //! Set up SPI for SX127x
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setFrequency(5000000); // for ESP8266
    SPI.setDataMode(SPI_MODE0);



    if (Write == 1)
    {
        bitSet(address, 7);			//! Bit 7 Write to registers
    }

    //! Enable SX127x
    digitalWrite (_SelectPins[moDule], HIGH);//! NSS setup time, From NSS falling edge to SCK rising edge. 30ns SX1276-79 spec

    //! Create an 16bit message for SPI data form address and value
    uint16_t message = ( address << 8) | value  ; // Register settings first

    Serial.print("Message to Module: ");Serial.print(_moDule);Serial.print(message, BIN);Serial.print(" using NSS pin : ");Serial.print(_SelectPins[moDule]);

    Serial.println("    Got reply:");
    //! Do the transfer on SPI
    SPI.transfer(address);
    SPI.transfer(value);
    // SPI.transfer16(message);
    delay(105); //! NSS hold time, From SCK falling edge to NSS rising edge, normal mode 100ns SX1276-79 spec

    // ackModule = SPI.transfer(0);        delay(100);
    //! Release SX127x
    digitalWrite (_SelectPins[moDule], LOW);

    state = 1;

    SPI.end();
    return state;
    delay(25);
}

uint8_t SX127x::burst()
{
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0)); // set up hardware SPI for SX127x
    if (serialDebug == 1)
    {
        Serial.println("SX127x::TX  :");
    }
    state = 1;
    delay(250);
    return state;
}



