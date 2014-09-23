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
 * Company:         http://proprojects.wordpress.com
 * Processor:       PIC18
 * Compiler:        C18 v3.46
 * File Name:       uart.h
 * Description:     UART header
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      10/31/13    Initial version
 * 1.1      11/04/13    Add public function uart_write_byte()
 *********************************************************************/

#ifndef __UART_H
#define __UART_H

/** INCLUDES *******************************************************/
#include "stdvars.h"

/** INTERFACE CONFIGURATION ****************************************/
#define UART_TX_BUFFER_SIZE 20  // 1 -> 255
#define UART_RX_BUFFER_SIZE 20  // 1 -> 255

/** PUBLIC FUNCTIONS ***********************************************/
/**
 * Initialize UART to desired baudrate and blocks size
 * @param desired_br 110 -> 921,600
 * @param max_error_rate 0.00 -> 100.00
 * @return 1 if error_rate <= max_error_rate, 0 otherwise
 */
bool_t uart_init(u32_t desired_br, float32_t max_error_rate);
/**
 * Flush tx buffer
 */
void uart_flush_tx_buffer(void);
/**
 * Flush rx buffer
 */
void uart_flush_rx_buffer(void);
/**
 * Check how many bytes are in the tx buffer
 * @return bytes in buffer
 */
u8_t uart_bytes_in_tx_buffer(void);
/**
 * Check how many bytes are in the rx buffer
 * @return bytes in buffer
 */
u8_t uart_bytes_in_rx_buffer(void);
/**
 * Write nbytes from p_buffer to usart
 * @param p_buffer Pointer to a buffer to send
 * @param nbytes Number of bytes to write
 * @return Number of bytes written
 */
u8_t uart_write_bytes(u8_t* p_buffer, const u8_t nbytes);
/**
 * Write one byte to uart buffer
 * if buffer is full byte will be ignored
 * @param byte byte to write
 */
void uart_write_byte(u8_t byte);
/**
 * Read nbytes from uart to p_buffer
 * @param p_buffer Pointer to a buffer to store the data
 * @param nbytes Number of bytes to read
 * @param read_anyway 1 will read <=nbytes, 0 if only want to read if nbytes are ready in buffer
 * @return Number of bytes read
 */
u8_t uart_read_bytes(u8_t* p_buffer, const u8_t nbytes, bool_t read_anyway);
/**
 * Tx & Rx data from and to uart buffers
 */
void uart_update(void);


#endif // __UART_H
