#include "board.h"
#include "spi_handler.h"

static void Init_SSP_PinMux(void)
{
    /* Configure SPI Pin */
    Chip_IOCON_PinMuxSet(LPC_IOCON, GPIO_SPI0_PORT, GPIO_SPI0_CLK,
                    (IOCON_FUNC2 | IOCON_MODE_INACT | IOCON_DIGMODE_EN));
    Chip_IOCON_PinMuxSet(LPC_IOCON, GPIO_SPI0_PORT, GPIO_SPI0_MISO,
                    (IOCON_FUNC1 | IOCON_MODE_INACT | IOCON_DIGMODE_EN));
    Chip_IOCON_PinMuxSet(LPC_IOCON, GPIO_SPI0_PORT, GPIO_SPI0_MOSI,
                    (IOCON_FUNC1 | IOCON_MODE_INACT | IOCON_DIGMODE_EN));
    Chip_IOCON_PinMuxSet(LPC_IOCON, GPIO_SPI0_PORT, GPIO_SPI0_CS,
                    (IOCON_FUNC0 | IOCON_MODE_PULLUP));
    Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_SPI0_PORT, GPIO_SPI0_CS);
    Chip_GPIO_SetPinState(LPC_GPIO, GPIO_SPI0_PORT, GPIO_SPI0_CS, true);

    /* Configure W5500 RESET Pin */
    Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_W5500_RST_PORT, GPIO_W5500_RST);
    Chip_GPIO_SetPinState(LPC_GPIO, GPIO_W5500_RST_PORT, GPIO_W5500_RST, true);
}

void SPI_Init()
{
    /* SSP initialization */
    Init_SSP_PinMux();
    Chip_SSP_Init(LPC_SSP0);

    Chip_SSP_SetFormat(LPC_SSP0, SSP_BITS_8, SSP_FRAMEFORMAT_SPI, SSP_CLOCK_MODE0);
    Chip_SSP_SetMaster(LPC_SSP0, true);
    Chip_SSP_SetBitRate(LPC_SSP0, 12000000);    // 12MHz
    Chip_SSP_Enable(LPC_SSP0);
}
