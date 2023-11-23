.def temp1 = r16
.def temp2 = r17
.def temp3 = r18
.def temp4 = r19

.def prov1 = r20
.def prov2 = r21
.def prov3 = r22
.def prov4 = r23

.DSEG ; Start data segment
flag_reg: .BYTE 1  ; 0b (Timer5s) 0 0 0 (Sensor4) (Sensor3) (Sensor2) (Sensor1)
modo_reg: .BYTE 1  ; Modos: 1(1001) 2(0010) 3(0100) 4(1000)
.CSEG 

;---------------------------------------------------------
; Vector de Interrupciones PAG(49)
;---------------------------------------------------------

.org 0x0000 jmp RESET ; Reset Handler
.org 0x0008 jmp RPCINT1 ; PCINT0 Handler
;---------------------------------------------------------
; Configuracion de Interrupciones
;---------------------------------------------------------

conf_PCINT0:
	lds temp1,PCICR
	ldi temp2, 0b0010
	or temp1,temp2
	sts PCICR,temp1
	LDI temp1, 0b00000111
	STS PCMSK1, temp1
	ret

.equ UBRR_VAL= 6 ; Table 19-12
conf_UARTt:
	// Double the USART Transmission Speed
	ldi prov1, (1<<U2X0)
	sts UCSR0A, prov1
	
	ldi prov1, (1<<TXEN0) | (1<< UDRIE0)  | (0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0)
	sts UCSR0B, prov1
	

	ldi prov1, (0<<UMSEL00) | (0<<UMSEL01) | (0<<UPM00) | (0<<UPM01) | (0<<USBS0) | (1<<UCsZ01) | (1<<UCsZ00)
	STS UCSR0C, prov1

	
	ldi prov1, low(UBRR_VAL)
	sts UBRR0L, prov1
	
	ldi prov1, high(UBRR_VAL)
	sts UBRR0H, prov1
	
	;ldi prov1,0
	;sts UART_Reg, prov1  

	ret

Enable_Timer1:
	ldi prov1, 0b100    ; prescalador a 256 - 16.77696hz
	sts TCCR1B, prov1

	;ldi prov1, 0b0100   ;configuracion del contador A
	;sts	OCR1AH, prov1 
	
	;ldi prov1, 0b10000000 ; configuracion del contador B
	;sts	OCR1BH, prov1

	;LDI	prov1, 0b100 ; configuracion del Interrupciones
	;STS	TIMSK1, prov1 
	ret
disabled_Timer1:
	ldi prov1, 0b000    ; prescalador a 64
	sts TCCR1B, prov1
	ret
;---------------------------------------------------------
; Subrutinas de Interrupciones
;---------------------------------------------------------

RPCINT1:
	in prov1, pinc
	cpi prov1, 0b0000
	breq fin_RPCINT0

	lds prov1,modo_reg    ; Rescata el estado del sistema
	cpi prov1, 0b1000		; Si no es modo 1, salta a modo 4
	breq puertoc0

	cpi prov1, 0b1001		; Si no es modo 1, salta a modo 4
	brne modo_falla
	


	in prov1, pinc
	andi prov1, 0b00001111
	 
	cpi prov1, 0b0001
	breq puertoc0

	cpi prov1, 0b010
	breq puertoc1

	cpi prov1, 0b100
	breq puertoc2

	fin_RPCINT0:
	reti
	;---------------------------------
	puertoc0:
		ldi prov1,0b1001
		sts modo_reg, prov1
		rjmp fin_RPCINT0
	puertoc1:
		ldi prov1,0b0010
		sts modo_reg, prov1
		rjmp fin_RPCINT0
	puertoc2:
		ldi prov1,0b0100
		sts modo_reg, prov1  
		rjmp fin_RPCINT0
	modo_falla:
		ldi prov1,0b1000
		sts modo_reg, prov1  
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

	ldi temp1,0b1001
	sts modo_reg, temp1			 ; Inicializa el modo de funcionamiento en 1

	; Configuracion de Puertos
	ldi temp1,0b00110000      ; Puerto B
	out ddrb, temp1
	ldi temp1,0b11111111      ; Puerto B
	out ddrd, temp1

	ldi temp1,0b0001
	sts flag_reg, temp1  

	sei                              ; Habilita todas las interrupciones
;---------------------------------------------------------
; Main
;---------------------------------------------------------
start:
	
	in temp1, pinb
	andi temp1, 0b10000111 
	sts flag_reg, temp1  

	lds temp1,modo_reg    ; Rescata el estado del sistema
	out portd,temp1

	cpi temp1, 0b1001		; Si es modo 1 Salta
	breq apagar_motores
	
	cpi temp1, 0b1000		; Si es modo 4 Salta
	breq apagar_motores

	cpi temp1, 0b0010		; Si no es modo 2 Salta
	breq modo_2

	cpi temp1, 0b0100		; Si no es modo 3 Salta
	breq modo_3

    rjmp start

	apagar_motores:
		in temp1, portb
		andi temp1, 0b00111111 
		out portb, temp1
		rjmp start

	modo_2:

		
		lds temp1,flag_reg

		mov temp2,temp1
		andi temp2, 0b10000000 
		cpi temp2, 0b10000000
		breq FlagT1

		mov temp2,temp1
		andi temp2, 0b0010 
		cpi temp2, 0b0010
		breq FlagP2

		mov temp2,temp1
		andi temp2, 0b0001 
		cpi temp2, 0b0001
		breq FlagP1

		rjmp start
		;---------------------------------------------------------
		FlagP1:
			; Activo Faja
			in temp1, PORTB    
			sbr temp1, 1 << 4    
			out PORTB, temp1   
			rjmp start

		FlagP2:
			in temp1, PORTB
			ldi temp1, 0b00110000    ; Activa Lavado
			out PORTB, temp1  
			      
			call Enable_Timer1
			ldi temp1,0b10000000
			sts flag_reg, prov1  
			rjmp start
		FlagT1:
			lds temp2, TCNT1H 
			cpi temp2, 0b10011000 ;Valor reloj
			brne start

				in temp1, PORTB
				ldi temp1, 0b00010000    ; Desactivo Lavado
				out PORTB, temp1  
				rjmp start
		
	modo_3:
		lds temp1,flag_reg

		mov temp2,temp1
		andi temp2, 0b1000 
		cpi temp2, 0b1000
		brne start

			in temp1, PORTB
			ldi temp1, 0b00000000    ; Desactivo Motor
			out PORTB, temp1

		rjmp start