#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "input_manager.hpp"

//=============================================================================

class InputHandler {
public:
  void listen(InputManager::Command);
  virtual void handle(InputManager::Command);
};

//=============================================================================

#endif /* INPUT_HANDLER_HPP */
