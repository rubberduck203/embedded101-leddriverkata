#include <stdint.h>
#include "Driver.h"

const uint8_t LED_ON = 1;

LedDriver::LedDriver(uint8_t& leds) : _ledzepelins(leds)
{
    _ledzepelins = 0x00;
}

void LedDriver::turnOnAtIndex(uint8_t index)
{
    _ledzepelins |= (LED_ON << index);
}