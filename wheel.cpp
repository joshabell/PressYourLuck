#include <stdio.h>

#include "Wheel.h"

/*
 *
 *  The first three LEDs are the target, so there are essentially only 48 positions
 *  in the "track".
 *
 *     T(3)
 *     T(2) X(4) X(5) X(6) ... X(50)
 *     T(1)
 */

static const int MaxPositions = 48;

Wheel::Wheel(Updater *updater) : m_updater(updater), m_position(0)
{

}

Wheel::~Wheel()
{

}

void Wheel::step()
{
    m_position++;
    if (m_position == MaxPositions)
    {
        m_position = 0;
    }    
    doUpdate();
}

void Wheel::doUpdate()
{
    m_updater->onStart();
    m_updater->onSet(1, LightTypeTarget);
    if (m_position == 0)
    {
        m_updater->onSet(2, LightTypeWinPosition);
    }
    else
    {
        m_updater->onSet(2, LightTypeTrack);
    }
    m_updater->onSet(3, LightTypeTarget);

    for (int i=1;i<MaxPositions;i++)
    {
        if (i == m_position)
        {
            m_updater->onSet(i + 3, LightTypePosition);
        }
        else
        {
            m_updater->onSet(i + 3, LightTypeTrack);
        }
    }
    m_updater->onDone();
}

void Wheel::reset()
{
    m_position = 0;
    doUpdate(); 
}

bool Wheel::isHit()
{
    return (m_position == 0);
}
