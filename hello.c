/*
 * Hello world example
 */
#include <rtems.h>
#include <stdlib.h>
#include <stdio.h>
#include <stm32l4r9_module_uart.h>

rtems_task Init(
  rtems_task_argument ignored
)
{
  uart_write_buf(USART2, "Success\n", 30);
  exit( 0 );
}
