#include "LightUpdater.h"

LightUpdater::LightUpdater(int pin) : m_neoPixels(50, pin, NEO_BGR + NEO_KHZ800)
{
    m_neoPixels.begin();
}
LightUpdater::~LightUpdater()
{
}

void LightUpdater::onStart()
{
}
void LightUpdater::onDone()
{
    m_neoPixels.show();
}
void LightUpdater::onSet(int index, LightType type)
{
    switch (type)
    {
    case LightTypePosition:
        m_neoPixels.setPixelColor(index - 1, m_neoPixels.Color(0, 0, 0xFF)); // Red
        break;
    case LightTypeTarget:
        m_neoPixels.setPixelColor(index - 1, m_neoPixels.Color(0, 0xCC, 0)); // Green
        break;
    case LightTypeTrack:
        m_neoPixels.setPixelColor(index - 1, m_neoPixels.Color(0x00, 0x00, 0x00)); // Off
        break;
    case LightTypeWinPosition:
        m_neoPixels.setPixelColor(index - 1, m_neoPixels.Color(0, 0xFF, 0xFF));
        break;
    };
}
