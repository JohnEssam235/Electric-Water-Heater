#line 1 "D:/swift act files/EEPROM.c"
#line 1 "d:/swift act files/eeprom.h"
#line 1 "d:/swift act files/std_types.h"
#line 20 "d:/swift act files/std_types.h"
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned int uint16;
typedef signed int sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef unsigned long long uint64;
typedef signed long long sint64;
typedef float float32;
typedef double float64;
#line 15 "d:/swift act files/eeprom.h"
void EEPROM_init(void);
void EEPROM_writeByte(unsigned short my_data,uint8 add);
uint8 EEPROM_readByte(uint8 add);
#line 2 "D:/swift act files/EEPROM.c"
void EEPROM_init(void)
{
 I2C1_Init(100000);
}

void EEPROM_writeByte(uint8 my_data,uint8 add)
{

 I2C1_Start();
 I2C1_Wr(0xA2);
 I2C1_Wr(add);
 I2C1_Wr(my_data);
 I2C1_Stop();
}

uint8 EEPROM_readByte(uint8 add)
{
 uint8 my_data;
 I2C1_Start();
 I2C1_Wr(0xA2);
 I2C1_Wr(add);

 I2C1_Repeated_Start();
 I2C1_Wr(0xA3);

 my_data = I2C1_Rd(0u);
 I2C1_Stop();
 return my_data;
}
