#include <msp430.h>
#include "button.h"

#define TRUE 1

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

char pollP1Buttons(char buttonsToPoll[], char numberOfButtonsToPoll)
{
    int i;

    while (TRUE)
    {
        for (i = 0; i < numberOfButtonsToPoll; i++) {
            if (isP1ButtonPressed(buttonsToPoll[i]))
            {
                return buttonsToPoll[i];
            }
        }
    }
}

void debounce()
{
    __delay_cycles(1000);
}
