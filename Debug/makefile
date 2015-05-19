################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TEST/subdir.mk
-include SHA/subdir.mk
-include RSA/subdir.mk
-include NET/subdir.mk
-include FILE/subdir.mk
-include ERROR/subdir.mk
-include CLIENT/subdir.mk
-include CERTIFICAT/subdir.mk
-include BENCODE/subdir.mk
-include BASE/subdir.mk
-include AES/subdir.mk
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
all: PKI_SERVER

# Tool invocations
PKI_SERVER: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	gcc -p -o "PKI_SERVER" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) PKI_SERVER
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
