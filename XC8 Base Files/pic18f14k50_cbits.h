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
 * File Name:       pic18f14k50_cbits.h
 * Description:     Configuration Bits for PIC18F14K50
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      07/15/14    Initial version
 *********************************************************************/

#ifndef __PIC18F14K50_CBITS_H
#define __PIC18F14K50_CBITS_H

/** CONFIGURATION BITS *********************************************/
#pragma config CPUDIV=NOCLKDIV
// CPU System Clock Selection bit:
// NOCLKDIV	No CPU System Clock divide  
// CLKDIV2	CPU System Clock divided by 2  
// CLKDIV3	CPU System Clock divided by 3  
// CLKDIV4	CPU System Clock divided by 4  
#pragma config USBDIV=OFF
// USB Clock Selection bit:
// OFF 		USB Clock comes directly from the OSC1/OSC2 oscillator block; no divide  
// ON		USB clock comes from the OSC1/OSC2 divided by 2  
#pragma config FOSC=IRC
// Oscillator Selection bits:
// LP		LP oscillator
// XT		XT oscillator  
// HS		HS oscillator  
// ERCCLKOUT	External RC oscillator, CLKOUT function on OSC2  
// ECCLKOUTH	EC, CLKOUT function on OSC2 (high)  
// ECH		EC (high)  
// ERC		External RC oscillator  
// IRC		Internal RC oscillator  
// IRCCLKOUT	Internal RC oscillator, CLKOUT function on OSC2  
// ECCLKOUTM	EC, CLKOUT function on OSC2 (medium)  
// ECM		EC (medium)  
// ECCLKOUTL	EC, CLKOUT function on OSC2 (low)  
// ECL		EC (low)  
#pragma config PLLEN=OFF
// 4 X PLL Enable bit:
// OFF		PLL is under software control  
// ON		Oscillator multiplied by 4  
#pragma config PCLKEN=OFF
// Primary Clock Enable Bit:
// OFF		Primary clock is under software control  
// ON		Primary clock enabled
#pragma config FCMEN=OFF
// Fail-Safe Clock Monitor Enable bit:
// OFF		Fail-Safe Clock Monitor disabled  
// ON		Fail-Safe Clock Monitor enabled  
#pragma config IESO=OFF
// Internal/External Oscillator Switchover bit:
// OFF		Oscillator Switchover mode disabled  
// ON		Oscillator Switchover mode enabled
#pragma config PWRTEN=OFF
// Power-up Timer Enable bit:
// ON		PWRT enabled  
// OFF		PWRT disabled  
#pragma config BOREN=ON
// Brown-out Reset Enable bits:
// OFF		Brown-out Reset disabled in hardware and software  
// ON		Brown-out Reset enabled and controlled by software (SBOREN is enabled)  
// NOSLP	Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)  
// SBORDIS	Brown-out Reset enabled in hardware only (SBOREN is disabled)  
#pragma config BORV=30
// Brown Out Voltage:
// 30		VBOR set to 3.0 V nominal  
// 27		VBOR set to 2.7 V nominal  
// 22		VBOR set to 2.2 V nominal  
// 19		VBOR set to 1.9 V nominal  
#pragma config WDTEN=OFF
// Watchdog Timer Enable bit:
// OFF		WDT is controlled by SWDTEN bit of the WDTCON register  
// ON		WDT is always enabled. SWDTEN bit has no effect.  
#pragma config WDTPS = 1
// Watchdog Timer Postscale Select bits:
// 1		1:1  
// 2		1:2  
// 4		1:4  
// 8		1:8  
// 16		1:16  
// 32		1:32  
// 64		1:64  
// 128		1:128  
// 256		1:256  
// 512		1:512  
// 1024		1:1024  
// 2048		1:2048  
// 4096		1:4096  
// 8192		1:8192  
// 16384	1:16384  
// 32768	1:32768  
#pragma config MCLRE=OFF
// MCLR Pin Enable bit:
// OFF		RE3 input pin enabled; MCLR disabled  
// ON		MCLR pin enabled, RE3 input pin disabled  
#pragma config HFOFST=OFF
// HFINTOSC Fast Start-up bit:
// OFF		The system clock is held off until the HFINTOSC is stable.  
// ON		HFINTOSC starts clocking the CPU without waiting for the oscillator to stablize. 
#pragma config STVREN=ON
// Stack Full/Underflow Reset Enable bit:
// OFF 		Stack full/underflow will not cause Reset  
// ON		Stack full/underflow will cause Reset  
#pragma config LVP=OFF
// Single-Supply ICSP Enable bit:
// OFF		Single-Supply ICSP disabled  
// ON		Single-Supply ICSP enabled
#pragma config BBSIZ=OFF
// Boot Block Size Select Bit:
// OFF		1kW boot block size  
// ON		2kW boot block size 
#pragma config XINST=OFF
// Extended Instruction Set Enable bit:
// OFF		Instruction set extension and Indexed Addressing mode disabled (Legacy mode)  
// ON		Instruction set extension and Indexed Addressing mode enabled  
#pragma config CP0=OFF
// Code Protection bit:
// ON		Block 0 code-protected
// OFF		Block 0 not code-protected
#pragma config CP1=OFF
// Code Protection bit:
// ON		Block 1 code-protected  
// OFF		Block 1 not code-protected  
#pragma config CPB=OFF
// Boot Block Code Protection bit:
// ON		Boot block code-protected  
// OFF		Boot block not code-protected  
#pragma config CPD=OFF
// Data EEPROM Code Protection bit:
// ON		Data EEPROM code-protected  
// OFF		Data EEPROM not code-protected
#pragma config WRT0=OFF
// Write Protection bit:
// ON		Block 0 write-protected  
// OFF		Block 0 not write-protected
#pragma config WRT1=OFF
// Write Protection bit:
// ON		Block 1 write-protected  
// OFF		Block 1 not write-protected  
#pragma config WRTB=OFF
// Boot Block Write Protection bit:
// ON		Boot block write-protected  
// OFF		Boot block not write-protected
#pragma config WRTC=OFF
// Configuration Register Write Protection bit:
// ON		Configuration registers write-protected  
// OFF		Configuration registers not write-protected 
#pragma config WRTD=OFF
// Data EEPROM Write Protection bit:
// ON		Data EEPROM write-protected  
// OFF		Data EEPROM not write-protected
#pragma config EBTR0=OFF
// Table Read Protection bit:
// ON		Block 0 protected from table reads executed in other blocks  
// OFF		Block 0 not protected from table reads executed in other blocks
#pragma config EBTR1=OFF
// Table Read Protection bit:
// ON		Block 1 protected from table reads executed in other blocks  
// OFF		Block 1 not protected from table reads executed in other blocks
#pragma config EBTRB=OFF
// Boot Block Table Read Protection bit:
// ON		Boot block protected from table reads executed in other blocks  
// OFF		Boot block not protected from table reads executed in other blocks

#endif
