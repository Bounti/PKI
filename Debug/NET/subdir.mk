################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NET/query.c \
../NET/socket.c 

OBJS += \
./NET/query.o \
./NET/socket.o 

C_DEPS += \
./NET/query.d \
./NET/socket.d 


# Each subdirectory must supply rules for building sources it contributes
NET/%.o: ../NET/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -std=c11 -Icrypto -O3 -g3 -p -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<" -fPIC
	@echo 'Finished building: $<'
	@echo ' '


