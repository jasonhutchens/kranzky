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
  return _images.size()-1;
}

//------------------------------------------------------------------------------
int
AssetManager::add_sound(std::wstring path) {
  _samples.push_back(new Gosu::Sample(Gosu::sharedResourcePrefix() + path));
  return _samples.size()-1;
}

//------------------------------------------------------------------------------
Gosu::Image*
AssetManager::get_image(int index) {
  return _images[index];
}

//------------------------------------------------------------------------------
Gosu::Sample*
AssetManager::get_sound(int index) {
  return _samples[index];
}

//------------------------------------------------------------------------------
Gosu::Font*
AssetManager::get_font() {
  return _font;
}

//=============================================================================
