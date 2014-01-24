#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <SDL2/SDL.h>

#include "input_handler.hpp"
#include "ship.hpp"

//=============================================================================

class AssetManager;
class InputManager;

class GameWindow : public InputHandler {
  SDL_Window* _window;
public:
  GameWindow(const char*);
  void show();
  void update();
  void draw();
  virtual void handle(Command, KeyState);
private:
  void _tick();
};

//=============================================================================

#endif /* GAME_WINDOW_HPP */
