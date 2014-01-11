#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <Gosu/Gosu.hpp>

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
  Ship _ship;
public:
  GameWindow();
  void update();
  void draw();
  void buttonDown(Gosu::Button);
  void buttonUp(Gosu::Button);
// Input Handler
  virtual void handle(InputManager::Command);
private:
  void _tick();
};

//=============================================================================

#endif /* GAME_WINDOW_HPP */
