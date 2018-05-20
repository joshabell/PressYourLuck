#if !defined(_WHEEL_H_)
#define _WHEEL_H_

#include "Updater.h"

/**
 * Wheel assumes an updater which has 50 lights.
 * Lights 1, 2, and 3 are the "target".
 * Lights indexes start at 1 and go to 50
 * 
 */

class Wheel
{
  public:
    Wheel(Updater *updater);
    virtual ~Wheel();

    void step();
    void reset();
    bool isHit();

private:
    void doUpdate();

  private:
    Updater *m_updater;
    int      m_maxLights;
    int      m_position;
};

#endif //_WHEEL_H_