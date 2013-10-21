#include <msp430.h>
#include "button.h"

void configureP1PinAsButton(char pin)
{
    P1DIR &= ~pin;
    P1OUT |= pin;
    P1REN |= pin;
}

char isP1ButtonReleased(char pin)
{
    return P1IN & pin;
}

void waitForP1ButtonRelease(char pin)
{
    while (!isP1ButtonReleased(pin)) {}
    debounce();
}

char isP1ButtonPressed(char pin)
{
    return !(P1IN & pin);
}

void debounce()
{
    __delay_cycles(1000);
}
