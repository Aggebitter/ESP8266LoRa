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

#define RESET_WAIT_MS 7

// The crystal oscillator frequency of the module
#define RH_RF95_FXOSC 32000000.0

// The Frequency Synthesizer step = RH_RF95_FXOSC / 2^^19
#define RH_RF95_FSTEP  (RH_RF95_FXOSC / 524288)

#define LORA_BASE_LF   (RFLR_OPMODE_LONGRANGEMODE_ON|RFLR_OPMODE_ACCESSSHAREDREG_DISABLE|RFLR_OPMODE_FREQMODE_ACCESS_LF)
const char modemMode = 'L';
//const int sx127xSelectPin_A = 15;
//const int DIO0_A = 2; // TX RX complete
//const int DIO5_A = 0; // Mode change complete
// const boolean dualLora =1; // skipa och ta i driver init
//const int sx127xSelectPin_B = 16;
//const int DIO0_B = 4; // TX RX complete
//const int DIO5_B = 5; // Mode change complete
const boolean useDisplay = false ;
const int serialDebug = 1 ;

