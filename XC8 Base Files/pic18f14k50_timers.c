/*
 *	Copyright (c) 2011-2014, http://www.proprojects.wordpress.com
 *	All rights reserved.
 *
 * 	Redistribution and use in source and binary forms, with or without modification, 
 *	are permitted provided that the following conditions are met:
 *
 *	1.- Redistributions of source code must retain the above copyright notice,
 *	    this list of conditions and the following disclaimer.
 *	2.- Redistributions in binary form must reproduce the above copyright notice, 
 *	    this list of conditions and the following disclaimer in the documentation
 *	    and/or other materials provided with the distribution.
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
 * File Name:       pic18f14k50_timers.c
 * Description:     
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      10/31/13    Initial version
 * 1.1      07/15/14    Updated to XC8
 *********************************************************************/

/** INCLUDES *******************************************************/
#include "pic18f14k50_timers.h"

/** PRIVATE VARIABLES **********************************************/

/** PRIVATE FUNCTION PROTOTYPES ************************************/

/** PRIVATE FUNCTION DEFINITIONS ***********************************/

/** PUBLIC FUNCTION DEFINITIONS ************************************/
uint16_t Read16bT0(void){
    uint16_t tl;
    tl = TMR0L; // Read TMR0L first then TMR0H
    return tl | (TMR0H * 256);
}

void Write16bT0(uint16_t v){
    TMR0H = v >> 8; // Write first on TMR0H
    TMR0L = v;  // Then TMR0L
}

uint16_t ReadT1(void){
    uint8_t tl;
    tl = TMR1L; // Read TMR1L first then TMR1H
    return tl | (TMR1H * 256);
}

void WriteT1(uint16_t v){
    TMR1H = v >> 8; // Write first on TMR1H
    TMR1L = v; // Then TMR1L
}

uint16_t ReadT3(void) {
    uint8_t t3;
    t3 = TMR3L; // Read TMR3L first then TMR3H
    return t3 | (TMR3H * 256); //
}

void WriteT3(uint16_t v) {
    TMR3H = v >> 8; // Write frist on TMR3H
    TMR3L = v; // Then TMR3L
}
