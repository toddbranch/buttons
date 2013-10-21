# button

Library for working with buttons on the MSP430.

Example code included in main.c.

## Functions

`void configureP1PinAsButton(char pin)`

Configures pin as input with internal pull-up resistor.

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
