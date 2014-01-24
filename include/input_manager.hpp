#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <vector>

#include "input_handler.hpp"

//=============================================================================

class InputManager {
  friend class GameWindow;
  std::vector<InputHandler::KeyState> _inputs;
  std::vector<InputHandler*> _handlers;
 public:
  static InputManager& instance();
  void add_handler(InputHandler*);
  void update(double);
private:
  InputManager() {}
  InputManager(InputManager const&);
  void operator=(InputManager const&);
}; 

//=============================================================================

#endif /* INPUT_MANAGER_HPP */
