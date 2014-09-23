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
 * Compiler:        C18 v3.46
 * File Name:       pic18f14k50_spi.h
 * Description:     Defines to use spi for PIC18F14K50
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rev.     Date        Comment
 * 1.0      06/05/13	Initial Version
 * 1.1      11/24/13    Format
 *********************************************************************/

#ifndef __PIC18F14K50_SPI_H
#define __PIC18F14K50_SPI_H

    /** INCLUDES *******************************************************/
    #include <p18f14k50.h>
    #include "stdvars.h"
    #include "pic18f14k50_io.h"
    #include "wait.h"
    
    /** INTERFACE CONFIGURATION ****************************************/
    #define SPI_MASTER_USE_SS_CONTROL

    #ifdef SPI_MASTER_USE_SS_CONTROL
            #define SPI_SS_OUTPUT()	OpenOutRC6() // Disable ADC, Output
            #define SPI_SS_WRITE_PIN	LATCbits.LATC6	// Pin to write to slave /SS
    #endif

    #define SPI_DELAY_FOR_STRINGS()     wait_in_ms(1) // delay between chars send

    // SPI Errors
    #define SPI_OVERFLOW_ERROR		SSPCON1bits.SSPOV   // Slave mode only: RX mode only
    #define SPI_WRITE_COLLITION_ERROR	SSPCON1bits.WCOL    // Tx mode only

    /** spi_init() DEFINES **********************************************/
    // For sync_mode, select only one
    #define SPI_MTR_FOSC_4	0	// Master mode, clock = Fosc/4
    #define SPI_MTR_FOSC_16	1	// Master mode, clock = Fosc/16
    #define SPI_MTR_FOSC_64     2	// Master mode, clock = Fosc/64
    #define SPI_MTR_FOSC_TMR2   3	// Master mode, clock = (TMR2 output) / 2
    #define SPI_SLV_SSON	4	// Slave mode, /SS pin on
    #define SPI_SLV_SSOFF	5	// Slave mode, /SS pin off

    // For bus_mode (SPI Mode, not pic mode), select one only
    //                      SPI Mode -> PIC Mode
    //                      CPOL,CPHA -> CKP,CKE
    #define SPI_MODE_00 0   // 0,0 -> 0,1   // CKE = 1, Slave: In this mode you must enable /SS
    #define SPI_MODE_01	1   // 0,1 -> 0,0
    #define SPI_MODE_10	2   // 1,0 -> 1,1   // CKE = 1, Slave: In this mode you must enable /SS
    #define SPI_MODE_11	3   // 1,1 -> 1,0

    // For smp_phase, select one only
    #define SPI_SMPMID	0	// Input data sample at middle of data out
    #define SPI_SMPEND	1	// Input data sample at end of data out

    //-- MSSP INTERRUPTS -----------------------------------------------
    #define SPI_INT_ENABLE()		PIE1bits.SSPIE = 1
    #define SPI_INT_DISABLE()		PIE1bits.SSPIE = 0

    #define SPI_HIGH_PRIORITY()		IPR1bits.SSPIP = 1
    #define SPI_LOW_PRIORITY()		IPR1bits.SSPIP = 0

    #define SPI_FLAG			PIR1bits.SSPIF	// =1, Transmission/Reception complete
    #define SPI_FLAG_CLEAR()		SSPFlag = 0

    /** PROTOTYPES *****************************************************/
    /**
     * Initialize SPI port
     * @param sync_mode SPI_MTR_FOSC_4, SPI_MTR_FOSC_16, SPI_MTR_FOSC_64, SPI_MTR_FOSC_TMR2, SPI_SLV_SSON, SPI_SLV_SSOFF
     * @param bus_mode SPI_MODE_00, SPI_MODE_01, SPI_MODE_10, SPI_MODE_11
     * @param smp_phase SPI_SMPMID, SPI_SMPEND
     */
    void spi_init(u8_t sync_mode, u8_t bus_mode, u8_t smp_phase);
    /**
     * Close SPI port
     */
    void spi_close(void);
    /**
     * Write byte to SPI port
     * @param data Byte to write
     * @return
     */
    bool_t spi_write(u8_t data);
    /**
     * Read byte from SPI port
     * @return Byte read
     */
    u8_t spi_read(void);
    /**
     * Write and Read from SPI port
     * @param data Byte to write
     * @return Byte read
     */
    u8_t spi_write_read(u8_t data);
    /**
     * Send string by SPI port
     * @param p_str Pointer to null terminated char string
     */
    void spi_send_string(char* p_str);
    /**
     * Send ROM string to SPI port
     * @param prom_str Pointer to ROM null terminated string
     */
    void spi_send_rom_string(rom char* prom_str);
    /**
     * Read a string from SPI port
     * @param p_str Null terminated string read
     */
    void spi_read_string(char* p_str);

#endif // __PIC18F14K50_SPI_H
