/*
 * MegaProjekt.c
 *
 * Created: 10.10.2018 15:07:58
 */ 

#include <avr/io.h>
#include "c1201.h"
#include "hc595.h"
#include "pwm.h"
#include "board.h"
#include "spi.h"
#include "util/delay.h"


int main(void)
{
	c1201_init();
    while (1)
    {
		c1201_transmit(0x01, 0x02);
		_delay_ms(500);
    }
}

