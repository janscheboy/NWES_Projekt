/*
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
void pwm_init(void)
{
	// Enable compare register A and select single slope PWM mode.
    TCF0.CTRLB = TC0_CCCEN_bm | TC_WGMODE_SS_gc;
	// Set clock period. We use 10000 for simplicity.
	TCF0.PER = 10000;
	// Initial duty cycle: 100%.
	TCF0.CCC = TCF0.PER;            
}

void pwm_start(void) {
	TCF0.CTRLA = TC_CLKSEL_DIV1_gc;
}

void pwm_stop(void) {
	TCF0.CTRLA = TC_CLKSEL_OFF_gc;
}

void pwm_duty(uint8_t duty) { //z.B. 25 oder 100
	uint8_t actualduty = 100 / duty;
	TCF0.PER = TCF0.PER / actualduty;
	TCF0.CCC = TCF0.PER / actualduty; // z.B. 4 oder 1
}
