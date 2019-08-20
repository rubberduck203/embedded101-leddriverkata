#include "CppUTest/TestHarness.h"

#include "../src/Driver.h"

TEST_GROUP(ExampleTests)
{
    /*setup goes here*/
};

const uint8_t LEDS_OFF = 0x00;
const uint8_t LEDS_ON = 0xFF;

TEST(ExampleTests, Test1)
{
    uint8_t leds = LEDS_OFF;
    LedDriver leddriver(leds);
    CHECK(true);
}

TEST(ExampleTests, initialization)
{
    uint8_t leds = LEDS_ON;
    LedDriver leddriver(leds);
    BYTES_EQUAL(LEDS_OFF, leds);
}

TEST(ExampleTests, turnSingleLedOn)
{
    uint8_t leds = LEDS_OFF;
    LedDriver leddriver(leds);
    leddriver.turnOnAtIndex(0);
    BYTES_EQUAL(0x01, leds);
}

TEST(ExampleTests, turnAnotherSingleLedOn) 
{
    uint8_t leds = LEDS_OFF;
    LedDriver leddriver(leds);
    leddriver.turnOnAtIndex(7);
    BYTES_EQUAL(0x80, leds);
}

TEST(ExampleTests, turnOnTwoLeds)
{
    uint8_t leds = LEDS_OFF;
    LedDriver leddriver(leds);
    leddriver.turnOnAtIndex(7);
    leddriver.turnOnAtIndex(0);
    BYTES_EQUAL(0x81, leds);
}