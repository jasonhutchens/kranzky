#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP
 
#include <Gosu/Gosu.hpp>

//=============================================================================

class AssetManager {
  std::vector<Gosu::Image*> _images;
  std::vector<Gosu::Sample*> _samples;
  Gosu::Window* _window;
  Gosu::Font* _font;
public:
  static AssetManager& instance();
  void init(Gosu::Window*);
  int add_image(std::wstring);
  int add_sound(std::wstring);
  Gosu::Image* get_image(int);
  Gosu::Sample* get_sound(int);
  Gosu::Font* get_font();
private:
  AssetManager() {}
  AssetManager(AssetManager const&);
  void operator=(AssetManager const&);
};

//=============================================================================

#endif /* ASSET_MANAGER_HPP */
