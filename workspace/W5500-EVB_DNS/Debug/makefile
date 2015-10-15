################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Internet/DNS/subdir.mk
-include src/Internet/DHCP/subdir.mk
-include src/Ethernet/W5500/subdir.mk
-include src/Ethernet/W5300/subdir.mk
-include src/Ethernet/W5200/subdir.mk
-include src/Ethernet/W5100/subdir.mk
-include src/Ethernet/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: W5500-EVB_DNS.axf

# Tool invocations
W5500-EVB_DNS.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"D:\06.Study\DNS\workspace\wiznet_evb_w5500evb_board\Debug" -L"D:\06.Study\DNS\workspace\lpc_chip_11exx\Debug" -Xlinker -Map="W5500-EVB_DNS.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "W5500-EVB_DNS_Debug.ld" -o "W5500-EVB_DNS.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) W5500-EVB_DNS.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "W5500-EVB_DNS.axf" ; arm-none-eabi-objcopy -O ihex "W5500-EVB_DNS.axf" "W5500-EVB_DNS.hex" ; # arm-none-eabi-objcopy -v -O binary "W5500-EVB_DNS.axf" "W5500-EVB_DNS.bin" ; # checksum -p LPC11E36_501 -d "W5500-EVB_DNS.bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
