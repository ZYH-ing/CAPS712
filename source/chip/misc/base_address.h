

#ifndef _BASE_ADDRESS_H
#define _BASE_ADDRESS_H

//page0 base address
#define SFR_BA				0x00
#define CLKMU_BA			0x10
#define RSTMU_BA			0x30
#define SYS_BA				0x28
#define EXTI_BA				0x38
#define WDT_BA				0x40
#define WWDT_BA				0x44
#define TM0_BA				0x48
#define GPIO0_BA			0x50
#define SRADC_BA			0x60
#define FMC_BA				0x68
#define TM2_BA				0x70

//page1 base address
#define TM3_BA				0x10
#define UART0_BA			0x20
#define TM4_BA				0x48
#define TEST_BA				0x78

//page4 base address
#define PROG_BA				0x10
#endif
