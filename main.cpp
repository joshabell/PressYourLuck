#ifndef ARDUINO
#include <iostream>

#include "Wheel.h"

class TestUpdater : public Updater
{
  public:
    virtual void onStart()
    {
        for (int i = 0; i < 51; i++)
        {
            m_leds[i] = '\0';
        }
    }
    virtual void onDone()
    {
        std::cout << (char *)m_leds << std::endl;
    }

    virtual void onSet(int index, LightType type)
    {

        if (type == LightTypePosition)
        {
            m_leds[index-1] = '*';
        }
        else if (type == LightTypeTarget)
        {
            m_leds[index-1] = '+';
        }
        else if (type == LightTypeTrack)
        {
            m_leds[index-1] = '.';
        }
        else if (type == LightTypeWinPosition)
        {
            m_leds[index-1] = '!';
        }
    }

  private:
    char m_leds[51];
};

int main(int, char **)
{
    TestUpdater t;
    Wheel w(&t);

    for (int i=0;i<100;i++)
    {
        w.step();
        if (w.isHit())
        {
            std::cout << "WIN!" << std::endl;
        }
    }
}
#endif
