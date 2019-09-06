################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lista_enc.c \
../src/lista_encadeada.c \
../src/no.c 

OBJS += \
./src/lista_enc.o \
./src/lista_encadeada.o \
./src/no.o 

C_DEPS += \
./src/lista_enc.d \
./src/lista_encadeada.d \
./src/no.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


