#include "input_handler.hpp"
#include "input_manager.hpp"

//=============================================================================

InputManager&
InputManager::instance() {
  static InputManager _instance;
  return _instance;
}

//------------------------------------------------------------------------------

void
InputManager::init(Gosu::Window* window) {
  _inputs.resize(InputHandler::LENGTH, InputHandler::ZERO);
}

//------------------------------------------------------------------------------

void
InputManager::add_handler(InputHandler* handler) {
  _handlers.push_back(handler);
}

//------------------------------------------------------------------------------

void
InputManager::update(double _dt) {
  for (InputHandler::Command command = InputHandler::START; command < InputHandler::LENGTH; ++command) {
    InputHandler::KeyState key_state = _inputs[command];
    // set the held flag based on what we've pressed and released this frame
    if (key_state&InputHandler::PRESSED) {
      key_state = static_cast<InputHandler::KeyState>(key_state | InputHandler::HELD);
    }
    if (key_state&InputHandler::RELEASED) {
      key_state = static_cast<InputHandler::KeyState>(key_state ^ InputHandler::HELD);
    }
    // notify the handlers
    for (std::vector<InputHandler*>::iterator it = _handlers.begin(); it != _handlers.end(); ++it) {
      InputHandler* handler = *it;
      if (key_state != InputHandler::ZERO && handler->wants(command, key_state)) {
        handler->handle(command, key_state);
      }
    }
    // clear the pressed and released flags
    _inputs[command] = static_cast<InputHandler::KeyState>(key_state & InputHandler::HELD);
  }
}

//------------------------------------------------------------------------------
// protected
//------------------------------------------------------------------------------

void
InputManager::press(Gosu::Button btn) {
  _handle(btn, InputHandler::PRESSED);
}

//------------------------------------------------------------------------------

void
InputManager::release(Gosu::Button btn) {
  _handle(btn, InputHandler::RELEASED);
}

//------------------------------------------------------------------------------
// private
//------------------------------------------------------------------------------

void
InputManager::_handle(Gosu::Button btn, int state) {
  InputHandler::Command command = InputHandler::UNDEFINED;
  if (btn == Gosu::kbW || btn == Gosu::gpUp) {
    command = InputHandler::LH_U;
  }
  if (btn == Gosu::kbS || btn == Gosu::gpDown) {
    command = InputHandler::LH_D;
  }
  if (btn == Gosu::kbA || btn == Gosu::gpLeft) {
    command = InputHandler::LH_L;
  }
  if (btn == Gosu::kbD || btn == Gosu::gpRight) {
    command = InputHandler::LH_R;
  }
  if (btn == Gosu::kbEscape) {
    command = InputHandler::EXIT;
  }
  if (command != InputHandler::UNDEFINED) {
    _inputs[command] = static_cast<InputHandler::KeyState>(_inputs[command] | state);
  }
}

//=============================================================================
