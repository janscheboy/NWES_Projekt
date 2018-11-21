#include <avr/io.h>
#include <util/delay.h>
#include "c1201.h"
#include "hc595.h"
#include "pwm.h"
#include "board.h"
#include "spi.h"


int main(void)
{
	BUTTON_LOW_PORT.PIN0CTRL = PORT_OPC_PULLUP_gc;
	BUTTON_LOW_PORT.PIN1CTRL = PORT_OPC_PULLUP_gc;
	BUTTON_LOW_PORT.PIN2CTRL = PORT_OPC_PULLUP_gc;
	BUTTON_LOW_PORT.PIN3CTRL = PORT_OPC_PULLUP_gc;
	
	c1201_init();
    while (1)
    {
		c1201_transmit(0x03, 0x03);
		_delay_ms(100);
		if (!(BUTTON_LOW_PORT.IN & BUTTON0_PIN_bm)) {
			TCE0.CCA = TCE0.PER;     // Duty cycle 100%: LED not dimmed
		}
		if (!(BUTTON_LOW_PORT.IN & BUTTON1_PIN_bm)) {
			TCE0.CCA = TCE0.PER/2;   // Duty cycle 50%: LED dimmed to 50%
		}
		if (!(BUTTON_LOW_PORT.IN & BUTTON2_PIN_bm)) {
			TCE0.CCA = TCE0.PER/4;   // Duty cycle 25%: LED dimmed to 25%
		}
		if (!(BUTTON_LOW_PORT.IN & BUTTON3_PIN_bm)) {
			TCE0.CCA = 0x0000;       // Duty cycle 0%: LED switched off
		}
    }
}

