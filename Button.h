#if !defined(_BUTTON_H_)
#define _BUTTON_H_

class Button {
public:
  Button(int pin, int longPressTime);
  virtual ~Button();

  void init();

  bool newPress();
  bool isLongPress();
  void lockout(int time);

private:
  static void onInterrupt();

private:
  static bool m_buttonHit;
  static unsigned long m_lockoutUntil;
  int m_pin;
  int m_longPressTime;
};

#endif // _BUTTON_H_