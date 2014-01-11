#ifndef SHIP_HPP
#define SHIP_HPP

#include <Gosu/Gosu.hpp>

#include "input_handler.hpp"
#include "input_manager.hpp"

//=============================================================================

class Ship : public InputHandler {
  double _x, _y, _dx, _dy, _a;
public:
  Ship(Gosu::Graphics&);
  void warp(double, double);
  void turnLeft();
  void turnRight();
  void accelerate();
  void update(double);
  void draw(Gosu::Image*) const;
  // InputHandler
  virtual void handle(InputManager::Command);
};

//=============================================================================

#endif /* SHIP_HPP */
