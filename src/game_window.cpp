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
  _p1(graphics(), L"Player 1", 0x88FF00FF, LH_U, LH_D, LH_L, LH_R),
  _p2(graphics(), L"Player 2", 0x88FF0000, LH_N, LH_S, LH_E, LH_W),
  _p3(graphics(), L"Player 3", 0x8800FF00, RH_U, RH_D, RH_L, RH_R),
  _p4(graphics(), L"Player 4", 0x8800FFFF, RH_N, RH_S, RH_E, RH_W)
{
  setCaption(L"Hello World!");
  _ms = _dt = 0;
  _am.init(this);
  _im.init(this);

  // load assets
  _am.add_image(L"assets/images/ship.png");
  _am.add_sound(L"assets/sounds/collect.wav");

  // this should be a physics manager
  b2Vec2 gravity(0.0f, -10.0f);
  b2World world(gravity);

  // and this should be a network manager
  zctx_t* ctx = zctx_new();

  listen(EXIT, PRESSED);
  _p1.warp(400, 150);
  _p2.warp(800, 150);
  _p3.warp(400, 550);
  _p4.warp(800, 550);
  _tick();
}

//------------------------------------------------------------------------------

void
GameWindow::update() {
  _tick();
  _im.update(_dt);
  _p1.update(_dt);
  _p2.update(_dt);
  _p3.update(_dt);
  _p4.update(_dt);
}

//------------------------------------------------------------------------------

void
GameWindow::draw() {
  _p1.draw();
  _p2.draw();
  _p3.draw();
  _p4.draw();
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
