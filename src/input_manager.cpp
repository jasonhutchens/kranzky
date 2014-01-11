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
  _inputs.reserve(4);
  _clear();
}

//------------------------------------------------------------------------------

void
InputManager::update(double _dt) {
  _clear();
}

//------------------------------------------------------------------------------

void
InputManager::down(Gosu::Button btn) {
  _inputs[LEFT] = _inputs[LEFT] || (btn == Gosu::kbLeft || btn == Gosu::gpLeft);
  _inputs[RIGHT] = _inputs[RIGHT] || (btn == Gosu::kbRight || btn == Gosu::gpRight);
  _inputs[THRUST] = _inputs[THRUST] || (btn == Gosu::kbUp || btn == Gosu::gpUp);
  _inputs[EXIT] = _inputs[EXIT] || (btn == Gosu::kbEscape);
}

//------------------------------------------------------------------------------

void
InputManager::up(Gosu::Button btn) {
}

//------------------------------------------------------------------------------

void
InputManager::listen(Command command, InputHandler* handler) {
}

//------------------------------------------------------------------------------
// private
//------------------------------------------------------------------------------

void
InputManager::_clear() {
  _inputs[EXIT] = false;
  _inputs[LEFT] = false;
  _inputs[RIGHT] = false;
  _inputs[THRUST] = false;
}

//=============================================================================
