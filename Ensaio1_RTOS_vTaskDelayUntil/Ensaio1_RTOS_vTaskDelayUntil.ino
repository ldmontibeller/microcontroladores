#include <Arduino_FreeRTOS.h>

#define EVER (;;)

const TickType_t _148ms = pdMS_TO_TICKS (148); //148ms interval
void setup()
{
  Serial.begin(9600);
  xTaskCreate(timedTask,"Timed Task",100,NULL,1,NULL);
}


void timedTask(void *pvParameters)
{
  TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  for EVER
  { 
    vTaskDelayUntil(&xLastWakeTime,_148ms);
    Serial.println(micros());
  }
}

void loop(){}
