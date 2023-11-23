.def temp1 = r16
.def temp2 = r17
.def temp3 = r18
.def temp4 = r19

.def prov1 = r20
.def prov2 = r21
.def prov3 = r22
.def prov4 = r23

;---------------------------------------------------------
; Vector de Interrupciones PAG(49)
;---------------------------------------------------------

.org 0x0000 jmp RESET ; Reset Handler
.org 0x0006 jmp RPCINT0 ; PCINT0 Handler
;---------------------------------------------------------
; Configuracion de Interrupciones
;---------------------------------------------------------

conf_PCINT0:
	lds temp1,PCICR
	ldi temp2, 0b0001
	or temp1,temp2
	sts PCICR,temp1
	LDI temp1, 0b00000011
	STS PCMSK0, temp1
	ret

;---------------------------------------------------------
; Subrutinas de Interrupciones
;---------------------------------------------------------

RPCINT0:
	lds prov1, pind

	cpi prov1, 0b001
	breq puertob0

	cpi prov1, 0b010
	breq puertob1

	cpi prov1, 0b100
	breq puertob2

	fin_RPCINT0:
	reti
	;---------------------------------
	puertob0:
		nop
		rjmp fin_RPCINT0

	puertob1:
		nop
		rjmp fin_RPCINT0
	puertob2:
		nop
		rjmp fin_RPCINT0

;---------------------------------------------------------
; Reset
;---------------------------------------------------------
RESET:
	; Definición de la pila
	LDI temp1, HIGH(RAMEND)
	OUT SPH, temp1
	LDI temp1, LOW(RAMEND)
	OUT SPL, temp1

;---------------------------------------------------------
; Main
;---------------------------------------------------------
start:


    inc temp1
    rjmp start