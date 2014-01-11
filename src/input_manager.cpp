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
  _inputs.resize(InputHandler::LENGTH, 0);
}

//------------------------------------------------------------------------------

void
InputManager::add_handler(InputHandler* handler) {
  _handlers.push_back(handler);
}

//------------------------------------------------------------------------------

void
InputManager::update(double _dt) {
  // set the held flag based on what we've pressed and released this frame
  for (std::vector<int>::iterator it = _inputs.begin(); it != _inputs.end(); ++it) {
    if (*it&InputHandler::PRESSED) {
      *it = *it | InputHandler::HELD;
    }
    if (*it&InputHandler::RELEASED) {
      *it = *it ^ InputHandler::HELD;
    }
  }
  // notify the handlers
  for (std::vector<InputHandler*>::iterator it = _handlers.begin(); it != _handlers.end(); ++it) {
    it->handle();
  }
  // clear the pressed and released flags
  for (std::vector<int>::iterator it = _inputs.begin(); it != _inputs.end(); ++it) {
    *it = *it & InputHandler::HELD;
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
    _inputs[command] = _inputs[command] | state;
  }
}

//=============================================================================
