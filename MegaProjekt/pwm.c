/*
 * \brief PWM: dim an LED.
 *
 * This example program dims LED 0 with the aid of pulse-width modulation.
 *
 * The relevant registers are:
 * - CTRLA: Control Register A
 *   - CLKSEL: Clock Select (0 -> off)
 * - CTRLB: Control Register B
 *   - CCAEN: Compare or Capture Enable
 *   - WGMODE: Waveform Generation Mode
 * - CCA: Compare or Capture Register
 * - PER: Period Register
 *
 * The value for CCA is calculated by CCA = (PER+1)*d-1 where
 * - d: duty cycle
 * 
 * Please see modules 4.2.4 and 4.3.4 for more information.
 */

#include <avr/io.h>

#include "board.h"

// We want to dim LED0. LED0 is on port E (PE0) and is connected to OC0A.
// Therefore we have to use TCE0 with compare register A. The LED is active
// low. This has to be taken into account when handling the dimming. We have
// two options to handle this issue:
// - We can invert the duty cycle: 0% => LED on, 25% => LED dimmed to 75% etc.
// - We can invert the pin: the active low LED becomes active high.
int muell(void)
{
	// Initialize the LED and invert the pin.
    LED_PORT.DIR |= LED0_PIN_bm;
	LED_PORT.PIN0CTRL = PORT_INVEN_bm;

	// Initialize the push-buttons.
	BUTTON_LOW_PORT.PIN0CTRL = PORT_OPC_PULLUP_gc;
	BUTTON_LOW_PORT.PIN1CTRL = PORT_OPC_PULLUP_gc;
	BUTTON_LOW_PORT.PIN2CTRL = PORT_OPC_PULLUP_gc;
	BUTTON_LOW_PORT.PIN3CTRL = PORT_OPC_PULLUP_gc;

	/***** Initialize the PWM *****/
	// Enable compare register A and select single slope PWM mode.
    TCE0.CTRLB = TC0_CCAEN_bm | TC_WGMODE_SS_gc;
	// Set clock period. We use 10000 for simplicity.
	TCE0.PER = 10000;
	// Initial duty cycle: 100%.
	TCE0.CCA =  TCE0.PER;            
	// Turn on the clock.
	TCE0.CTRLA = TC_CLKSEL_DIV1_gc;

	while(1)
	{
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

void init_pwm(void) {

}
