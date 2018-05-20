#include "Button.h"
#include "LightUpdater.h"
#include "Wheel.h"


static const unsigned int NeoPixelPin = 6;
static const unsigned int ButtonInterruptPin = 2;

/**
 * Starting default speed/delay. Long presses can update this.
 */

int delayTime = 50;

LightUpdater lights(NeoPixelPin);
Wheel wheel(&lights);
Button button(ButtonInterruptPin, 3000);

void setup() {
  wheel.reset();
  button.init();
}

void loop() {
  wheel.step();
  if (button.newPress()) {
    // Without this, you can "single step" the LED
    button.lockout(5000);
    // Is the user holding the button to request a speed change?
    if (button.isLongPress()) {
      delayTime = (delayTime == 150 ? 50 : 150);
      // Give some indication to the user that the speed change was received
      wheel.step();
      delay(100);
      wheel.step();
      delay(100);
      wheel.step();
      delay(100);
      delay(3000);
    } else {
      delay(4000);
    }
  }
  delay(delayTime);
}
