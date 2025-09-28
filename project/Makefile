###################################################
#工具链定义处
###################################################
TOOLCHAIN_DIR = D:\CSU-IDE\chipsea\tools\Compiler\C
ASM	   				= "$(TOOLCHAIN_DIR)\csasm.exe"
CC    				= "$(TOOLCHAIN_DIR)\c16ext\cscc.exe"
LINKER 				= "$(TOOLCHAIN_DIR)\cslinker.exe"
LIBMAKER 			= "$(TOOLCHAIN_DIR)\CSLibMaker.exe"
RM	   				= del /F 1>NUL 2>NUL



###################################################
#编译选项定义处
###################################################
OUTPUT_DIR            = D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\project\.\Release
INTERTMP_DIR          = D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\project\.\Release
PROJ_PATH			  = D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\project
PROJ_NAME			  = JSP68A
BODY_NAME			  = CSU39F10
CFLAGS                = -cc1 -S  -debug-info-kind=limited -fshort-enums -O0 -triple=cscc -fno-inline -chip=CSU39F10 -I "../source/app" -I "../source/module" -I "../source/chip/misc" -I "../source/chip/boot" -I "../source/chip/driver" -I "../source/chip/fwlib" -I "../source/protocollib"
ASMFLAGS              = -filetype=obj -arch=cscc -fill=0xffff -DM=__CHIPSEA__CSU39F10 -chip=CSU39F10 -mattr=c16ext -BankCount=11
LINKFLAGS             = -bt 17
LIBMAKERFLAGS         = -chiptype 17 -debuginfo RemoveDebugInfo -encodeinfo Encryption
CODE_OPTION			  = %%CodeOption%%
ASM_FILES			  = "$(INTERTMP_DIR)\drv_adc.asm" \
"$(INTERTMP_DIR)\drv_flash.asm" \
"$(INTERTMP_DIR)\drv_gpio.asm" \
"$(INTERTMP_DIR)\drv_iic.asm" \
"$(INTERTMP_DIR)\drv_timer.asm" \
"$(INTERTMP_DIR)\drv_uart.asm" \
"$(INTERTMP_DIR)\drv_wdt.asm" \
"$(INTERTMP_DIR)\cs_common.asm" \
"$(INTERTMP_DIR)\sys_register.asm" \
"$(INTERTMP_DIR)\system_csu39fx10.asm" \
"$(INTERTMP_DIR)\csu39fx10_clkmu.asm" \
"$(INTERTMP_DIR)\csu39fx10_exti.asm" \
"$(INTERTMP_DIR)\csu39fx10_rstmu.asm" \
"$(INTERTMP_DIR)\csu39fx10_syscfg.asm" \
"$(INTERTMP_DIR)\mod_adc_convert.asm" \
"$(INTERTMP_DIR)\mod_dcdc.asm" \
"$(INTERTMP_DIR)\mod_display.asm" \
"$(INTERTMP_DIR)\mod_input_output.asm" \
"$(INTERTMP_DIR)\mod_key.asm" \
"$(INTERTMP_DIR)\mod_modbus.asm" \
"$(INTERTMP_DIR)\mod_queue.asm" \
"$(INTERTMP_DIR)\app_debug.asm" \
"$(INTERTMP_DIR)\app_init.asm" \
"$(INTERTMP_DIR)\app_interrupt.asm" \
"$(INTERTMP_DIR)\app_main.asm" \
"$(INTERTMP_DIR)\app_state_machine.asm" \
"$(INTERTMP_DIR)\app_typec_deal.asm" \
"D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\cstartup.asm"

OBJ_FILES			  = "$(INTERTMP_DIR)\drv_adc.obj" \
"$(INTERTMP_DIR)\drv_flash.obj" \
"$(INTERTMP_DIR)\drv_gpio.obj" \
"$(INTERTMP_DIR)\drv_iic.obj" \
"$(INTERTMP_DIR)\drv_timer.obj" \
"$(INTERTMP_DIR)\drv_uart.obj" \
"$(INTERTMP_DIR)\drv_wdt.obj" \
"$(INTERTMP_DIR)\cs_common.obj" \
"$(INTERTMP_DIR)\sys_register.obj" \
"$(INTERTMP_DIR)\system_csu39fx10.obj" \
"$(INTERTMP_DIR)\csu39fx10_clkmu.obj" \
"$(INTERTMP_DIR)\csu39fx10_exti.obj" \
"$(INTERTMP_DIR)\csu39fx10_rstmu.obj" \
"$(INTERTMP_DIR)\csu39fx10_syscfg.obj" \
"$(INTERTMP_DIR)\mod_adc_convert.obj" \
"$(INTERTMP_DIR)\mod_dcdc.obj" \
"$(INTERTMP_DIR)\mod_display.obj" \
"$(INTERTMP_DIR)\mod_input_output.obj" \
"$(INTERTMP_DIR)\mod_key.obj" \
"$(INTERTMP_DIR)\mod_modbus.obj" \
"$(INTERTMP_DIR)\mod_queue.obj" \
"$(INTERTMP_DIR)\app_debug.obj" \
"$(INTERTMP_DIR)\app_init.obj" \
"$(INTERTMP_DIR)\app_interrupt.obj" \
"$(INTERTMP_DIR)\app_main.obj" \
"$(INTERTMP_DIR)\app_state_machine.obj" \
"$(INTERTMP_DIR)\app_typec_deal.obj" \
"$(INTERTMP_DIR)\cstartup.obj"

OUTPUT_FILE_TYPE	  = binfile
OUTPUT_FILE_EXTENSION = hex
OUTPUT_OTHER_FILES	  = "$(INTERTMP_DIR)\*.asm" \
						    "$(INTERTMP_DIR)\*.obj" \
                            "$(INTERTMP_DIR)\*.map"	\
							"$(INTERTMP_DIR)\*.txt"	\
						    "$(INTERTMP_DIR)\*.xml" \
							"$(INTERTMP_DIR)\*.sbms" \
							"$(INTERTMP_DIR)\*.cscc_bk"



###################################################
#.C文件到.ASM文件
###################################################
"$(INTERTMP_DIR)\drv_adc.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_adc.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_adc.c" -o "$(INTERTMP_DIR)\drv_adc.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_flash.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_flash.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_flash.c" -o "$(INTERTMP_DIR)\drv_flash.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_gpio.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_gpio.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_gpio.c" -o "$(INTERTMP_DIR)\drv_gpio.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_iic.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_iic.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_iic.c" -o "$(INTERTMP_DIR)\drv_iic.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_timer.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_timer.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_timer.c" -o "$(INTERTMP_DIR)\drv_timer.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_uart.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_uart.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_uart.c" -o "$(INTERTMP_DIR)\drv_uart.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_wdt.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_wdt.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\driver\drv_wdt.c" -o "$(INTERTMP_DIR)\drv_wdt.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\cs_common.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\cs_common.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\cs_common.c" -o "$(INTERTMP_DIR)\cs_common.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\sys_register.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\sys_register.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\sys_register.c" -o "$(INTERTMP_DIR)\sys_register.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\system_csu39fx10.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\system_csu39fx10.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\system_csu39fx10.c" -o "$(INTERTMP_DIR)\system_csu39fx10.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\csu39fx10_clkmu.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\fwlib\csu39fx10_clkmu.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\fwlib\csu39fx10_clkmu.c" -o "$(INTERTMP_DIR)\csu39fx10_clkmu.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\csu39fx10_exti.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\fwlib\csu39fx10_exti.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\fwlib\csu39fx10_exti.c" -o "$(INTERTMP_DIR)\csu39fx10_exti.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\csu39fx10_rstmu.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\fwlib\csu39fx10_rstmu.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\fwlib\csu39fx10_rstmu.c" -o "$(INTERTMP_DIR)\csu39fx10_rstmu.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\csu39fx10_syscfg.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\fwlib\csu39fx10_syscfg.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\fwlib\csu39fx10_syscfg.c" -o "$(INTERTMP_DIR)\csu39fx10_syscfg.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_adc_convert.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_adc_convert.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_adc_convert.c" -o "$(INTERTMP_DIR)\mod_adc_convert.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_dcdc.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_dcdc.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_dcdc.c" -o "$(INTERTMP_DIR)\mod_dcdc.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_display.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_display.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_display.c" -o "$(INTERTMP_DIR)\mod_display.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_input_output.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_input_output.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_input_output.c" -o "$(INTERTMP_DIR)\mod_input_output.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_key.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_key.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_key.c" -o "$(INTERTMP_DIR)\mod_key.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_modbus.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_modbus.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_modbus.c" -o "$(INTERTMP_DIR)\mod_modbus.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_queue.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_queue.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\module\mod_queue.c" -o "$(INTERTMP_DIR)\mod_queue.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\app_debug.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_debug.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_debug.c" -o "$(INTERTMP_DIR)\app_debug.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\app_init.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_init.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_init.c" -o "$(INTERTMP_DIR)\app_init.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\app_interrupt.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_interrupt.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_interrupt.c" -o "$(INTERTMP_DIR)\app_interrupt.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\app_main.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_main.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_main.c" -o "$(INTERTMP_DIR)\app_main.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\app_state_machine.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_state_machine.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_state_machine.c" -o "$(INTERTMP_DIR)\app_state_machine.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\app_typec_deal.asm" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_typec_deal.c"
	$(CC) $(CFLAGS)  "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\app\app_typec_deal.c" -o "$(INTERTMP_DIR)\app_typec_deal.asm" 
	$(ECHO)

#main.asm :
#	$(CC) $(CFLAGS) "$(PROJ_PATH)\main.c" -o "$(PROJ_PATH)\main.asm"

###################################################
#.ASM文件到.OBJ文件
###################################################
"$(INTERTMP_DIR)\drv_adc.obj" : "$(INTERTMP_DIR)\drv_adc.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\drv_adc.asm" -o "$(INTERTMP_DIR)\drv_adc.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_flash.obj" : "$(INTERTMP_DIR)\drv_flash.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\drv_flash.asm" -o "$(INTERTMP_DIR)\drv_flash.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_gpio.obj" : "$(INTERTMP_DIR)\drv_gpio.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\drv_gpio.asm" -o "$(INTERTMP_DIR)\drv_gpio.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_iic.obj" : "$(INTERTMP_DIR)\drv_iic.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\drv_iic.asm" -o "$(INTERTMP_DIR)\drv_iic.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_timer.obj" : "$(INTERTMP_DIR)\drv_timer.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\drv_timer.asm" -o "$(INTERTMP_DIR)\drv_timer.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_uart.obj" : "$(INTERTMP_DIR)\drv_uart.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\drv_uart.asm" -o "$(INTERTMP_DIR)\drv_uart.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\drv_wdt.obj" : "$(INTERTMP_DIR)\drv_wdt.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\drv_wdt.asm" -o "$(INTERTMP_DIR)\drv_wdt.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\cs_common.obj" : "$(INTERTMP_DIR)\cs_common.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\cs_common.asm" -o "$(INTERTMP_DIR)\cs_common.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\sys_register.obj" : "$(INTERTMP_DIR)\sys_register.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\sys_register.asm" -o "$(INTERTMP_DIR)\sys_register.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\system_csu39fx10.obj" : "$(INTERTMP_DIR)\system_csu39fx10.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\system_csu39fx10.asm" -o "$(INTERTMP_DIR)\system_csu39fx10.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\csu39fx10_clkmu.obj" : "$(INTERTMP_DIR)\csu39fx10_clkmu.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\csu39fx10_clkmu.asm" -o "$(INTERTMP_DIR)\csu39fx10_clkmu.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\csu39fx10_exti.obj" : "$(INTERTMP_DIR)\csu39fx10_exti.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\csu39fx10_exti.asm" -o "$(INTERTMP_DIR)\csu39fx10_exti.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\csu39fx10_rstmu.obj" : "$(INTERTMP_DIR)\csu39fx10_rstmu.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\csu39fx10_rstmu.asm" -o "$(INTERTMP_DIR)\csu39fx10_rstmu.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\csu39fx10_syscfg.obj" : "$(INTERTMP_DIR)\csu39fx10_syscfg.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\csu39fx10_syscfg.asm" -o "$(INTERTMP_DIR)\csu39fx10_syscfg.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_adc_convert.obj" : "$(INTERTMP_DIR)\mod_adc_convert.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\mod_adc_convert.asm" -o "$(INTERTMP_DIR)\mod_adc_convert.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_dcdc.obj" : "$(INTERTMP_DIR)\mod_dcdc.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\mod_dcdc.asm" -o "$(INTERTMP_DIR)\mod_dcdc.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_display.obj" : "$(INTERTMP_DIR)\mod_display.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\mod_display.asm" -o "$(INTERTMP_DIR)\mod_display.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_input_output.obj" : "$(INTERTMP_DIR)\mod_input_output.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\mod_input_output.asm" -o "$(INTERTMP_DIR)\mod_input_output.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_key.obj" : "$(INTERTMP_DIR)\mod_key.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\mod_key.asm" -o "$(INTERTMP_DIR)\mod_key.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_modbus.obj" : "$(INTERTMP_DIR)\mod_modbus.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\mod_modbus.asm" -o "$(INTERTMP_DIR)\mod_modbus.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\mod_queue.obj" : "$(INTERTMP_DIR)\mod_queue.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\mod_queue.asm" -o "$(INTERTMP_DIR)\mod_queue.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\app_debug.obj" : "$(INTERTMP_DIR)\app_debug.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\app_debug.asm" -o "$(INTERTMP_DIR)\app_debug.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\app_init.obj" : "$(INTERTMP_DIR)\app_init.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\app_init.asm" -o "$(INTERTMP_DIR)\app_init.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\app_interrupt.obj" : "$(INTERTMP_DIR)\app_interrupt.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\app_interrupt.asm" -o "$(INTERTMP_DIR)\app_interrupt.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\app_main.obj" : "$(INTERTMP_DIR)\app_main.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\app_main.asm" -o "$(INTERTMP_DIR)\app_main.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\app_state_machine.obj" : "$(INTERTMP_DIR)\app_state_machine.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\app_state_machine.asm" -o "$(INTERTMP_DIR)\app_state_machine.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\app_typec_deal.obj" : "$(INTERTMP_DIR)\app_typec_deal.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\app_typec_deal.asm" -o "$(INTERTMP_DIR)\app_typec_deal.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\cstartup.obj" : "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\cstartup.asm"
	$(ASM) $(ASMFLAGS) -gstab "D:\ZXV\负责项目\CAPS712\CAPS712_20250626_V2\source\chip\misc\cstartup.asm" -o "$(INTERTMP_DIR)\cstartup.obj" 
	$(ECHO)

#main.obj :
#	$(ASM) $(ASMFLAGS) "$(PROJ_PATH)\main.asm" -o "$(PROJ_PATH)\main.obj"

###################################################
#命令定义处
###################################################
.PHONY : build
prepare : prebuild outputdir

re_prepare : prebuild outputdir clean_buildfile

build  : prebuild outputdir compiler_all_c_files compiler_all_asm_files $(OUTPUT_FILE_TYPE) postbuild

.PHONY : rebuild
rebuild: prebuild outputdir clean_buildfile build postbuild

output_file : $(OUTPUT_FILE_TYPE) postbuild

.PHONY : clean
clean :
	$(RM)  "$(INTERTMP_DIR)\dee"
	$(RM)  "$(INTERTMP_DIR)\*.lik"
	$(RM)  "$(INTERTMP_DIR)\*.lst"
	$(RM)  $(OUTPUT_OTHER_FILES)
	$(RM)  "$(OUTPUT_DIR)\$(PROJ_NAME).$(OUTPUT_FILE_EXTENSION)"
	$(RM)  "$(INTERTMP_DIR)\$(PROJ_NAME).dat"

clean_buildfile :
	$(RM)  $(OUTPUT_OTHER_FILES)
	$(RM)  "$(OUTPUT_DIR)\$(PROJ_NAME).$(OUTPUT_FILE_EXTENSION)"
    
outputdir:
	if not exist "$(OUTPUT_DIR)/$(NULL)" mkdir "$(OUTPUT_DIR)"
	if not exist "$(INTERTMP_DIR)/$(NULL)" mkdir "$(INTERTMP_DIR)"
	
binfile: 
	$(LINKER) $(LINKFLAGS) -s "$(INTERTMP_DIR)\Script.lik"
	
libfile: 
	$(LIBMAKER) $(LIBMAKERFLAGS) -o $(OBJ_FILES) -lib "$(OUTPUT_DIR)\$(PROJ_NAME).lib"
	
compiler_all_c_files : $(ASM_FILES)

compiler_all_asm_files: $(OBJ_FILES)

prebuild :
	

postbuild :
	

