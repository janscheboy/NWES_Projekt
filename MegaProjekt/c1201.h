/*
 * \brief This module implements an interface to the MIKROE-1201 7seg click.
 *
 * The MIKROE-1201 7seg click provides two seven-segment displays using a
 * 74HC595 serial-in, parallel-out shift register. This module provides an
 * interface to this module.
 */

#ifndef C1201_H_
#define C1201_H_

/**** Low level functions *****/

/// <summary>Transmit the segment patterns.</summary>
/// <remarks>
/// Selects at which row the stored data is displayed.
/// </remarks>
/// <param name="dis1">Segment pattern for display 1.</param>
/// <param name="dis2">Segment pattern for display 2.</param>
void c1201_transmit(uint8_t dis1, uint8_t dis2);

/**** High level functions *****/

/// <summary>Initialize click module.</summary>
/// <remarks>
/// Initializes the click module by setting up the SPI
/// module, the PWM module and the reset line. The display
/// is turned off after initialization.
/// </remarks>
void c1201_init(void);

/// <summary>Turn display on.</summary>
/// <remarks>
/// Turns the display on by activating the PWM.
/// </remarks>
void c1201_display_on(void);

/// <summary>Turn display off.</summary>
/// <remarks>
/// Turns the display on by shutting down the PWM.
/// </remarks>
void c1201_display_off(void);

/// <summary>Clear display.</summary>
/// <remarks>
/// Clears the display by a master reset.
/// </remarks>
void c1201_display_clear(void);

/// <summary>Dim display.</summary>
/// <remarks>
/// Dims the display by specifying the desired intensity.
/// The intensity corresponds to the duty cycle of the
/// PWM signal used to control the luminance.
/// </remarks>
/// <param name="intensity">The per cent intensity of the luminance.</param>
void c1201_set_intensity(uint8_t intensity);

/// <summary>Display a number.</summary>
/// <remarks>
/// Displays a number by transmitting the corresponding
/// segment pattern. The range of number must be between
/// 0 and 99. Leading zeros are suppressed.
/// </remarks>
/// <param name="number">The number to be displayed.</param>
void c1201_display_number(uint8_t number);

/// <summary>Display symbols.</summary>
/// <remarks>
/// Display two code B encoded symbols on the display. The
/// following encoding is used:
/// | Code   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15    |
/// |--------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|-------|
/// | Symbol | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  - |  E |  H |  L |  P | blank |
/// </remarks>
/// <param name="dis1">The row to be activated</param>
/// <param name="dis2">The row to be activated</param>
void c1201_display_symbols(uint8_t dis1, uint8_t dis2);

#endif /* c1201_H_ */