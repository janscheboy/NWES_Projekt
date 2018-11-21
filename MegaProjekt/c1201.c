#include <avr/io.h>
#include "c1201.h"
#include "hc595.h"
#include "board.h"
#include "spi.h"

void c1201_init() {
	spi_init();
	spi_select_slave();
	HC595_PORT.IN = (HC595_MR_bm);
	HC595_PORT.DIR = (HC595_MR_bm);
}


void c1201_transmit(uint8_t dis1, uint8_t dis2){
	
	spi_transfer(dis1);
	spi_transfer(dis2);
	spi_deselect_slave();
	spi_select_slave();
}