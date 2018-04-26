/*************************************************************
 * @file      : Init.c
 * @brief     : Peripheral Init Functions
 * @version   : 1.2.4
 * @date      : 05/10/2017  14:16 
 * @author    : Created by CoSmart 1.2.4
**************************************************************/
#include "DrvGPIO.h"
#include "DrvSPI.h"
#include "DrvADC.h"

/*************************************************************
 * GPIOB Initialization
**************************************************************/
void GPIOB_Init()
{
   //
   // Set PB11 Pin Mode
   //
   DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT);
   //
   // Set PB15 Pin Mode
   //
   DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);

}

/*************************************************************
 * GPIOD Initialization
**************************************************************/
void GPIOD_Init()
{
   //
   // Set PD14 Pin Mode
   //
   DrvGPIO_Open(E_GPD, 14, E_IO_OUTPUT);

}

/*************************************************************
 * GPIOC Initialization
**************************************************************/
void GPIOC_Init()
{
   //
   // Set PC12 Pin Mode
   //
   DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);
   //
   // Set PC13 Pin Mode
   //
   DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT);
   //
   // Set PC14 Pin Mode
   //
   DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT);
   //
   // Set PC15 Pin Mode
   //
   DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT);

}

/*************************************************************
 * SPI Initialization Code Template
**************************************************************/
void SPI3_Init()
{
    E_DRVSPI_PORT eSpiPort;

    /* Get which port to be used */
    eSpiPort = eDRVSPI_PORT3;
    DrvGPIO_InitFunction(E_FUNC_SPI3);

    /* Slave mode; clock parity, transmit and receive edge(eType) */
    DrvSPI_Open(eSpiPort, eDRVSPI_SLAVE, eDRVSPI_TYPE0, 32);

    /* Slave Select Trigger Mode */
    DrvSPI_SetTriggerMode(eSpiPort, eDRVSPI_EDGE_TRIGGER);

    /* Slave Selcet Active Level */
    DrvSPI_SetSlaveSelectActiveLevel(eSpiPort, eDRVSPI_ACTIVE_LOW_FALLING);

    /* LSB or MSB */
    DrvSPI_SetEndian(eSpiPort, eDRVSPI_MSB_FIRST);
}

/***************************************************************************//**
 * Declare function prototype
*******************************************************************************/
void ADC_Callbackfn(uint32_t u32UserData);
/*************************************************************
 * ADC Initialization
**************************************************************/
void ADC_Init()
{
    //
    // Configure the relative pins for ADC function
    //
    DrvGPIO_InitFunction(E_FUNC_ADC0);
    DrvGPIO_InitFunction(E_FUNC_ADC1);
    DrvGPIO_InitFunction(E_FUNC_ADC2);
    DrvGPIO_InitFunction(E_FUNC_ADC3);
    DrvGPIO_InitFunction(E_FUNC_ADC4);
    DrvGPIO_InitFunction(E_FUNC_ADC5);
    DrvGPIO_InitFunction(E_FUNC_ADC6);
    DrvGPIO_InitFunction(E_FUNC_ADC7);
    //
    // Config clock, input mode, operate mode and convert channel for ADC
    //
    DrvADC_Open(ADC_SINGLE_END,ADC_SINGLE_OP,0x01|0x02|0x04|0x08|0x10|0x20|0x40|0x80,EXTERNAL_12MHZ,0);
    //
    // Select source for ADC channel 7
    //
    DrvADC_ConfigADCChannel7(EXTERNAL_INPUT_SIGNAL);
    //
    // Enable ADC convert end interrupt and install callback function
    //
    DrvADC_EnableADCInt(ADC_Callbackfn,0);
}

/* ADC Convert End CallBack function */
void ADC_Callbackfn(uint32_t u32UserData)
{
    //add your code
}

void Init()
{
    GPIOB_Init();
    GPIOD_Init();
    GPIOC_Init();
    SPI3_Init();
    ADC_Init();
}
