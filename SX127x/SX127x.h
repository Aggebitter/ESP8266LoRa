// the #include statment and code go here...
#ifndef SX127x_h
#define SX127x_h

#include <stdlib.h>
#include <stdint.h>
#include "Arduino.h"
#include <SPI.h>

#include <sx127xRegs-LoRa.h>


//! CONFIG

// #define SX1272_debug_mode 0 // fixed in init
//#define mode 'L'
//#define USE_DIO0  // TX RX complete
//#define USE_DIO5  // Mode change complete
//#define dualLora
//#define sx1276SelectPin_A 15

//#if defined USE_DIO0
//#define DIO0_A 2
//#endif

//#if defined USE_DIO5
//#define DIO5_A 0
//#endif

//#if defined dualLora
//#define sx1276SelectPin_B 16;

//#if defined USE_DIO0
//#define DIO0_B 4; // TX RX complete
//#endif

//#if defined USE_DIO5
//#define DIO5_B 5; // Mode change complete
//#endif
//#endif


class SX127x
{
public:
    SX127x(uint8_t serialDebug);
    uint8_t init(uint8_t sx1276SelectPin, uint8_t DIO0pin, uint8_t DIO5pin);
    uint8_t init(uint8_t sx1276SelectPin, uint8_t DIO0pin);
    uint8_t init(uint8_t sx1276SelectPin);
    uint8_t modemLoRa(uint8_t BW, uint8_t SF, uint8_t CR);
    uint8_t modemFSK(uint8_t BW);
    uint8_t modemOOK(uint8_t BW);
    uint8_t single(uint8_t moDule, uint8_t registerSetting, uint8_t value, uint8_t Write);
    uint8_t burst();
    uint8_t fifo();
    uint8_t serialDebug;
    uint8_t NumberOfModules;
    uint8_t state;
    uint8_t moDule;
    uint8_t address;
    uint8_t value;
    uint8_t Write;
    uint8_t ackModule;

protected:

    uint8_t _serialDebug;
    uint8_t _NumberOfModules;
    uint8_t _sx1276SelectPin;
    uint8_t _DIO0pins[8];
    uint8_t _DIO5pins[8];
    uint8_t _SelectPins[8];
    uint8_t _sx1276SelectPinCounter;
    uint8_t _DIO0_A;
    uint8_t _DIO5_A;
    uint8_t _DIO0_B;
    uint8_t _DIO5_B;
    uint8_t _moDule;
    uint8_t _address;
    uint8_t _replySPIsingle;



};

#endif
