
_EEPROM_init:

	MOVLW      20
	MOVWF      SSPADD+0
	CALL       _I2C1_Init+0
L_end_EEPROM_init:
	RETURN
; end of _EEPROM_init

_EEPROM_writeByte:

	CALL       _I2C1_Start+0
	MOVLW      162
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
	MOVF       FARG_EEPROM_writeByte_add+0, 0
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
	MOVF       FARG_EEPROM_writeByte_my_data+0, 0
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
	CALL       _I2C1_Stop+0
L_end_EEPROM_writeByte:
	RETURN
; end of _EEPROM_writeByte

_EEPROM_readByte:

	CALL       _I2C1_Start+0
	MOVLW      162
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
	MOVF       FARG_EEPROM_readByte_add+0, 0
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
	CALL       _I2C1_Repeated_Start+0
	MOVLW      163
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
	CLRF       FARG_I2C1_Rd_ack+0
	CALL       _I2C1_Rd+0
	MOVF       R0+0, 0
	MOVWF      EEPROM_readByte_my_data_L0+0
	CALL       _I2C1_Stop+0
	MOVF       EEPROM_readByte_my_data_L0+0, 0
	MOVWF      R0+0
L_end_EEPROM_readByte:
	RETURN
; end of _EEPROM_readByte
