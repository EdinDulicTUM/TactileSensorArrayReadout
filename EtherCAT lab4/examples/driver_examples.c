/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

void I2C_0_example(void)
{
	struct io_descriptor *I2C_0_io;

	i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
	i2c_m_sync_enable(&I2C_0);
	i2c_m_sync_set_slaveaddr(&I2C_0, 0x12, I2C_M_SEVEN);
	io_write(I2C_0_io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_SPI_0[12] = "Hello World!";

static void tx_complete_cb_SPI_0(struct _dma_resource *resource)
{
	/* Transfer completed */
}

void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_m_dma_get_io_descriptor(&SPI_0, &io);

	spi_m_dma_register_callback(&SPI_0, SPI_M_DMA_CB_TX_DONE, tx_complete_cb_SPI_0);
	spi_m_dma_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
}

void I2C_1_example(void)
{
	struct io_descriptor *I2C_1_io;

	i2c_m_sync_get_io_descriptor(&I2C_1, &I2C_1_io);
	i2c_m_sync_enable(&I2C_1);
	i2c_m_sync_set_slaveaddr(&I2C_1, 0x12, I2C_M_SEVEN);
	io_write(I2C_1_io, (uint8_t *)"Hello World!", 12);
}
