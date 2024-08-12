#include <rtems.h>
#include <rtems/irq.h>
#include <rtems/rtems/tasks.h>
#include <stdio.h>
#include <stdlib.h>
#include <stm32l4r9xx.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


#include "BoardInit.h"
#include "UartConsole.h"

extern "C" rtems_task Init(rtems_task_argument ignored); 

rtems_task Init(
  rtems_task_argument ignored
)
{ 
  //Init Board
  BoardInit();
  
  //Console UART
  UartConsole con1;
  con1.Init();

  con1.print("Hello World");
	  
	  
	
  exit( 0 );
}




