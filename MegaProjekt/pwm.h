/** \file pwm.h
 *
 * \brief This module implements a PWM driver.
 *
 * \author    Wolfgang Neff
 * \version   2.0
 * \date      2018-03-10
 *
 * \par History
 *      Created: 2017-07-06
 *      Modified: 2018-03-10
 */

#ifndef PWM_H_
#define PWM_H_

#define PWM_PORT PORTF
#define PWM_CCEN TC0_CCCEN_bm
#define PWM_CCREG CCC
#define PWM_MODULE TCF0
#define PWM_PIN_bm PIN2_bm

#ifdef __cplusplus
extern "C"
{
#endif

/// <summary>Initialize PWM module.</summary>
/// <remarks>
/// Initializes the PWM module but does not yet start
/// the modulation.
/// </remarks>
void pwm_init(void);

/// <summary>Stop the modulation.</summary>
/// <remarks>
/// Stops the modulations, clears the oscillator pin and
/// resets the PWM timer.
/// </remarks>
void pwm_stop(void);

/// <summary>Start the modulation.</summary>
/// <remarks>
/// Start the modulation on the oscillator pin.
/// </remarks>
void pwm_start(void);

/// <summary>Set the duty cycle.</summary>
/// <remarks>
/// Sets the duty cycle of the pulse width modulated signal.
/// </remarks>
/// <param name="duty">The duty cycle per cent.</param>
void pwm_duty(uint8_t duty);

#ifdef __cplusplus
}
#endif

#endif /* PWM_H_ */