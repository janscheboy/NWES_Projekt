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
		if (!(BUTTON_LOW_PORT.IN & BUTTON0_PIN_bm)) {
			pwm_duty(100);
		}
		if (!(BUTTON_LOW_PORT.IN & BUTTON1_PIN_bm)) {
			pwm_duty(75);
		}
		if (!(BUTTON_LOW_PORT.IN & BUTTON2_PIN_bm)) {
			pwm_duty(50);
		}
		if (!(BUTTON_LOW_PORT.IN & BUTTON3_PIN_bm)) {
			pwm_duty(25);
		}
    }
}

