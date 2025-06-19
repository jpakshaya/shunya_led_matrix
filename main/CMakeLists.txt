idf_component_register(SRCS "main.c" "MAP_LED.c" "MAP_COLOR.c"
                    PRIV_REQUIRES spi_flash
                    INCLUDE_DIRS "."
                    REQUIRES driver led_strip
                    )
