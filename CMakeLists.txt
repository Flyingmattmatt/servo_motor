cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(servo-motor C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(servo-motor
	servo-motor.c
)

pico_enable_stdio_usb(servo-motor 1)
pico_enable_stdio_uart(servo-motor 1)

pico_add_extra_outputs(servo-motor)

target_link_libraries(servo-motor pico_stdlib hardware_pwm)
