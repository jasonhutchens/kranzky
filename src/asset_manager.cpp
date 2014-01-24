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
  _window = window;
  _font = new Gosu::Font(_window->graphics(), Gosu::defaultFontName(), 20);
}

//------------------------------------------------------------------------------
int
AssetManager::add_image(std::wstring path) {
  _images.push_back(new Gosu::Image(_window->graphics(), Gosu::sharedResourcePrefix() + path, false));
}

//------------------------------------------------------------------------------
Gosu::Image*
AssetManager::get(int index) {
  return _images[index];
}

//------------------------------------------------------------------------------
Gosu::Font*
AssetManager::get_font() {
  return _font;
}

//=============================================================================
