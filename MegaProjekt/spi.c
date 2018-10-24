/** \file main.c
 *
 * \brief SPI: data transfer.
 *
 * This example program transmits data via the Serial Peripheral Interface.
 *
 * The relevant registers are:
 * - CTRL: SPI Control Register
 *   - ENABLE: SPI Enable
 *   - MASTER: Master/Slave Select
 *   - PRESCALER: Clock Prescaler
 * - DATA: SPI Data Register
 * - STATUS: SPI Status Register
 *   - IF: Interrupt Flag
 *
 * Please see module 5.3.3 for more information.
 *
 * \author    Wolfgang Neff
 * \version   1.2
 * \date      2018-06-27
 *
 * \par History
 *      Created: 2015-02-06 \n
 *      Modified: 2016-10-15 \n
 *      Modified: 2018-06-27
 */

#include <avr/io.h>
#include <util/delay.h>

#include "board.h"

// We define some constants to have better mnemonics (names).
#define SPI_MODULE  SPIC
#define SPI_PORT    PORTC

#define SPI_SS_bm   PIN4_bm  // Slave Select
#define SPI_MOSI_bm PIN5_bm  // Master Out, Slave In
#define SPI_MISO_bm PIN6_bm  // Master In, Slave Out
#define SPI_SCK_bm  PIN7_bm  // Serial Clock

#define SPI_DATA 'A'

// We want to transmit data via the SPI interface on port C. The microcontroller
// is the master of the transmission. MISO is input. MOSI, SS and SCK are output.
// We use a prescaler of 64. Therefore the transmission speed is 31.25 kbps. The
// slave select line is active low. At the beginning the slave is deselected.
int init_main(void)
{
	/***** Initialize the SPI. *****/
	// Deactivate the slave.
	SPI_PORT.OUT |= SPI_SS_bm;
	// Make MISO an input line.
	SPI_PORT.DIR &= ~SPI_MISO_bm;
	// Make SS, MOSI and SCK output lines.
	SPI_PORT.DIR |= SPI_SS_bm | SPI_MOSI_bm | SPI_SCK_bm;
	// Enable SPI, select master mode and set the prescaler factor to 64.
	SPI_MODULE.CTRL = SPI_ENABLE_bm | SPI_MASTER_bm | SPI_PRESCALER_DIV64_gc;

    while(1)
    {
		// Select the slave.
		SPI_PORT.OUT &= ~SPI_SS_bm;
		// Send the data.
		SPI_MODULE.DATA = SPI_DATA;
		// While transmission has not yet finished do nothing.
		while (!(SPI_MODULE.STATUS & SPI_IF_bm));
		// Deselect the slave.
		SPI_PORT.OUT |= SPI_SS_bm;
		// Wait a bit before starting the next transmission.
		_delay_ms(1000);
    }
}
