#ifndef SHIP_HPP
#define SHIP_HPP

#include <Gosu/Gosu.hpp>

#include "input_handler.hpp"
#include "input_manager.hpp"

//=============================================================================

class Ship : public InputHandler {
  double _x, _y, _dx, _dy, _ax, _ay;
  unsigned _c;
  int _u, _d, _l, _r;
  std::wstring _name;
  Gosu::Graphics* _graphics;
public:
  Ship(Gosu::Graphics&, std::wstring, unsigned, int, int, int, int);
  void warp(double, double);
  void update(double);
  void draw() const;
  // InputHandler
  virtual void handle(Command, KeyState);
};

//=============================================================================

#endif /* SHIP_HPP */
