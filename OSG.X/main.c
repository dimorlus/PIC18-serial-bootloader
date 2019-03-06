/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F24K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
// <editor-fold defaultstate="collapsed" desc="Pins usage">
/* 
 *                         PIC18F24K40 QFN
 *                   +------------------------+
 *              Rx >-|15 RC7/Rx      Tx/RC6 14|-> Tx
 *             GND *-|16 GND        SDO/RC5 13|-> X
 *             3V3 *-|17 Vcc        SDI/RC4 12|-> SDA
 *               X <-|18 RB0/AN12   SCK/RC3 11|-> SCL
 *               X <-|19 RB1/AN10  CCP1/RC2 10|-> PWM1         
 *               X <-|20 RB2/ANB2  CCP2/RC1  9|-> PWM2     
 *               X <-|21 RB3/ANB3       RC0  8|-> Relay
 *                   +------------------------+
 *               X <-|22 RB4/ANB4  ANA6/RA6  7|-> EN1
 *               X <-|23 RB5/ANB5  ANA7/RA7  6|-> EN2
 *        LRed/PGC <-|24 RB6/ANB6      GND   5|-* GND
 *        LGrn/PGD <-|25 RB7/ANB7  ANA5/RA5  4|-> X
 *             Rst *-|26 MCLR      ANA4/RA4  3|-> X  
 *              A0 >-|27 RA0/ANA0  ANA3/RA3  2|-< A3
 *              A1 >-|28 RA1/ANA1  ANA2/RA2  1|-< A2
 *                   +-----------------------^*
 */

#include "mcc_generated_files/mcc.h"
#include "types.h"

/*
                         Main application
 */

//__eeprom u8 inputData[10] = "eeprom";
__EEPROM_DATA(0, 1, 2, 3, 4, 5, 6, 7);
u8 _1ms;
u8 _100ms;

void Tmr0intr(void)
{
 _1ms++;
 if (_1ms >= 100)
 {
  _100ms++;
  _1ms = 0;
  LATBbits.LATB5 ^= 1;
 }
}


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    TMR0_SetInterruptHandler(Tmr0intr);

    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
       //LATBbits.LATB5 ^= 1;
       LATBbits.LATB4 ^= 1;
       LATBbits.LATB6 ^= 1;
       ClrWdt();
    }
}
/**
 End of File
*/