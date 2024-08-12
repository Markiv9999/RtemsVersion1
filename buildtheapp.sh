#!/bin/bash

./waf configure --rtems=$HOME/quick-start/rtems-tool-suite/6.1-rc3 --rtems-bsp=arm/stm32l4

./waf 
