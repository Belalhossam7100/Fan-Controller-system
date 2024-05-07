################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc_mine.c \
../fan_controller.c \
../gpio.c \
../lcd.c \
../motor_mine.c \
../pwm_mine.c \
../temp_sensor_mine.c 

OBJS += \
./adc_mine.o \
./fan_controller.o \
./gpio.o \
./lcd.o \
./motor_mine.o \
./pwm_mine.o \
./temp_sensor_mine.o 

C_DEPS += \
./adc_mine.d \
./fan_controller.d \
./gpio.d \
./lcd.d \
./motor_mine.d \
./pwm_mine.d \
./temp_sensor_mine.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


