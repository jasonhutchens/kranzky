#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <SDL2/SDL.h>

#include "input_handler.hpp"
#include "ship.hpp"

//=============================================================================

class AssetManager;
class InputManager;

class GameWindow : public Gosu::Window, public InputHandler {
  AssetManager& _am;
  InputManager& _im;
  double _ms;
  double _dt;
  Ship _p1;
  Ship _p2;
  Ship _p3;
  Ship _p4;
public:
  GameWindow();
  void update();
  void draw();
  void buttonDown(Gosu::Button);
  void buttonUp(Gosu::Button);
  virtual void handle(Command, KeyState);
private:
  void _tick();
};

//=============================================================================

#endif /* GAME_WINDOW_HPP */
