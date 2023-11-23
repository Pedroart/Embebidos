.def temp1 = r16
.def temp2 = r17
.def temp3 = r18
.def temp4 = r19

.def prov1 = r20
.def prov2 = r21
.def prov3 = r22
.def prov4 = r23

.DSEG ; Start data segment
flag_reg: .BYTE 1  ; 0b 0 0 0 0 0 0 0 (Dato Recibido)
modo_reg: .BYTE 1  ; Modos: 1(0000) 2(0010) 3(0100) 4(1000)
.CSEG 

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
	LDI temp1, 0b00000111
	STS PCMSK0, temp1
	ret

;---------------------------------------------------------
; Subrutinas de Interrupciones
;---------------------------------------------------------

RPCINT0:
	lds prov1,modo_reg    ; Rescata el estado del sistema
	cpi prov1, 0b1000		; Si no es modo 1, salta a modo 4
	brne puertob0
	
	cpi prov1, 0b000		; Si no es modo 1, salta a modo 4
	brne modo_falla

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
		ldi prov1,0b0000
		sts modo_falla, prov1
		rjmp fin_RPCINT0
	puertob1:
		ldi prov1,0b0010
		sts modo_falla, prov1
		rjmp fin_RPCINT0
	puertob2:
		ldi prov1,0b0100
		sts modo_falla, prov1  
		rjmp fin_RPCINT0
	modo_falla:
		ldi prov1,0b1000
		sts modo_falla, prov1  
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

	call conf_PCINT0				 ; LLama a la subrutina de configuracion del PCINT0 usado para el teclado

	ldi temp1,0b0001
	sts modo_falla, prov1			 ; Inicializa el modo de funcionamiento en 1

	sei                              ; Habilita todas las interrupciones
;---------------------------------------------------------
; Main
;---------------------------------------------------------
start:


    inc temp1
    rjmp start