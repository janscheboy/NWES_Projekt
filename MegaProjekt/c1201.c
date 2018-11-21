#include <avr/io.h>
#include "c1201.h"
//#include "hc595.h"
//#include "board.h"
#include "spi.h"

void c1201_init() {
	spi_init();
}

void c1201_transmit(uint8_t dis1, uint8_t dis2) {
	spi_select_slave();
	spi_transfer(dis1);
	spi_transfer(dis2);
}

