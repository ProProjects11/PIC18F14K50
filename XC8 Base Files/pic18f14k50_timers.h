/*
 *	Copyright (c) 2011-2014, http://www.proprojects.wordpress.com
 *	All rights reserved.
 *
 * 	Redistribution and use in source and binary forms, with or without modification, 
 *	are permitted provided that the following conditions are met:
 *
 *	1.- Redistributions of source code must retain the above copyright notice,
 *          this list of conditions and the following disclaimer.
 *	2.- Redistributions in binary form must reproduce the above copyright notice, 
 *          this list of conditions and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution.
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
 * File Name:       pic18f14k50_timers.h
 * Description:     Defines to use Timers for PIC18F14K50
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      05/21/13	Initial Version
 * 1.1      10/31/13    Add *.c file for this module and more comments
 * 1.2      07/15/14    Updated to XC8
 *********************************************************************/

#ifndef __PIC18F14K50_TIMERS_H
#define __PIC18F14K50_TIMERS_H

/** INCLUDES *******************************************************/
#include <xc.h>
#include <stdint.h>

/** TIMER0 DEFINES *************************************************/
#define OpenTmrT0()	T0CONbits.T0CS = 0
#define OpenCtrT0()	LATCbits.LATC5 = 0; TRISCbits.TRISC5 = 1; T0CONbits.T0CS = 1

#define Set8BitsT0()	T0CONbits.T08BIT = 1
#define Set16BitsT0()	T0CONbits.T08BIT = 0

#define SetHTLCtrT0()	T0CONbits.T0SE = 1
#define SetLTHCtrT0()	T0CONbits.T0SE = 0

#define UsePSAT0()	T0CONbits.PSA = 0
#define NoUsePSAT0()	T0CONbits.PSA = 1
// 0=1:2, 1=1:4, 2=1:8, 3=1:16, 4=1:32, 5=1:64, 6=1:128, 7=1:256
#define SetPST0(p)	T0CONbits.T0PS = p

#define StartT0()	T0CONbits.TMR0ON = 1
#define StopT0()	T0CONbits.TMR0ON = 0

#define T08bReg		TMR0L
#define Read8bT0()	TMR0L
#define Write8bT0(v)	TMR0L = v

/**
 * Read T0 16b
 * @return Read value
 */
uint16_t Read16bT0(void);

/**
 * Write to T0 16b
 * @param v 16b value to write
 */
void Write16bT0(uint16_t v);

//-- TIMER0 INTERRUPTS -----------------------------------------------
#define INTT0Enable()       INTCONbits.TMR0IE = 1
#define INTT0Disable()      INTCONbits.TMR0IE = 0

#define INTPT0HPriority()   INTCON2bits.TMR0IP = 1
#define INTPT0LPriority()   INTCON2bits.TMR0IP = 0

#define INTT0Flag           INTCONbits.TMR0IF
#define INTT0FlagClear()    INTT0Flag = 0

/** TIMER1 DEFINES *************************************************/
#define OpenTmrT1()         T1CONbits.TMR1CS = 0
// Rising Edge only, it counts after first falling edge
#define OpenCtrT1()         ANSELHbits.ANS8 = 0; LATCbits.LATC6 = 0; TRISCbits.TRISC6 = 1; T1CONbits.TMR1CS = 1
// Disable ADC first
#define OpenRTCT1()         ANSELHbits.ANS8 = 0; ANSELHbits.ANS9 = 0; T1CON = 0b1001110

#define CtrSyncT1()         T1CONbits.T1SYNC = 0 // Default (Like Counter0)
#define CtrASyncT1()        T1CONbits.T1SYNC = 1

#define MSCFromT1OSC()      T1CONbits.T1RUN = 1	// Main system clock comes from Timer1
#define MSCFromOS()         T1CONbits.T1RUN = 0	// Main system clock comes from another source (default)

#define UseRWOneOPT1()      T1CONbits.RD16 = 1	// Read/Write in one 16-bit operation (Like Timer0 in 16b mode).
#define UseRWTwoOPT1()      T1CONbits.RD16 = 0	// Read/Write in two 8-bit operation.
// 0=1:1, 1=1:2, 2=1:4, 3=1:8
#define SetPST1(p)          T1CONbits.T1CKPS = p
#define NoUsePSAT1()        T1CONbits.T1CKPS = 0 // Default

#define T1OscOn()           T1CONbits.T1OSCEN = 1 // If you will use external oscillator
#define T1OscOff()          T1CONbits.T1OSCEN = 0 // Default

#define StartT1()           T1CONbits.TMR1ON = 1
#define StopT1()            T1CONbits.TMR1ON = 0

/**
 * Read T1 16b
 * @return Read value
 */
uint16_t ReadT1(void);

/**
 * Write 16b value to T1
 * @param v 16b value to write
 */
void WriteT1(uint16_t v);

//-- TIMER1 INTERRUPTS -----------------------------------------------
#define INTT1Enable()		PIE1bits.TMR1IE = 1
#define INTT1Disable()		PIE1bits.TMR1IE = 0

#define INTPT1HPriority()       IPR1bits.TMR1IP = 1
#define INTPT1LPriority()       IPR1bits.TMR1IP = 0

#define INTT1Flag		PIR1bits.TMR1IF
#define INTT1FlagClear()        INTT1Flag = 0

/** TIMER2 DEFINES *************************************************/
#define OpenTmrT2()		// Nothing to do, because it's just timer XD
// 0=1:1, 1=1:4, 2=1:16, 3=1:16
#define SetPST2(p)		T2CONbits.T2CKPS = p
// 0=1:1, 1=1:2, 2=1:4, ..., 15=1:16
#define SetOUTPST2(op)		T2CONbits.T2OUTPS = op

#define StartT2()		T2CONbits.TMR2ON = 1
#define StopT2()		T2CONbits.TMR2ON = 0

#define T2Reg			TMR2
#define ReadT2()		TMR2
#define WriteT2(v)		TMR2 = v
#define PR2Reg			PR2
#define ReadPR2()		PR2
#define WritePR2(v)		PR2 = v

//-- TIMER2 INTERRUPTS -----------------------------------------------
#define INTT2Enable()		PIE1bits.TMR2IE = 1
#define INTT2Disable()		PIE1bits.TMR2IE = 0

#define INTPT2HPriority()       IPR1bits.TMR2IP = 1
#define INTPT2LPriority()       IPR1bits.TMR2IP = 0

#define INTT2Flag		PIR1bits.TMR2IF
#define INTT2FlagClear()        INTT2Flag = 0

/** TIMER3 DEFINES *************************************************/
#define OpenTmrT3()		T3CONbits.TMR3CS = 0
// Rising Edge only, it counts after first falling edge
#define OpenCtrT3()		ANSELHbits.ANS8 = 0; LATCbits.LATC6 = 0; TRISCbits.TRISC6 = 1; T3CONbits.TMR3CS = 1
// Disable ADC first
#define OpenRTCT3()		ANSELHbits.ANS8 = 0; ANSELHbits.ANS9 = 0; T1OscOn(); T3CON = 0b1000110

#define CtrSyncT3()		T3CONbits.T3SYNC = 0 // Default (Like Counter0)
#define CtrASyncT3()		T3CONbits.T3SYNC = 1

#define UseRWOneOPT3()		T3CONbits.RD16 = 1 // Read/Write in one 16-bit operation (Like Timer0 in 16b mode).
#define UseRWTwoOPT3()		T3CONbits.RD16 = 0 // Read/Write in two 8-bit operation.
// 0=1:1, 1=1:2, 2=1:4, 3=1:8
#define SetPST3(p)		T3CONbits.T3CKPS = p
#define NoUsePSAT3()		T3CONbits.T3CKPS = 0 // Default

#define StartT3()		T3CONbits.TMR3ON = 1
#define StopT3()		T3CONbits.TMR3ON = 0

/**
 * Read T3 value
 * @return 16b value
 */
uint16_t ReadT3(void);

/**
 * Write 16b value to T3
 * @param v value to write
 */
void WriteT3(uint16_t v);

//-- TIMER3 INTERRUPTS -----------------------------------------------
#define INTT3Enable()		PIE2bits.TMR3IE = 1
#define INTT3Disable()		PIE2bits.TMR3IE = 0

#define INTPT3HPriority()       IPR2bits.TMR3IP = 1
#define INTPT3LPriority()       IPR2bits.TMR3IP = 0

#define INTT3Flag		PIR2bits.TMR3IF
#define INTT3FlagClear()        INTT3Flag = 0

#endif // __PIC18F14K50_TIMERS_H
