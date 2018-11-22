#include <TimerOne.h>
#include <millisDelay.h>

#define B1_PERIOD 330
#define B2_PERIOD 842

millisDelay _B1;
millisDelay _B2;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(500000); 
  Timer1.attachInterrupt(foregroundFunction); 
  _B1.start(B1_PERIOD);
  _B2.start(B2_PERIOD);
}

void loop() 
{
 backgroundFunction1();
 backgroundFunction2();
}

void foregroundFunction()
{ 
  Serial.print("F: ");
  Serial.println(micros()); 
}

void backgroundFunction1()
{
  if(_B1.isFinished()){
    _B1.repeat();
    Serial.print("B1: ");
    Serial.println(micros());
  }
}

void backgroundFunction2()
{
  if(_B2.isFinished()){
    _B2.repeat();
    Serial.print("B2: ");
    Serial.println(micros());
  }
}
