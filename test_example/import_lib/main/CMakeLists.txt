idf_component_register(SRCS "hello_world_main.c"
                    INCLUDE_DIRS "")


# VSF lib

cmake_minimum_required(VERSION 3.13)

set(VSF_HAL_CHIP_VENDOR     Espressif)
#set(VSF_HAL_CHIP_SERIES    ESP32)
#set(VSF_HAL_CHIP_NAME      ESP32)
set(VSF_ARCH_SERIES         rtos)
set(VSF_ARCH_NAME          freertos)

include(lib/vsf_dev/source/cmake/extensions.cmake)
add_subdirectory(lib/vsf_dev/source)
target_include_directories(vsf INTERFACE
  lib
  $ENV{IDF_PATH}/components/freertos/include/freertos
)

#target_include_directories(vsf ${IDF_INCLUDE_DIRECTORIES})
#target_compile_options(vsf INTERFACE "-std=gnu11 -Wall -fno-builtin -fno-strict-aliasing -fdata-sections -fms-extensions -ffunction-sections")
target_compile_options(vsf INTERFACE "-std=gnu11")
target_compile_options(vsf INTERFACE "-fdata-sections")
target_compile_options(vsf INTERFACE "-ffunction-sections")
target_compile_options(vsf INTERFACE "-fms-extensions")
target_compile_options(vsf INTERFACE "-Wall")
target_compile_options(vsf INTERFACE "-fno-builtin")
target_compile_options(vsf INTERFACE "-fno-strict-aliasing")
#target_compile_definitions(vsf ${IDF_COMPILE_DEFINITIONS})

target_link_libraries(${COMPONENT_LIB} PUBLIC vsf)
