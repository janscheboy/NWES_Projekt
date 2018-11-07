/*
 * \brief  Header file for the SPI interface.
 *
 * This library provides high level access to the Serial Peripheral Interface
 * bus interface.
 */

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define SPI_PORT PORTF
#define SPI_MODULE SPIF

#define SPI_SS_bp    PIN4_bp
#define SPI_MOSI_bp  PIN5_bp
#define SPI_MISO_bp  PIN6_bp
#define SPI_SCK_bp   PIN7_bp

#define SPI_CLOCK_SPEED_gc SPI_PRESCALER_DIV4_gc

#ifdef __cplusplus
extern "C"
{
#endif

/// <summary>Initialize interface.</summary>
/// <remarks>
/// Setup the interface pins and initialize the spi controller.
/// </remarks>
void spi_init(void);

/// <summary>Activate the slave.</summary>
/// <remarks>
/// Drops the chip select line in order to activate the slave.
/// </remarks>
void spi_select_slave(void);

/// <summary>Dectivate the slave.</summary>
/// <remarks>
/// Drives the chip select line high in order to deactivate
/// the slave.
/// </remarks>
void spi_deselect_slave(void);

/// <summary>Transfer one data byte.</summary>
/// <remarks>
/// Transmits one data byte to the slave and receives one from
/// the slave.
/// </remarks>
/// <param name="byte">The data byte sent to the slave.</param>
/// <returns>The data byte received from the slave.</returns>
uint8_t spi_transfer(uint8_t byte);

#ifdef __cplusplus
}
#endif

#endif /* SPI_H_ */