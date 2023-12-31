/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app0adc.c

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

#include "app0adc.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP0ADC_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP0ADC_DATA app0adcData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP0ADC_Initialize ( void )

  Remarks:
    See prototype in app0adc.h.
 */

void APP0ADC_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app0adcData.state = APP0ADC_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP0ADC_Tasks ( void )

  Remarks:
    See prototype in app0adc.h.
 */

void APP0ADC_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app0adcData.state )
    {
        /* Application's initial state. */
        case APP0ADC_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                app0adcData.state = APP0ADC_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP0ADC_STATE_SERVICE_TASKS:
        {

            break;
        }

        /* TODO: implement your application state machine.*/


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
