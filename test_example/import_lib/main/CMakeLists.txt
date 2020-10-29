idf_component_register(SRCS "hello_world_main.c"
                    INCLUDE_DIRS "")


# VSF lib

cmake_minimum_required(VERSION 3.13)

set(VSF_HAL_CHIP_VENDOR     Espressif)
#set(VSF_HAL_CHIP_SERIES    ESP32)
#set(VSF_HAL_CHIP_NAME      ESP32)
set(VSF_ARCH_SERIES         rtos)
set(VSF_ARCH_NAME          freertos)

set(CMAKE_C_FLAGS 
  "-std=gnu11 -Wall -fno-builtin -fno-strict-aliasing -fdata-sections -fms-extensions -ffunction-sections"
  CACHE INTERNAL "c compiler flags")
set(CMAKE_CXX_FLAGS 
  "-Wall -fno-builtin -fno-strict-aliasing -fdata-sections -fms-extensions -ffunction-sections"
  CACHE INTERNAL "cxx compiler flags")

include(lib/vsf_dev/source/cmake/extensions.cmake)

add_subdirectory(lib/vsf_dev/source)
target_include_directories(vsf INTERFACE
  lib
  $ENV{IDF_PATH}/components/freertos/include/freertos
)

target_link_libraries(${COMPONENT_LIB} PUBLIC vsf)
