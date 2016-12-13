#include <SPI.h> 
#include "SX127X.h"
#include "config.h" // lyfte ut config
int r_size;
//char message;
long randNumber;
uint8_t message[100];
char float_str[20];
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

  // Print a start message
  Serial.println("Simple LoRa TX");


 /*!
 Returns: Integer that determines if there has been any error
   state = 2  --> The command has not been executed
   state = 1  --> There has been an error while executing the command
   state = 0  --> The command has been executed with no errors
   state = -1 --> Forbidden command for this protocol
*/  

SX1272 SX1272;
  SX1272.ON(); // sätter och startar SPI för modul
  sx1272.setMode(LORAMODE);
  // skapa setCR
  // skapa setSF
  // skapa setBW
  //sx1272._enableCarrierSense=true;
  //sx1272.setChannel(CH_05_433);
 sx1272.setFrequency (434000000); // setFrequency avrundar ej utan kapar decimalen, troligen svänger kretsen in på mottagarsidan korrekt ia alla fall
  
   

  //int8_t SX1272::setPower(char p)
  sx1272.setPower('x'); // Function: Sets the signal power indicated in the module. Parameters:p: power option to set in configuration.
Serial.println("SX127x successfully configured\n");

}

void loop() {
   wdt_disable(); // dissable ESP8266 watchdog
char msg[4];
randomize(msg);

  Serial.print("Random Letters: ");
  Serial.println(msg);
sx1272.sendPacketTimeout(DEFAULT_DEST_ADDR, msg);
 delay(20);
}



void randomize(char *ran) {
  
for (int i=0; i <= 3; i++){ 
  randomSeed(analogRead(0)); 
  long int f = random(0,128);
  int randNumber;
  randNumber = (int) f;
  ran[i] = char (f);
}
 ran[3] = 0;    // 4th array element is a null terminator
}

