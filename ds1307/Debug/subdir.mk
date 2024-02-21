################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DIO-progarm.c \
../DS1307_program.c \
../PORT_program.c \
../TWI_program.c \
../main.c 

OBJS += \
./CLCD_program.o \
./DIO-progarm.o \
./DS1307_program.o \
./PORT_program.o \
./TWI_program.o \
./main.o 

C_DEPS += \
./CLCD_program.d \
./DIO-progarm.d \
./DS1307_program.d \
./PORT_program.d \
./TWI_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


