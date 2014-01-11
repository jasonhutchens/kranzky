#include <Gosu/Gosu.hpp>

#include "asset_manager.hpp"

#include "game_window.hpp"

//=============================================================================

GameWindow::GameWindow() :
  Gosu::Window(1200, 675, false),
  _am(AssetManager::instance()),
  _im(InputManager::instance()),
  _ship(graphics())
{
  setCaption(L"Hello World!");
  _ms = _dt = 0;
  _am.init(this);
  _im.init(this);
  listen(InputManager::EXIT);
  _ship.warp(600, 350);
  _tick();
}

//------------------------------------------------------------------------------

void
GameWindow::update() {
  _tick();
  _im.update(_dt);
  _ship.update(_dt);
}

//------------------------------------------------------------------------------

void
GameWindow::draw() {
  _ship.draw(_am.get(0));
}

//------------------------------------------------------------------------------

void
GameWindow::handle(InputManager::Command command) {
  switch(command) {
  case InputManager::EXIT:
    close();
    break;
  default:
    break;
  }
}

//------------------------------------------------------------------------------

void
GameWindow::buttonDown(Gosu::Button btn) {
  _im.down(btn);
}

//------------------------------------------------------------------------------

void
GameWindow::buttonUp(Gosu::Button btn) {
  _im.up(btn);
}

//------------------------------------------------------------------------------
// private
//------------------------------------------------------------------------------

void
GameWindow::_tick() {
  _dt = Gosu::milliseconds() - _ms;
  _ms = Gosu::milliseconds();
}

//=============================================================================
