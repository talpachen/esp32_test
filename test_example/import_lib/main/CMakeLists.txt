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


