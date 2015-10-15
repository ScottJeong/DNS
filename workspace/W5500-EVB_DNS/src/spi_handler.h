/*
 * spi_handler.h
 *
 *  Created on: 2015. 9. 14.
 *      Author: Administrator
 */

#ifndef SPI_HANDLER_H_
#define SPI_HANDLER_H_

#define GPIO_SPI0_PORT      0
#define GPIO_W5500_RST_PORT 0

#define GPIO_SPI0_CS        2
#define GPIO_SPI0_CLK       6
#define GPIO_SPI0_MISO      8
#define GPIO_SPI0_MOSI      9
#define GPIO_W5500_RST      3

void SPI_Init();


#endif /* SPI_HANDLER_H_ */
