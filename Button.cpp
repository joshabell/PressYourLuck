#include "Button.h"
#include <arduino.h>

static bool Button::m_buttonHit = false;
static unsigned long Button::m_lockoutUntil = 0;

Button::Button(int pin, int longPressTime) : m_pin(pin), m_longPressTime(longPressTime)
{
}

Button::~Button()
{
}

void Button::onInterrupt()
{
    if (m_lockoutUntil && (millis() < m_lockoutUntil))
    {
        // Ignore hit due to lockout
    }
    else
    {
        Button::m_buttonHit = true;
        m_lockoutUntil = 0;
    }
}

void Button::init()
{
    pinMode(m_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(m_pin), Button::onInterrupt, LOW);
}

bool Button::newPress()
{
    bool res = false;
    if (m_buttonHit)
    {
        res = true;
        m_buttonHit = false;
    }
    return res;
}

bool Button::isLongPress()
{
    int timeToHold = m_longPressTime;
    while ((digitalRead(m_pin) == 0) && (timeToHold > 0))
    {
        timeToHold -= 10;
        delay(10);
    }
    m_buttonHit = false;

    return (timeToHold <= 0);
}

void Button::lockout(int time)
{
    m_lockoutUntil = millis() + time;
}