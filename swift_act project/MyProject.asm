
_main:

	CALL       _EEPROM_init+0
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	NOP
	BSF        TRISB+0, 0
	CLRF       TRISD+0
	BCF        TRISA+0, 4
	BCF        TRISA+0, 5
	BSF        TRISB+0, 1
	BSF        TRISB+0, 2
	BCF        TRISB+0, 7
	BCF        PORTB+0, 7
	BCF        TRISC+0, 2
	BCF        PORTC+0, 2
	BCF        TRISC+0, 5
	BCF        PORTC+0, 5
L_main1:
	BTFSS      RB0_bit+0, BitPos(RB0_bit+0)
	GOTO       L_main2
	GOTO       L_main1
L_main2:
	MOVLW      1
	MOVWF      _elec_heater_flag+0
	MOVLW      2
	MOVWF      FARG_EEPROM_readByte_add+0
	CALL       _EEPROM_readByte+0
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main3
	MOVLW      6
	MOVWF      _temp1+0
	CLRF       _temp2+0
	GOTO       L_main4
L_main3:
	MOVLW      2
	MOVWF      FARG_EEPROM_readByte_add+0
	CALL       _EEPROM_readByte+0
	MOVF       R0+0, 0
	MOVWF      _temp1+0
	MOVLW      3
	MOVWF      FARG_EEPROM_readByte_add+0
	CALL       _EEPROM_readByte+0
	MOVF       R0+0, 0
	MOVWF      _temp2+0
L_main4:
	CALL       _Os_start+0
L_end_main:
	GOTO       $+0
; end of _main
