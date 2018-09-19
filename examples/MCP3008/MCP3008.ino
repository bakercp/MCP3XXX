//
// Copyright (c) 2018 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include <MCP3XXX.h>


MCP3008 adc;


void setup()
{
  Serial.begin(9600);

  // Use the default SPI hardware interface.
  adc.begin();

  // Or use custom pins to use a software SPI interface.
  // adc.begin(SS, MOSI, MISO, SCK);
}

void loop()
{
  for (size_t i = 0; i < adc.numChannels(); ++i)
  {
    Serial.print(adc.analogRead(i));
    
    if (i == adc.numChannels() - 1)
    {
      Serial.println();
    }
    else
    {
      Serial.print(",");
    }
  }

  delay(10);
}
