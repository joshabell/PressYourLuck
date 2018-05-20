#include "LightUpdater.h"
#include "Wheel.h"
#include "Button.h"

static const unsigned int NeoPixelPin = 6;
static const unsigned int ButtonInterruptPin = 2;

/**
 * Starting default delay time. Long presses can step thru other values.
 * 
 */

int delayTime = 50;

LightUpdater lights(NeoPixelPin);
Wheel wheel(&lights);
Button button(ButtonInterruptPin, 3000);

void setup()
{
  	wheel.reset();
    button.init();
}

void loop()
{
	wheel.step();
    if (button.newPress())
    {
        button.lockout(5000);
        if (button.isLongPress())
        {
            delayTime = (delayTime == 150 ? 50 : 150);
            wheel.step();delay(100);
            wheel.step();delay(100);
            wheel.step();delay(100);
            delay(3000);
        }
        else
        {
            delay(4000);
        }
    }
    delay(delayTime);
}
