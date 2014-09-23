/*
 *	Copyright (c) 2011-2014, http://www.proprojects.wordpress.com
 *	All rights reserved.
 *
 * 	Redistribution and use in source and binary forms, with or without modification, 
 *	are permitted provided that the following conditions are met:
 *
 *	1.- Redistributions of source code must retain the above copyright notice,
 *		this list of conditions and the following disclaimer.
 *	2.- Redistributions in binary form must reproduce the above copyright notice, 
 *		this list of conditions and the following disclaimer in the documentation 
 *		and/or other materials provided with the distribution.
 *
 *	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 *	EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 *	OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 *	IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 *	INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
 *	OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 *	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 *	WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*********************************************************************
 * By:              Omar Gurrola
 * Site:            http://www.proprojects.wordpress.com
 * Processor:       PIC18
 * Compiler:        XC8 v1.32
 * File Name:       pic18f14k50_io.h
 * Description:     Defines to use IO for PIC18F14K50
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      01/31/13    Initial version (PORTA Only)
 * 1.1      02/07/13	Re-organize and added PORTB & PORC
 * 1.2      02/19/13	Minor fixes in PORB and PORTC sections
 * 1.3      04/08/13	Add Interrupt defines for PORTA and PORTB IOC
 * 1.4      07/15/14    Updated to XC8
 *********************************************************************/

#ifndef __PIC18F14K50_IO_H
#define __PIC18F14K50_IO_H

/** INCLUDES *******************************************************/
#include <xc.h>

/** INTERFACE CONFIGURATION ****************************************/
#define PIN	1       // Pin input
#define INPUT	0xFF	// Port input
#define POUT	0	// Pin out
#define OUTPUT	0x00	// Port output

/** INTERRUPT CONTROL DEFINES *************************************/
#define INTPABEnable()      INTCONbits.RABIE = 1    // Enable IOC on PA & PB
#define INTPABDisable()     INTCONbits.RABIE = 0    // Disable IOC on PA & PB

#define INTPABHPriority()   INTCON2bits.RABIP = 1   // High Priority
#define INTPABLPriority()   INTCON2bits.RABIP = 0   // Low Priority

#define INTPABFlag          INTCONbits.RABIF        // Interrupt Flag
#define INTPABFlagClear()   INTPABFlag = 0          // Clear IF

#define PABWPUEnable()      INTCON2bits.RABPU = 0   // Enable Pull-Up on PORTA & PORTB
#define PABWPUDisable()     INTCON2bits.RABPU = 1   // Disable Pull-Up on PORTA & PORTB

/** PORTA DEFINES *************************************************/
// GENERICS --------------------------------------------------------
// Disable Analog function on RA4, Clear PA, All PA as B
#define OpenPA(B)           ANSELbits.ANS3 = 0; LATA = 0x00; TRISA = B
// Disable Analog function on RA4, Clear RAX, RAX as b
#define OpenRA4(b)          ANSELbits.ANS3 = 0; LATAbits.LATA4 = 0; TRISAbits.TRISA4 = b
// Clear RAX, RAX as b
#define OpenRA5(b)          LATAbits.LATA5 = 0; TRISAbits.TRISA5 = b

// INPUTS ----------------------------------------------------------
// IOCAX must be enable to make a RAX pin input work
#define OpenInPA()	OpenPA(INPUT); IOCAEnable()
#define OpenInRA0()	IOCA0Enable()
#define OpenInRA1()	IOCA1Enable()
#define OpenInRA3()	IOCA3Enable()
#define OpenInRA4()	OpenRA4(PIN); IOCA4Enable()
#define OpenInRA5()	OpenRA5(PIN); IOCA5Enable()

// OUTPUTS ---------------------------------------------------------
#define OpenOutPA()	OpenPA(OUTPUT)
#define OpenOutRA4()	OpenRA4(POUT)
#define OpenOutRA5()	OpenRA5(POUT)

// READ ------------------------------------------------------------
#define ReadPA()	PORTA
#define ReadRA0()	PORTAbits.RA0
#define ReadRA1()	PORTAbits.RA1
#define ReadRA3()	PORTAbits.RA3
#define ReadRA4()	PORTAbits.RA4
#define ReadRA5()	PORTAbits.RA5

// WRITE -----------------------------------------------------------
#define WritePA(B)	LATA = B
#define WriteRA4(b)	LATAbits.LATA4 = b
#define WriteRA5(b)	LATAbits.LATA5 = b

// WEAK PULL UP ----------------------------------------------------
#define WPUAEnable()	WPUA = 0xFF
#define WPUA3Enable()	WPUAbits.WPUA3 = 1
#define WPUA4Enable()	WPUAbits.WPUA4 = 1
#define WPUA5Enable()	WPUAbits.WPUA5 = 1

#define WPUADisable()	WPUA = 0x00
#define WPUA3Disable()	WPUAbits.WPUA3 = 0
#define WPUA4Disable()	WPUAbits.WPUA4 = 0
#define WPUA5Disable()	WPUAbits.WPUA5 = 0

// INTERRUPT ON CHANGE ---------------------------------------------
#define IOCAEnable()	IOCA = 0xFF
#define IOCA0Enable()	IOCAbits.IOCA0 = 1
#define IOCA1Enable()	IOCAbits.IOCA1 = 1
#define IOCA3Enable()	IOCAbits.IOCA3 = 1
#define IOCA4Enable()	IOCAbits.IOCA4 = 1
#define IOCA5Enable()	IOCAbits.IOCA5 = 1

#define IOCADisable()	IOCA = 0x00
#define IOCA0Disable()	IOCAbits.IOCA0 = 0
#define IOCA1Disable()	IOCAbits.IOCA1 = 0
#define IOCA3Disable()	IOCAbits.IOCA3 = 0
#define IOCA4Disable()	IOCAbits.IOCA4 = 0
#define IOCA5Disable()	IOCAbits.IOCA5 = 0

/** PORTB DEFINES *************************************************/
// GENERICS --------------------------------------------------------
// Disable Analog function on RB4-ANS10 & RB5-ANS-11, Clear PX, All PX as B
#define OpenPB(B)	ANSELHbits.ANS11 = 0; ANSELHbits.ANS10 = 0; LATB = 0x00; TRISB = B
// Diable analog function on RB4-ANS10, Clear PX, PX as b
#define OpenRB4(b)	ANSELHbits.ANS10 = 0; LATBbits.LATB4 = 0; TRISBbits.TRISB4 = b
// Diable analog function on RB5-ANS11, Clear PX, PX as b
#define OpenRB5(b)	ANSELHbits.ANS11 = 0; LATBbits.LATB5 = 0; TRISBbits.TRISB5 = b
// Clear PX, PX as b
#define OpenRB6(b)	LATBbits.LATB6 = 0; TRISBbits.TRISB6 = b
// Clear PX, PX as b
#define OpenRB7(b)	LATBbits.LATB7 = 0; TRISBbits.TRISB7 = b

// INPUTS ----------------------------------------------------------
#define OpenInPB()	OpenPB(INPUT)
#define OpenInRB4()	OpenRB4(PIN)
#define OpenInRB5()	OpenRB5(PIN)
#define OpenInRB6()	OpenRB6(PIN)
#define OpenInRB7()	OpenRB7(PIN)

// OUTPUTS ---------------------------------------------------------
#define OpenOutPB()	OpenPB(OUTPUT)
#define OpenOutRB4()	OpenRB4(POUT)
#define OpenOutRB5()	OpenRB5(POUT)
#define OpenOutRB6()	OpenRB6(POUT)
#define OpenOutRB7()	OpenRB7(POUT)

// READ ------------------------------------------------------------
#define ReadPB()	PORTB
#define ReadRB4()	PORTBbits.RB4
#define ReadRB5()	PORTBbits.RB5
#define ReadRB6()	PORTBbits.RB6
#define ReadRB7()	PORTBbits.RB7

// WRITE -----------------------------------------------------------
#define WritePB(B)	LATB = B
#define WriteRB4(b)	LATBbits.LATB4 = b
#define WriteRB5(b)	LATBbits.LATB5 = b
#define WriteRB6(b)	LATBbits.LATB6 = b
#define WriteRB7(b)	LATBbits.LATB7 = b

// WEAK PULL UP ----------------------------------------------------
#define WPUBEnable()	WPUB = 0xFF
#define WPUB4Enable()	WPUBbits.WPUB4 = 1
#define WPUB5Enable()	WPUBbits.WPUB5 = 1
#define WPUB6Enable()	WPUBbits.WPUB6 = 1
#define WPUB7Enable()	WPUBbits.WPUB7 = 1

#define WPUBDisable()	WPUB = 0x00
#define WPUB4Disable()	WPUBbits.WPUB4 = 0
#define WPUB5Disable()	WPUBbits.WPUB5 = 0
#define WPUB6Disable()	WPUBbits.WPUB6 = 0
#define WPUB7Disable()	WPUBbits.WPUB7 = 0

// INTERRUPT ON CHANGE ---------------------------------------------
#define IOCBEnable()	IOCB = 0xFF
#define IOCB4Enable()	IOCBbits.IOCB4 = 1
#define IOCB5Enable()	IOCBbits.IOCB5 = 1
#define IOCB6Enable()	IOCBbits.IOCB6 = 1
#define IOCB7Enable()	IOCBbits.IOCB7 = 1

#define IOCBDisable()	IOCB = 0x00
#define IOCB4Disable()	IOCBbits.IOCB4 = 0
#define IOCB5Disable()	IOCBbits.IOCB5 = 0
#define IOCB6Disable()	IOCBbits.IOCB6 = 0
#define IOCB7Disable()	IOCBbits.IOCB7 = 0

/** PORTC DEFINES *************************************************/
// GENERICS --------------------------------------------------------
// Disable Analog function on RC0-ANS4, RC1-ANS5, RC2-ANS6, RC3-ANS7, RC6-ANS8, RC7-ANS9, Clear PX, All PX as B
#define OpenPC(B)	ANSEL &= 0x0F; ANSELH &=0xF8; LATC = 0x00; TRISC = B
// Diable analog function on RC0-ANS4, Clear PX, PX as b
#define OpenRC0(b)	ANSELbits.ANS4 = 0; LATCbits.LATC0 = 0; TRISCbits.TRISC0 = b
// Diable analog function on RC1-ANS5, Clear PX, PX as b
#define OpenRC1(b)	ANSELbits.ANS5 = 0; LATCbits.LATC1 = 0; TRISCbits.TRISC1 = b
// Diable analog function on RC2-ANS6, Clear PX, PX as b
#define OpenRC2(b)	ANSELbits.ANS6 = 0; LATCbits.LATC2 = 0; TRISCbits.TRISC2 = b
// Diable analog function on RC3-ANS7, Clear PX, PX as b
#define OpenRC3(b)	ANSELbits.ANS7 = 0; LATCbits.LATC3 = 0; TRISCbits.TRISC3 = b
// Clear PX, PX as b
#define OpenRC4(b)	LATCbits.LATC4 = 0; TRISCbits.TRISC4 = b
// Clear PX, PX as b
#define OpenRC5(b)	LATCbits.LATC5 = 0; TRISCbits.TRISC5 = b
// Diable analog function on RC6-ANS8, Clear PX, PX as b
#define OpenRC6(b)	ANSELHbits.ANS8 = 0; LATCbits.LATC6 = 0; TRISCbits.TRISC6 = b
// Diable analog function on RC7-ANS9, Clear PX, PX as b
#define OpenRC7(b)	ANSELHbits.ANS9 = 0; LATCbits.LATC7 = 0; TRISCbits.TRISC7 = b

// INPUTS ----------------------------------------------------------
#define OpenInPC()	OpenPC(INPUT)
#define OpenInRC0()	OpenRC0(PIN)
#define OpenInRC1()	OpenRC1(PIN)
#define OpenInRC2()	OpenRC2(PIN)
#define OpenInRC3()	OpenRC3(PIN)
#define OpenInRC4()	OpenRC4(PIN)
#define OpenInRC5()	OpenRC5(PIN)
#define OpenInRC6()	OpenRC6(PIN)
#define OpenInRC7()	OpenRC7(PIN)

// OUTPUTS ---------------------------------------------------------
#define OpenOutPC()	OpenPC(OUTPUT)
#define OpenOutRC0()	OpenRC0(POUT)
#define OpenOutRC1()	OpenRC1(POUT)
#define OpenOutRC2()	OpenRC2(POUT)
#define OpenOutRC3()	OpenRC3(POUT)
#define OpenOutRC4()	OpenRC4(POUT)
#define OpenOutRC5()	OpenRC5(POUT)
#define OpenOutRC6()	OpenRC6(POUT)
#define OpenOutRC7()	OpenRC7(POUT)

// READ ------------------------------------------------------------
#define ReadPC()	PORTC
#define ReadRC0()	PORTCbits.RC0
#define ReadRC1()	PORTCbits.RC1
#define ReadRC2()	PORTCbits.RC2
#define ReadRC3()	PORTCbits.RC3
#define ReadRC4()	PORTCbits.RC4
#define ReadRC5()	PORTCbits.RC5
#define ReadRC6()	PORTCbits.RC6
#define ReadRC7()	PORTCbits.RC7

// WRITE -----------------------------------------------------------
#define WritePC(B)	LATC = B
#define WriteRC0(b)	LATCbits.LATC0 = b
#define WriteRC1(b)	LATCbits.LATC1 = b
#define WriteRC2(b)	LATCbits.LATC2 = b
#define WriteRC3(b)	LATCbits.LATC3 = b
#define WriteRC4(b)	LATCbits.LATC4 = b
#define WriteRC5(b)	LATCbits.LATC5 = b
#define WriteRC6(b)	LATCbits.LATC6 = b
#define WriteRC7(b)	LATCbits.LATC7 = b

// WEAK PULL UP ----------------------------------------------------
// NA

// INTERRUPT ON CHANGE ---------------------------------------------
// NA	

#endif // __PIC18F14K50_IO_H
