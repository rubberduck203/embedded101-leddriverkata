#include "CppUTest/TestHarness.h"

#include "../src/Driver.h"

TEST_GROUP(ExampleTests)
{
    /*setup goes here*/
};

const uint8_t LEDS_OFF = 0x00;
const uint8_t LEDS_ON = 0xFF;
const uint8_t DONT_CARE = 0xAA;

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

TEST(ExampleTests, turnOffOneLed)
{
    uint8_t leds = DONT_CARE;
    LedDriver ledDriver(leds);
    ledDriver.turnOnAtIndex(0);
    ledDriver.turnOnAtIndex(1);
    ledDriver.turnOffAtIndex(0);
    BYTES_EQUAL(0x02, leds);
}

TEST(ExampleTests, turnOffAnotherLed)
{
    uint8_t leds = DONT_CARE;
    LedDriver ledDriver(leds);
    ledDriver.turnOnAtIndex(0);
    ledDriver.turnOnAtIndex(1);
    ledDriver.turnOffAtIndex(1);
    BYTES_EQUAL(0x01, leds);
}

TEST(ExampleTests, turnEmAllOn)
{
    uint8_t leds = DONT_CARE;
    LedDriver ledDriver(leds);
    ledDriver.turnAllOn();
    BYTES_EQUAL(0xFF, leds);
}

TEST(ExampleTests, turnEmAllOff)
{
    uint8_t leds = DONT_CARE;
    LedDriver ledDriver(leds);
    ledDriver.turnAllOn();
    ledDriver.turnAllOff();
    BYTES_EQUAL(0x00, leds);
}