#include "EEPROM.h"
void EEPROM_init(void)
{
  I2C1_Init(100000);         // initialize I2C communication
}

void EEPROM_writeByte(uint8 my_data,uint8 add)
{

  I2C1_Start();              // issue I2C start signal
  I2C1_Wr(0xA2);            // send byte via I2C  (device address + W)
  I2C1_Wr(add);                // send byte (address of EEPROM location)
  I2C1_Wr(my_data);            // send data (data to be written)
  I2C1_Stop();               // issue I2C stop signal
}

uint8 EEPROM_readByte(uint8 add)
{
    uint8 my_data;
    I2C1_Start();              // issue I2C start signal
  I2C1_Wr(0xA2);           // send byte via I2C  (device address + W)
  I2C1_Wr(add);               // send byte (data address)

  I2C1_Repeated_Start();     // issue I2C signal repeated start
  I2C1_Wr(0xA3);             // send byte (device address + R)

  my_data = I2C1_Rd(0u);       // Read the data (NO acknowledge)
  I2C1_Stop();               // issue I2C stop signal
  return my_data;
}