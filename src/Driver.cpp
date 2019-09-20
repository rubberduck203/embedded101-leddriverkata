#include <stdint.h>
#include "Driver.h"

LedDriver::LedDriver(volatile uint8_t& leds) : _ledzepelins(leds)
{
    _ledzepelins = 0x00;
}

uint8_t createLedMaskForIndex(uint8_t index)
{
    return 1 << index;
}

void LedDriver::turnOnAtIndex(uint8_t index)
{
    _ledzepelins |= createLedMaskForIndex(index);
}

void LedDriver::turnOffAtIndex(uint8_t index)
{
    _ledzepelins &= ~createLedMaskForIndex(index);
}

void LedDriver::turnAllOn()
{
    _ledzepelins = 0xFF;
}

void LedDriver::turnAllOff()
{
    _ledzepelins = 0x00;
}