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
 * Company:         http://www.proprojects.wordpress.com
 * Processor:       PIC18
 * Compiler:        C18 3.46
 * File Name:       stdvars.h
 * Description:     New variables declaration standard.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      04/27/12    Initial version
 * 1.1      05/02/12	Replace VARIABLES_H to __VARIABLES_H
 * 1.2      05/05/12	Add bolean type (false, FALSE, true, TRUE)
 * 1.3      10/13/12	Replace name __VARIABLES_H to __STDVARS_H
 * 1.4      10/23/13	Add 't' to all typedef & changed booleans declaration
 * 1.5      10/30/13    NETRINO standard (Lower case and _t at the end for typedef, UPPERCASE for #defines)
  ********************************************************************/

#ifndef __STDVARS_H
#define __STDVARS_H

    /** MACROS & TYPEDEF FOR PIC18 ***********************************/
    // 8b signed [-128 -> 127]
    typedef char                int8_t, s8_t, char_t;
    // 8b unsigned [0 -> 255]
    typedef unsigned char       uint8_t, u8_t, byte_t;
    
    // 16b signed [-32,768 -> 32,767]
    typedef int                 int16_t, s16_t;
    //typedef short             SSHORT;
    // 16b unsigned [0 -> 65,535]
    typedef unsigned int        uint16_t, u16_t, word_t;
    //typedef unsigned short    USHORT;

    // 24b signed [-8,388,608 -> 8,388,607]
    typedef short long          int24_t, s24_t;
    // 24b unsigned [0 -> 16,777,215]
    typedef unsigned short long uint24_t, u24_t;

    // 32b signed [-2,147,483,648 -> 2,147,483,647]
    typedef long                int32_t, s32_t;
    // 32b unsigned [0 -> 4,294,967,295]
    typedef unsigned long       uint32_t, u32_t, dword_t;

    // 32b decimal point [exp(-126) -> exp(128)]
    typedef float               float32_t;
    typedef double              double32_t;
    
    // 8b Boolean
    typedef unsigned char       bool_t, boolean_t;

    // Boolean constants
    #define TRUE    1
    #define FALSE   0

    // Char constants
    #define NULL    0

#endif // __STDVARS_H
