#include <Gosu/Gosu.hpp>
#include <Box2D/Box2D.h>
#include <czmq.h>

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

  // load images
  _am.add_image(L"assets/images/ship.png");

  // this should be a physics manager
  b2Vec2 gravity(0.0f, -10.0f);
  b2World world(gravity);

  // and this should be a network manager
  zctx_t* ctx = zctx_new();

  listen(EXIT, PRESSED);
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
  _ship.draw();
}

//------------------------------------------------------------------------------

void
GameWindow::handle(Command command, KeyState key_state) {
  switch(command) {
  case EXIT:
    close();
    break;
  default:
    break;
  }
}

//------------------------------------------------------------------------------

void
GameWindow::buttonDown(Gosu::Button btn) {
  _im.press(btn);
}

//------------------------------------------------------------------------------

void
GameWindow::buttonUp(Gosu::Button btn) {
  _im.release(btn);
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
