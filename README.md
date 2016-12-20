# ESP8266LoRa UNDER heavy Construction
IoT With SemTech SX1276-79/HopeRF RFM9x and ESP6266 on Arduino


Not LoRa or EU ISM-band compliable !!

In Windows with default Arduino IDE installation path

Install SX12x folder under C:\Program Files (x86)\Arduino\libraries\

Create a new folder under C:\Users\User\Documents\Arduino (replace User with our username)

Rename the created folder to "ESP_LoRa" and copy the Example files "ESP_LoRa.ino and config.h" in to it

# Usage:

SX127x SX127x(serialDebug) // 1 Enables, set in config.h

SX127x.init(NSSpin); // max eight modules, New init for each module // will ad use of DIO1 and DIO5 

SX127x.single(Module#, address byte, data byte, (R)ead or (W)rite) // Works 6.625 us for 16bits transaction (address + payload)

SX127x.burst TODO

SX127x.fifo TODO

//Agge
