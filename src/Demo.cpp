#include <avr/io.h>
#include <util/delay.h>

#include "Driver.h"

int main(void) 
{   
    //TODO: setup and loop

    DDRD = 0xFF; //output
    LedDriver ledDriver(PORTD);

    for(;;)
    {
        ledDriver.turnAllOn();
        _delay_ms(500);
        ledDriver.turnAllOff();
        _delay_ms(1000);

        for(int8_t i = 0; i < 8; i++)
        {
            ledDriver.turnOnAtIndex(i);
            _delay_ms(500);
        }

        for(int8_t i = 0; i < 8; i++)
        {
            ledDriver.turnOffAtIndex(i);
            _delay_ms(500);
        }
    }

    return 0;
}