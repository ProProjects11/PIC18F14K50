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
 * Site:            http://www.proprojects.wordpress.com
 * Processor:       PIC18
 * Compiler:        XC8 v1.32
 * File Name:       pic18f14k50_spi.h
 * Description:     code to use spi for PIC18F14K50
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      06/05/13	Initial Version
 * 1.1      11/24/13    Format
 * 1.2      07/15/14    Updated to XC8
 *********************************************************************/

/** INCLUDES *******************************************************/
#include "pic18f14K50_spi.h"

/* DEFINES *********************************************************/
#define SPI_SDO_OUTPUT()    ANSELHbits.ANS9 = 0; TRISCbits.TRISC7 = 0
#define SPI_SDI_INPUT()     ANSELHbits.ANS10 = 0; TRISBbits.TRISB4 = 1
#define SPI_SCL_INPUT()     TRISBbits.TRISB6 = 1
#define SPI_SCL_OUTPUT()    TRISBbits.TRISB6 = 0
#define SPI_SS_INPUT()      ANSELHbits.ANS8 = 0; TRISCbits.TRISC6 = 1
#define SPI_SS_ENABLE()     SPI_SS_WRITE_PIN = 0
#define SPI_SS_DISABLE()    SPI_SS_WRITE_PIN = 1
#define SPI_ENABLE()        SSPCON1bits.SSPEN = 1
#define SPI_DISABLE()       SSPCON1bits.SSPEN = 0
#define SPI_SET_MODE00()    SSPCON1bits.CKP = 0; SSPSTATbits.CKE = 1
#define SPI_SET_MODE01()    SSPCON1bits.CKP = 0; SSPSTATbits.CKE = 0
#define SPI_SET_MODE10()    SSPCON1bits.CKP = 1; SSPSTATbits.CKE = 1
#define SPI_SET_MODE11()    SSPCON1bits.CKP = 1; SSPSTATbits.CKE = 0
#define SPI_CKEBIT()        SSPSTATbits.CKE
#define SPI_CLEAR_SMP()     SSPSTATbits.SMP = 0
#define SPI_COMPLETE_FLAG   PIR1bits.SSPIF

/** MODULE PRIVATE *************************************************/
static bool gb_master_mode = TRUE;

/** FUNCTION DEFINITIONS *******************************************/
void spi_init(uint8_t sync_mode, uint8_t bus_mode, uint8_t smp_phase) {
    SPI_DISABLE(); // Disable SPI module
    // General Initial SPI
    SPI_SDO_OUTPUT(); // SDO output
    SPI_SDI_INPUT(); // SDI input
    SSPCON1bits.SSPM = sync_mode; // Set sync mode
    switch (bus_mode) // Set bus mode
    {
        case SPI_MODE_00: SPI_SET_MODE00();
            break;
        case SPI_MODE_01: SPI_SET_MODE01();
            break;
        case SPI_MODE_10: SPI_SET_MODE10();
            break;
        case SPI_MODE_11: SPI_SET_MODE11();
            break;
        default: SPI_SET_MODE00();
            break;
    }
    if (sync_mode < 4) // Master mode (0-3)
    {
        // Master Mode -----------------------
        gb_master_mode = TRUE; // Master mode
        SPI_SCL_OUTPUT(); // SCL output
#ifdef SPI_MASTER_USE_SS_CONTROL
        SPI_SS_OUTPUT(); // /SS output
#endif
        SSPSTATbits.SMP = smp_phase; // Set smp phase for master
    } else {
        // Slave Mode ------------------------
        gb_master_mode = FALSE; // Slave Mode (4-5)
        SPI_SCL_INPUT(); // SCL input
        if (sync_mode == SPI_SLV_SSON || SPI_CKEBIT() == 1) // ds-p145
        {
            SPI_SS_INPUT(); // /SS input
        }
        SPI_CLEAR_SMP(); // Clear SMP when used in slave mode (datasheet)
    }
    SPI_ENABLE(); // Enable SPI module
}

void spi_close(void) {
    SPI_DISABLE(); // Disable SPI module
}

bool spi_write(uint8_t data) {
    uint8_t tmp;
#ifdef SPI_MASTER_USE_SS_CONTROL
    SPI_SS_ENABLE(); // Select /SS
#endif
    tmp = SSPBUF; // Read buffer to clear BF
    SPI_COMPLETE_FLAG = 0; // Clear IF
    SPI_WRITE_COLLITION_ERROR = 0; // Clear error
    SSPBUF = data; // Send data
    if (SPI_WRITE_COLLITION_ERROR) // Write Collition ocurred?
    {
#ifdef SPI_MASTER_USE_SS_CONTROL
        SPI_SS_DISABLE(); // Deselect /SS
#endif
        return FALSE; // Return error
    }
    while (!SPI_COMPLETE_FLAG); // Wait for tx/rx complete
#ifdef SPI_MASTER_USE_SS_CONTROL
    SPI_SS_DISABLE(); // Deselect /SS
#endif
    return TRUE; // OK
}

uint8_t spi_read(void) {
    uint8_t tmp;
#ifdef SPI_MASTER_USE_SS_CONTROL
    SPI_SS_ENABLE(); // Select /SS
#endif
    tmp = SSPBUF; // Read buffer to clear BF
    SPI_COMPLETE_FLAG = 0; // Clear IF
    SPI_WRITE_COLLITION_ERROR = 0; // Clear error
    SPI_OVERFLOW_ERROR = 0; // Clear error
    SSPBUF = 0x00; // Send dummy data
    while (!SPI_COMPLETE_FLAG); // Wait for tx/rx complete

#ifdef SPI_MASTER_USE_SS_CONTROL
    SPI_SS_DISABLE(); // Deselect /SS
#endif
    return SSPBUF;
}

uint8_t spi_write_read(uint8_t data) {
    uint8_t tmp;
#ifdef SPI_MASTER_USE_SS_CONTROL
    SPI_SS_ENABLE(); // Select /SS
#endif

    tmp = SSPBUF; // Read buffer to clear BF
    SPI_COMPLETE_FLAG = 0; // Clear IF
    SPI_WRITE_COLLITION_ERROR = 0; // Clear error
    SPI_OVERFLOW_ERROR = 0; // Clear error
    SSPBUF = data; // Send data
    if (SPI_WRITE_COLLITION_ERROR) // Write Collition ocurred?
    {
#ifdef SPI_MASTER_USE_SS_CONTROL
        SPI_SS_DISABLE(); // Deselect /SS
#endif
        return FALSE; // Return error
    }
    while (!SPI_COMPLETE_FLAG); // Wait for tx/rx complete

#ifdef SPI_MASTER_USE_SS_CONTROL
    SPI_SS_DISABLE(); // Deselect /SS
#endif

    return SSPBUF; // OK
}

void spi_send_string(char* p_str) {
    do {
        spi_write(*p_str);
        p_str++;
        SPI_DELAY_FOR_STRINGS();
    } while (*(p_str - 1));
}

void spi_read_string(char* p_str) {
    uint8_t t = 0;
    do {
        *p_str = spi_read();
        p_str++;
        t++;
        SPI_DELAY_FOR_STRINGS();
    } while (*(p_str - 1));
}
