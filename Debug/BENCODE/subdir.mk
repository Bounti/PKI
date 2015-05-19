################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BENCODE/bencode.c \
../BENCODE/bencodeW.c 

OBJS += \
./BENCODE/bencode.o \
./BENCODE/bencodeW.o 

C_DEPS += \
./BENCODE/bencode.d \
./BENCODE/bencodeW.d 


# Each subdirectory must supply rules for building sources it contributes
BENCODE/%.o: ../BENCODE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -std=c11 -Icrypto -O3 -g3 -p -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<" -fPIC
	@echo 'Finished building: $<'
	@echo ' '


