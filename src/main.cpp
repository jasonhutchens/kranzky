#include <iostream>

#include "game_window.hpp"

//=============================================================================

int main() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    return 1;
  }
  atexit(SDL_Quit);
  GameWindow window("Dwarf Squad");
  window.show();
}

//=============================================================================
