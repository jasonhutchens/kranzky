#include <Gosu/Gosu.hpp>

#include "asset_manager.hpp"

//=============================================================================

AssetManager&
AssetManager::instance() {
  static AssetManager _instance;
  return _instance;
}

//------------------------------------------------------------------------------

void
AssetManager::init(Gosu::Window* window) {
  _images.push_back(new Gosu::Image(window->graphics(), Gosu::sharedResourcePrefix() + L"assets/images/ship.png", false));
}

//------------------------------------------------------------------------------

Gosu::Image*
AssetManager::get(int index) {
  return _images[index];
}

//=============================================================================
