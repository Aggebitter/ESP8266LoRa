
// the #include statment and code go here...
#ifndef SX127x_h
#define SX127x_h

#include <stdlib.h>
#include <stdint.h>
#include <Arduino.h>
#include <SPI.h>

#include <sx127xRegs-LoRa.h>


//! CONFIG

#define SX1272_debug_mode 1
#define mode 'L'
#define USE_DIO0  // TX RX complete
#define USE_DIO5  // Mode change complete
#define dualLora
#define sx1276SelectPin_A 15

#if defined USE_DIO0
    #define DIO0_A 2
#endif

#if defined USE_DIO5
    #define DIO5_A 0
#endif

#if defined dualLora
    #define sx1276SelectPin_B 16;

    #if defined USE_DIO0
        #define DIO0_B 4; // TX RX complete
    #endif

    #if defined USE_DIO5
        #define DIO5_B 5; // Mode change complete
    #endif
#endif


class SX127x
{
  public:
    SX127x(int NumberOfModules);
    int init(int moDule, uint8_t registerSetting, uint8_t value, uint8_t ReadOrWrite);
    int TX();
    int RX();
    int state;
    int moDule;
    uint8_t registerSetting;
    uint8_t value;
    uint8_t ReadOrWrite;
    uint8_t ackModule;
  private:
    int _NumberOfModules;
    int _sx1276SelectPin_A;
    int _sx1276SelectPin_B;
    int _DIO0_A;
    int _DIO5_A;
    int _DIO0_B;
    int _DIO5_B;
    int _moDule;
    uint8_t _registerSetting;


};

#endif
