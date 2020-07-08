
_main:

	BSF        TRISE+0, 5
	CLRF       TRISD+0
	BSF        TRISB+0, 0
	BSF        TRISB+0, 1
	BCF        TRISB+0, 2
	BCF        PORTB+0, 2
	BCF        TRISC+0, 2
	BCF        PORTC+0, 2
	BCF        TRISC+0, 5
	BCF        PORTC+0, 5
L_main0:
	BTFSC      RB5_bit+0, BitPos(RB5_bit+0)
	GOTO       L_main1
	GOTO       L_main0
L_main1:
	MOVLW      1
	MOVWF      _elec_heater_flag+0
	CALL       _Os_start+0
L_end_main:
	GOTO       $+0
; end of _main
