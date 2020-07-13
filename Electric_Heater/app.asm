
_Init_Task:

	BSF        PEIE_bit+0, BitPos(PEIE_bit+0)
	BSF        GIE_bit+0, BitPos(GIE_bit+0)
	MOVLW      145
	MOVWF      ADCON0+0
	MOVLW      192
	MOVWF      ADCON1+0
L_end_Init_Task:
	RETURN
; end of _Init_Task

_SSD_TASK:

	MOVF       _SSD_Enable_flag+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK0
	MOVF       _SSD_FLAG+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_SSD_TASK1
	BCF        PORTA+0, 5
	GOTO       L_SSD_TASK2
L_SSD_TASK4:
	MOVLW      91
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK3
L_SSD_TASK5:
	MOVLW      79
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK3
L_SSD_TASK6:
	MOVLW      102
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK3
L_SSD_TASK7:
	MOVLW      109
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK3
L_SSD_TASK8:
	MOVLW      125
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK3
L_SSD_TASK9:
	MOVLW      7
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK3
L_SSD_TASK10:
	MOVLW      127
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK3
L_SSD_TASK2:
	MOVF       _temp1+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK4
	MOVF       _temp1+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK5
	MOVF       _temp1+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK6
	MOVF       _temp1+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK7
	MOVF       _temp1+0, 0
	XORLW      6
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK8
	MOVF       _temp1+0, 0
	XORLW      7
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK9
	MOVF       _temp1+0, 0
	XORLW      8
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK10
L_SSD_TASK3:
	BSF        PORTA+0, 4
	MOVLW      1
	MOVWF      _SSD_FLAG+0
	GOTO       L_SSD_TASK11
L_SSD_TASK1:
	MOVF       _SSD_FLAG+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_SSD_TASK12
	BCF        PORTA+0, 4
	GOTO       L_SSD_TASK13
L_SSD_TASK15:
	MOVLW      63
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK16:
	MOVLW      6
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK17:
	MOVLW      91
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK18:
	MOVLW      79
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK19:
	MOVLW      102
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK20:
	MOVLW      109
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK21:
	MOVLW      125
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK22:
	MOVLW      7
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK23:
	MOVLW      127
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK24:
	MOVLW      111
	MOVWF      PORTD+0
	GOTO       L_SSD_TASK14
L_SSD_TASK13:
	MOVF       _temp2+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK15
	MOVF       _temp2+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK16
	MOVF       _temp2+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK17
	MOVF       _temp2+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK18
	MOVF       _temp2+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK19
	MOVF       _temp2+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK20
	MOVF       _temp2+0, 0
	XORLW      6
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK21
	MOVF       _temp2+0, 0
	XORLW      7
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK22
	MOVF       _temp2+0, 0
	XORLW      8
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK23
	MOVF       _temp2+0, 0
	XORLW      9
	BTFSC      STATUS+0, 2
	GOTO       L_SSD_TASK24
L_SSD_TASK14:
	BSF        PORTA+0, 5
	CLRF       _SSD_FLAG+0
L_SSD_TASK12:
L_SSD_TASK11:
L_SSD_TASK0:
L_end_SSD_TASK:
	RETURN
; end of _SSD_TASK

_up_ButtonTask:

	BTFSC      RB1_bit+0, BitPos(RB1_bit+0)
	GOTO       L_up_ButtonTask25
	MOVLW      1
	MOVWF      _SSD_blinking_flag+0
	CLRF       _SSD_blinking_counter+0
	MOVF       _temp1+0, 0
	XORLW      7
	BTFSS      STATUS+0, 2
	GOTO       L_up_ButtonTask28
	MOVF       _temp2+0, 0
	XORLW      5
	BTFSS      STATUS+0, 2
	GOTO       L_up_ButtonTask28
L__up_ButtonTask69:
	GOTO       L_up_ButtonTask29
L_up_ButtonTask28:
	MOVF       _temp2+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_up_ButtonTask30
	MOVLW      5
	ADDWF      _temp2+0, 1
	MOVF       _temp1+0, 0
	MOVWF      FARG_EEPROM_writeByte_my_data+0
	MOVLW      2
	MOVWF      FARG_EEPROM_writeByte_add+0
	CALL       _EEPROM_writeByte+0
	MOVF       _temp2+0, 0
	MOVWF      FARG_EEPROM_writeByte_my_data+0
	MOVLW      3
	MOVWF      FARG_EEPROM_writeByte_add+0
	CALL       _EEPROM_writeByte+0
	GOTO       L_up_ButtonTask31
L_up_ButtonTask30:
	MOVF       _temp2+0, 0
	XORLW      5
	BTFSS      STATUS+0, 2
	GOTO       L_up_ButtonTask32
	CLRF       _temp2+0
	INCF       _temp1+0, 1
	MOVF       _temp1+0, 0
	MOVWF      FARG_EEPROM_writeByte_my_data+0
	MOVLW      2
	MOVWF      FARG_EEPROM_writeByte_add+0
	CALL       _EEPROM_writeByte+0
	MOVF       _temp2+0, 0
	MOVWF      FARG_EEPROM_writeByte_my_data+0
	MOVLW      3
	MOVWF      FARG_EEPROM_writeByte_add+0
	CALL       _EEPROM_writeByte+0
L_up_ButtonTask32:
L_up_ButtonTask31:
L_up_ButtonTask29:
	MOVF       _temp1+0, 0
	MOVWF      R0+0
	MOVLW      10
	MOVWF      R4+0
	CALL       _Mul_8X8_U+0
	MOVF       _temp2+0, 0
	ADDWF      R0+0, 0
	MOVWF      _set_temp+0
L_up_ButtonTask25:
L_end_up_ButtonTask:
	RETURN
; end of _up_ButtonTask

_down_ButtonTask:

	BTFSC      RB2_bit+0, BitPos(RB2_bit+0)
	GOTO       L_down_ButtonTask33
	MOVLW      1
	MOVWF      _SSD_blinking_flag+0
	CLRF       _SSD_blinking_counter+0
	MOVF       _temp1+0, 0
	XORLW      3
	BTFSS      STATUS+0, 2
	GOTO       L_down_ButtonTask36
	MOVF       _temp2+0, 0
	XORLW      5
	BTFSS      STATUS+0, 2
	GOTO       L_down_ButtonTask36
L__down_ButtonTask70:
	GOTO       L_down_ButtonTask37
L_down_ButtonTask36:
	MOVF       _temp2+0, 0
	XORLW      5
	BTFSS      STATUS+0, 2
	GOTO       L_down_ButtonTask38
	CLRF       _temp2+0
	MOVF       _temp1+0, 0
	MOVWF      FARG_EEPROM_writeByte_my_data+0
	MOVLW      2
	MOVWF      FARG_EEPROM_writeByte_add+0
	CALL       _EEPROM_writeByte+0
	MOVF       _temp2+0, 0
	MOVWF      FARG_EEPROM_writeByte_my_data+0
	MOVLW      3
	MOVWF      FARG_EEPROM_writeByte_add+0
	CALL       _EEPROM_writeByte+0
	GOTO       L_down_ButtonTask39
L_down_ButtonTask38:
	MOVF       _temp2+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_down_ButtonTask40
	MOVLW      5
	MOVWF      _temp2+0
	DECF       _temp1+0, 1
	MOVF       _temp1+0, 0
	MOVWF      FARG_EEPROM_writeByte_my_data+0
	MOVLW      2
	MOVWF      FARG_EEPROM_writeByte_add+0
	CALL       _EEPROM_writeByte+0
	MOVF       _temp2+0, 0
	MOVWF      FARG_EEPROM_writeByte_my_data+0
	MOVLW      3
	MOVWF      FARG_EEPROM_writeByte_add+0
	CALL       _EEPROM_writeByte+0
L_down_ButtonTask40:
L_down_ButtonTask39:
L_down_ButtonTask37:
	MOVF       _temp1+0, 0
	MOVWF      R0+0
	MOVLW      10
	MOVWF      R4+0
	CALL       _Mul_8X8_U+0
	MOVF       _temp2+0, 0
	ADDWF      R0+0, 0
	MOVWF      _set_temp+0
L_down_ButtonTask33:
L_end_down_ButtonTask:
	RETURN
; end of _down_ButtonTask

_Heater_Led_Task:

	BTFSS      RC5_bit+0, BitPos(RC5_bit+0)
	GOTO       L_Heater_Led_Task41
	MOVLW      2
	ADDWF      _led_count+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      _led_count+0
	MOVF       R1+0, 0
	XORLW      10
	BTFSS      STATUS+0, 2
	GOTO       L_Heater_Led_Task42
	MOVLW      128
	XORWF      PORTB+0, 1
	CLRF       _led_count+0
L_Heater_Led_Task42:
	GOTO       L_Heater_Led_Task43
L_Heater_Led_Task41:
	BTFSS      RC2_bit+0, BitPos(RC2_bit+0)
	GOTO       L_Heater_Led_Task44
	BSF        PORTB+0, 7
L_Heater_Led_Task44:
L_Heater_Led_Task43:
L_end_Heater_Led_Task:
	RETURN
; end of _Heater_Led_Task

_ADC_Task:

	MOVF       _adc_flag+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_ADC_Task45
	MOVF       _count+0, 0
	XORLW      9
	BTFSS      STATUS+0, 2
	GOTO       L_ADC_Task46
	MOVF       _count+0, 0
	MOVWF      R0+0
	RLF        R0+0, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      _read+0
	MOVWF      FLOC__ADC_Task+0
	MOVLW      2
	MOVWF      FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	CALL       _word2double+0
	MOVLW      229
	MOVWF      R4+0
	MOVLW      255
	MOVWF      R4+1
	MOVLW      31
	MOVWF      R4+2
	MOVLW      119
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVLW      10
	MOVWF      R4+0
	MOVLW      215
	MOVWF      R4+1
	MOVLW      35
	MOVWF      R4+2
	MOVLW      120
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	CALL       _double2word+0
	MOVF       FLOC__ADC_Task+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	MOVF       R0+1, 0
	INCF       FSR, 1
	MOVWF      INDF+0
	MOVF       _read+2, 0
	ADDWF      _read+0, 0
	MOVWF      R0+0
	MOVF       _read+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _read+3, 0
	MOVWF      R0+1
	MOVF       _read+4, 0
	ADDWF      R0+0, 1
	MOVF       _read+5, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVF       _read+6, 0
	ADDWF      R0+0, 1
	MOVF       _read+7, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVF       _read+8, 0
	ADDWF      R0+0, 1
	MOVF       _read+9, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVF       _read+10, 0
	ADDWF      R0+0, 1
	MOVF       _read+11, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVF       _read+12, 0
	ADDWF      R0+0, 1
	MOVF       _read+13, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVF       _read+14, 0
	ADDWF      R0+0, 1
	MOVF       _read+15, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVF       _read+16, 0
	ADDWF      R0+0, 1
	MOVF       _read+17, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVF       _read+18, 0
	ADDWF      R0+0, 1
	MOVF       _read+19, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	CALL       _Div_16X16_U+0
	MOVF       R0+0, 0
	MOVWF      _average+0
	MOVF       R0+0, 0
	MOVWF      _temp_var+0
	CLRF       _dodo+0
L_ADC_Task47:
	MOVLW      2
	SUBWF      _dodo+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_ADC_Task48
	MOVF       _dodo+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_ADC_Task50
	MOVLW      10
	MOVWF      R4+0
	MOVF       _temp_var+0, 0
	MOVWF      R0+0
	CALL       _Div_8X8_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _temp2+0
	MOVLW      10
	MOVWF      R4+0
	MOVF       _temp_var+0, 0
	MOVWF      R0+0
	CALL       _Div_8X8_U+0
	MOVF       R0+0, 0
	MOVWF      _temp_var+0
	GOTO       L_ADC_Task51
L_ADC_Task50:
	MOVF       _temp_var+0, 0
	MOVWF      _temp1+0
L_ADC_Task51:
	INCF       _dodo+0, 1
	GOTO       L_ADC_Task47
L_ADC_Task48:
	MOVF       _set_temp+0, 0
	SUBWF      _average+0, 0
	MOVWF      R1+0
	CLRF       R1+1
	BTFSS      STATUS+0, 0
	DECF       R1+1, 1
	MOVLW      128
	XORWF      R1+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__ADC_Task79
	MOVLW      5
	SUBWF      R1+0, 0
L__ADC_Task79:
	BTFSS      STATUS+0, 0
	GOTO       L_ADC_Task52
	BSF        PORTC+0, 2
	BCF        PORTC+0, 5
	GOTO       L_ADC_Task53
L_ADC_Task52:
	MOVF       _set_temp+0, 0
	SUBWF      _average+0, 0
	MOVWF      R1+0
	CLRF       R1+1
	BTFSS      STATUS+0, 0
	DECF       R1+1, 1
	MOVLW      127
	MOVWF      R0+0
	MOVLW      128
	XORWF      R1+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__ADC_Task80
	MOVF       R1+0, 0
	SUBLW      251
L__ADC_Task80:
	BTFSS      STATUS+0, 0
	GOTO       L_ADC_Task54
	BSF        PORTC+0, 5
	BCF        PORTC+0, 2
L_ADC_Task54:
L_ADC_Task53:
	CLRF       _count+0
	GOTO       L_ADC_Task55
L_ADC_Task46:
	MOVF       _count+0, 0
	MOVWF      R0+0
	RLF        R0+0, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      _read+0
	MOVWF      FLOC__ADC_Task+0
	MOVLW      2
	MOVWF      FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	CALL       _word2double+0
	MOVLW      229
	MOVWF      R4+0
	MOVLW      255
	MOVWF      R4+1
	MOVLW      31
	MOVWF      R4+2
	MOVLW      119
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVLW      10
	MOVWF      R4+0
	MOVLW      215
	MOVWF      R4+1
	MOVLW      35
	MOVWF      R4+2
	MOVLW      120
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	CALL       _double2word+0
	MOVF       FLOC__ADC_Task+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	MOVF       R0+1, 0
	INCF       FSR, 1
	MOVWF      INDF+0
	INCF       _count+0, 1
L_ADC_Task55:
L_ADC_Task45:
L_end_ADC_Task:
	RETURN
; end of _ADC_Task

_heater_task:

	BTFSC      RB0_bit+0, BitPos(RB0_bit+0)
	GOTO       L_heater_task56
	MOVF       _elec_heater_flag+0, 0
	MOVLW      1
	BTFSS      STATUS+0, 2
	MOVLW      0
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      _elec_heater_flag+0
	MOVF       R1+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_heater_task57
	CLRF       PORTD+0
	BCF        PORTA+0, 5
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_heater_task58:
	DECFSZ     R13+0, 1
	GOTO       L_heater_task58
	DECFSZ     R12+0, 1
	GOTO       L_heater_task58
	DECFSZ     R11+0, 1
	GOTO       L_heater_task58
	NOP
	BCF        PORTA+0, 4
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_heater_task59:
	DECFSZ     R13+0, 1
	GOTO       L_heater_task59
	DECFSZ     R12+0, 1
	GOTO       L_heater_task59
	DECFSZ     R11+0, 1
	GOTO       L_heater_task59
	NOP
	BCF        PORTC+0, 2
	BCF        PORTC+0, 5
	CLRF       _adc_flag+0
	BCF        PORTB+0, 7
L_heater_task57:
L_heater_task56:
L_end_heater_task:
	RETURN
; end of _heater_task

_SSD_blinking:

	MOVF       _SSD_blinking_flag+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_SSD_blinking60
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking72
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking72
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      20
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking72
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      30
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking72
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      40
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking72
	GOTO       L_SSD_blinking63
L__SSD_blinking72:
	CLRF       PORTD+0
	MOVLW      1
	MOVWF      _SSD_Enable_flag+0
L_SSD_blinking63:
	INCF       _SSD_blinking_counter+0, 1
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking71
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      15
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking71
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      25
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking71
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      35
	BTFSC      STATUS+0, 2
	GOTO       L__SSD_blinking71
	GOTO       L_SSD_blinking66
L__SSD_blinking71:
	CLRF       _SSD_Enable_flag+0
	GOTO       L_SSD_blinking67
L_SSD_blinking66:
	MOVF       _SSD_blinking_counter+0, 0
	XORLW      45
	BTFSS      STATUS+0, 2
	GOTO       L_SSD_blinking68
	BCF        PORTA+0, 4
	BCF        PORTA+0, 5
	CLRF       _SSD_blinking_counter+0
	CLRF       _SSD_blinking_flag+0
	CLRF       _SSD_Enable_flag+0
	MOVLW      1
	MOVWF      _adc_flag+0
L_SSD_blinking68:
L_SSD_blinking67:
L_SSD_blinking60:
L_end_SSD_blinking:
	RETURN
; end of _SSD_blinking
