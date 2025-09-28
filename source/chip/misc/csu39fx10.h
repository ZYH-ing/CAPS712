
#ifndef _CSU39FX10_H
#define _CSU39FX10_H

#include "base_address.h"

extern volatile unsigned char bank0 APToBoot0             @ 0xfe;
extern volatile unsigned char bank0 APToBoot1             @ 0xff;
extern volatile sbit bank0 flag_INT						  @ 0x80*8+0;



//page0 registers
extern volatile unsigned char bank0 IND0		@SFR_BA+ 0x00;
extern volatile unsigned char bank0 IND1		@SFR_BA+ 0x01;
extern volatile unsigned char bank0 FSR0		@SFR_BA+ 0x02;
extern volatile unsigned char bank0 FSR1		@SFR_BA+ 0x03;
extern volatile unsigned char bank0 STATUS		@SFR_BA+ 0x04;
extern volatile unsigned char bank0 WORK		@SFR_BA+ 0x05;
extern volatile unsigned char bank0 INTE		@SFR_BA+ 0x06;
extern volatile unsigned char bank0 BSR			@SFR_BA+ 0x07;
extern volatile unsigned char bank0 FSR0H		@SFR_BA+ 0x08;
extern volatile unsigned char bank0 FSR1H		@SFR_BA+ 0x09;
extern volatile unsigned char bank0 PCLOADL		@SFR_BA+ 0x0A;
extern volatile unsigned char bank0 PCLOADH		@SFR_BA+ 0x0B;
extern volatile unsigned char bank0 INTFL		@SFR_BA+ 0x0C;
extern volatile unsigned char bank0 INTFM		@SFR_BA+ 0x0D;
extern volatile unsigned char bank0 INTFH		@SFR_BA+ 0x0E;

extern volatile unsigned char bank0 MCK			@CLKMU_BA+ 0x00;
extern volatile unsigned char bank0 TCTRIM		@CLKMU_BA+ 0x01;
extern volatile unsigned char bank0 CLKSEL0		@CLKMU_BA+ 0x02;
extern volatile unsigned char bank0 CLKSEL1		@CLKMU_BA+ 0x03;
extern volatile unsigned char bank0 CLKSEL2		@CLKMU_BA+ 0x04;
extern volatile unsigned char bank0 CLKDIV0		@CLKMU_BA+ 0x05;
extern volatile unsigned char bank0 CLKDIV1		@CLKMU_BA+ 0x06;
extern volatile unsigned char bank0 CLKDIV2		@CLKMU_BA+ 0x07;
extern volatile unsigned char bank0 CLKDIV3		@CLKMU_BA+ 0x08;
extern volatile unsigned char bank0 CLKDIV4		@CLKMU_BA+ 0x09;

extern volatile unsigned char bank0 RSTSR		@RSTMU_BA+ 0x00;
extern volatile unsigned char bank0 LVDCON		@RSTMU_BA+ 0x01;

extern volatile unsigned char bank0 CFGR1		@SYS_BA+ 0x00;
extern volatile unsigned char bank0 CFGR2		@SYS_BA+ 0x01;
extern volatile unsigned char bank0 CFGR3		@SYS_BA+ 0x02;
extern volatile unsigned char bank0 CFGR4		@SYS_BA+ 0x03;
extern volatile unsigned char bank0 CFGR5		@SYS_BA+ 0x04;
extern volatile unsigned char bank0 CFGR6		@SYS_BA+ 0x05;
extern volatile unsigned char bank0 CFGR7		@SYS_BA+ 0x06;
extern volatile unsigned char bank0 CFGR8		@SYS_BA+ 0x07;

extern volatile unsigned char bank0 EXICON		@EXTI_BA+ 0x00;
extern volatile unsigned char bank0 EXIIE		@EXTI_BA+ 0x01;
extern volatile unsigned char bank0 EXIIF		@EXTI_BA+ 0x02;
extern volatile unsigned char bank0 INTCFG1		@EXTI_BA+ 0x03;
extern volatile unsigned char bank0 INTCFG2		@EXTI_BA+ 0x04;
extern volatile unsigned char bank0 INTCFG3		@EXTI_BA+ 0x05;

extern volatile unsigned char bank0 WDTCON		@WDT_BA+ 0x00;
extern volatile unsigned char bank0 WDTIN		@WDT_BA+ 0x01;

extern volatile unsigned char bank0 WWDTCR		@WWDT_BA+ 0x00;
extern volatile unsigned char bank0 WWDTWR		@WWDT_BA+ 0x01;

extern volatile unsigned char bank0 TM0CON		@TM0_BA+ 0x00;
extern volatile unsigned char bank0 TM0IN		@TM0_BA+ 0x01;
extern volatile unsigned char bank0 TM0CNT		@TM0_BA+ 0x02;

extern volatile unsigned char bank0 PT1			@GPIO0_BA+ 0x00;
extern volatile unsigned char bank0 PT1EN		@GPIO0_BA+ 0x01;
extern volatile unsigned char bank0 PT1PU		@GPIO0_BA+ 0x02;
extern volatile unsigned char bank0 PT2			@GPIO0_BA+ 0x05;
extern volatile unsigned char bank0 PT2EN		@GPIO0_BA+ 0x06;
extern volatile unsigned char bank0 PT2PU		@GPIO0_BA+ 0x07;
extern volatile unsigned char bank0 PT2OTYPE	@GPIO0_BA+ 0x09;
extern volatile unsigned char bank0 PT3			@GPIO0_BA+ 0x0A;
extern volatile unsigned char bank0 PT3EN		@GPIO0_BA+ 0x0B;
extern volatile unsigned char bank0 PT3PU		@GPIO0_BA+ 0x0C;
extern volatile unsigned char bank0 PTOFFDIN	@GPIO0_BA+ 0x0D;
extern volatile unsigned char bank0 PTSHORT		@GPIO0_BA+ 0x0E;

extern volatile unsigned char bank0 SRADCON0	@SRADC_BA+ 0x00;
extern volatile unsigned char bank0 SRADCON1	@SRADC_BA+ 0x01;
extern volatile unsigned char bank0 SRADCON2	@SRADC_BA+ 0x02;
extern volatile unsigned char bank0 SRADL		@SRADC_BA+ 0x03;
extern volatile unsigned char bank0 SRADH		@SRADC_BA+ 0x04;
extern volatile unsigned char bank0 SROFTL		@SRADC_BA+ 0x05;
extern volatile unsigned char bank0 SROFTH		@SRADC_BA+ 0x06;

extern volatile unsigned char bank0 EADRH		@FMC_BA+ 0x00;
extern volatile unsigned char bank0 EADRL		@FMC_BA+ 0x01;
extern volatile unsigned char bank0 EDATH		@FMC_BA+ 0x02;
extern volatile unsigned char bank0 EDATL		@FMC_BA+ 0x03;
extern volatile unsigned char bank0 ISPCR		@FMC_BA+ 0x04;
extern volatile unsigned char bank0 CMD			@FMC_BA+ 0x05;
extern volatile unsigned char bank0 ISPSR		@FMC_BA+ 0x06;
extern volatile unsigned char bank0 WRPRT		@FMC_BA+ 0x07;

extern volatile unsigned char bank0 TM2CON		@TM2_BA+ 0x00;
extern volatile unsigned char bank0 TM2IN		@TM2_BA+ 0x01;
extern volatile unsigned char bank0 TM2CNT		@TM2_BA+ 0x02;
extern volatile unsigned char bank0 TM2R		@TM2_BA+ 0x03;


//page1 registers
extern volatile unsigned char bank2 TM3CON		@TM3_BA+ 0x00;
extern volatile unsigned char bank2 TM3IN		@TM3_BA+ 0x01;
extern volatile unsigned char bank2 TM3INH		@TM3_BA+ 0x02;
extern volatile unsigned char bank2 TM3CNT		@TM3_BA+ 0x03;
extern volatile unsigned char bank2 TM3CNTH		@TM3_BA+ 0x04;
extern volatile unsigned char bank2 TM3R		@TM3_BA+ 0x05;
extern volatile unsigned char bank2 TM3RH		@TM3_BA+ 0x06;
extern volatile unsigned char bank2 TM3CON2		@TM3_BA+ 0x07;

extern volatile unsigned char bank2 UR0_CR1		@UART0_BA+ 0x00;
extern volatile unsigned char bank2 UR0_BRR0	@UART0_BA+ 0x01;
extern volatile unsigned char bank2 UR0_BRR1	@UART0_BA+ 0x02;
extern volatile unsigned char bank2 UR0_TX_REG	@UART0_BA+ 0x03;
extern volatile unsigned char bank2 UR0_RX_REG	@UART0_BA+ 0x04;
extern volatile unsigned char bank2 UR0_ST		@UART0_BA+ 0x05;
extern volatile unsigned char bank2 UR0_INTF	@UART0_BA+ 0x06;
extern volatile unsigned char bank2 UR0_INTE	@UART0_BA+ 0x07;

extern volatile unsigned char bank2 TM4CON		@TM4_BA+ 0x00;
extern volatile unsigned char bank2 TM4IN		@TM4_BA+ 0x01;
extern volatile unsigned char bank2 TM4INH		@TM4_BA+ 0x02;
extern volatile unsigned char bank2 TM4CNT		@TM4_BA+ 0x03;
extern volatile unsigned char bank2 TM4CNTH		@TM4_BA+ 0x04;
extern volatile unsigned char bank2 TM4R		@TM4_BA+ 0x05;
extern volatile unsigned char bank2 TM4RH		@TM4_BA+ 0x06;

extern volatile unsigned char bank2 TESTOP		@TEST_BA+ 0x00;
extern volatile unsigned char bank2 TEST		@TEST_BA+ 0x01;


//page4 registers
extern volatile unsigned char bank8 CHIP_ID0L	@PROG_BA+ 0x00;
extern volatile unsigned char bank8 CHIP_ID0H	@PROG_BA+ 0x01;
extern volatile unsigned char bank8 CHIP_ID1L	@PROG_BA+ 0x02;
extern volatile unsigned char bank8 CHIP_ID1H	@PROG_BA+ 0x03;
extern volatile unsigned char bank8 SFR_WK		@PROG_BA+ 0x04;
extern volatile unsigned char bank8 MM_WK		@PROG_BA+ 0x05;
extern volatile unsigned char bank8 UOB_WK		@PROG_BA+ 0x06;
extern volatile unsigned char bank8 POB_WK		@PROG_BA+ 0x07;
extern volatile unsigned char bank8 MP_WK		@PROG_BA+ 0x08;
extern volatile unsigned char bank8 CAL_SELECT	@PROG_BA+ 0x09;
extern volatile unsigned char bank8 TRIMREF		@PROG_BA+ 0x0a;
extern volatile unsigned char bank8 TRIMWDT		@PROG_BA+ 0x0b;
extern volatile unsigned char bank8 TRIMHIRC	@PROG_BA+ 0x0c;
extern volatile unsigned char bank8 OSC_DIV		@PROG_BA+ 0x0d;
extern volatile unsigned char bank8 SR			@PROG_BA+ 0x0e;
extern volatile unsigned char bank8 VCHK_SUM	@PROG_BA+ 0x0f;
extern volatile unsigned char bank8 TRIMLIMIT	@PROG_BA+ 0x10;
extern volatile unsigned char bank8 SR2			@PROG_BA+ 0x11;
extern volatile unsigned char bank8 TRAMGAP		@PROG_BA+ 0x12;




//page0 bits define

//reg: STATUS
extern volatile sbit bank0 Z					@(SFR_BA+ 0x04)* 8+ 0;
extern volatile sbit bank0 C					@(SFR_BA+ 0x04)* 8+ 1;
extern volatile sbit bank0 DC					@(SFR_BA+ 0x04)* 8+ 2;
extern volatile sbit bank0 TO					@(SFR_BA+ 0x04)* 8+ 3;
extern volatile sbit bank0 PD					@(SFR_BA+ 0x04)* 8+ 4;
extern volatile sbit bank0 SOF					@(SFR_BA+ 0x04)* 8+ 5;

//reg: INTE
extern volatile sbit bank0 GIE					@(SFR_BA+ 0x06)* 8+ 7;

//reg: BSR
extern volatile sbit bank0 PAGE_0				@(SFR_BA+ 0x07)* 8+ 0;
extern volatile sbit bank0 PAGE_1				@(SFR_BA+ 0x07)* 8+ 1;
extern volatile sbit bank0 PAGE_2				@(SFR_BA+ 0x07)* 8+ 2;

//reg: PCLOADL
extern volatile sbit bank0 PCLOAD_0				@(SFR_BA+ 0x0A)* 8+ 0;
extern volatile sbit bank0 PCLOAD_1				@(SFR_BA+ 0x0A)* 8+ 1;
extern volatile sbit bank0 PCLOAD_2				@(SFR_BA+ 0x0A)* 8+ 2;
extern volatile sbit bank0 PCLOAD_3				@(SFR_BA+ 0x0A)* 8+ 3;
extern volatile sbit bank0 PCLOAD_4				@(SFR_BA+ 0x0A)* 8+ 4;
extern volatile sbit bank0 PCLOAD_5				@(SFR_BA+ 0x0A)* 8+ 5;
extern volatile sbit bank0 PCLOAD_6				@(SFR_BA+ 0x0A)* 8+ 6;
extern volatile sbit bank0 PCLOAD_7				@(SFR_BA+ 0x0A)* 8+ 7;

//reg: PCLOADH
extern volatile sbit bank0 PCLOAD_8				@(SFR_BA+ 0x0B)* 8+ 0;
extern volatile sbit bank0 PCLOAD_9				@(SFR_BA+ 0x0B)* 8+ 1;
extern volatile sbit bank0 PCLOAD_10			@(SFR_BA+ 0x0B)* 8+ 2;
extern volatile sbit bank0 PCLOAD_11			@(SFR_BA+ 0x0B)* 8+ 3;
extern volatile sbit bank0 PCLOAD_12			@(SFR_BA+ 0x0B)* 8+ 4;
extern volatile sbit bank0 PCLOAD_13			@(SFR_BA+ 0x0B)* 8+ 5;

//reg: MCK
extern volatile sbit bank0 SYSCLK_S_0			@(CLKMU_BA+ 0x00)* 8+ 0;
extern volatile sbit bank0 SYSCLK_S_1			@(CLKMU_BA+ 0x00)* 8+ 1;
extern volatile sbit bank0 XT_GM_0				@(CLKMU_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 XT_GM_1				@(CLKMU_BA+ 0x00)* 8+ 3;
extern volatile sbit bank0 XT_GM_2				@(CLKMU_BA+ 0x00)* 8+ 4;
extern volatile sbit bank0 CST_WDT				@(CLKMU_BA+ 0x00)* 8+ 5;
extern volatile sbit bank0 CST_IN				@(CLKMU_BA+ 0x00)* 8+ 6;
extern volatile sbit bank0 CST_XT				@(CLKMU_BA+ 0x00)* 8+ 7;

//reg: TCTRIM
extern volatile sbit bank0 TC_TRIM0				@(CLKMU_BA+ 0x01)* 8+ 0;
extern volatile sbit bank0 TC_TRIM1				@(CLKMU_BA+ 0x01)* 8+ 1;
extern volatile sbit bank0 TC_TRIM2				@(CLKMU_BA+ 0x01)* 8+ 2;

//reg: CLKSEL0
extern volatile sbit bank0 T0CKS_0				@(CLKMU_BA+ 0x02)* 8+ 0;
extern volatile sbit bank0 T0CKS_1				@(CLKMU_BA+ 0x02)* 8+ 1;
extern volatile sbit bank0 T2CKS_0				@(CLKMU_BA+ 0x02)* 8+ 4;
extern volatile sbit bank0 T2CKS_1				@(CLKMU_BA+ 0x02)* 8+ 5;
extern volatile sbit bank0 T3CKS_0				@(CLKMU_BA+ 0x02)* 8+ 6;
extern volatile sbit bank0 T3CKS_1				@(CLKMU_BA+ 0x02)* 8+ 7;

//reg: CLKSEL1
extern volatile sbit bank0 URTCKS_0				@(CLKMU_BA+ 0x03)* 8+ 2;
extern volatile sbit bank0 URTCKS_1				@(CLKMU_BA+ 0x03)* 8+ 3;

//reg: CLKSEL2
extern volatile sbit bank0 T4CKS_0				@(CLKMU_BA+ 0x04)* 8+ 0;
extern volatile sbit bank0 T4CKS_1				@(CLKMU_BA+ 0x04)* 8+ 1;
extern volatile sbit bank0 TYPCS_0				@(CLKMU_BA+ 0x04)* 8+ 2;
extern volatile sbit bank0 TYPCS_1				@(CLKMU_BA+ 0x04)* 8+ 3;
extern volatile sbit bank0 PDS_0				@(CLKMU_BA+ 0x04)* 8+ 4;
extern volatile sbit bank0 PDS_1				@(CLKMU_BA+ 0x04)* 8+ 5;

//reg: CLKDIV0
extern volatile sbit bank0 T0DIV_0				@(CLKMU_BA+ 0x05)* 8+ 0;
extern volatile sbit bank0 T0DIV_1				@(CLKMU_BA+ 0x05)* 8+ 1;
extern volatile sbit bank0 T0DIV_2				@(CLKMU_BA+ 0x05)* 8+ 2;

//reg: CLKDIV1
extern volatile sbit bank0 T2DIV_0				@(CLKMU_BA+ 0x06)* 8+ 0;
extern volatile sbit bank0 T2DIV_1				@(CLKMU_BA+ 0x06)* 8+ 1;
extern volatile sbit bank0 T2DIV_2				@(CLKMU_BA+ 0x06)* 8+ 2;
extern volatile sbit bank0 T3DIV_0				@(CLKMU_BA+ 0x06)* 8+ 4;
extern volatile sbit bank0 T3DIV_1				@(CLKMU_BA+ 0x06)* 8+ 5;
extern volatile sbit bank0 T3DIV_2				@(CLKMU_BA+ 0x06)* 8+ 6;

//reg: CLKDIV2
extern volatile sbit bank0 URTDIV_0				@(CLKMU_BA+ 0x07)* 8+ 4;
extern volatile sbit bank0 URTDIV_1				@(CLKMU_BA+ 0x07)* 8+ 5;
extern volatile sbit bank0 URTDIV_2				@(CLKMU_BA+ 0x07)* 8+ 6;

//reg: CLKDIV3
extern volatile sbit bank0 SRADCKS_0			@(CLKMU_BA+ 0x08)* 8+ 0;
extern volatile sbit bank0 SRADCKS_1			@(CLKMU_BA+ 0x08)* 8+ 1;
extern volatile sbit bank0 T4DIV_0				@(CLKMU_BA+ 0x08)* 8+ 4;
extern volatile sbit bank0 T4DIV_1				@(CLKMU_BA+ 0x08)* 8+ 5;
extern volatile sbit bank0 T4DIV_2				@(CLKMU_BA+ 0x08)* 8+ 6;

//reg: CLKDIV4
extern volatile sbit bank0 SCPDIV_0				@(CLKMU_BA+ 0x09)* 8+ 0;
extern volatile sbit bank0 SCPDIV_1				@(CLKMU_BA+ 0x09)* 8+ 1;

//reg: RSTSR
extern volatile sbit bank0 WWDTF				@(RSTMU_BA+ 0x00)* 8+ 0;
extern volatile sbit bank0 ILOPF				@(RSTMU_BA+ 0x00)* 8+ 1;
extern volatile sbit bank0 EMCF					@(RSTMU_BA+ 0x00)* 8+ 2;

//reg: LVDCON
extern volatile sbit bank0 LVDF					@(RSTMU_BA+ 0x01)* 8+ 3;
extern volatile sbit bank0 LVDEN				@(RSTMU_BA+ 0x01)* 8+ 4;

//reg: CFGR1
extern volatile sbit bank0 PT33FUNC_2			@(SYS_BA+ 0x00)* 8+ 0;
extern volatile sbit bank0 PT34FUNC_2			@(SYS_BA+ 0x00)* 8+ 1;
extern volatile sbit bank0 TMP_MEAS_EN			@(SYS_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 DIG_METCH_0			@(SYS_BA+ 0x00)* 8+ 3;
extern volatile sbit bank0 DIG_METCH_1			@(SYS_BA+ 0x00)* 8+ 4;
extern volatile sbit bank0 DIG_METCH_2			@(SYS_BA+ 0x00)* 8+ 5;
extern volatile sbit bank0 DIG_METCH_3			@(SYS_BA+ 0x00)* 8+ 6;
extern volatile sbit bank0 VTHSEL				@(SYS_BA+ 0x00)* 8+ 7;

//reg: CFGR2
extern volatile sbit bank0 PT10FUNC_0			@(SYS_BA+ 0x01)* 8+ 0;
extern volatile sbit bank0 PT10FUNC_1			@(SYS_BA+ 0x01)* 8+ 1;
extern volatile sbit bank0 PT11FUNC_0			@(SYS_BA+ 0x01)* 8+ 2;
extern volatile sbit bank0 PT11FUNC_1			@(SYS_BA+ 0x01)* 8+ 3;
extern volatile sbit bank0 PT12FUNC_0			@(SYS_BA+ 0x01)* 8+ 4;
extern volatile sbit bank0 PT12FUNC_1			@(SYS_BA+ 0x01)* 8+ 5;
extern volatile sbit bank0 PT13FUNC_0			@(SYS_BA+ 0x01)* 8+ 6;
extern volatile sbit bank0 PT13FUNC_1			@(SYS_BA+ 0x01)* 8+ 7;

//reg: CFGR3
extern volatile sbit bank0 PT14FUNC_0			@(SYS_BA+ 0x02)* 8+ 0;
extern volatile sbit bank0 PT14FUNC_1			@(SYS_BA+ 0x02)* 8+ 1;
extern volatile sbit bank0 PT15FUNC_0			@(SYS_BA+ 0x02)* 8+ 2;
extern volatile sbit bank0 PT15FUNC_1			@(SYS_BA+ 0x02)* 8+ 3;
extern volatile sbit bank0 PT16FUNC_0			@(SYS_BA+ 0x02)* 8+ 4;
extern volatile sbit bank0 PT16FUNC_1			@(SYS_BA+ 0x02)* 8+ 5;
extern volatile sbit bank0 PT17FUNC_0			@(SYS_BA+ 0x02)* 8+ 6;
extern volatile sbit bank0 PT17FUNC_1			@(SYS_BA+ 0x02)* 8+ 7;

//reg: CFGR4
extern volatile sbit bank0 PT20FUNC_0			@(SYS_BA+ 0x03)* 8+ 0;
extern volatile sbit bank0 PT20FUNC_1			@(SYS_BA+ 0x03)* 8+ 1;
extern volatile sbit bank0 PT21FUNC_0			@(SYS_BA+ 0x03)* 8+ 2;
extern volatile sbit bank0 PT21FUNC_1			@(SYS_BA+ 0x03)* 8+ 3;
extern volatile sbit bank0 PT22FUNC_0			@(SYS_BA+ 0x03)* 8+ 4;
extern volatile sbit bank0 PT22FUNC_1			@(SYS_BA+ 0x03)* 8+ 5;
extern volatile sbit bank0 PT23FUNC_0			@(SYS_BA+ 0x03)* 8+ 6;
extern volatile sbit bank0 PT23FUNC_1			@(SYS_BA+ 0x03)* 8+ 7;

//reg: CFGR5
extern volatile sbit bank0 PT24FUNC_0			@(SYS_BA+ 0x04)* 8+ 0;
extern volatile sbit bank0 PT24FUNC_1			@(SYS_BA+ 0x04)* 8+ 1;
extern volatile sbit bank0 PT25FUNC_0			@(SYS_BA+ 0x04)* 8+ 2;
extern volatile sbit bank0 PT25FUNC_1			@(SYS_BA+ 0x04)* 8+ 3;
extern volatile sbit bank0 PT26FUNC_0			@(SYS_BA+ 0x04)* 8+ 4;
extern volatile sbit bank0 PT26FUNC_1			@(SYS_BA+ 0x04)* 8+ 5;

//reg: CFGR6
extern volatile sbit bank0 PT30FUNC_0			@(SYS_BA+ 0x05)* 8+ 0;
extern volatile sbit bank0 PT30FUNC_1			@(SYS_BA+ 0x05)* 8+ 1;
extern volatile sbit bank0 PT31FUNC_0			@(SYS_BA+ 0x05)* 8+ 2;
extern volatile sbit bank0 PT31FUNC_1			@(SYS_BA+ 0x05)* 8+ 3;
extern volatile sbit bank0 PT32FUNC_0			@(SYS_BA+ 0x05)* 8+ 4;
extern volatile sbit bank0 PT32FUNC_1			@(SYS_BA+ 0x05)* 8+ 5;
extern volatile sbit bank0 PT33FUNC_0			@(SYS_BA+ 0x05)* 8+ 6;
extern volatile sbit bank0 PT33FUNC_1			@(SYS_BA+ 0x05)* 8+ 7;

//reg: CFGR7
extern volatile sbit bank0 PT34FUNC_0			@(SYS_BA+ 0x06)* 8+ 0;
extern volatile sbit bank0 PT34FUNC_1			@(SYS_BA+ 0x06)* 8+ 1;
extern volatile sbit bank0 PT35FUNC_0			@(SYS_BA+ 0x06)* 8+ 2;
extern volatile sbit bank0 PT35FUNC_1			@(SYS_BA+ 0x06)* 8+ 3;
extern volatile sbit bank0 PT36FUNC_0			@(SYS_BA+ 0x06)* 8+ 4;
extern volatile sbit bank0 PT36FUNC_1			@(SYS_BA+ 0x06)* 8+ 5;
extern volatile sbit bank0 PT37FUNC_0			@(SYS_BA+ 0x06)* 8+ 6;
extern volatile sbit bank0 PT37FUNC_1			@(SYS_BA+ 0x06)* 8+ 7;

//reg: CFGR8
extern volatile sbit bank0 CMP0VRS_0			@(SYS_BA+ 0x07)* 8+ 0;
extern volatile sbit bank0 CMP0VRS_1			@(SYS_BA+ 0x07)* 8+ 1;
extern volatile sbit bank0 CMP0VRS_2			@(SYS_BA+ 0x07)* 8+ 2;
extern volatile sbit bank0 CMP0VRS_3			@(SYS_BA+ 0x07)* 8+ 3;
extern volatile sbit bank0 CMP1VRS_0			@(SYS_BA+ 0x07)* 8+ 4;
extern volatile sbit bank0 CMP1VRS_1			@(SYS_BA+ 0x07)* 8+ 5;
extern volatile sbit bank0 CMP1VRS_2			@(SYS_BA+ 0x07)* 8+ 6;
extern volatile sbit bank0 CMPVR_EN				@(SYS_BA+ 0x07)* 8+ 7;

//reg: EXICON
extern volatile sbit bank0 E0M_0				@(EXTI_BA+ 0x00)* 8+ 0;
extern volatile sbit bank0 E0M_1				@(EXTI_BA+ 0x00)* 8+ 1;
extern volatile sbit bank0 E1M_0				@(EXTI_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 E1M_1				@(EXTI_BA+ 0x00)* 8+ 3;
extern volatile sbit bank0 E2M_0				@(EXTI_BA+ 0x00)* 8+ 4;
extern volatile sbit bank0 E2M_1				@(EXTI_BA+ 0x00)* 8+ 5;

//reg: EXIIE
extern volatile sbit bank0 E0IE					@(EXTI_BA+ 0x01)* 8+ 0;
extern volatile sbit bank0 E1IE					@(EXTI_BA+ 0x01)* 8+ 1;
extern volatile sbit bank0 E2IE					@(EXTI_BA+ 0x01)* 8+ 2;

//reg: EXIIF
extern volatile sbit bank0 E0IF					@(EXTI_BA+ 0x02)* 8+ 0;
extern volatile sbit bank0 E1IF					@(EXTI_BA+ 0x02)* 8+ 1;
extern volatile sbit bank0 E2IF					@(EXTI_BA+ 0x02)* 8+ 2;

//reg: INTCFG1
extern volatile sbit bank0 PT1INT0				@(EXTI_BA+ 0x03)* 8+ 2;
extern volatile sbit bank0 PT1INT1				@(EXTI_BA+ 0x03)* 8+ 3;
extern volatile sbit bank0 PT1INT2				@(EXTI_BA+ 0x03)* 8+ 4;
extern volatile sbit bank0 PT1INT3				@(EXTI_BA+ 0x03)* 8+ 5;

//reg: INTCFG2
extern volatile sbit bank0 PT2INT0				@(EXTI_BA+ 0x04)* 8+ 2;
extern volatile sbit bank0 PT2INT1				@(EXTI_BA+ 0x04)* 8+ 3;
extern volatile sbit bank0 PT2INT2				@(EXTI_BA+ 0x04)* 8+ 4;
extern volatile sbit bank0 PT2INT3				@(EXTI_BA+ 0x04)* 8+ 5;
extern volatile sbit bank0 PT2INT4				@(EXTI_BA+ 0x04)* 8+ 6;

//reg: INTCFG3
extern volatile sbit bank0 PT3INT0				@(EXTI_BA+ 0x05)* 8+ 1;
extern volatile sbit bank0 PT3INT1				@(EXTI_BA+ 0x05)* 8+ 2;
extern volatile sbit bank0 PT3INT2				@(EXTI_BA+ 0x05)* 8+ 3;
extern volatile sbit bank0 PT3INT3				@(EXTI_BA+ 0x05)* 8+ 4;
extern volatile sbit bank0 PT3INT4				@(EXTI_BA+ 0x05)* 8+ 5;
extern volatile sbit bank0 PT3INT5				@(EXTI_BA+ 0x05)* 8+ 6;

//reg: WDTCON
extern volatile sbit bank0 WDTS_0				@(WDT_BA+ 0x00)* 8+ 0;
extern volatile sbit bank0 WDTS_1				@(WDT_BA+ 0x00)* 8+ 1;
extern volatile sbit bank0 WDTS_2				@(WDT_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 WDTEN				@(WDT_BA+ 0x00)* 8+ 7;

//reg: WDTIN
extern volatile sbit bank0 WDTIN_0				@(WDT_BA+ 0x01)* 8+ 0;
extern volatile sbit bank0 WDTIN_1				@(WDT_BA+ 0x01)* 8+ 1;
extern volatile sbit bank0 WDTIN_2				@(WDT_BA+ 0x01)* 8+ 2;
extern volatile sbit bank0 WDTIN_3				@(WDT_BA+ 0x01)* 8+ 3;
extern volatile sbit bank0 WDTIN_4				@(WDT_BA+ 0x01)* 8+ 4;
extern volatile sbit bank0 WDTIN_5				@(WDT_BA+ 0x01)* 8+ 5;
extern volatile sbit bank0 WDTIN_6				@(WDT_BA+ 0x01)* 8+ 6;
extern volatile sbit bank0 WDTIN_7				@(WDT_BA+ 0x01)* 8+ 7;

//reg: TM0CON
extern volatile sbit bank0 T0RSTB				@(TM0_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 TM0IE				@(TM0_BA+ 0x00)* 8+ 5;
extern volatile sbit bank0 TM0IF				@(TM0_BA+ 0x00)* 8+ 6;
extern volatile sbit bank0 T0EN					@(TM0_BA+ 0x00)* 8+ 7;

//reg: TM0IN
extern volatile sbit bank0 TM0IN_0				@(TM0_BA+ 0x01)* 8+ 0;
extern volatile sbit bank0 TM0IN_1				@(TM0_BA+ 0x01)* 8+ 1;
extern volatile sbit bank0 TM0IN_2				@(TM0_BA+ 0x01)* 8+ 2;
extern volatile sbit bank0 TM0IN_3				@(TM0_BA+ 0x01)* 8+ 3;
extern volatile sbit bank0 TM0IN_4				@(TM0_BA+ 0x01)* 8+ 4;
extern volatile sbit bank0 TM0IN_5				@(TM0_BA+ 0x01)* 8+ 5;
extern volatile sbit bank0 TM0IN_6				@(TM0_BA+ 0x01)* 8+ 6;
extern volatile sbit bank0 TM0IN_7				@(TM0_BA+ 0x01)* 8+ 7;

//reg: TM0CNT
extern volatile sbit bank0 TM0CNT_0				@(TM0_BA+ 0x02)* 8+ 0;
extern volatile sbit bank0 TM0CNT_1				@(TM0_BA+ 0x02)* 8+ 1;
extern volatile sbit bank0 TM0CNT_2				@(TM0_BA+ 0x02)* 8+ 2;
extern volatile sbit bank0 TM0CNT_3				@(TM0_BA+ 0x02)* 8+ 3;
extern volatile sbit bank0 TM0CNT_4				@(TM0_BA+ 0x02)* 8+ 4;
extern volatile sbit bank0 TM0CNT_5				@(TM0_BA+ 0x02)* 8+ 5;
extern volatile sbit bank0 TM0CNT_6				@(TM0_BA+ 0x02)* 8+ 6;
extern volatile sbit bank0 TM0CNT_7				@(TM0_BA+ 0x02)* 8+ 7;

//reg: PT1
extern volatile sbit bank0 PT10					@(GPIO0_BA+ 0x00)* 8+ 0;
extern volatile sbit bank0 PT11					@(GPIO0_BA+ 0x00)* 8+ 1;
extern volatile sbit bank0 PT12					@(GPIO0_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 PT13					@(GPIO0_BA+ 0x00)* 8+ 3;
extern volatile sbit bank0 PT14					@(GPIO0_BA+ 0x00)* 8+ 4;
extern volatile sbit bank0 PT15					@(GPIO0_BA+ 0x00)* 8+ 5;
extern volatile sbit bank0 PT16					@(GPIO0_BA+ 0x00)* 8+ 6;
extern volatile sbit bank0 PT17					@(GPIO0_BA+ 0x00)* 8+ 7;

//reg: PT1EN
extern volatile sbit bank0 PT1EN0				@(GPIO0_BA+ 0x01)* 8+ 0;
extern volatile sbit bank0 PT1EN1				@(GPIO0_BA+ 0x01)* 8+ 1;
extern volatile sbit bank0 PT1EN2				@(GPIO0_BA+ 0x01)* 8+ 2;
extern volatile sbit bank0 PT1EN3				@(GPIO0_BA+ 0x01)* 8+ 3;
extern volatile sbit bank0 PT1EN4				@(GPIO0_BA+ 0x01)* 8+ 4;
extern volatile sbit bank0 PT1EN5				@(GPIO0_BA+ 0x01)* 8+ 5;
extern volatile sbit bank0 PT1EN6				@(GPIO0_BA+ 0x01)* 8+ 6;
extern volatile sbit bank0 PT1EN7				@(GPIO0_BA+ 0x01)* 8+ 7;

//reg: PT1PU
extern volatile sbit bank0 PT1PU0				@(GPIO0_BA+ 0x02)* 8+ 0;
extern volatile sbit bank0 PT1PU1				@(GPIO0_BA+ 0x02)* 8+ 1;
extern volatile sbit bank0 PT1PU2				@(GPIO0_BA+ 0x02)* 8+ 2;
extern volatile sbit bank0 PT1PU3				@(GPIO0_BA+ 0x02)* 8+ 3;
extern volatile sbit bank0 PT1PU4				@(GPIO0_BA+ 0x02)* 8+ 4;
extern volatile sbit bank0 PT1PU5				@(GPIO0_BA+ 0x02)* 8+ 5;
extern volatile sbit bank0 PT1PU6				@(GPIO0_BA+ 0x02)* 8+ 6;
extern volatile sbit bank0 PT1PU7				@(GPIO0_BA+ 0x02)* 8+ 7;

//reg: PT2
extern volatile sbit bank0 PT20					@(GPIO0_BA+ 0x05)* 8+ 0;
extern volatile sbit bank0 PT21					@(GPIO0_BA+ 0x05)* 8+ 1;
extern volatile sbit bank0 PT22					@(GPIO0_BA+ 0x05)* 8+ 2;
extern volatile sbit bank0 PT23					@(GPIO0_BA+ 0x05)* 8+ 3;
extern volatile sbit bank0 PT24					@(GPIO0_BA+ 0x05)* 8+ 4;
extern volatile sbit bank0 PT25					@(GPIO0_BA+ 0x05)* 8+ 5;
extern volatile sbit bank0 PT26					@(GPIO0_BA+ 0x05)* 8+ 6;

//reg: PT2EN
extern volatile sbit bank0 PT2EN0				@(GPIO0_BA+ 0x06)* 8+ 0;
extern volatile sbit bank0 PT2EN1				@(GPIO0_BA+ 0x06)* 8+ 1;
extern volatile sbit bank0 PT2EN2				@(GPIO0_BA+ 0x06)* 8+ 2;
extern volatile sbit bank0 PT2EN3				@(GPIO0_BA+ 0x06)* 8+ 3;
extern volatile sbit bank0 PT2EN4				@(GPIO0_BA+ 0x06)* 8+ 4;
extern volatile sbit bank0 PT2EN5				@(GPIO0_BA+ 0x06)* 8+ 5;
extern volatile sbit bank0 PT2EN6				@(GPIO0_BA+ 0x06)* 8+ 6;

//reg: PT2PU
extern volatile sbit bank0 PT2PU0				@(GPIO0_BA+ 0x07)* 8+ 0;
extern volatile sbit bank0 PT2PU1				@(GPIO0_BA+ 0x07)* 8+ 1;
extern volatile sbit bank0 PT2PU2				@(GPIO0_BA+ 0x07)* 8+ 2;
extern volatile sbit bank0 PT2PU3				@(GPIO0_BA+ 0x07)* 8+ 3;
extern volatile sbit bank0 PT2PU4				@(GPIO0_BA+ 0x07)* 8+ 4;
extern volatile sbit bank0 PT2PU5				@(GPIO0_BA+ 0x07)* 8+ 5;
extern volatile sbit bank0 PT2PU6				@(GPIO0_BA+ 0x07)* 8+ 6;

//reg: PT2OTYPE
extern volatile sbit bank0 PT2OTYPE0			@(GPIO0_BA+ 0x09)* 8+ 0;
extern volatile sbit bank0 PT2OTYPE1			@(GPIO0_BA+ 0x09)* 8+ 1;

//reg: PT3
extern volatile sbit bank0 PT30					@(GPIO0_BA+ 0x0A)* 8+ 0;
extern volatile sbit bank0 PT31					@(GPIO0_BA+ 0x0A)* 8+ 1;
extern volatile sbit bank0 PT32					@(GPIO0_BA+ 0x0A)* 8+ 2;
extern volatile sbit bank0 PT33					@(GPIO0_BA+ 0x0A)* 8+ 3;
extern volatile sbit bank0 PT34					@(GPIO0_BA+ 0x0A)* 8+ 4;
extern volatile sbit bank0 PT35					@(GPIO0_BA+ 0x0A)* 8+ 5;
extern volatile sbit bank0 PT36					@(GPIO0_BA+ 0x0A)* 8+ 6;
extern volatile sbit bank0 PT37					@(GPIO0_BA+ 0x0A)* 8+ 7;

//reg: PT3EN
extern volatile sbit bank0 PT3EN0				@(GPIO0_BA+ 0x0B)* 8+ 0;
extern volatile sbit bank0 PT3EN1				@(GPIO0_BA+ 0x0B)* 8+ 1;
extern volatile sbit bank0 PT3EN2				@(GPIO0_BA+ 0x0B)* 8+ 2;
extern volatile sbit bank0 PT3EN3				@(GPIO0_BA+ 0x0B)* 8+ 3;
extern volatile sbit bank0 PT3EN4				@(GPIO0_BA+ 0x0B)* 8+ 4;
extern volatile sbit bank0 PT3EN5				@(GPIO0_BA+ 0x0B)* 8+ 5;
extern volatile sbit bank0 PT3EN6				@(GPIO0_BA+ 0x0B)* 8+ 6;
extern volatile sbit bank0 PT3EN7				@(GPIO0_BA+ 0x0B)* 8+ 7;

//reg: PT3PU
extern volatile sbit bank0 PT3PU0				@(GPIO0_BA+ 0x0C)* 8+ 0;
extern volatile sbit bank0 PT3PU1				@(GPIO0_BA+ 0x0C)* 8+ 1;
extern volatile sbit bank0 PT3PU2				@(GPIO0_BA+ 0x0C)* 8+ 2;
extern volatile sbit bank0 PT3PU3				@(GPIO0_BA+ 0x0C)* 8+ 3;
extern volatile sbit bank0 PT3PU4				@(GPIO0_BA+ 0x0C)* 8+ 4;
extern volatile sbit bank0 PT3PU5				@(GPIO0_BA+ 0x0C)* 8+ 5;
extern volatile sbit bank0 PT3PU6				@(GPIO0_BA+ 0x0C)* 8+ 6;
extern volatile sbit bank0 PT3PU7				@(GPIO0_BA+ 0x0C)* 8+ 7;

//reg: PTOFFDIN
extern volatile sbit bank0 PT3OFFDIN_1			@(GPIO0_BA+ 0x0D)* 8+ 0;
extern volatile sbit bank0 PT3OFFDIN_2			@(GPIO0_BA+ 0x0D)* 8+ 1;
extern volatile sbit bank0 PT3OFFDIN_3			@(GPIO0_BA+ 0x0D)* 8+ 2;
extern volatile sbit bank0 PT3OFFDIN_4			@(GPIO0_BA+ 0x0D)* 8+ 3;
extern volatile sbit bank0 PT3OFFDIN_5			@(GPIO0_BA+ 0x0D)* 8+ 4;
extern volatile sbit bank0 PT3OFFDIN_6			@(GPIO0_BA+ 0x0D)* 8+ 5;
extern volatile sbit bank0 PT2OFFDIN_3			@(GPIO0_BA+ 0x0D)* 8+ 6;
extern volatile sbit bank0 PT2OFFDIN_4			@(GPIO0_BA+ 0x0D)* 8+ 7;

//reg: PTSHORT
extern volatile sbit bank0 SHORT_3730			@(GPIO0_BA+ 0x0E)* 8+ 0;
extern volatile sbit bank0 SHORT_2225			@(GPIO0_BA+ 0x0E)* 8+ 1;
extern volatile sbit bank0 SHORT_2124			@(GPIO0_BA+ 0x0E)* 8+ 2;
extern volatile sbit bank0 SHORT_2023			@(GPIO0_BA+ 0x0E)* 8+ 3;

//reg: SRADCON0
extern volatile sbit bank0 SAR_DIFFEN			@(SRADC_BA+ 0x00)* 8+ 0;
extern volatile sbit bank0 SRADIE				@(SRADC_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 SRADIF				@(SRADC_BA+ 0x00)* 8+ 3;
extern volatile sbit bank0 SRADACKS_0			@(SRADC_BA+ 0x00)* 8+ 4;
extern volatile sbit bank0 SRADACKS_1			@(SRADC_BA+ 0x00)* 8+ 5;

//reg: SRADCON1
extern volatile sbit bank0 OFFEX				@(SRADC_BA+ 0x01)* 8+ 2;
extern volatile sbit bank0 ENOV					@(SRADC_BA+ 0x01)* 8+ 3;
extern volatile sbit bank0 CALIF				@(SRADC_BA+ 0x01)* 8+ 4;
extern volatile sbit bank0 OFTEN				@(SRADC_BA+ 0x01)* 8+ 5;
extern volatile sbit bank0 SRADS				@(SRADC_BA+ 0x01)* 8+ 6;
extern volatile sbit bank0 SRADEN				@(SRADC_BA+ 0x01)* 8+ 7;

//reg: SRADCON2
extern volatile sbit bank0 VREFS_0				@(SRADC_BA+ 0x02)* 8+ 0;
extern volatile sbit bank0 VREFS_1				@(SRADC_BA+ 0x02)* 8+ 1;
extern volatile sbit bank0 VREFS_2				@(SRADC_BA+ 0x02)* 8+ 2;
extern volatile sbit bank0 CHS_0				@(SRADC_BA+ 0x02)* 8+ 3;
extern volatile sbit bank0 CHS_1				@(SRADC_BA+ 0x02)* 8+ 4;
extern volatile sbit bank0 CHS_2				@(SRADC_BA+ 0x02)* 8+ 5;
extern volatile sbit bank0 CHS_3				@(SRADC_BA+ 0x02)* 8+ 6;
extern volatile sbit bank0 CHS_4				@(SRADC_BA+ 0x02)* 8+ 7;

//reg: SRADL
extern volatile sbit bank0 SRAD_0				@(SRADC_BA+ 0x03)* 8+ 0;
extern volatile sbit bank0 SRAD_1				@(SRADC_BA+ 0x03)* 8+ 1;
extern volatile sbit bank0 SRAD_2				@(SRADC_BA+ 0x03)* 8+ 2;
extern volatile sbit bank0 SRAD_3				@(SRADC_BA+ 0x03)* 8+ 3;
extern volatile sbit bank0 SRAD_4				@(SRADC_BA+ 0x03)* 8+ 4;
extern volatile sbit bank0 SRAD_5				@(SRADC_BA+ 0x03)* 8+ 5;
extern volatile sbit bank0 SRAD_6				@(SRADC_BA+ 0x03)* 8+ 6;
extern volatile sbit bank0 SRAD_7				@(SRADC_BA+ 0x03)* 8+ 7;

//reg: SRADH
extern volatile sbit bank0 SRAD_8				@(SRADC_BA+ 0x04)* 8+ 0;
extern volatile sbit bank0 SRAD_9				@(SRADC_BA+ 0x04)* 8+ 1;
extern volatile sbit bank0 SRAD_10				@(SRADC_BA+ 0x04)* 8+ 2;
extern volatile sbit bank0 SRAD_11				@(SRADC_BA+ 0x04)* 8+ 3;

//reg: SRADL
extern volatile sbit bank0 SROFT_0				@(SRADC_BA+ 0x05)* 8+ 0;
extern volatile sbit bank0 SROFT_1				@(SRADC_BA+ 0x05)* 8+ 1;
extern volatile sbit bank0 SROFT_2				@(SRADC_BA+ 0x05)* 8+ 2;
extern volatile sbit bank0 SROFT_3				@(SRADC_BA+ 0x05)* 8+ 3;
extern volatile sbit bank0 SROFT_4				@(SRADC_BA+ 0x05)* 8+ 4;
extern volatile sbit bank0 SROFT_5				@(SRADC_BA+ 0x05)* 8+ 5;
extern volatile sbit bank0 SROFT_6				@(SRADC_BA+ 0x05)* 8+ 6;
extern volatile sbit bank0 SROFT_7				@(SRADC_BA+ 0x05)* 8+ 7;

//reg: SRADH
extern volatile sbit bank0 SROFT_8				@(SRADC_BA+ 0x06)* 8+ 0;
extern volatile sbit bank0 SROFT_9				@(SRADC_BA+ 0x06)* 8+ 1;
extern volatile sbit bank0 SROFT_10				@(SRADC_BA+ 0x06)* 8+ 2;
extern volatile sbit bank0 SROFT_11				@(SRADC_BA+ 0x06)* 8+ 3;

//reg: EADRH
extern volatile sbit bank0 EDAR_8				@(FMC_BA+ 0x00)* 8+ 0;
extern volatile sbit bank0 EDAR_9				@(FMC_BA+ 0x00)* 8+ 1;
extern volatile sbit bank0 EDAR_10				@(FMC_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 EDAR_11				@(FMC_BA+ 0x00)* 8+ 3;
extern volatile sbit bank0 EDAR_12				@(FMC_BA+ 0x00)* 8+ 4;
extern volatile sbit bank0 EDAR_13				@(FMC_BA+ 0x00)* 8+ 5;
extern volatile sbit bank0 EDAR_14				@(FMC_BA+ 0x00)* 8+ 6;
extern volatile sbit bank0 EDAR_15				@(FMC_BA+ 0x00)* 8+ 7;

//reg: EADRL
extern volatile sbit bank0 EDAR_0				@(FMC_BA+ 0x01)* 8+ 0;
extern volatile sbit bank0 EDAR_1				@(FMC_BA+ 0x01)* 8+ 1;
extern volatile sbit bank0 EDAR_2				@(FMC_BA+ 0x01)* 8+ 2;
extern volatile sbit bank0 EDAR_3				@(FMC_BA+ 0x01)* 8+ 3;
extern volatile sbit bank0 EDAR_4				@(FMC_BA+ 0x01)* 8+ 4;
extern volatile sbit bank0 EDAR_5				@(FMC_BA+ 0x01)* 8+ 5;
extern volatile sbit bank0 EDAR_6				@(FMC_BA+ 0x01)* 8+ 6;
extern volatile sbit bank0 EDAR_7				@(FMC_BA+ 0x01)* 8+ 7;

//reg: EDATH
extern volatile sbit bank0 EDAT_8				@(FMC_BA+ 0x02)* 8+ 0;
extern volatile sbit bank0 EDAT_9				@(FMC_BA+ 0x02)* 8+ 1;
extern volatile sbit bank0 EDAT_10				@(FMC_BA+ 0x02)* 8+ 2;
extern volatile sbit bank0 EDAT_11				@(FMC_BA+ 0x02)* 8+ 3;
extern volatile sbit bank0 EDAT_12				@(FMC_BA+ 0x02)* 8+ 4;
extern volatile sbit bank0 EDAT_13				@(FMC_BA+ 0x02)* 8+ 5;
extern volatile sbit bank0 EDAT_14				@(FMC_BA+ 0x02)* 8+ 6;
extern volatile sbit bank0 EDAT_15				@(FMC_BA+ 0x02)* 8+ 7;

//reg: EDATL
extern volatile sbit bank0 EDAT_0				@(FMC_BA+ 0x03)* 8+ 0;
extern volatile sbit bank0 EDAT_1				@(FMC_BA+ 0x03)* 8+ 1;
extern volatile sbit bank0 EDAT_2				@(FMC_BA+ 0x03)* 8+ 2;
extern volatile sbit bank0 EDAT_3				@(FMC_BA+ 0x03)* 8+ 3;
extern volatile sbit bank0 EDAT_4				@(FMC_BA+ 0x03)* 8+ 4;
extern volatile sbit bank0 EDAT_5				@(FMC_BA+ 0x03)* 8+ 5;
extern volatile sbit bank0 EDAT_6				@(FMC_BA+ 0x03)* 8+ 6;
extern volatile sbit bank0 EDAT_7				@(FMC_BA+ 0x03)* 8+ 7;

//reg: ISPCR
extern volatile sbit bank0 START				@(FMC_BA+ 0x04)* 8+ 0;
extern volatile sbit bank0 ISPEN				@(FMC_BA+ 0x04)* 8+ 5;
extern volatile sbit bank0 READM0				@(FMC_BA+ 0x04)* 8+ 6;
extern volatile sbit bank0 READM1				@(FMC_BA+ 0x04)* 8+ 7;

//reg: CMD
extern volatile sbit bank0 CMD_0				@(FMC_BA+ 0x05)* 8+ 0;
extern volatile sbit bank0 CMD_1				@(FMC_BA+ 0x05)* 8+ 1;
extern volatile sbit bank0 CMD_2				@(FMC_BA+ 0x05)* 8+ 2;
extern volatile sbit bank0 CMD_3				@(FMC_BA+ 0x05)* 8+ 3;
extern volatile sbit bank0 CMD_4				@(FMC_BA+ 0x05)* 8+ 4;
extern volatile sbit bank0 CMD_5				@(FMC_BA+ 0x05)* 8+ 5;
extern volatile sbit bank0 CMD_6				@(FMC_BA+ 0x05)* 8+ 6;
extern volatile sbit bank0 CMD_7				@(FMC_BA+ 0x05)* 8+ 7;

//reg: ISPSR
extern volatile sbit bank0 BSY					@(FMC_BA+ 0x06)* 8+ 0;
extern volatile sbit bank0 ISPOF				@(FMC_BA+ 0x06)* 8+ 1;
extern volatile sbit bank0 PGERR				@(FMC_BA+ 0x06)* 8+ 2;
extern volatile sbit bank0 UNLOCK				@(FMC_BA+ 0x06)* 8+ 3;

//reg: TM2CON
extern volatile sbit bank0 T2RSTB				@(TM2_BA+ 0x00)* 8+ 2;
extern volatile sbit bank0 PWM2STALL			@(TM2_BA+ 0x00)* 8+ 4;
extern volatile sbit bank0 TM2IE				@(TM2_BA+ 0x00)* 8+ 5;
extern volatile sbit bank0 TM2IF				@(TM2_BA+ 0x00)* 8+ 6;
extern volatile sbit bank0 T2EN					@(TM2_BA+ 0x00)* 8+ 7;

//reg: TM2IN
extern volatile sbit bank0 TM2IN_0				@(TM2_BA+ 0x01)* 8+ 0;
extern volatile sbit bank0 TM2IN_1				@(TM2_BA+ 0x01)* 8+ 1;
extern volatile sbit bank0 TM2IN_2				@(TM2_BA+ 0x01)* 8+ 2;
extern volatile sbit bank0 TM2IN_3				@(TM2_BA+ 0x01)* 8+ 3;
extern volatile sbit bank0 TM2IN_4				@(TM2_BA+ 0x01)* 8+ 4;
extern volatile sbit bank0 TM2IN_5				@(TM2_BA+ 0x01)* 8+ 5;
extern volatile sbit bank0 TM2IN_6				@(TM2_BA+ 0x01)* 8+ 6;
extern volatile sbit bank0 TM2IN_7				@(TM2_BA+ 0x01)* 8+ 7;

//reg: TM2CNT
extern volatile sbit bank0 TM2CNT_0				@(TM2_BA+ 0x02)* 8+ 0;
extern volatile sbit bank0 TM2CNT_1				@(TM2_BA+ 0x02)* 8+ 1;
extern volatile sbit bank0 TM2CNT_2				@(TM2_BA+ 0x02)* 8+ 2;
extern volatile sbit bank0 TM2CNT_3				@(TM2_BA+ 0x02)* 8+ 3;
extern volatile sbit bank0 TM2CNT_4				@(TM2_BA+ 0x02)* 8+ 4;
extern volatile sbit bank0 TM2CNT_5				@(TM2_BA+ 0x02)* 8+ 5;
extern volatile sbit bank0 TM2CNT_6				@(TM2_BA+ 0x02)* 8+ 6;
extern volatile sbit bank0 TM2CNT_7				@(TM2_BA+ 0x02)* 8+ 7;

//reg: TM2R
extern volatile sbit bank0 TM2R_0				@(TM2_BA+ 0x03)* 8+ 0;
extern volatile sbit bank0 TM2R_1				@(TM2_BA+ 0x03)* 8+ 1;
extern volatile sbit bank0 TM2R_2				@(TM2_BA+ 0x03)* 8+ 2;
extern volatile sbit bank0 TM2R_3				@(TM2_BA+ 0x03)* 8+ 3;
extern volatile sbit bank0 TM2R_4				@(TM2_BA+ 0x03)* 8+ 4;
extern volatile sbit bank0 TM2R_5				@(TM2_BA+ 0x03)* 8+ 5;
extern volatile sbit bank0 TM2R_6				@(TM2_BA+ 0x03)* 8+ 6;
extern volatile sbit bank0 TM2R_7				@(TM2_BA+ 0x03)* 8+ 7;


//reg: page1 bits define

//reg: TM3CON
extern volatile sbit bank2 T3RSTB				@(TM3_BA+ 0x00)* 8+ 2;
extern volatile sbit bank2 TM3IE				@(TM3_BA+ 0x00)* 8+ 5;
extern volatile sbit bank2 TM3IF				@(TM3_BA+ 0x00)* 8+ 6;
extern volatile sbit bank2 T3EN					@(TM3_BA+ 0x00)* 8+ 7;

//reg: TM3IN
extern volatile sbit bank2 TM3IN_0				@(TM3_BA+ 0x01)* 8+ 0;
extern volatile sbit bank2 TM3IN_1				@(TM3_BA+ 0x01)* 8+ 1;
extern volatile sbit bank2 TM3IN_2				@(TM3_BA+ 0x01)* 8+ 2;
extern volatile sbit bank2 TM3IN_3				@(TM3_BA+ 0x01)* 8+ 3;
extern volatile sbit bank2 TM3IN_4				@(TM3_BA+ 0x01)* 8+ 4;
extern volatile sbit bank2 TM3IN_5				@(TM3_BA+ 0x01)* 8+ 5;
extern volatile sbit bank2 TM3IN_6				@(TM3_BA+ 0x01)* 8+ 6;
extern volatile sbit bank2 TM3IN_7				@(TM3_BA+ 0x01)* 8+ 7;

//reg: TM3INH
extern volatile sbit bank2 TM3IN_8				@(TM3_BA+ 0x02)* 8+ 0;
extern volatile sbit bank2 TM3IN_9				@(TM3_BA+ 0x02)* 8+ 1;
extern volatile sbit bank2 TM3IN_10				@(TM3_BA+ 0x02)* 8+ 2;
extern volatile sbit bank2 TM3IN_11				@(TM3_BA+ 0x02)* 8+ 3;

//reg: TM3CNT
extern volatile sbit bank2 TM3CNT_0				@(TM3_BA+ 0x03)* 8+ 0;
extern volatile sbit bank2 TM3CNT_1				@(TM3_BA+ 0x03)* 8+ 1;
extern volatile sbit bank2 TM3CNT_2				@(TM3_BA+ 0x03)* 8+ 2;
extern volatile sbit bank2 TM3CNT_3				@(TM3_BA+ 0x03)* 8+ 3;
extern volatile sbit bank2 TM3CNT_4				@(TM3_BA+ 0x03)* 8+ 4;
extern volatile sbit bank2 TM3CNT_5				@(TM3_BA+ 0x03)* 8+ 5;
extern volatile sbit bank2 TM3CNT_6				@(TM3_BA+ 0x03)* 8+ 6;
extern volatile sbit bank2 TM3CNT_7				@(TM3_BA+ 0x03)* 8+ 7;

//reg: TM3CNTH
extern volatile sbit bank2 TM3CNT_8				@(TM3_BA+ 0x04)* 8+ 0;
extern volatile sbit bank2 TM3CNT_9				@(TM3_BA+ 0x04)* 8+ 1;
extern volatile sbit bank2 TM3CNT_10			@(TM3_BA+ 0x04)* 8+ 2;
extern volatile sbit bank2 TM3CNT_11			@(TM3_BA+ 0x04)* 8+ 3;

//reg: TM3R
extern volatile sbit bank2 TM3R_0				@(TM3_BA+ 0x05)* 8+ 0;
extern volatile sbit bank2 TM3R_1				@(TM3_BA+ 0x05)* 8+ 1;
extern volatile sbit bank2 TM3R_2				@(TM3_BA+ 0x05)* 8+ 2;
extern volatile sbit bank2 TM3R_3				@(TM3_BA+ 0x05)* 8+ 3;
extern volatile sbit bank2 TM3R_4				@(TM3_BA+ 0x05)* 8+ 4;
extern volatile sbit bank2 TM3R_5				@(TM3_BA+ 0x05)* 8+ 5;
extern volatile sbit bank2 TM3R_6				@(TM3_BA+ 0x05)* 8+ 6;
extern volatile sbit bank2 TM3R_7				@(TM3_BA+ 0x05)* 8+ 7;

//reg: TM3CNTH
extern volatile sbit bank2 TM3R_8				@(TM3_BA+ 0x06)* 8+ 0;
extern volatile sbit bank2 TM3R_9				@(TM3_BA+ 0x06)* 8+ 1;
extern volatile sbit bank2 TM3R_10				@(TM3_BA+ 0x06)* 8+ 2;
extern volatile sbit bank2 TM3R_11				@(TM3_BA+ 0x06)* 8+ 3;

//reg: TM3CON2
extern volatile sbit bank2 P3LINV				@(TM3_BA+ 0x07)* 8+ 0;
extern volatile sbit bank2 P3HINV				@(TM3_BA+ 0x07)* 8+ 1;
extern volatile sbit bank2 DT3_EN				@(TM3_BA+ 0x07)* 8+ 2;
extern volatile sbit bank2 DT3CNT_0				@(TM3_BA+ 0x07)* 8+ 3;
extern volatile sbit bank2 DT3CNT_1				@(TM3_BA+ 0x07)* 8+ 4;
extern volatile sbit bank2 DT3CNT_2				@(TM3_BA+ 0x07)* 8+ 5;
extern volatile sbit bank2 DT3CNT_3				@(TM3_BA+ 0x07)* 8+ 6;
extern volatile sbit bank2 PWM3STALL			@(TM3_BA+ 0x07)* 8+ 7;

//reg: UR0_CR1
extern volatile sbit bank2 UART0_EN				@(UART0_BA+ 0x00)* 8+ 0;
extern volatile sbit bank2 TX_EN				@(UART0_BA+ 0x00)* 8+ 2;
extern volatile sbit bank2 RX_EN				@(UART0_BA+ 0x00)* 8+ 3;
extern volatile sbit bank2 RX9_EN				@(UART0_BA+ 0x00)* 8+ 4;
extern volatile sbit bank2 TX9_EN				@(UART0_BA+ 0x00)* 8+ 5;
extern volatile sbit bank2 RX9D					@(UART0_BA+ 0x00)* 8+ 6;
extern volatile sbit bank2 TX9D					@(UART0_BA+ 0x00)* 8+ 7;

//reg: UR0_BRR0
extern volatile sbit bank2 BRR0_0				@(UART0_BA+ 0x01)* 8+ 0;
extern volatile sbit bank2 BRR0_1				@(UART0_BA+ 0x01)* 8+ 1;
extern volatile sbit bank2 BRR0_2				@(UART0_BA+ 0x01)* 8+ 2;
extern volatile sbit bank2 BRR0_3				@(UART0_BA+ 0x01)* 8+ 3;
extern volatile sbit bank2 BRR0_4				@(UART0_BA+ 0x01)* 8+ 4;
extern volatile sbit bank2 BRR0_5				@(UART0_BA+ 0x01)* 8+ 5;
extern volatile sbit bank2 BRR0_6				@(UART0_BA+ 0x01)* 8+ 6;
extern volatile sbit bank2 BRR0_7				@(UART0_BA+ 0x01)* 8+ 7;

//reg: UR0_BRR1
extern volatile sbit bank2 BRR1_0				@(UART0_BA+ 0x02)* 8+ 0;
extern volatile sbit bank2 BRR1_1				@(UART0_BA+ 0x02)* 8+ 1;
extern volatile sbit bank2 BRR1_2				@(UART0_BA+ 0x02)* 8+ 2;
extern volatile sbit bank2 BRR1_3				@(UART0_BA+ 0x02)* 8+ 3;

//reg: UR0_TX_REG
extern volatile sbit bank2 TX_REG_0				@(UART0_BA+ 0x03)* 8+ 0;
extern volatile sbit bank2 TX_REG_1				@(UART0_BA+ 0x03)* 8+ 1;
extern volatile sbit bank2 TX_REG_2				@(UART0_BA+ 0x03)* 8+ 2;
extern volatile sbit bank2 TX_REG_3				@(UART0_BA+ 0x03)* 8+ 3;
extern volatile sbit bank2 TX_REG_4				@(UART0_BA+ 0x03)* 8+ 4;
extern volatile sbit bank2 TX_REG_5				@(UART0_BA+ 0x03)* 8+ 5;
extern volatile sbit bank2 TX_REG_6				@(UART0_BA+ 0x03)* 8+ 6;
extern volatile sbit bank2 TX_REG_7				@(UART0_BA+ 0x03)* 8+ 7;

//reg: UR0_RX_REG
extern volatile sbit bank2 RX_REG_0				@(UART0_BA+ 0x04)* 8+ 0;
extern volatile sbit bank2 RX_REG_1				@(UART0_BA+ 0x04)* 8+ 1;
extern volatile sbit bank2 RX_REG_2				@(UART0_BA+ 0x04)* 8+ 2;
extern volatile sbit bank2 RX_REG_3				@(UART0_BA+ 0x04)* 8+ 3;
extern volatile sbit bank2 RX_REG_4				@(UART0_BA+ 0x04)* 8+ 4;
extern volatile sbit bank2 RX_REG_5				@(UART0_BA+ 0x04)* 8+ 5;
extern volatile sbit bank2 RX_REG_6				@(UART0_BA+ 0x04)* 8+ 6;
extern volatile sbit bank2 RX_REG_7				@(UART0_BA+ 0x04)* 8+ 7;

//reg: UR0_ST
extern volatile sbit bank2 STOP_ERR				@(UART0_BA+ 0x05)* 8+ 0;
extern volatile sbit bank2 RX_OV_ERR			@(UART0_BA+ 0x05)* 8+ 1;
extern volatile sbit bank2 TX_BUSY				@(UART0_BA+ 0x05)* 8+ 2;
extern volatile sbit bank2 RX_BUSY				@(UART0_BA+ 0x05)* 8+ 3;
extern volatile sbit bank2 TXFIFO_EMPTY			@(UART0_BA+ 0x05)* 8+ 4;
extern volatile sbit bank2 UR_RINV				@(UART0_BA+ 0x05)* 8+ 6;
extern volatile sbit bank2 UR_TINV				@(UART0_BA+ 0x05)* 8+ 7;

//reg: UR0_INTF
extern volatile sbit bank2 UR0_TEIF				@(UART0_BA+ 0x06)* 8+ 0;
extern volatile sbit bank2 UR0WK_IF				@(UART0_BA+ 0x06)* 8+ 1;
extern volatile sbit bank2 UR0_RNIF				@(UART0_BA+ 0x06)* 8+ 2;
extern volatile sbit bank2 UR0_RHIF				@(UART0_BA+ 0x06)* 8+ 3;
extern volatile sbit bank2 UR0ERRIF				@(UART0_BA+ 0x06)* 8+ 4;

//reg: UR0_INTE
extern volatile sbit bank2 UR0_TEIE				@(UART0_BA+ 0x07)* 8+ 0;
extern volatile sbit bank2 UR0WK_IE				@(UART0_BA+ 0x07)* 8+ 1;
extern volatile sbit bank2 UR0_RNIE				@(UART0_BA+ 0x07)* 8+ 2;
extern volatile sbit bank2 UR0_RHIE				@(UART0_BA+ 0x07)* 8+ 3;
extern volatile sbit bank2 UR0ERRIE				@(UART0_BA+ 0x07)* 8+ 4;

//reg: TM4CON
extern volatile sbit bank2 T4RSTB				@(TM4_BA+ 0x00)* 8+ 2;
extern volatile sbit bank2 PWM4STALL			@(TM4_BA+ 0x00)* 8+ 4;
extern volatile sbit bank2 TM4IE				@(TM4_BA+ 0x00)* 8+ 5;
extern volatile sbit bank2 TM4IF				@(TM4_BA+ 0x00)* 8+ 6;
extern volatile sbit bank2 T4EN					@(TM4_BA+ 0x00)* 8+ 7;

//reg: TM4IN
extern volatile sbit bank2 TM4IN_0				@(TM4_BA+ 0x01)* 8+ 0;
extern volatile sbit bank2 TM4IN_1				@(TM4_BA+ 0x01)* 8+ 1;
extern volatile sbit bank2 TM4IN_2				@(TM4_BA+ 0x01)* 8+ 2;
extern volatile sbit bank2 TM4IN_3				@(TM4_BA+ 0x01)* 8+ 3;
extern volatile sbit bank2 TM4IN_4				@(TM4_BA+ 0x01)* 8+ 4;
extern volatile sbit bank2 TM4IN_5				@(TM4_BA+ 0x01)* 8+ 5;
extern volatile sbit bank2 TM4IN_6				@(TM4_BA+ 0x01)* 8+ 6;
extern volatile sbit bank2 TM4IN_7				@(TM4_BA+ 0x01)* 8+ 7;

//reg: TM4INH
extern volatile sbit bank2 TM4IN_8				@(TM4_BA+ 0x02)* 8+ 0;
extern volatile sbit bank2 TM4IN_9				@(TM4_BA+ 0x02)* 8+ 1;
extern volatile sbit bank2 TM4IN_10				@(TM4_BA+ 0x02)* 8+ 2;
extern volatile sbit bank2 TM4IN_11				@(TM4_BA+ 0x02)* 8+ 3;

//reg: TM4CNT
extern volatile sbit bank2 TM4CNT_0				@(TM4_BA+ 0x03)* 8+ 0;
extern volatile sbit bank2 TM4CNT_1				@(TM4_BA+ 0x03)* 8+ 1;
extern volatile sbit bank2 TM4CNT_2				@(TM4_BA+ 0x03)* 8+ 2;
extern volatile sbit bank2 TM4CNT_3				@(TM4_BA+ 0x03)* 8+ 3;
extern volatile sbit bank2 TM4CNT_4				@(TM4_BA+ 0x03)* 8+ 4;
extern volatile sbit bank2 TM4CNT_5				@(TM4_BA+ 0x03)* 8+ 5;
extern volatile sbit bank2 TM4CNT_6				@(TM4_BA+ 0x03)* 8+ 6;
extern volatile sbit bank2 TM4CNT_7				@(TM4_BA+ 0x03)* 8+ 7;

//reg: TM4CNTH
extern volatile sbit bank2 TM4CNT_8				@(TM4_BA+ 0x04)* 8+ 0;
extern volatile sbit bank2 TM4CNT_9				@(TM4_BA+ 0x04)* 8+ 1;
extern volatile sbit bank2 TM4CNT_10			@(TM4_BA+ 0x04)* 8+ 2;
extern volatile sbit bank2 TM4CNT_11			@(TM4_BA+ 0x04)* 8+ 3;

//reg: TM4R
extern volatile sbit bank2 TM4R_0				@(TM4_BA+ 0x05)* 8+ 0;
extern volatile sbit bank2 TM4R_1				@(TM4_BA+ 0x05)* 8+ 1;
extern volatile sbit bank2 TM4R_2				@(TM4_BA+ 0x05)* 8+ 2;
extern volatile sbit bank2 TM4R_3				@(TM4_BA+ 0x05)* 8+ 3;
extern volatile sbit bank2 TM4R_4				@(TM4_BA+ 0x05)* 8+ 4;
extern volatile sbit bank2 TM4R_5				@(TM4_BA+ 0x05)* 8+ 5;
extern volatile sbit bank2 TM4R_6				@(TM4_BA+ 0x05)* 8+ 6;
extern volatile sbit bank2 TM4R_7				@(TM4_BA+ 0x05)* 8+ 7;

//reg: TM4RH
extern volatile sbit bank2 TM4R_8				@(TM4_BA+ 0x06)* 8+ 0;
extern volatile sbit bank2 TM4R_9				@(TM4_BA+ 0x06)* 8+ 1;
extern volatile sbit bank2 TM4R_10				@(TM4_BA+ 0x06)* 8+ 2;
extern volatile sbit bank2 TM4R_11				@(TM4_BA+ 0x06)* 8+ 3;

//reg: TESTOP
extern volatile sbit bank2 TMOD_0				@(TEST_BA+ 0x00)* 8+ 0;
extern volatile sbit bank2 TMOD_1				@(TEST_BA+ 0x00)* 8+ 1;
extern volatile sbit bank2 TMOD_2				@(TEST_BA+ 0x00)* 8+ 2;
extern volatile sbit bank2 TMOD_3				@(TEST_BA+ 0x00)* 8+ 3;
extern volatile sbit bank2 ANATESTMOD_0			@(TEST_BA+ 0x00)* 8+ 4;
extern volatile sbit bank2 ANATESTMOD_1			@(TEST_BA+ 0x00)* 8+ 5;
extern volatile sbit bank2 ANATESTMOD_2			@(TEST_BA+ 0x00)* 8+ 6;
extern volatile sbit bank2 ANATESTMOD_3			@(TEST_BA+ 0x00)* 8+ 7;

//reg: TEST
extern volatile sbit bank2 TEST_0				@(TEST_BA+ 0x01)* 8+ 0;
extern volatile sbit bank2 TEST_1				@(TEST_BA+ 0x01)* 8+ 1;
extern volatile sbit bank2 TEST_2				@(TEST_BA+ 0x01)* 8+ 2;
extern volatile sbit bank2 TEST_3				@(TEST_BA+ 0x01)* 8+ 3;
extern volatile sbit bank2 TEST_4				@(TEST_BA+ 0x01)* 8+ 4;
extern volatile sbit bank2 TEST_5				@(TEST_BA+ 0x01)* 8+ 5;
extern volatile sbit bank2 TEST_6				@(TEST_BA+ 0x01)* 8+ 6;
extern volatile sbit bank2 TEST_7				@(TEST_BA+ 0x01)* 8+ 7;

//reg: 
//reg: page3 bits define

//reg: CHIP_ID0L
extern volatile sbit bank8 CHIP_ID0L_0			@(PROG_BA+ 0x00)* 8+ 0;
extern volatile sbit bank8 CHIP_ID0L_1			@(PROG_BA+ 0x00)* 8+ 1;
extern volatile sbit bank8 CHIP_ID0L_2			@(PROG_BA+ 0x00)* 8+ 2;
extern volatile sbit bank8 CHIP_ID0L_3			@(PROG_BA+ 0x00)* 8+ 3;
extern volatile sbit bank8 CHIP_ID0L_4			@(PROG_BA+ 0x00)* 8+ 4;
extern volatile sbit bank8 CHIP_ID0L_5			@(PROG_BA+ 0x00)* 8+ 5;
extern volatile sbit bank8 CHIP_ID0L_6			@(PROG_BA+ 0x00)* 8+ 6;
extern volatile sbit bank8 CHIP_ID0L_7			@(PROG_BA+ 0x00)* 8+ 7;

//reg: CHIP_ID0H
extern volatile sbit bank8 CHIP_ID0H_0			@(PROG_BA+ 0x01)* 8+ 0;
extern volatile sbit bank8 CHIP_ID0H_1			@(PROG_BA+ 0x01)* 8+ 1;
extern volatile sbit bank8 CHIP_ID0H_2			@(PROG_BA+ 0x01)* 8+ 2;
extern volatile sbit bank8 CHIP_ID0H_3			@(PROG_BA+ 0x01)* 8+ 3;
extern volatile sbit bank8 CHIP_ID0H_4			@(PROG_BA+ 0x01)* 8+ 4;
extern volatile sbit bank8 CHIP_ID0H_5			@(PROG_BA+ 0x01)* 8+ 5;
extern volatile sbit bank8 CHIP_ID0H_6			@(PROG_BA+ 0x01)* 8+ 6;
extern volatile sbit bank8 CHIP_ID0H_7			@(PROG_BA+ 0x01)* 8+ 7;

//reg: CHIP_ID1L
extern volatile sbit bank8 CHIP_ID1L_0			@(PROG_BA+ 0x02)* 8+ 0;
extern volatile sbit bank8 CHIP_ID1L_1			@(PROG_BA+ 0x02)* 8+ 1;
extern volatile sbit bank8 CHIP_ID1L_2			@(PROG_BA+ 0x02)* 8+ 2;
extern volatile sbit bank8 CHIP_ID1L_3			@(PROG_BA+ 0x02)* 8+ 3;
extern volatile sbit bank8 CHIP_ID1L_4			@(PROG_BA+ 0x02)* 8+ 4;
extern volatile sbit bank8 CHIP_ID1L_5			@(PROG_BA+ 0x02)* 8+ 5;
extern volatile sbit bank8 CHIP_ID1L_6			@(PROG_BA+ 0x02)* 8+ 6;
extern volatile sbit bank8 CHIP_ID1L_7			@(PROG_BA+ 0x02)* 8+ 7;

//reg: CHIP_ID1H
extern volatile sbit bank8 CHIP_ID1H_0			@(PROG_BA+ 0x03)* 8+ 0;
extern volatile sbit bank8 CHIP_ID1H_1			@(PROG_BA+ 0x03)* 8+ 1;
extern volatile sbit bank8 CHIP_ID1H_2			@(PROG_BA+ 0x03)* 8+ 2;
extern volatile sbit bank8 CHIP_ID1H_3			@(PROG_BA+ 0x03)* 8+ 3;
extern volatile sbit bank8 CHIP_ID1H_4			@(PROG_BA+ 0x03)* 8+ 4;
extern volatile sbit bank8 CHIP_ID1H_5			@(PROG_BA+ 0x03)* 8+ 5;
extern volatile sbit bank8 CHIP_ID1H_6			@(PROG_BA+ 0x03)* 8+ 6;
extern volatile sbit bank8 CHIP_ID1H_7			@(PROG_BA+ 0x03)* 8+ 7;

//reg: SFR_WK
extern volatile sbit bank8 SFR_WK_0				@(PROG_BA+ 0x04)* 8+ 0;
extern volatile sbit bank8 SFR_WK_1				@(PROG_BA+ 0x04)* 8+ 1;
extern volatile sbit bank8 SFR_WK_2				@(PROG_BA+ 0x04)* 8+ 2;
extern volatile sbit bank8 SFR_WK_3				@(PROG_BA+ 0x04)* 8+ 3;
extern volatile sbit bank8 SFR_WK_4				@(PROG_BA+ 0x04)* 8+ 4;
extern volatile sbit bank8 SFR_WK_5				@(PROG_BA+ 0x04)* 8+ 5;
extern volatile sbit bank8 SFR_WK_6				@(PROG_BA+ 0x04)* 8+ 6;
extern volatile sbit bank8 SFR_WK_7				@(PROG_BA+ 0x04)* 8+ 7;

//reg: MM_WK
extern volatile sbit bank8 MM_WK_0				@(PROG_BA+ 0x05)* 8+ 0;
extern volatile sbit bank8 MM_WK_1				@(PROG_BA+ 0x05)* 8+ 1;
extern volatile sbit bank8 MM_WK_2				@(PROG_BA+ 0x05)* 8+ 2;
extern volatile sbit bank8 MM_WK_3				@(PROG_BA+ 0x05)* 8+ 3;
extern volatile sbit bank8 MM_WK_4				@(PROG_BA+ 0x05)* 8+ 4;
extern volatile sbit bank8 MM_WK_5				@(PROG_BA+ 0x05)* 8+ 5;
extern volatile sbit bank8 MM_WK_6				@(PROG_BA+ 0x05)* 8+ 6;
extern volatile sbit bank8 MM_WK_7				@(PROG_BA+ 0x05)* 8+ 7;

//reg: UOB_WK
extern volatile sbit bank8 UOB_WK_0				@(PROG_BA+ 0x06)* 8+ 0;
extern volatile sbit bank8 UOB_WK_1				@(PROG_BA+ 0x06)* 8+ 1;
extern volatile sbit bank8 UOB_WK_2				@(PROG_BA+ 0x06)* 8+ 2;
extern volatile sbit bank8 UOB_WK_3				@(PROG_BA+ 0x06)* 8+ 3;
extern volatile sbit bank8 UOB_WK_4				@(PROG_BA+ 0x06)* 8+ 4;
extern volatile sbit bank8 UOB_WK_5				@(PROG_BA+ 0x06)* 8+ 5;
extern volatile sbit bank8 UOB_WK_6				@(PROG_BA+ 0x06)* 8+ 6;
extern volatile sbit bank8 UOB_WK_7				@(PROG_BA+ 0x06)* 8+ 7;

//reg: POB_WK
extern volatile sbit bank8 POB_WK_0				@(PROG_BA+ 0x07)* 8+ 0;
extern volatile sbit bank8 POB_WK_1				@(PROG_BA+ 0x07)* 8+ 1;
extern volatile sbit bank8 POB_WK_2				@(PROG_BA+ 0x07)* 8+ 2;
extern volatile sbit bank8 POB_WK_3				@(PROG_BA+ 0x07)* 8+ 3;
extern volatile sbit bank8 POB_WK_4				@(PROG_BA+ 0x07)* 8+ 4;
extern volatile sbit bank8 POB_WK_5				@(PROG_BA+ 0x07)* 8+ 5;
extern volatile sbit bank8 POB_WK_6				@(PROG_BA+ 0x07)* 8+ 6;
extern volatile sbit bank8 POB_WK_7				@(PROG_BA+ 0x07)* 8+ 7;

//reg: MP_WK
extern volatile sbit bank8 MP_WK_0				@(PROG_BA+ 0x08)* 8+ 0;
extern volatile sbit bank8 MP_WK_1				@(PROG_BA+ 0x08)* 8+ 1;
extern volatile sbit bank8 MP_WK_2				@(PROG_BA+ 0x08)* 8+ 2;
extern volatile sbit bank8 MP_WK_3				@(PROG_BA+ 0x08)* 8+ 3;
extern volatile sbit bank8 MP_WK_4				@(PROG_BA+ 0x08)* 8+ 4;
extern volatile sbit bank8 MP_WK_5				@(PROG_BA+ 0x08)* 8+ 5;
extern volatile sbit bank8 MP_WK_6				@(PROG_BA+ 0x08)* 8+ 6;
extern volatile sbit bank8 MP_WK_7				@(PROG_BA+ 0x08)* 8+ 7;

//reg: CAL_SELECT
extern volatile sbit bank8 OSC_0				@(PROG_BA+ 0x09)* 8+ 0;
extern volatile sbit bank8 OSC_1				@(PROG_BA+ 0x09)* 8+ 1;
extern volatile sbit bank8 OSC_2				@(PROG_BA+ 0x09)* 8+ 2;
extern volatile sbit bank8 OSC_3				@(PROG_BA+ 0x09)* 8+ 3;
extern volatile sbit bank8 TRIMAUTO				@(PROG_BA+ 0x09)* 8+ 6;
extern volatile sbit bank8 CAL_SELECT_START		@(PROG_BA+ 0x09)* 8+ 7;

//reg: TRIMREF
extern volatile sbit bank8 TRIMREF_0			@(PROG_BA+ 0x0a)* 8+ 0;
extern volatile sbit bank8 TRIMREF_1			@(PROG_BA+ 0x0a)* 8+ 1;
extern volatile sbit bank8 TRIMREF_2			@(PROG_BA+ 0x0a)* 8+ 2;
extern volatile sbit bank8 TRIMREF_3			@(PROG_BA+ 0x0a)* 8+ 3;
extern volatile sbit bank8 TRIMREF_4			@(PROG_BA+ 0x0a)* 8+ 4;
extern volatile sbit bank8 TRIMREF_5			@(PROG_BA+ 0x0a)* 8+ 5;
extern volatile sbit bank8 TRIMREF_6			@(PROG_BA+ 0x0a)* 8+ 6;
extern volatile sbit bank8 TRIMREF_7			@(PROG_BA+ 0x0a)* 8+ 7;

//reg: TRIMWDT
extern volatile sbit bank8 TRIMWDT_0			@(PROG_BA+ 0x0b)* 8+ 0;
extern volatile sbit bank8 TRIMWDT_1			@(PROG_BA+ 0x0b)* 8+ 1;
extern volatile sbit bank8 TRIMWDT_2			@(PROG_BA+ 0x0b)* 8+ 2;
extern volatile sbit bank8 TRIMWDT_3			@(PROG_BA+ 0x0b)* 8+ 3;
extern volatile sbit bank8 TRIMWDT_4			@(PROG_BA+ 0x0b)* 8+ 4;
extern volatile sbit bank8 TRIMWDT_5			@(PROG_BA+ 0x0b)* 8+ 5;
extern volatile sbit bank8 TRIMWDT_6			@(PROG_BA+ 0x0b)* 8+ 6;
extern volatile sbit bank8 TRIMWDT_7			@(PROG_BA+ 0x0b)* 8+ 7;

//reg: TRIMHIRC
extern volatile sbit bank8 TRIMHIRC_0			@(PROG_BA+ 0x0c)* 8+ 0;
extern volatile sbit bank8 TRIMHIRC_1			@(PROG_BA+ 0x0c)* 8+ 1;
extern volatile sbit bank8 TRIMHIRC_2			@(PROG_BA+ 0x0c)* 8+ 2;
extern volatile sbit bank8 TRIMHIRC_3			@(PROG_BA+ 0x0c)* 8+ 3;
extern volatile sbit bank8 TRIMHIRC_4			@(PROG_BA+ 0x0c)* 8+ 4;
extern volatile sbit bank8 TRIMHIRC_5			@(PROG_BA+ 0x0c)* 8+ 5;
extern volatile sbit bank8 TRIMHIRC_6			@(PROG_BA+ 0x0c)* 8+ 6;
extern volatile sbit bank8 TRIMHIRC_7			@(PROG_BA+ 0x0c)* 8+ 7;

//reg: OSC_DIV
extern volatile sbit bank8 OSC_DIV_0			@(PROG_BA+ 0x0d)* 8+ 0;
extern volatile sbit bank8 OSC_DIV_1			@(PROG_BA+ 0x0d)* 8+ 1;
extern volatile sbit bank8 OSC_DIV_2			@(PROG_BA+ 0x0d)* 8+ 2;
extern volatile sbit bank8 OSC_DIV_3			@(PROG_BA+ 0x0d)* 8+ 3;
extern volatile sbit bank8 OSC_SLEEP			@(PROG_BA+ 0x0d)* 8+ 7;

//reg: SR
extern volatile sbit bank8 ERR_0				@(PROG_BA+ 0x0e)* 8+ 0;
extern volatile sbit bank8 ERR_1				@(PROG_BA+ 0x0e)* 8+ 1;
extern volatile sbit bank8 BUSY					@(PROG_BA+ 0x0e)* 8+ 2;
extern volatile sbit bank8 MMWEL				@(PROG_BA+ 0x0e)* 8+ 3;
extern volatile sbit bank8 UOBWEL				@(PROG_BA+ 0x0e)* 8+ 4;
extern volatile sbit bank8 POBWEL				@(PROG_BA+ 0x0e)* 8+ 5;
extern volatile sbit bank8 MPWEL				@(PROG_BA+ 0x0e)* 8+ 6;
extern volatile sbit bank8 SFRWEL				@(PROG_BA+ 0x0e)* 8+ 7;

//reg: VCHK_SUM
extern volatile sbit bank8 VCHK_SUM_0			@(PROG_BA+ 0x0f)* 8+ 0;
extern volatile sbit bank8 VCHK_SUM_1			@(PROG_BA+ 0x0f)* 8+ 1;
extern volatile sbit bank8 VCHK_SUM_2			@(PROG_BA+ 0x0f)* 8+ 2;
extern volatile sbit bank8 VCHK_SUM_3			@(PROG_BA+ 0x0f)* 8+ 3;
extern volatile sbit bank8 VCHK_SUM_4			@(PROG_BA+ 0x0f)* 8+ 4;
extern volatile sbit bank8 VCHK_SUM_5			@(PROG_BA+ 0x0f)* 8+ 5;
extern volatile sbit bank8 VCHK_SUM_6			@(PROG_BA+ 0x0f)* 8+ 6;
extern volatile sbit bank8 VCHK_SUM_7			@(PROG_BA+ 0x0f)* 8+ 7;

//reg: TRIMLIMIT
extern volatile sbit bank8 TRIMLIMIT_0			@(PROG_BA+ 0x10)* 8+ 0;
extern volatile sbit bank8 TRIMLIMIT_1			@(PROG_BA+ 0x10)* 8+ 1;
extern volatile sbit bank8 TRIMLIMIT_2			@(PROG_BA+ 0x10)* 8+ 2;
extern volatile sbit bank8 TRIMLIMIT_3			@(PROG_BA+ 0x10)* 8+ 3;
extern volatile sbit bank8 TRIMLIMIT_4			@(PROG_BA+ 0x10)* 8+ 4;
extern volatile sbit bank8 TRIMLIMIT_5			@(PROG_BA+ 0x10)* 8+ 5;
extern volatile sbit bank8 TRIMLIMIT_6			@(PROG_BA+ 0x10)* 8+ 6;
extern volatile sbit bank8 TRIMLIMIT_7			@(PROG_BA+ 0x10)* 8+ 7;

//reg: SR2
extern volatile sbit bank8 TRIM_ERR				@(PROG_BA+ 0x11)* 8+ 1;
extern volatile sbit bank8 BUF_BUSY				@(PROG_BA+ 0x11)* 8+ 4;
extern volatile sbit bank8 BUSY_OEN				@(PROG_BA+ 0x11)* 8+ 5;

//reg: TRAMGAP
extern volatile sbit bank8 TRAMGAP_0			@(PROG_BA+ 0x12)* 8+ 0;
extern volatile sbit bank8 TRAMGAP_1			@(PROG_BA+ 0x12)* 8+ 1;
extern volatile sbit bank8 TRAMGAP_2			@(PROG_BA+ 0x12)* 8+ 2;
extern volatile sbit bank8 TRAMGAP_3			@(PROG_BA+ 0x12)* 8+ 3;
extern volatile sbit bank8 TRAMGAP_4			@(PROG_BA+ 0x12)* 8+ 4;
extern volatile sbit bank8 TRAMGAP_5			@(PROG_BA+ 0x12)* 8+ 5;
extern volatile sbit bank8 TRAMGAP_6			@(PROG_BA+ 0x12)* 8+ 6;
extern volatile sbit bank8 TRAMGAP_7			@(PROG_BA+ 0x12)* 8+ 7;

#endif
