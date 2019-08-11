# MCP3XXX

[![Build Status](https://travis-ci.org/bakercp/MCP3XXX.svg?branch=master)](https://travis-ci.org/bakercp/MCP3XXX)

## Description

An Arduino Library supporting the MCP3XXX series of ADC SPI chips, including MCP3002, MCP3004, MCP3008 and others.

## Features

_MCP3XXX_ is a simple library enabling access to the MCP3XXX series of ADC SPI chips. Support for differential and psuedo-differential reads. Supports MCP3002, MCP3004 and MCP3008. Support for 12 and 13 bit chips such as MCP3202, MCP3204, MCP3208 and MCP3304 will be added when they can officially tested.  When not reading data, the chip goes into standby / low power mode. On the MCP3004/3008, for example the standby current is only 5 nA.

## Background

_Why do I need this?_ You need additional analog inputs.

### Setup
#### Basic

To read from analog input 0 on an MCP3002 using the default hardware SPI pins, you might use:


```c++
#include <MCP3XXX.h>


// Create an instance of the MCP3002 ADC.
MCP3002 adc;


void setup()
{
  Serial.begin(9600);

  // Use the default SPI hardware interface.
  adc.begin();
}

void loop()
{
  // Read from channel 0 and print.
  Serial.print(adc.analogRead(0));
  delay(10);
}
```

## Troubleshooting

If you encounter connection issues, confirm that the maximum sampling frequency you are using is supported by voltage of your board. For example, the aliases `MCP3002`, `MCP3004`, `MCP3008` are defined as:

```cpp
/// \brief A typedef for the MCP3002.
/// Max clock frequency for 2.7V: 1200000 Hz
/// Max clock frequency for 5.0V: 3200000 Hz
/// \sa http://ww1.microchip.com/downloads/en/DeviceDoc/21294E.pdf
typedef MCP3XXX_<10, 2, 1200000, 2> MCP3002;

/// \brief A typedef for the MCP3004.
/// Max clock frequency for 2.7V: 1350000 Hz
/// Max clock frequency for 5.0V: 3600000 Hz
/// \sa http://ww1.microchip.com/downloads/en/DeviceDoc/21295C.pdf
typedef MCP3XXX_<10, 4, 1350000> MCP3004;

/// \brief A typedef for the MCP3008.
/// Max clock frequency for 2.7V: 1350000 Hz
/// Max clock frequency for 5.0V: 3600000 Hz
/// \sa http://ww1.microchip.com/downloads/en/DeviceDoc/21295C.pdf
typedef MCP3XXX_<10, 8, 1350000> MCP3008;
```

Thus, higher voltage boards allow a higher sampling rate.

## Examples

See the included examples for further usage options.

## Developer Notes

Currently the library has been tested with MCP3002 and MCP3008. MCP3004 support is also included because it uses the same SPI command structure as the MCP3008.

### Datasheets

- [MCP3002](http://ww1.microchip.com/downloads/en/DeviceDoc/21294E.pdf)
- [MCP3004/3008](http://ww1.microchip.com/downloads/en/devicedoc/21295c.pdf)
- [MCP3202](http://ww1.microchip.com/downloads/en/DeviceDoc/21034D.pdf)
- [MCP3204/3208](http://ww1.microchip.com/downloads/en/DeviceDoc/21298c.pdf)
- [MCP3302/3304](http://ww1.microchip.com/downloads/en/DeviceDoc/21697e.pdf)

## Changelog

See [CHANGELOG.md](CHANGELOG.md).

## License

See [LICENSE.md](LICENSE.md).
