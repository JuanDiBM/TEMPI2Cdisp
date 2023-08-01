/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app3.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app3.h"
#include "config/default/definitions.h"
#include "stdio.h"
#include <string.h>

float temperature;

APP3_DATA app3Data;

#define TCN75A_ADDRESS      0x48


void APP3_Initialize(void) {
    /* Place the App state machine in its initial state. */
    app3Data.state = APP3_STATE_INIT;

    I2C1_Initialize();

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

void APP3_Tasks(void) {

    /* Check the application's current state. */
    switch (app3Data.state) {
            /* Application's initial state. */
        case APP3_STATE_INIT:
        {
             bool appInitialized = true;


            if (appInitialized) {

                app3Data.state = APP3_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP3_STATE_SERVICE_TASKS:
        {
            uint8_t txData[1] = {0x00}; // Buffer para enviar el registro de temperatura
            uint8_t rxData[2] = {0}; // Buffer para recibir los datos de temperatura

            if(!I2C1_Write(TCN75A_ADDRESS, txData, 1)){ // Iniciar la transmisión
            }
            while (I2C1_IsBusy()); // Esperar a que la transmisión se complete

            // Leer los datos de temperatura desde el TCN75A
            if(!I2C1_Read(TCN75A_ADDRESS, rxData, 2)){ // Iniciar la recepción
            }
            while (I2C1_IsBusy()); // Esperar a que la recepción se complete

            uint16_t Value = ((uint16_t) rxData[0] << 7) | (rxData[1] & 0x01);
            
            // Si el bit más significativo (bit de signo) es 1, entonces el valor es negativo.
            // En ese caso, convertimos el valor negativo al complemento a 2.
            if (Value & 0x0100) {
                Value = ~Value + 1;
                temperature = -(float) Value * 0.5f;
            } else {
                temperature = (float) Value * 0.5f;
            }

            
            
        }
            /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
