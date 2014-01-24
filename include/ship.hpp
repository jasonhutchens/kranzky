#ifndef SHIP_HPP
#define SHIP_HPP

#include <Gosu/Gosu.hpp>

#include "input_handler.hpp"
#include "input_manager.hpp"

//=============================================================================

class Ship : public InputHandler {
  double _x, _y, _dx, _dy, _a;
  std::wstring _name;
  Gosu::Graphics* _graphics;
public:
  Ship(Gosu::Graphics&);
  void warp(double, double);
  void turnLeft();
  void turnRight();
  void accelerate();
  void fire();
  void update(double);
  void draw() const;
  // InputHandler
  virtual void handle(Command, KeyState);
};

//=============================================================================

#endif /* SHIP_HPP */
