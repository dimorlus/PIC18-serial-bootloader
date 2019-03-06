/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F24K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set A0 aliases
#define A0_TRIS                 TRISAbits.TRISA0
#define A0_LAT                  LATAbits.LATA0
#define A0_PORT                 PORTAbits.RA0
#define A0_WPU                  WPUAbits.WPUA0
#define A0_OD                   ODCONAbits.ODCA0
#define A0_ANS                  ANSELAbits.ANSELA0
#define A0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define A0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define A0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define A0_GetValue()           PORTAbits.RA0
#define A0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define A0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define A0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define A0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define A0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define A0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define A0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define A0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set A1 aliases
#define A1_TRIS                 TRISAbits.TRISA1
#define A1_LAT                  LATAbits.LATA1
#define A1_PORT                 PORTAbits.RA1
#define A1_WPU                  WPUAbits.WPUA1
#define A1_OD                   ODCONAbits.ODCA1
#define A1_ANS                  ANSELAbits.ANSELA1
#define A1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define A1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define A1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define A1_GetValue()           PORTAbits.RA1
#define A1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define A1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define A1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define A1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define A1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define A1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define A1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define A1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set A2 aliases
#define A2_TRIS                 TRISAbits.TRISA2
#define A2_LAT                  LATAbits.LATA2
#define A2_PORT                 PORTAbits.RA2
#define A2_WPU                  WPUAbits.WPUA2
#define A2_OD                   ODCONAbits.ODCA2
#define A2_ANS                  ANSELAbits.ANSELA2
#define A2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define A2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define A2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define A2_GetValue()           PORTAbits.RA2
#define A2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define A2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define A2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define A2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define A2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define A2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define A2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define A2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set A3 aliases
#define A3_TRIS                 TRISAbits.TRISA3
#define A3_LAT                  LATAbits.LATA3
#define A3_PORT                 PORTAbits.RA3
#define A3_WPU                  WPUAbits.WPUA3
#define A3_OD                   ODCONAbits.ODCA3
#define A3_ANS                  ANSELAbits.ANSELA3
#define A3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define A3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define A3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define A3_GetValue()           PORTAbits.RA3
#define A3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define A3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define A3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define A3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define A3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define A3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define A3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define A3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set Boot aliases
#define Boot_TRIS                 TRISAbits.TRISA5
#define Boot_LAT                  LATAbits.LATA5
#define Boot_PORT                 PORTAbits.RA5
#define Boot_WPU                  WPUAbits.WPUA5
#define Boot_OD                   ODCONAbits.ODCA5
#define Boot_ANS                  ANSELAbits.ANSELA5
#define Boot_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define Boot_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define Boot_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define Boot_GetValue()           PORTAbits.RA5
#define Boot_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define Boot_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define Boot_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define Boot_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define Boot_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define Boot_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define Boot_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define Boot_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set EN1 aliases
#define EN1_TRIS                 TRISAbits.TRISA6
#define EN1_LAT                  LATAbits.LATA6
#define EN1_PORT                 PORTAbits.RA6
#define EN1_WPU                  WPUAbits.WPUA6
#define EN1_OD                   ODCONAbits.ODCA6
#define EN1_ANS                  ANSELAbits.ANSELA6
#define EN1_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define EN1_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define EN1_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define EN1_GetValue()           PORTAbits.RA6
#define EN1_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define EN1_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define EN1_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define EN1_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define EN1_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define EN1_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define EN1_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define EN1_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set EN2 aliases
#define EN2_TRIS                 TRISAbits.TRISA7
#define EN2_LAT                  LATAbits.LATA7
#define EN2_PORT                 PORTAbits.RA7
#define EN2_WPU                  WPUAbits.WPUA7
#define EN2_OD                   ODCONAbits.ODCA7
#define EN2_ANS                  ANSELAbits.ANSELA7
#define EN2_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define EN2_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define EN2_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define EN2_GetValue()           PORTAbits.RA7
#define EN2_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define EN2_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define EN2_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define EN2_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define EN2_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define EN2_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define EN2_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define EN2_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set IO_RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.ODCB0
#define IO_RB0_ANS                  ANSELBbits.ANSELB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set IO_RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_WPU                  WPUBbits.WPUB1
#define IO_RB1_OD                   ODCONBbits.ODCB1
#define IO_RB1_ANS                  ANSELBbits.ANSELB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_RB1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_RB1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_RB1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_RB1_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set IO_RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSELB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set IO_RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_WPU                  WPUBbits.WPUB3
#define IO_RB3_OD                   ODCONBbits.ODCB3
#define IO_RB3_ANS                  ANSELBbits.ANSELB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define IO_RB3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define IO_RB3_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set IO_RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set LRed aliases
#define LRed_TRIS                 TRISBbits.TRISB6
#define LRed_LAT                  LATBbits.LATB6
#define LRed_PORT                 PORTBbits.RB6
#define LRed_WPU                  WPUBbits.WPUB6
#define LRed_OD                   ODCONBbits.ODCB6
#define LRed_ANS                  ANSELBbits.ANSELB6
#define LRed_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define LRed_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define LRed_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define LRed_GetValue()           PORTBbits.RB6
#define LRed_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define LRed_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define LRed_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define LRed_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define LRed_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define LRed_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define LRed_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define LRed_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set Relay aliases
#define Relay_TRIS                 TRISCbits.TRISC0
#define Relay_LAT                  LATCbits.LATC0
#define Relay_PORT                 PORTCbits.RC0
#define Relay_WPU                  WPUCbits.WPUC0
#define Relay_OD                   ODCONCbits.ODCC0
#define Relay_ANS                  ANSELCbits.ANSELC0
#define Relay_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Relay_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Relay_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Relay_GetValue()           PORTCbits.RC0
#define Relay_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Relay_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define Relay_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define Relay_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define Relay_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define Relay_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define Relay_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define Relay_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC3
#define SCL1_LAT                  LATCbits.LATC3
#define SCL1_PORT                 PORTCbits.RC3
#define SCL1_WPU                  WPUCbits.WPUC3
#define SCL1_OD                   ODCONCbits.ODCC3
#define SCL1_ANS                  ANSELCbits.ANSELC3
#define SCL1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL1_GetValue()           PORTCbits.RC3
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC4
#define SDA1_LAT                  LATCbits.LATC4
#define SDA1_PORT                 PORTCbits.RC4
#define SDA1_WPU                  WPUCbits.WPUC4
#define SDA1_OD                   ODCONCbits.ODCC4
#define SDA1_ANS                  ANSELCbits.ANSELC4
#define SDA1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA1_GetValue()           PORTCbits.RC4
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSELC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/