#include "FlySkyIBus.h"

void setup() 
{
  IBus.begin(Serial);
}

void loop() 
{
  IBus.loop();
  
  for (int i = 0; i < 6; i++)
  {
    Serial.print(IBus.readChannel(i));
    Serial.print('\t');
  }
  
  Serial.println();
}
