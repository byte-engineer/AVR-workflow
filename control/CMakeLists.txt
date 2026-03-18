cmake_minimum_required(VERSION 3.16)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_SIZE avr-size)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(control C CXX)

set(MCU atmega8)

set(CMAKE_C_FLAGS "-mmcu=${MCU} -Os -Wall --save-temps")
set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -Os -Wall --save-temps")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")

# Collect all source files
file(GLOB SRC_FILES
    src/*.c
    src/*.cpp
)

add_executable(firmware.elf ${SRC_FILES})

add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom firmware.elf firmware.hex
    COMMAND ${CMAKE_SIZE} firmware.elf
)