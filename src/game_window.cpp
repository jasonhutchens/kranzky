#include <SDL2/SDL_Video.h>
#include <Box2D/Box2D.h>
#include <czmq.h>

#include "asset_manager.hpp"
#include "game_window.hpp"

//=============================================================================

GameWindow::GameWindow(const char* caption) :
  _window(SDL_CreateWindow(caption, 0, 0, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP))
{
}

//------------------------------------------------------------------------------
void
GameWindow::show() {
  SDL_ShowWindow(_window);
}

//------------------------------------------------------------------------------
void
GameWindow::update() {
  _tick();
}

//------------------------------------------------------------------------------
void
GameWindow::draw() {
}

//------------------------------------------------------------------------------
void
GameWindow::handle(Command command, KeyState key_state) {
}

//------------------------------------------------------------------------------
// private
//------------------------------------------------------------------------------
void
GameWindow::_tick() {
}

//=============================================================================
