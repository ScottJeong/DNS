################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ethernet/socket.c \
../src/Ethernet/wizchip_conf.c 

OBJS += \
./src/Ethernet/socket.o \
./src/Ethernet/wizchip_conf.o 

C_DEPS += \
./src/Ethernet/socket.d \
./src/Ethernet/wizchip_conf.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ethernet/%.o: ../src/Ethernet/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0 -D__USE_ROMDIVIDE -D__USE_LPCOPEN -D__LPC11EXX__ -D__REDLIB__ -I"D:\06.Study\DNS\workspace\W5500-EVB_DNS\src" -I"D:\06.Study\DNS\workspace\W5500-EVB_DNS\src\Ethernet" -I"D:\06.Study\DNS\workspace\W5500-EVB_DNS\src\Internet" -I"D:\06.Study\DNS\workspace\W5500-EVB_DNS\src\Internet\DHCP" -I"D:\06.Study\DNS\workspace\wiznet_evb_w5500evb_board\inc" -I"D:\06.Study\DNS\workspace\lpc_chip_11exx\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


