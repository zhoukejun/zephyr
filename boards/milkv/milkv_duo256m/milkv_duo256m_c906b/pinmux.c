/*
 * Copyright (c) 2024 ZHOU Kejun <zhoukejun@outlook.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT sophgo_pinctrl

#include <stdio.h>
#include <zephyr/arch/cpu.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/pinctrl.h>

#include <zephyr/dt-bindings/pinctrl/sophgo-sg200x-pinctrl.h>


#define PINCTRL_BASE_ADDR	DT_INST_REG_ADDR(0)

#define MUX_MASK	(0x7)
#define MUX_OFFSET	(0)


#define PINMUX_CONFIG(PIN_ID, FUNC_TYPE) \
	sys_write32((sys_read32(PINCTRL_BASE_ADDR + (PIN_ID * 0x4)) & \
		 ~(MUX_MASK << MUX_OFFSET)) | FUNC_TYPE << MUX_OFFSET, \
		PINCTRL_BASE_ADDR + (PIN_ID * 0x4))

static int milkv_duo256m_c906b_pinmux_init(void)
{
	PINMUX_CONFIG(FMUX_REG_PWR_GPIO2, PWR_GPIO2__PWR_GPIO2);
	return 0;
}

SYS_INIT(milkv_duo256m_c906b_pinmux_init, PRE_KERNEL_1,
		CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
