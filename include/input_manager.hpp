#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <Gosu/Gosu.hpp>
#include <vector>

//=============================================================================

class InputHandler;

class InputManager {
  friend class GameWindow;
  std::vector<int> _inputs;
  std::vector<InputHandler*> _handlers;
 public:
  static InputManager& instance();
  void init(Gosu::Window*);
  void add_handler(InputHandler*);
  void update(double);
protected:
  void press(Gosu::Button);
  void release(Gosu::Button);
private:
  InputManager() {}
  InputManager(InputManager const&);
  void operator=(InputManager const&);
  void _handle(Gosu::Button, int);
}; 

//=============================================================================

#endif /* INPUT_MANAGER_HPP */
