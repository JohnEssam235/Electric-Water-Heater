
_Timer1_start:

	CLRF       TMR1L+0
	CLRF       TMR1H+0
	BCF        T1CKPS0_bit+0, BitPos(T1CKPS0_bit+0)
	BCF        T1CKPS1_bit+0, BitPos(T1CKPS1_bit+0)
	BCF        TMR1CS_bit+0, BitPos(TMR1CS_bit+0)
	BSF        TMR1ON_bit+0, BitPos(TMR1ON_bit+0)
	MOVF       FARG_Timer1_start_my_tick+0, 0
	MOVWF      CCPR1+0
	CLRF       CCPR1+1
	MOVLW      11
	MOVWF      CCP1CON+0
	BSF        CCP1IE_bit+0, BitPos(CCP1IE_bit+0)
L_end_Timer1_start:
	RETURN
; end of _Timer1_start

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

	BTFSS      CCP1IF_bit+0, BitPos(CCP1IF_bit+0)
	GOTO       L_interrupt0
	INCF       gpt_count+0, 1
	MOVF       gpt_count+0, 0
	XORLW      100
	BTFSS      STATUS+0, 2
	GOTO       L_interrupt1
	CALL       _Os_newTimerTick+0
	CLRF       gpt_count+0
L_interrupt1:
	BCF        CCP1IF_bit+0, BitPos(CCP1IF_bit+0)
L_interrupt0:
L_end_interrupt:
L__interrupt4:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

gpt____?ag:

L_end_gpt___?ag:
	RETURN
; end of gpt____?ag
