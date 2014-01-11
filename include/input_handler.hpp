#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "input_manager.hpp"

//=============================================================================

class InputHandler {
public:
  enum Command {
    LH_U,
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
    PRESSED = 1,
    HELD = 2,
    RELEASED = 4
  };
  InputHandler();
  void listen(Command, KeyState);
  virtual void handle(Command, KeyState);
};

//=============================================================================

#endif /* INPUT_HANDLER_HPP */
