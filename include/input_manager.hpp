#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <Gosu/Gosu.hpp>
#include <vector>

//=============================================================================

class InputHandler;

class InputManager {
  std::vector<bool> _inputs;
  std::vector<InputHandler*> _handlers;
 public:
  enum Command { EXIT, LEFT, RIGHT, THRUST };
  static InputManager& instance();
  void init(Gosu::Window*);
  void update(double);
  void down(Gosu::Button);
  void up(Gosu::Button);
  void listen(Command, InputHandler*);
private:
  InputManager() {}
  InputManager(InputManager const&);
  void operator=(InputManager const&);
  void _clear();
}; 

//=============================================================================

#endif /* INPUT_MANAGER_HPP */
