

#include <rtems.h>
#include <rtems/irq.h>
#include <rtems/rtems/tasks.h>
#include <stdio.h>
#include <stdlib.h>
#include <stm32l4r9xx.h>


/* BSP includes */


/* ST includes */
#include "BoardInit.h"
#include "UartConsole.h"
/* Test includes */
// #include "test_nand_routines.h"
// #include "test_image_storage_routines.h"


 // TODO: remove from here.

// command variables for gdb interfaces
//int clean_nand_n = 0; 


//rtems_id frame_handler_tid;

extern "C" rtems_task Init(
  rtems_task_argument ignored
)
{
  BoardInit();
  UartConsole con1;
  con1.Init();
  con1.print("\nHello World from UARTConsole\n");
  printf( "\nHello World from RTEMSConsole\n" );
  exit( 0 );
}


