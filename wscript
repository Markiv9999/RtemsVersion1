#
# Hello world Waf script
#
from __future__ import print_function

rtems_version = "6"

try:
    import rtems_waf.rtems as rtems
except:
    print('error: no rtems_waf git submodule')
    import sys
    sys.exit(1)

def init(ctx):
    rtems.init(ctx, version = rtems_version, long_commands = True)

def bsp_configure(conf, arch_bsp):
    # Add BSP specific configuration checks
    pass

def options(opt):
    rtems.options(opt)

def configure(conf):
    rtems.configure(conf, bsp_configure = bsp_configure)

    


def build(bld):
    rtems.build(bld)
    
    # Specify the path to HAL source and header files
    hal_source_dir = './Drivers/STM32L4xx_HAL_Driver/Src'
    hal_include_dir = './Drivers/STM32L4xx_HAL_Driver/Inc'
    cmsis_include_dir = './Drivers/CMSIS/Include'

    # Collect all HAL source files from the source directory
    hal_sources = [
        'stm32l4xx_hal_uart.c',
        'stm32l4xx_hal_uart_ex.c',
        # Add more HAL source files as needed
    ]

    # Generate the full path for HAL source files
    hal_source_files = [f'{hal_source_dir}/{src}' for src in hal_sources]

    bld(features = 'c cxx cprogram',
        target = 'hello.elf',
        cflags = '-g -O0 -mthumb -mfloat-abi=hard -fstack-usage',
        source = ['hello.cpp',
                  'init.c',
                  'BoardInit.cpp',
                  'UartConsole.cpp'
                  ] + hal_source_files,
        includes=[hal_include_dir, cmsis_include_dir],
		linkflags=['-lstdc++'])
