//
// Example program demonstrating the use of button.h
// Toggles Launchpad LEDs on each button push
//

#include <msp430g2553.h>
#include "button.h"

int exampleMain()
{

    WDTCTL = WDTPW|WDTHOLD;

    configureP1PinAsButton(BIT1|BIT2|BIT3);         // configure pins 1, 2, and 3 as buttons

    P1DIR |= BIT0|BIT6;                             // set launchpad LEDs to output

    while (1) {
        char buttons[] = {BIT1, BIT2, BIT3};
        char pressedButton = pollP1Buttons(buttons, 3);
        
        switch (pressedButton) {
            case BIT1:
                // do something in response 
                break;
            case BIT2:
                // do something in response
                break;
            case BIT3:
                // toggle LEDs and wait for release
                P1OUT ^= BIT0|BIT6;
                waitForP1ButtonRelease(BIT3);
                break;
        }
    }

    return 0;
}
