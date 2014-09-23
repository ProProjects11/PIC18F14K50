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
 * Company:         http://proprojects.wordpress.com
 * Processor:       PIC18
 * Compiler:        XC8 v1.32
 * File Name:       pic18f14k50_int.h
 * Description:     Interrupts defines
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      04/08/13    Initial version
 * 1.1      07/15/14    Updated to XC8
 *********************************************************************/

#ifndef __PIC18F14K50_INT_H
#define __PIC18F14K50_INT_H

/** INCLUDES *******************************************************/
#include <xc.h>

/** INTERFACE CONFIGURATION ****************************************/
#define INTPDisable()	RCONbits.IPEN = 0	// Compatibility Mode (Default)
#define INTPEnable()	RCONbits.IPEN = 1	// Priority Mode

#define GIEnable()	INTCONbits.GIE = 1	// General Int Enable
#define GIDisable()	INTCONbits.GIE = 0	// General Int Disable
#define GIEHEnable()	GIEnable()
#define GIEHDisable()	GIDisable()

#define PEIEnable()	INTCONbits.PEIE = 1	// Peripherial Int Enable
#define PEIDisable()	INTCONbits.PEIE = 0	// Peripherial Int Disable
#define GIELEnable()	PEIEnable()
#define GIELDisable()	PEIDisable()

//
/** INT0 DEFINES ***************************************************/
#define INT0Enable()	INTCONbits.INT0IE = 1	// Enable INT
#define INT0Disable()	INTCONbits.INT0IE = 0	// Disable INT

//#define INT0HPSet()	// Always High Priority
//#define INT0LPSet()	// N/A

#define INT0REdg()	INTCON2bits.INTEDG0 = 1 // Rising Edge
#define INT0FEdg()	INTCON2bits.INTEDG0 = 0 // Falling Edge

#define INT0Flag	INTCONbits.INT0IF	// Interrupt Flag
#define INT0FlagClear()	INT0Flag = 0;		// Clear IF

/** INT1 DEFINES ***************************************************/
#define INT1Enable()	INTCON3bits.INT1IE = 1	// Enable INT
#define INT1Disable()	INTCON3bits.INT1IE = 0	// Disable INT

#define INT1HPriority()	INTCON3bits.INT1IP = 1 	// High Priority
#define INT1LPriority()	INTCON3bits.INT1IP = 0	// Low Priority

#define INT1REdg()	INTCON2bits.INTEDG1 = 1	// Rising Edge
#define INT1FEdg()	INTCON2bits.INTEDG1 = 0	// Falling Edge

#define INT1Flag	INTCON3bits.INT1IF	// Interrupt Flag
#define INT1FlagClear()	INT1Flag = 0;		// Clear IF

/** INT2 DEFINES ***************************************************/
#define INT2Enable()	INTCON3bits.INT2IE = 1	// Enable INT
#define INT2Disable()	INTCON3bits.INT2IE = 0	// Disable INT

#define INT2HPriority()	INTCON3bits.INT2IP = 1 	// High Priority
#define INT2LPriority()	INTCON3bits.INT2IP = 0	// Low Priority

#define INT2REdg()      INTCON2bits.INTEDG2 = 1 // Rising Edge
#define INT2FEdg()      INTCON2bits.INTEDG2 = 0 // Falling Edge

#define INT2Flag        INTCON3bits.INT2IF	// Interrupt Flag
#define INT2FlagClear()	INT2Flag = 0;		// Clear IF

/** OSC Fail DEFINES ***********************************************/
#define OSCFEnable()	PIE2bits.OSCFIE = 1	// Enable INT
#define OSCFDisable()	PIE2bits.OSCFIE = 0	// Disable INT

#define OSCFHPriority()	IPR2bits.OSCFIP = 1     // High Priority
#define OSCFLPriority()	IPR2bits.OSCFIP = 0	// Low Priority

#define OSCFFlag        PIR2bits.OSCFIF         // Interrupt Flag
#define OSCFFlagClear()	OSCFFlag = 0;		// Clear IF

/** BUS Collision DEFINES ******************************************/
#define BUSCEnable()	PIE2bits.BCLIE = 1	// Enable INT
#define BUSCDisable()	PIE2bits.BCLIE = 0	// Disable INT

#define BUSCHPriority()	IPR2bits.BCLIP = 1	// High Priority
#define BUSCLPriority()	IPR2bits.BCLIP = 0	// Low Priority

#define BUSCFlag        PIR2bits.BCLIF          // Interrupt Flag
#define BUSCFlagClear()	OSCFFlag = 0		// Clear IF

#endif // __PIC18F14K50_INT_H
