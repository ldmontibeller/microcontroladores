#include <Arduino_FreeRTOS.h>
#include "timers.h"

#define EVER (;;)

#define PERIOD_T1 (pdMS_TO_TICKS(330))
#define PERIOD_T2 (pdMS_TO_TICKS(842))
#define PERIOD_T3 (pdMS_TO_TICKS(500))

TimerHandle_t xT1, xT2, xT3;
BaseType_t xT1Started, xT2Started, xT3Started;

void setup()
{  
  Serial.begin(9600);
  
  xT1 = xTimerCreate("Task 1",PERIOD_T1,pdTRUE,0,prvT1);
   if(xT1 != NULL)
    {
      xT1Started = xTimerStart(xT1,0);
      while(xT1Started != pdPASS){}   
    }
   else
    {
      Serial.println("Creation of Task 1 failed");  
    }

  xT2 = xTimerCreate("Task 2",PERIOD_T2,pdTRUE,0,prvT2);
   if(xT2 != NULL)
    {
      xT2Started = xTimerStart(xT2,0);
      while(xT2Started != pdPASS){}   
    }
    else
    {
      Serial.println("Creation of Task 2 failed");  
    }
  
  xT3 = xTimerCreate("Task 3",PERIOD_T3,pdTRUE,0,prvT3);
    if(xT3 != NULL)
    {
      xT3Started = xTimerStart(xT3,0);
      while(xT3Started != pdPASS){}   
    }
     else
    {
      Serial.println("Creation of Task 3 failed");
    }
}

void prvT1(TimerHandle_t xTimer1)
{
  Serial.print("T1: ");
  Serial.println(micros());
}

void prvT2(TimerHandle_t xTimer2)
{
  Serial.print("T2: ");
  Serial.println(micros());
}

void prvT3(TimerHandle_t xTimer3)
{
  Serial.print("T3: ");
  Serial.println(micros());
}

void loop(){}
