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
 * File Name:       fifo.c
 * Description:     FIFO Stack
 * References:      https://coactionos.com/projects/coactionos/wiki/A_FIFO_Buffer_Implementation
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      10/30/13    Initial version
 * 1.1      11/01/13    Add bytes_in_buffer function
 * 1.2      07/15/14    Updated to XC8
 *********************************************************************/

/** INCLUDES *******************************************************/
#include "fifo.h"

/** PRIVATE VARIABLES **********************************************/

/** PRIVATE FUNCTION PROTOTYPES ************************************/

/** PRIVATE FUNCTION DEFINITIONS ***********************************/

/** PUBLIC FUNCTION DEFINITIONS ************************************/
void fifo_init(fifo_t* p_fifo, uint8_t* p_buffer, uint8_t size){
    p_fifo->head = 0;
    p_fifo->tail = 0;
    p_fifo->size = size;
    p_fifo->bytes_in_buffer = 0;
    p_fifo->p_buffer = p_buffer;
}

void fifo_flush(fifo_t* p_fifo){
    p_fifo->head = 0;
    p_fifo->tail = 0;
    p_fifo->bytes_in_buffer = 0;
}

bool fifo_is_empty(fifo_t* p_fifo){
    bool is_empty;

    // Check if bytes in buffer is 0
    if(p_fifo->bytes_in_buffer == 0){
        is_empty = true;
    }
    else{
        is_empty = false;
    }
    return is_empty;
}

bool fifo_is_full(fifo_t* p_fifo){
    bool is_full;

    // Check if bytes in buffer equal to size
    if(p_fifo->bytes_in_buffer == p_fifo->size){
        is_full = true;
    }
    else{
        is_full = false;
    }
    return is_full;
}

uint8_t fifo_available_space(fifo_t* p_fifo){
    return (p_fifo->size - p_fifo->bytes_in_buffer);
}

uint8_t fifo_bytes_in_buffer(fifo_t* p_fifo){
    return p_fifo->bytes_in_buffer;
}

bool fifo_write(fifo_t* p_fifo, uint8_t* p_buffer_to_write, uint8_t nbytes){
    bool write_ok;

    // Check if there's enough space in the fifo buffer
    if(fifo_available_space(p_fifo) >= nbytes){
        for(nbytes; nbytes > 0; nbytes--) {
            p_fifo->p_buffer[p_fifo->head] = *p_buffer_to_write; // Add new data
            p_fifo->bytes_in_buffer++; // Increment counter
            p_fifo->head++; // Increment head
            // Check for wrap-around
            if(p_fifo->head == p_fifo->size) {
                p_fifo->head = 0;   // Restart head to 0
            }
            p_buffer_to_write++; // Next data to write
        }
        write_ok = true;
    }
    else {
        write_ok = false;
    }
    return write_ok;
}

uint8_t fifo_read(fifo_t* p_fifo, uint8_t* p_buffer, uint8_t nbytes){
    uint8_t bytes_read;

    bytes_read = 0;
    // Check if there is data in fifo buffer & check if we haven't reach nbytes read.
    while((!fifo_is_empty(p_fifo)) && (bytes_read < nbytes)) {
        *p_buffer = p_fifo->p_buffer[p_fifo->tail]; // Get data from buffer
        p_fifo->bytes_in_buffer--; // Decrement counter
        p_fifo->tail++; // Increment tail
        // Check for wrap-around
        if(p_fifo->tail == p_fifo->size){
            p_fifo->tail = 0;
        }
        p_buffer++; // Increment buffer where we're writing
        bytes_read++; // Increment read bytes
    }
    return bytes_read;
}
