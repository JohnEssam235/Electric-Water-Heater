#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void EEPROM_init(void);
void EEPROM_writeByte(unsigned short my_data,uint8 add);
uint8 EEPROM_readByte(uint8 add);


#endif /* EXTERNAL_EEPROM_H_ */