/*
 *	Copyright (c) 2011-2013, http://www.proprojects.wordpress.com
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
 * Compiler:        C18 3.46
 * File Name:       wait.h
 * Description:     Basic wait functions, multiples of seconds.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      04/01/12    Initial version
 * 1.1      04/27/12    Add "variables.h", Rename WaitXms() to Waitmsx()
 * 1.2      05/02/12	Remove "variables.h", Replace WAIT_H to __WAIT_H
 * 2.0      02/01/13	Add more frequencies and reorganize all
 * 2.1      11/09/13    Organize and fixed file format
  ********************************************************************/

/** INCLUDES *******************************************************/
#include "wait.h"

/** PUBLIC FUNCTIONS *************************************************/
void wait_in_ms(u16_t ms){
    unsigned int c;
    for(c=0; c < ms; c++)
        Delay1MS();
}