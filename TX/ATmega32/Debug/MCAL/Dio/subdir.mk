################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Dio/Dio.c \
../MCAL/Dio/Dio_Config.c 

OBJS += \
./MCAL/Dio/Dio.o \
./MCAL/Dio/Dio_Config.o 

C_DEPS += \
./MCAL/Dio/Dio.d \
./MCAL/Dio/Dio_Config.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Dio/%.o: ../MCAL/Dio/%.c MCAL/Dio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


