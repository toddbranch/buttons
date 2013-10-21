//
// Example program demonstrating the use of button.h
// Toggles Launchpad LEDs on each button push
//

#include <msp430g2553.h>
#include "button.h"

int main()
{

    WDTCTL = WDTPW|WDTHOLD;

    configureP1PinAsButton(BIT3);

    P1DIR |= BIT0|BIT6;

    while (1) {
        while (isP1ButtonReleased(BIT3)) {}
        
        P1OUT ^= BIT0|BIT6;

        waitForP1ButtonRelease(BIT3);
    }

    return 0;
}
