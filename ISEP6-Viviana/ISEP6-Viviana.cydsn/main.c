/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

volatile uint8 FlagError = 0;
volatile uint8 tipo;
volatile uint8 data;
volatile uint8 habilitador_triger;
volatile int distancias[] = {1,1,1,1};
const uint8 digitPatterns[] = {
    0b0111111,  // 0
    0b0000110,  // 1
    0b1011011,  // 2
    0b1001111,  // 3
    0b1100110,  // 4
    0b1101101,  // 5
    0b1111101,  // 6
    0b0000111,  // 7
    0b1111111,  // 8
    0b1101111   // 9
};

void displayCharacter(uint8 digit) {
   Segmento_Write(digitPatterns[digit]);
}



uint8 procesarDistancias() {
    
    uint8 resultado = 0b00000000;
    int numElementos = 4;
    for (int i = 0; i < numElementos; ++i) {
        // Establecer el bit correspondiente según el valor de distancias[i]
        resultado |= (distancias[i] << i);
    }
    return resultado;
}



void enviarDatos(uint8 tipo, uint8 data)
{
    // Combina el tipo (4 bits más significativos) y la data (4 bits menos significativos)
    uint8 datoAEnviar = ((tipo & 0x0F) << 4) | (data & 0x0F);

    // Espera hasta que el buffer de transmisión esté listo
    while (UART_Atmega_ReadTxStatus() & UART_Atmega_TX_STS_FIFO_FULL);

    // Envía el byte a través de la UART
    UART_Atmega_WriteTxData(datoAEnviar);

    // Espera a que se complete la transmisión
    while (!(UART_Atmega_ReadTxStatus() & UART_Atmega_TX_STS_COMPLETE));
}

CY_ISR_PROTO(Perror);
CY_ISR_PROTO(UART_RX_ISR);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Atmega_Start();
    irq_P_StartEx(Perror);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint8_t lectura_sensor=0b0000;
    uint8_t modo = 0b0000;
    uint8_t modo_anterior = 0b0000;
    for(;;)
    {
        LED_D_Write(0);
        LED_F_Write(0);
        if(FlagError ==1){
            enviarDatos(0b01100000, 0b0001000);
            V1_Write(0);
            V2_Write(0);
            LED_F_Write(1);
        }
        else{
            enviarDatos(0b00110000, procesarDistancias());
            
            // Leer la variable tipo y realizar acciones basadas en su valor
            if (tipo == 0b0011) {
                // Guardar el bit(2) de data en la variable lectura_sensor
                lectura_sensor = (data >> 2) & 0x01;
                // Realizar acciones con lectura_sensor si es necesario
            }
            
            // Leer la variable tipo y realizar acciones basadas en su valor
            if (tipo == 0b0110) {
                // Guardar el valor de data en la variable modo
                modo = data;
                if (modo_anterior == 0b0100 && modo == 0b1001) {
                    // Activar el pin led (ajusta el nombre del pin según tu configuración)
                    LED_D_Write(1);
                }
                // Realizar acciones con modo si es necesario
            }
            modo_anterior = modo;
            if (modo == 0b0100) {
                    // Leer la variable lectura_sensor y realizar acciones adicionales si es necesario
                    if (lectura_sensor == 0b0100) {
                        // Activar los pines v1 y v2
                        V1_Write(1);
                        V2_Write(1);
                    }else{
                        V1_Write(0);
                        V2_Write(0);
                    }
            }
            
        }
        
        
        
    }
}


CY_ISR(Perror){
    FlagError=1;
}

CY_ISR(irq_Activacion_Lectura){
    int value_counter = 65535-Timer_Lectura_ReadCounter();
    int Selector = Contador_Estado_Read();
    distancias[Selector] = value_counter;
}

CY_ISR(irq_Activacion_triger){
   habilitador_triger = 1;
   Trigger_out_Write(1);
    CyDelay(10u);
   Trigger_out_Write(0);
}


CY_ISR(UART_RX_ISR)
{
    // Leer el byte recibido y almacenarlo en la variable global
    uint8 rx_data = 0;
    rx_data = UART_Atmega_ReadRxData();
    tipo = (rx_data >> 4) & 0x0F;
    data = rx_data & 0x0F;
}

/* [] END OF FILE */
