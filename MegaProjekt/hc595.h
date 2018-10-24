/** \file hc595.h
 *
 * \brief Header file for the 74HC595 serial-in, parallel-out shift register.
 *
 * This file defines the pin mapping for the 74HC595 8-bit serial-in,
 * serial or parallel-out shift register with output latches.
 *
 * \author    Wolfgang Neff
 * \version   1.0
 * \date      2018-03-09
 *
 * \par History
 *      Created: 2018-03-09
 */

#ifndef HC595_H_
#define HC595_H_

#include "spi.h"

/**** Pin Description *****/

#define HC595_PORT SPI_PORT
#define HC595_MODULE SPI_MODULE

/* Serial Data Output */
#define HC595_Q7S_bp SPI_MISO_bp
#define HC595_Q7S_bm SPI_MISO_bm

/* Master Reset (active low) */
#define HC595_MR_bp PIN3_bp
#define HC595_MR_bm PIN3_bm

/* Shift Register Clock Input */
#define HC595_SHCP_bp SPI_SCK_bp
#define HC595_SHCP_bm SPI_SCK_bm

/* Storage Register Clock Input  */
#define HC595_STCP_bp SPI_SS_bp
#define HC595_STCP_bm SPI_SS_bm

/* Serial Data Input  */
#define HC595_DS_bp SPI_MOSI_bp
#define HC595_DS_bm SPI_MOSI_bm

#endif /* HC595_H_ */