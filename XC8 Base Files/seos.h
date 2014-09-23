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
 * File Name:       seos.h
 * Description:     Simple Embedded Operating System
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      10/31/13    Initial version
 * 1.1      07/15/14    Updated to XC8
 *********************************************************************/

#ifndef __SEOS_H
#define __SEOS_H

/** INCLUDES *******************************************************/
#include <stdint.h>

/** INTERFACE CONFIGURATION ****************************************/
#define TMR1_PS_1_1  0
#define TMR1_PS_1_2  1
#define TMR1_PS_1_4  2
#define TMR1_PS_1_8  3

/** PUBLIC FUNCTIONS ***********************************************/
/**
 * Initialize Interupts, Timer1 values and start it.
 * Time(s) = (4/Fosc) * LoadValue * PreScaler
 * LoadValue = Time(s) / [(4/Fosc)(PreScaler)]
 * @param load_value 16b value to count (Ticks)
 * @param prescaler TMR1_PS_1_1, TMR1_PS_1_2, TMR1_PS_1_4, TMR1_PS_1_8
 */
void seos_init_timer1(uint16_t load_value, uint8_t prescaler);
/**
 * This operating system enters sleep mode to save power.
 */
void seos_go_to_sleep(void);

#endif // __SEOS_H
