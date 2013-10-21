#ifndef _BUTTON_H
#define _BUTTON_H

//
// Configures pin as input with internal pull-up resistor.
//
void configureP1PinAsButton(char pin);

//
// Returns one if button pin is high, zero if button pin is low.
char isP1ButtonReleased(char pin);

//
// Blocks while button pin is low.  Debounces on release.
//
void waitForP1ButtonRelease(char pin);

//
// Returns one if button pin is low, zero if button pin is high.
//
char isP1ButtonPressed(char pin);

//
// Delays for 1000 clock cycles.
//
void debounce();

#endif
