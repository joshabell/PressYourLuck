#if !defined(_LIGHT_UPDATER_H_)
#define _LIGHT_UPDATER_H_

#include <Adafruit_NeoPixel.h>
#include "Updater.h"

class LightUpdater : public Updater
{
  public:
    LightUpdater(int pin);
    virtual ~LightUpdater();

  public:
  public: // Updater Interface
    virtual void onStart();
    virtual void onDone();
    virtual void onSet(int index, LightType type);

  private:
    Adafruit_NeoPixel m_neoPixels;
};

#endif // _LIGHT_UPDATER_H_