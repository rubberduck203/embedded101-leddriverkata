class LedDriver
{
    private:
        volatile uint8_t &_ledzepelins;
    public:
        LedDriver(volatile uint8_t& leds);
        void turnOnAtIndex(uint8_t index);
        void turnOffAtIndex(uint8_t index);
        void turnAllOn();
        void turnAllOff();
};