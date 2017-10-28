################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Dir_handler.cpp \
../src/Log.cpp \
../src/Opt_chars.cpp \
../src/Opt_word.cpp \
../src/Options.cpp \
../src/main.cpp 

OBJS += \
./src/Dir_handler.o \
./src/Log.o \
./src/Opt_chars.o \
./src/Opt_word.o \
./src/Options.o \
./src/main.o 

CPP_DEPS += \
./src/Dir_handler.d \
./src/Log.d \
./src/Opt_chars.d \
./src/Opt_word.d \
./src/Options.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


