cmake_minimum_required(VERSION 3.16)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_SIZE avr-size)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(AVR_Project C)

set(MCU atmega8)
set(F_CPU 16000000UL)

set(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os -Wall")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")

add_executable(firmware.elf main.c)

add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom firmware.elf firmware.hex
    COMMAND ${CMAKE_SIZE} firmware.elf
)