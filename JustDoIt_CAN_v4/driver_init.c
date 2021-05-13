/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>

struct can_async_descriptor CAN_0;
struct can_async_descriptor CAN_1;

struct usart_sync_descriptor TARGET_IO;

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void TARGET_IO_PORT_init(void)
{

	gpio_set_pin_function(PA5, MUX_PA5C_UART1_URXD1);

	gpio_set_pin_function(PA6, MUX_PA6C_UART1_UTXD1);
}

void TARGET_IO_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_UART1);
}

void TARGET_IO_init(void)
{
	TARGET_IO_CLOCK_init();
	usart_sync_init(&TARGET_IO, UART1, _uart_get_usart_sync());
	TARGET_IO_PORT_init();
}

/**
 * \brief MCAN Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void CAN_0_CLOCK_init()
{
	_pmc_enable_periph_clock(ID_MCAN0);
}

/**
 * \brief MCAN pinmux initialization function
 *
 * Set each required pin to MCAN functionality
 */
void CAN_0_PORT_init(void)
{

	gpio_set_pin_function(PB3, MUX_PB3A_MCAN0_CANRX0);

	gpio_set_pin_function(PB2, MUX_PB2A_MCAN0_CANTX0);
}
/**
 * \brief CAN initialization function
 *
 * Enables CAN peripheral, clocks and initializes CAN driver
 */
void CAN_0_init(void)
{
	CAN_0_CLOCK_init();
	CAN_0_PORT_init();
	can_async_init(&CAN_0, MCAN0);
}

/**
 * \brief MCAN Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void CAN_1_CLOCK_init()
{
	_pmc_enable_periph_clock(ID_MCAN1);
}

/**
 * \brief MCAN pinmux initialization function
 *
 * Set each required pin to MCAN functionality
 */
void CAN_1_PORT_init(void)
{

	gpio_set_pin_function(PC12, MUX_PC12C_MCAN1_CANRX1);

	gpio_set_pin_function(PC14, MUX_PC14C_MCAN1_CANTX1);
}
/**
 * \brief CAN initialization function
 *
 * Enables CAN peripheral, clocks and initializes CAN driver
 */
void CAN_1_init(void)
{
	CAN_1_CLOCK_init();
	CAN_1_PORT_init();
	can_async_init(&CAN_1, MCAN1);
}

void system_init(void)
{
	init_mcu();

	_pmc_enable_periph_clock(ID_PIOB);

	/* Disable Watchdog */
	hri_wdt_set_MR_WDDIS_bit(WDT);

	/* GPIO on PB0 */

	gpio_set_pin_level(silent0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(silent0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(silent0, GPIO_PIN_FUNCTION_OFF);

	/* GPIO on PB1 */

	gpio_set_pin_level(silen1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(silen1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(silen1, GPIO_PIN_FUNCTION_OFF);

	delay_driver_init();

	TARGET_IO_init();

	CAN_0_init();
	CAN_1_init();
}
