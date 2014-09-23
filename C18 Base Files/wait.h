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

#ifndef __WAIT_H
#define __WAIT_H

    /** INCLUDES *******************************************************/
    #include <delays.h> // Delays in instructions
    #include "stdvars.h"
    
    /** DEFINES ********************************************************/
    // To calculate instructions needed for T (time s) is I = (F*T)/4
    // Select only one frequency
    //#define FQ_48M
    #define FQ_32M
    //#define FQ_24M
    //#define FQ_16M
    //#define FQ_12M
    //#define FQ_6M
    //#define FQ_4M
    
    #ifdef FQ_48M
            //1us	4.80E+07	1.00E-06	12.00
            //5us	4.80E+07	5.00E-06	60.00
            //10us	4.80E+07	1.00E-05	120.00
            //20us	4.80E+07	2.00E-05	240.00
            //25us	4.80E+07	2.50E-05	300.00
            //50us	4.80E+07	5.00E-05	600.00
            //100us	4.80E+07	1.00E-04	1,200.00
            //200us	4.80E+07	2.00E-04	2,400.00
            //250us	4.80E+07	2.50E-04	3,000.00
            //500us	4.80E+07	5.00E-04	6,000.00
            //1ms	4.80E+07	1.00E-03	12,000.00
            //1s	4.80E+07	1.00E+00	12,000,000.00
            #define Wait1us()	Delay10TCYx(1); Delay1TCY(); Delay1TCY()
	    #define Wait5us()	Delay10TCYx(6)
	    #define Wait10us() 	Delay10TCYx(12)
	    #define Wait20us() 	Delay10TCYx(24)
	    #define Wait25us() 	Delay10TCYx(30)
	    #define Wait50us() 	Delay10TCYx(60)
	    #define Wait100us()	Delay100TCYx(12)
	    #define Wait200us()	Delay100TCYx(24)
	    #define Wait250us()	Delay100TCYx(30)
	    #define Wait500us()	Delay100TCYx(60)
            #define Delay1MS()	Delay1KTCYx(12)
    #elif defined(FQ_32M)
            // Calculation using excel
            //1us	3.20E+07	1.00E-06	8.00
            //5us	3.20E+07	5.00E-06	40.00
            //10us	3.20E+07	1.00E-05	80.00
            //20us	3.20E+07	2.00E-05	160.00
            //25us	3.20E+07	2.50E-05	200.00
            //50us	3.20E+07	5.00E-05	400.00
            //100us	3.20E+07	1.00E-04	800.00
            //200us	3.20E+07	2.00E-04	1,600.00
            //250us	3.20E+07	2.50E-04	2,000.00
            //500us	3.20E+07	5.00E-04	4,000.00
            //1ms	3.20E+07	1.00E-03	8,000.00
            //1s	3.20E+07	1.00E+00	8,000,000.00
            #define Wait1us()	Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait5us()	Delay10TCYx(4)
	    #define Wait10us() 	Delay10TCYx(8)
	    #define Wait20us() 	Delay10TCYx(16)
	    #define Wait25us() 	Delay10TCYx(20)
	    #define Wait50us() 	Delay10TCYx(40)
	    #define Wait100us()	Delay10TCYx(80)
	    #define Wait200us()	Delay100TCYx(16)
	    #define Wait222us() Delay10TCYx(177);Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait250us()	Delay100TCYx(20)
	    #define Wait444us() Delay100TCYx(35);Delay10TCYx(5);Delay1TCY();Delay1TCY()
	    #define Wait500us()	Delay100TCYx(40)
            #define Delay1MS()	Delay1KTCYx(8)
	#elif defined(FQ_24M)
            // Calculation using excel
            //1us	2.40E+07	1.00E-06	6.00
            //5us	2.40E+07	5.00E-06	30.00
            //10us	2.40E+07	1.00E-05	60.00
            //20us	2.40E+07	2.00E-05	120.00
            //25us	2.40E+07	2.50E-05	150.00
            //50us	2.40E+07	5.00E-05	300.00
            //100us	2.40E+07	1.00E-04	600.00
            //200us	2.40E+07	2.00E-04	1,200.00
            //250us	2.40E+07	2.50E-04	1,500.00
            //500us	2.40E+07	5.00E-04	3,000.00
            //1ms	2.40E+07	1.00E-03	6,000.00
            //1s	2.40E+07	1.00E+00	6,000,000.00
            #define Wait1us()	Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait5us()	Delay10TCYx(3)
	    #define Wait10us() 	Delay10TCYx(6)
	    #define Wait20us() 	Delay10TCYx(12)
	    #define Wait25us() 	Delay10TCYx(15)
	    #define Wait50us() 	Delay10TCYx(30)
	    #define Wait100us()	Delay10TCYx(60)
	    #define Wait200us()	Delay100TCYx(12)
	    #define Wait250us()	Delay100TCYx(15)
	    #define Wait500us()	Delay100TCYx(30)
            #define Delay1MS()	Delay1KTCYx(6)
	#elif defined(FQ_16M)
            // Calculation using excel
            //1us	1.60E+07	1.00E-06	4.00
            //5us	1.60E+07	5.00E-06	20.00
            //10us	1.60E+07	1.00E-05	40.00
            //20us	1.60E+07	2.00E-05	80.00
            //25us	1.60E+07	2.50E-05	100.00
            //50us	1.60E+07	5.00E-05	200.00
            //100us	1.60E+07	1.00E-04	400.00
            //200us	1.60E+07	2.00E-04	800.00
            //250us	1.60E+07	2.50E-04	1,000.00
            //500us	1.60E+07	5.00E-04	2,000.00
            //1ms	1.60E+07	1.00E-03	4,000.00
            //1s	1.60E+07	1.00E+00	4,000,000.00
            #define Wait1us()	Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait5us()	Delay10TCYx(2)
	    #define Wait10us() 	Delay10TCYx(4)
	    #define Wait20us() 	Delay10TCYx(8)
	    #define Wait25us() 	Delay10TCYx(10)
	    #define Wait50us() 	Delay10TCYx(20)
	    #define Wait100us()	Delay10TCYx(40)
	    #define Wait200us()	Delay10TCYx(80)
	    #define Wait250us()	Delay100TCYx(10)
	    #define Wait500us()	Delay100TCYx(20)
            #define Delay1MS()	Delay1KTCYx(4)
	#elif defined(FQ_12M)
	    // Calculation using excel
            //1us	1.20E+07	1.00E-06	3.00
            //5us	1.20E+07	5.00E-06	15.00
            //10us	1.20E+07	1.00E-05	30.00
            //20us	1.20E+07	2.00E-05	60.00
            //25us	1.20E+07	2.50E-05	75.00
            //50us	1.20E+07	5.00E-05	150.00
            //100us	1.20E+07	1.00E-04	300.00
            //200us	1.20E+07	2.00E-04	600.00
            //250us	1.20E+07	2.50E-04	750.00
            //500us	1.20E+07	5.00E-04	1,500.00
            //1ms	1.20E+07	1.00E-03	3,000.00
            //1s	1.20E+07	1.00E+00	3,000,000.00
            #define Wait1us()	Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait5us()	Delay10TCYx(1);Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait10us() 	Delay10TCYx(3)
	    #define Wait20us() 	Delay10TCYx(6)
	    #define Wait25us() 	Delay10TCYx(7);Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait50us() 	Delay10TCYx(15)
	    #define Wait100us()	Delay10TCYx(30)
	    #define Wait200us()	Delay10TCYx(60)
	    #define Wait250us()	Delay10TCYx(75)
	    #define Wait500us()	Delay10TCYx(150)
	    #define Delay1MS()	Delay1KTCYx(3)
	#elif defined(FQ_6M)
	    // Calculation using excel
            //1us	6.00E+06	1.00E-06	1.50
            //5us	6.00E+06	5.00E-06	7.50
            //10us	6.00E+06	1.00E-05	15.00
            //20us	6.00E+06	2.00E-05	30.00
            //25us	6.00E+06	2.50E-05	37.50
            //50us	6.00E+06	5.00E-05	75.00
            //100us	6.00E+06	1.00E-04	150.00
            //200us	6.00E+06	2.00E-04	300.00
            //250us	6.00E+06	2.50E-04	375.00
            //500us	6.00E+06	5.00E-04	750.00
            //1ms	6.00E+06	1.00E-03	1,500.00
            //1s	6.00E+06	1.00E+00	1,500,000.00
            #define Wait1us()	Delay1TCY()
	    #define Wait5us()	Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait10us() 	Delay10TCYx(1);Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait20us() 	Delay10TCYx(3)
	    #define Wait25us() 	Delay10TCYx(3);Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait50us() 	Delay10TCYx(7);Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait100us()	Delay10TCYx(15)
	    #define Wait200us()	Delay10TCYx(30)
	    #define Wait250us()	Delay10TCYx(37);Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait500us()	Delay10TCYx(75)
            #define Delay1MS()	Delay100TCYx(15)
	#elif defined(FQ_4M)
	    // Calculation using excel
            //1us	4.00E+06	1.00E-06	1.00
            //5us	4.00E+06	5.00E-06	5.00
            //10us	4.00E+06	1.00E-05	10.00
            //20us	4.00E+06	2.00E-05	20.00
            //25us	4.00E+06	2.50E-05	25.00
            //50us	4.00E+06	5.00E-05	50.00
            //100us	4.00E+06	1.00E-04	100.00
            //200us	4.00E+06	2.00E-04	200.00
            //250us	4.00E+06	2.50E-04	250.00
            //500us	4.00E+06	5.00E-04	500.00
            //1ms	4.00E+06	1.00E-03	1,000.00
            //1s	4.00E+06	1.00E+00	1,000,000.00
            #define Wait1us()	Delay1TCY()
	    #define Wait5us()	Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait10us() 	Delay10TCYx(1)
	    #define Wait20us() 	Delay10TCYx(2)
	    #define Wait25us() 	Delay10TCYx(2);Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY()
	    #define Wait50us() 	Delay10TCYx(5)
	    #define Wait100us()	Delay10TCYx(10)
	    #define Wait200us()	Delay10TCYx(20)
	    #define Wait250us()	Delay10TCYx(25)
	    #define Wait500us()	Delay10TCYx(50)
	    #define Delay1MS()	Delay1KTCYx(1)
	#else
		#error NO FREQUENCY SPECIFIED!!!!
    #endif

    /** PROTOTYPES *****************************************************/
     /**
      * Wait in ms intervals
      * @param ms 1-65,535 ms to wait (16b)
      */
    void wait_in_ms(u16_t ms);
    
#endif // __WAIT_H
