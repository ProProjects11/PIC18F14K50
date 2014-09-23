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
 * Company:         http://proprojects.wordpress.com
 * Processor:       PIC18
 * Compiler:        XC8 v1.32
 * File Name:       seos.c
 * Description:     Simple Embedded Operating System
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      10/31/13    Initial version
 * 1.1      07/15/14    Updated to XC8
 *********************************************************************/

/** INCLUDES *******************************************************/
#include "seos.h"
#include "main.h"
#include "pic18f14k50_timers.h" // Apropiate PIC18 timers defines
#include "pic18f14k50_int.h"    // Apropiate PIC18 interrupts defines

/** PRIVATE VARIABLES **********************************************/
static uint16_t g_reload_value;

/** PRIVATE FUNCTION PROTOTYPES ************************************/

/** INTERRUPT FUNCTION DEFINITIONS *********************************/
void interrupt seos_tmr1_isr(void) {
    WriteT1(g_reload_value); // Manual reload timer value

    // Call tasks here

    INTT1FlagClear(); // Clear interrupt flag
} //This return will be a "retfie fast"

/** PUBLIC FUNCTION DEFINITIONS ************************************/
void seos_init_timer1(uint16_t load_value, uint8_t prescaler) {
    // Interrupts Configuration (Only 1 interrupt for this operating system)
    GIDisable(); // Disable global interrupt
    INTT1FlagClear(); // Clear interrupt flag
    INTT1Enable(); // Enable interrupt
    INTPDisable(); // No priority (all HP)
    PEIEnable(); // Timmers are peripherials
    GIEnable(); // Enable global interrupt

    // Timer1 configuration
    StopT1(); // Stop Timmer
    OpenTmrT1(); // Work as timer
    SetPST1(prescaler); // Set prescaler
    UseRWOneOPT1(); // One read and write operation 16b
    g_reload_value = 65536 - load_value;
    WriteT1(g_reload_value); // Load value
    StartT1(); // Start timer
}

void seos_go_to_sleep(void) {
    OSCCONbits.IDLEN = 1; // Peripherals ON, CPU Off
    Sleep(); // Sleep uC
}
