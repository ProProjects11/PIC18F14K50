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
 * File Name:       fifo.h
 * Description:     FIFO Stack
 * References:      https://coactionos.com/projects/coactionos/wiki/A_FIFO_Buffer_Implementation
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      10/30/13    Initial version
 * 1.1      11/01/13    Add bytes_in_buffer function
 * 1.2      07/15/14    Updated to XC8
 *********************************************************************/

#ifndef __FIFO_H
#define __FIFO_H

/** INCLUDES *******************************************************/
#include <stdint.h>
#include <stdbool.h>

/** INTERFACE CONFIGURATION ****************************************/

/** Fifo struct */
typedef struct {
    uint8_t* p_buffer;
    uint8_t bytes_in_buffer;
    uint8_t head;
    uint8_t tail;
    uint8_t size;
} fifo_t;

/** PUBLIC FUNCTIONS ***********************************************/
/**
 * Initialize fifo stack
 * @param p_fifo Pointer to fifo_t structure
 * @param p_buffer Pointer to a buffer
 * @param size Size of buffer
 */
/** PUBLIC FUNCTIONS ***********************************************/
/**
 * Initialize fifo stack
 * @param p_fifo Pointer to fifo_t structure
 * @param p_buffer Pointer to a buffer
 * @param size Size of buffer
 */
void fifo_init(fifo_t* p_fifo, uint8_t* p_buffer, uint8_t size);
/**
 * Flush fifo stack
 * @param p_fifo Pointer to fifo_t structure
 */
void fifo_flush(fifo_t* p_fifo);
/**
 * Check if fifo is empty
 * @param p_fifo Pointer to fifo_t structure
 * @return 1 if empty, 0 otherwise
 */
bool fifo_is_empty(fifo_t* p_fifo);
/**
 * Check if fifo is full
 * @param p_fifo Pointer to fifo_t structure
 * @return 1 if full, 0 otherwise
 */
bool fifo_is_full(fifo_t* p_fifo);
/**
 * Check available space in fifo
 * @param p_fifo Pointer to fifo_t structure
 * @return Available space in bytes, 0 = No space
 */
uint8_t fifo_available_space(fifo_t* p_fifo);
/**
 * Check how many bytes are in buffer
 * @param p_fifo Pointer to a fifo_t
 * @return Number of bytes in buffer, 0 = None
 */
uint8_t fifo_bytes_in_buffer(fifo_t* p_fifo);
/**
 * Write nbytes of data to fifo buffer
 * @param p_fifo Pointer to fifo_t structure
 * @param p_buffer_to_write Pointer to a buffer
 * @param nbytes How much bytes you want to write
 * @return 1 if all ok, 0 otherwise
 */
bool fifo_write(fifo_t* p_fifo, uint8_t* p_buffer_to_write, uint8_t nbytes);
/**
 * Read nbytes of data from fifo buffer
 * @param p_fifo Pointer to fifo_t structure
 * @param p_buffer Pointer to a buffer to store the data
 * @param nbytes How much data you want to read
 * @return Number read data
 */
uint8_t fifo_read(fifo_t* p_fifo, uint8_t* p_buffer, uint8_t nbytes);

#endif // __FIFO_H
