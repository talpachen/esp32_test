idf_component_register(SRCS "hello_world_main.c"
                    INCLUDE_DIRS "")

idf_component_set_property(main ORIG_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
