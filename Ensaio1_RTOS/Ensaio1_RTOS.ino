#include <Arduino_FreeRTOS.h>

#define EVER (;;) //infinite loops funnier

const TickType_t _148ms = pdMS_TO_TICKS(148);
/* Each tick is actually ~16.444 ms in the day it was measured. 
 * The Watchdog Timer varies with the temperature, so does the tick.
 */
void setup() 
{
  Serial.begin(9600);
  //Serial.println(_148ms); //checking how many ticks was taken as 148 ms
  xTaskCreate(timedTask,"Timed Task",100,NULL,1,NULL);
}

void timedTask(void *pvParameters)
{
  for EVER
  { 
    Serial.println(micros());
    vTaskDelay(_148ms);
  }
}

void loop(){}
