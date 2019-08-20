class LedDriver
{
    private:
        volatile uint8_t &_ledzepelins;
    public:
        LedDriver(uint8_t& leds);
        void turnOnAtIndex(uint8_t index);
};