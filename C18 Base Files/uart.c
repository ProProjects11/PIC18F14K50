/*
 *	Copyright (c) 2011-2013, http://www.proprojects.wordpress.com
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
 * Compiler:        C18 v3.46
 * File Name:       uart.c
 * Description:     UART source code
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      10/31/13    Initial version
 * 1.1      11/04/13    Add public function uart_write_byte()
 *********************************************************************/

/** INCLUDES *******************************************************/
#include "uart.h"
#include "fifo.h"
#include "main.h"
#include "pic18f14k50_io.h"
#include <usart.h>

/** PRIVATE VARIABLES **********************************************/
static u8_t g_tx_buffer[UART_TX_BUFFER_SIZE];
static u8_t g_rx_buffer[UART_RX_BUFFER_SIZE];
static fifo_t g_rx_fifo;
static fifo_t g_tx_fifo;

/** PRIVATE FUNCTION PROTOTYPES ************************************/

/** PRIVATE FUNCTION DEFINITIONS ***********************************/

/** PUBLIC FUNCTION DEFINITIONS ************************************/
bool_t uart_init(u32_t desired_br, float32_t max_error_rate){
    float32_t error;
    float32_t n;
    float32_t calc_br;
    u8_t x, baudbits, baudhigh;
    float32_t select_error = 100;
    u8_t select_mode = 0;
    bool_t is_config_ok;

    // Calculate and compare the three modes
    for(x = 64; x > 3; x /= 4){
        // Calculate n
        n = ((float32_t)OSC_FREQ /((float32_t)x*(float32_t)desired_br))-1;

        // Round n
        if((n - (u32_t)n) >= 0.5){
            n++;
        }
        n = (u32_t)n;

        // Calculate BR
        calc_br = (float32_t)OSC_FREQ / ((float32_t)x*(n+1));

        // Calculate Error
        error = (((calc_br - desired_br))/desired_br)*(float32_t)100;

        // Absolute Error
        if(error < 0)
            error *= -1;

        // Conditions to select actual mode
        // if mode 64 N < 255 AND Error <= LastError
        // if mode 16 or 4 N < 65535 AND Error < LastError
        if(((x == 64) && (n < 255) && (error <= select_error)) || ((x < 64) && (n < (u16_t)65535) && (error < select_error))){
            select_mode = x;
            select_error = error;
        }
    }
    if(select_error <= max_error_rate){
        // Get mode
        switch(select_mode){
            case 64:
                baudbits = BAUD_8_BIT_RATE;
                baudhigh = USART_BRGH_LOW;
                break;
            case 16:
                baudbits = BAUD_16_BIT_RATE;
                baudhigh = USART_BRGH_LOW;
                break;
            case 4:
                baudbits = BAUD_16_BIT_RATE;
                baudhigh = USART_BRGH_HIGH;
                break;
        }
        // USART Config
        OpenInRB5();    // RX
        OpenOutRB7();   // TX
        baudUSART(  BAUD_IDLE_CLK_LOW &	// Idle
                    baudbits &          // 16b or 8B
                    BAUD_WAKEUP_OFF &	// Disable auto-wake-up
                    BAUD_AUTO_OFF	// Disable auto-baud-rate
                    );
        OpenUSART(  USART_TX_INT_OFF &  // Tx Int off
                    USART_RX_INT_OFF &	// Rx Int off
                    USART_ASYNCH_MODE &	// Asynchronous
                    USART_EIGHT_BIT &	// 8bit
                    USART_CONT_RX &	// Cont
                    baudhigh,           // High baud rate
                    (u16_t)n		// for defined n br
                    );
        BAUDCONbits.DTRXP = 0;		// We need to define polarity of RX, 0 = Low idle (Because a BUG in library)

        fifo_init(&g_tx_fifo,&g_tx_buffer[0],UART_TX_BUFFER_SIZE); // Init tx fifo
        fifo_init(&g_rx_fifo,&g_rx_buffer[0],UART_RX_BUFFER_SIZE); // Init rx fifo
        is_config_ok = TRUE;
    }
    else{
        is_config_ok = FALSE;
    }
    return is_config_ok;
}

void uart_flush_tx_buffer(void){
    fifo_flush(&g_tx_fifo);
}

void uart_flush_rx_buffer(void){
    fifo_flush(&g_rx_fifo);
}

u8_t uart_bytes_in_tx_buffer(void){
    return g_tx_fifo.bytes_in_buffer;
}

u8_t uart_bytes_in_rx_buffer(void){
    return g_rx_fifo.bytes_in_buffer;
}

u8_t uart_write_bytes(u8_t* p_buffer, const u8_t nbytes){
    u8_t bytes_written;

    // Check if nbytes fit in tx buffer
    if(fifo_available_space(&g_tx_fifo) >= nbytes){
        fifo_write(&g_tx_fifo,p_buffer,nbytes); // Add nbytes
        bytes_written = nbytes;
    }
    else{
        bytes_written = 0;
    }
    return bytes_written;
}

void uart_write_byte(u8_t byte){
    if(fifo_available_space(&g_tx_fifo) > 0){
        fifo_write(&g_tx_fifo,&byte,1);
    }
}

u8_t uart_read_bytes(u8_t* p_buffer, const u8_t nbytes, bool_t read_anyway){
    u8_t bytes_read;

    // If we have nbytes or more to read
    if(g_rx_fifo.bytes_in_buffer >= nbytes){
        fifo_read(&g_rx_fifo,p_buffer,nbytes);  // Read only nbytes
        bytes_read = nbytes;
    }
    // If we have at last one byte and read_anyway is 1
    else if (!fifo_is_empty(&g_rx_fifo) && read_anyway){
        bytes_read = g_rx_fifo.bytes_in_buffer; // store first how many bytes are in buffer
        fifo_read(&g_rx_fifo,p_buffer,g_rx_fifo.bytes_in_buffer);  // Read all available bytes
    }
    else{
        bytes_read = 0; // No bytes were read
    }
    return bytes_read;
}

void uart_update(void){
    u8_t byte;

    // RX new data?
    if(DataRdyUSART()){
        byte = ReadUSART();  // Get byte
        if(!fifo_is_full(&g_rx_fifo)){ // If fifo is not full store byte
            fifo_write(&g_rx_fifo,&byte,1); // Add byte to fifo
        }
    }

    // TX data available & usart not busy
    if(!BusyUSART() && !fifo_is_empty(&g_tx_fifo)){
        fifo_read(&g_tx_fifo,&byte,1);
        WriteUSART(byte); // Send byte
    }
}