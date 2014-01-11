#include "ship.hpp"

//=============================================================================

Ship::Ship(Gosu::Graphics& graphics) {
  _x = _y = _dx = _dy = _a = 0;
  listen(LH_L, HELD);
  listen(LH_R, HELD);
  listen(LH_U, HELD);
}

//------------------------------------------------------------------------------

void
Ship::warp(double x, double y) {
  _x = x;
  _y = y;
}

//------------------------------------------------------------------------------

void
Ship::handle(Command command, KeyState key_state) {
  switch(command) {
  case LH_L:
    turnLeft();
    break;
  case LH_R:
    turnRight();
    break;
  case LH_U:
    accelerate();
    break;
  default:
    break;  
  }
}

//------------------------------------------------------------------------------

void
Ship::turnLeft() {
  _a -= 4.5;
}

//------------------------------------------------------------------------------

void
Ship::turnRight() {
  _a += 4.5;
}

//------------------------------------------------------------------------------

void
Ship::accelerate() {
  _dx += Gosu::offsetX(_a, 0.5);
  _dy += Gosu::offsetY(_a, 0.5);
}

//------------------------------------------------------------------------------

void
Ship::update(double _dt) {
  _x = Gosu::wrap(_x + _dx, 0.0, 1200.0);
  _y = Gosu::wrap(_y + _dy, 0.0, 675.0);
  _dx *= 0.95;
  _dy *= 0.95;
}

//------------------------------------------------------------------------------

void
Ship::draw(Gosu::Image* image) const {
  image->drawRot(_x, _y, 1, _a, 0.5, 0.5, 4, 4);
}

//=============================================================================
