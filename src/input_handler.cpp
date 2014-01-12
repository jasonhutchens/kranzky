#include "input_handler.hpp"
#include "input_manager.hpp"

//=============================================================================

InputHandler::InputHandler() {
  InputManager::instance().add_handler(this);
}

//------------------------------------------------------------------------------

void
InputHandler::listen(Command command, KeyState key_state) {
}

//------------------------------------------------------------------------------

bool
InputHandler::wants(Command command, KeyState key_state) {
  return true;
}

//=============================================================================
