#ifndef SHIP_HPP
#define SHIP_HPP

#include "input_handler.hpp"
#include "input_manager.hpp"

//=============================================================================

class Ship : public InputHandler {
public:
  Ship();
  // InputHandler
  virtual void handle(Command, KeyState);
};

//=============================================================================

#endif /* SHIP_HPP */
