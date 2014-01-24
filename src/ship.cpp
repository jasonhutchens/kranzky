#include "ship.hpp"
#include "asset_manager.hpp"

//=============================================================================

Ship::Ship(Gosu::Graphics& graphics, std::wstring name, unsigned c, int u, int d, int l, int r) {
  _graphics = &graphics;
  _x = _y = _dx = _dy = _ax = _ay = 0;
  _u = u;
  _d = d;
  _l = l;
  _r = r;
  _c = c;
  _name = name;
  listen(static_cast<InputHandler::Command>(_u), HELD);
  listen(static_cast<InputHandler::Command>(_d), HELD);
  listen(static_cast<InputHandler::Command>(_l), HELD);
  listen(static_cast<InputHandler::Command>(_r), HELD);
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
  if (command == _u) {
    _ay = -1;
  }
  if (command == _d) {
    _ay = 1;
  }
  if (command == _l) {
    _ax = -1;
  }
  if (command == _r) {
    _ax = 1;
  }
}

//------------------------------------------------------------------------------
void
Ship::update(double _dt) {
  _x = Gosu::wrap(_x + _dx, 0.0, 1200.0);
  _y = Gosu::wrap(_y + _dy, 0.0, 675.0);
  _dx += _ax;
  _dy += _ay;
  _dx *= 0.9;
  _dy *= 0.9;
  _ax = 0;
  _ay = 0;
}

//------------------------------------------------------------------------------
void
Ship::draw() const {
  AssetManager& am(AssetManager::instance());
  am.get_image(0)->drawRot(_x, _y, 1, 0, 0.5, 0.5, 1, 1);
  float width = am.get_font()->textWidth(_name, 0.7);
  am.get_font()->draw(_name, _x - width * 0.5, _y + 18, 999, 0.7, 0.7, 0xAAFFFFFF);
  _graphics->drawQuad(
    _x-16, _y-16, _c,
    _x+16, _y-16, _c,
    _x+16, _y+16, _c,
    _x-16, _y+16, _c,
    0
  );
}

//=============================================================================
