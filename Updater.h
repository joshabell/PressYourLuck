#if !defined(_UPDATER_INTERFACE_H_)
#define _UPDATER_INTERFACE_H_

enum LightType { LightTypePosition, LightTypeTarget, LightTypeTrack, LightTypeWinPosition};

class Updater {
public:
  virtual void onStart() = 0;
  virtual void onDone() = 0;
  virtual void onSet(int index, LightType type) = 0;
};

#endif // (_UPDATER_INTERFACE_H_)