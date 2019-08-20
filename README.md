# Embedded 101 2019 Class Led Driver Kata

2019 Class' implementation of the [LED Driver Kata](https://github.com/rubberduck203/led-driver-kata).

Running `make` will build and run the tests, then, if successful, compile, link, and generate the `*.hex` file for your avr device.

Stories:
  - [ ] Turn ALL LEDs on
  - [ ] Turn ALL LEDs off
  - [x] Turn Single LED on
  - [ ] Turn Single LED off
  - [x] Initialize the LEDs to off
  - [ ] Oops! It's active low!

## Supported Make targets

- all: Run tests, build hex file, display size
- avr: Build hex file, display size
- size: Display the AVR Memory Usage
- check: Run tests
- clean: Delete all files in all `bin` and `obj` directories
- install: Use AVRDUDE to upload your program to the device

## Mocks

Mocks are stored in the `test/mocks` directory and made available as system includes in the test builds.
This allows you to reference `<avr/io.h>` and `<util/delay.h>` in your code under test without referencing the real AVR include files, which is problematic as the avr-asm has some instructions that are unavailable to the regular gcc compiler.

The `PORT_t` definition in `<avr/io.h>` should be updated according to your particular target device.
The real headers for these are available in the avr-gcc installation directory under `avr/include/avr`.

More mocks may be added in this directory as needed. The test makefile will automatically put them on the path as system (angle bracket) includes.

