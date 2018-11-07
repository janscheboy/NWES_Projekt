/*
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
 */

#include <avr/io.h>
#include <util/delay.h>

//#include "board.h"

// We define some constants to have better mnemonics (names).
#define SPI_MODULE  SPIC
#define SPI_PORT    PORTC

#define SPI_SS_bm   PIN4_bm  // Slave Select
#define SPI_MOSI_bm PIN5_bm  // Master Out, Slave In
#define SPI_MISO_bm PIN6_bm  // Master In, Slave Out
#define SPI_SCK_bm  PIN7_bm  // Serial Clock

// We want to transmit data via the SPI interface on port C. The microcontroller
// is the master of the transmission. MISO is input. MOSI, SS and SCK are output.
// We use a prescaler of 64. Therefore the transmission speed is 31.25 kbps. The
// slave select line is active low. At the beginning the slave is deselected.
void spi_init(void)
{
	// Deactivate the slave.
	SPI_PORT.OUT |= SPI_SS_bm;
	// Make MISO an input line.
	SPI_PORT.DIR &= ~SPI_MISO_bm;
	// Make SS, MOSI and SCK output lines.
	SPI_PORT.DIR |= SPI_SS_bm | SPI_MOSI_bm | SPI_SCK_bm;
	// Enable SPI, select master mode and set the prescaler factor to 64.
	SPI_MODULE.CTRL = SPI_ENABLE_bm | SPI_MASTER_bm | SPI_PRESCALER_DIV64_gc;
}

void spi_select_slave(void) {
	SPI_PORT.OUT &= ~SPI_SS_bm;
}

void spi_deselect_slave(void) {
	SPI_PORT.OUT |= SPI_SS_bm;
}

uint8_t spi_transfer(uint8_t byte) {
	// Send the data.
	SPI_MODULE.DATA = byte;
	// While transmission has not yet finished do nothing.
	while (!(SPI_MODULE.STATUS & SPI_IF_bm));
	return byte;
}