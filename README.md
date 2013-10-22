# button

Library for working with buttons on the MSP430.

Example code included in main.c.

## Functions

- `void configureP1PinAsButton(char pin)`
    - Configures pin as input with internal pull-up resistor
    - Pin settings
        - P1DIR = 0 (input)
        - P1REN = 1 (enable internal pull-up/pull-down networks)
        - P1OUT = 1 (configure as pull-up)
    - Usage:
        - `configureP1PinAsButton(BIT3);`
            - Configures Port 1, Pin 3 as button
        - `configureP1PinAsButton(BIT0|BIT1|BIT2);`
            - Configures Port 1, Pins 0, 1, and 2 as button

`char isP1ButtonReleased(char pin)`

Returns one if button pin is high, zero if button pin is low.

`void waitForP1ButtonRelease(char pin)`

Blocks while button pin is low.  Debounces on release.

`char isP1ButtonPressed(char pin)`

Returns one if button pin is low, zero if button pin is high.

`void debounce()`

Delays for 1000 clock cycles.

## License

Anyone is free to use and modify this for any purpose, provided they document it.
