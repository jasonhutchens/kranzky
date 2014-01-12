#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

//=============================================================================

class InputHandler {
public:
  enum Command {
    START = 0,
    LH_U = 0,
    LH_D,
    LH_L,
    LH_R,
    RH_U,
    RH_D,
    RH_L,
    RH_R,
    PREV,
    NEXT,
    PAUSE,
    EXIT,
    LENGTH,
    UNDEFINED
  };
  enum KeyState {
    ZERO = 0,
    PRESSED = 1,
    HELD = 2,
    RELEASED = 4
  };
  InputHandler();
  void listen(Command, KeyState);
  bool wants(Command, KeyState);
  virtual void handle(Command, KeyState) {};
};

//=============================================================================

#endif /* INPUT_HANDLER_HPP */
