#if !defined(_UPDATER_INTERFACE_H_)
#define _UPDATER_INTERFACE_H_

// There are 4 possible states that an light could be in:

enum LightType
{
    LightTypePosition,   //< The "spinner" position
    LightTypeTarget,     //< The "target" indicators
    LightTypeTrack,      //< The ring positions which are not the "spinner"
    LightTypeWinPosition //< The "spinner" is within the "target"
};

/**
 * Interface used to recieve updates regarding the state of the circle. This was done with
 * an interface for testability (a console program could implement this or an implementation could
 * be provided that actually interfaces to hardware.
 */

class Updater
{
  public:
    virtual void onStart() = 0;
    virtual void onDone() = 0;
    virtual void onSet(int index, LightType type) = 0;
};

#endif // (_UPDATER_INTERFACE_H_)