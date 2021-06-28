cmake_minimum_required(VERSION 3.10...3.17 FATAL_ERROR)

set(OUTPUT_NAME encoder_explorer)
project(${OUTPUT_NAME})

add_executable(${OUTPUT_NAME} ${CMAKE_CURRENT_LIST_DIR}/demo.cpp)

target_include_directories(${OUTPUT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(${OUTPUT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

# Pull in pico libraries that we need
target_link_libraries(${OUTPUT_NAME} ioexpander pico_stdlib breakout_encoder pico_explorer pico_graphics st7789 hardware_i2c)
#target_link_libraries(${OUTPUT_NAME} pico_stdlib breakout_encoder pico_explorer)

# enable usb output, disable uart output
pico_enable_stdio_usb(${OUTPUT_NAME} 1)
pico_enable_stdio_uart(${OUTPUT_NAME} 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(${OUTPUT_NAME})
