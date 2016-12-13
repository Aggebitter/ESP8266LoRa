 /* WeMos D1 R2 mini pinout 
 *  Pin     Function                    ESP-8266 pin    Arduino Pin RMF9x
 *  TX      TXD                           TXD           1
 *  RX      RXD                           RXD           3 
 *  D0      IO                            GPIO16        16
 *  D1      IO/SCL                        GPIO5         5
 *  D2      IO/SDA                        GPIO4         4
 *  D3      IO, 10K Pull Up               GPIO0         0
 *  D4      IO, 10K Pull Up BUILTIN_LED   GPIO12        2
 *  D5      IO, SCK                       GPIO14        14
 *  D6      IO, MISO                      GPIO12        12
 *  D7      IO, MOSI                      GPIO13        13
 *  D8      IO, 10K Pull Down             GPIO15        15
 *  A0      Analog input, Max 3.3V input  A0            A0
 *  G       Ground                        GND           
 *  5V      5V
 *  3V3     3.3V                          3.3V           
 *  RST     Reset                         RST            
*/
// IMPORTANT
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// please uncomment only 1 choice
//
// uncomment if your radio is an HopeRF RFM92W or RFM95W
#define RADIO_RFM92_95
// uncomment if your radio is a Modtronix inAirB (the one with +20dBm features), if inAir9, leave commented
//#define RADIO_INAIR9B
// uncomment if you only know that it has 20dBm feature
//#define RADIO_20DBM
/////////////////////////////////////////////////////////////////////////////////////////////////////////// 

// IMPORTANT
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// please uncomment only 1 choice
//#define BAND868
#define BAND900
///////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// COMMENT OR UNCOMMENT TO CHANGE FEATURES. 
// ONLY IF YOU KNOW WHAT YOU ARE DOING!!! OTHERWISE LEAVE AS IT IS
#define WITH_EEPROM
#define WITH_APPKEY
#define FLOAT_TEMP
#define NEW_DATA_FIELD
//#define LOW_POWER
//#define LOW_POWER_HIBERNATE
//#define WITH_ACK
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// CHANGE HERE THE LORA MODE, NODE ADDRESS 
#define LORAMODE  1
#define node_addr 5
//////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// CHANGE HERE THE THINGSPEAK FIELD BETWEEN 1 AND 4
#define field_index 2
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// CHANGE HERE THE READ PIN AND THE POWER PIN FOR THE TEMP. SENSOR
#define TEMP_PIN_READ  A0
// use digital 8 to power the temperature sensor if needed
#define TEMP_PIN_POWER 2
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// CHANGE HERE THE TIME IN MINUTES BETWEEN 2 READING & TRANSMISSION
unsigned int idlePeriodInMin = 1;
///////////////////////////////////////////////////////////////////

#ifdef WITH_APPKEY
///////////////////////////////////////////////////////////////////
// CHANGE HERE THE APPKEY, BUT IF GW CHECKS FOR APPKEY, MUST BE
// IN THE APPKEY LIST MAINTAINED BY GW.
uint8_t my_appKey[4]={5, 6, 7, 8};
///////////////////////////////////////////////////////////////////
#endif

#define PRINTLN                   Serial.println("")
#define PRINT_CSTSTR(fmt,param)   Serial.print(F(param))
#define PRINT_STR(fmt,param)      Serial.print(param)
#define PRINT_VALUE(fmt,param)    Serial.print(param)
#define FLUSHOUTPUT               Serial.flush();

#define DEFAULT_DEST_ADDR 1

#ifdef WITH_ACK
#define NB_RETRIES 2
#endif

#define TEMP_SCALE  3300.0

