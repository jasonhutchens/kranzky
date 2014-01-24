#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP
 
#include <Gosu/Gosu.hpp>

//=============================================================================

class AssetManager {
  std::vector<Gosu::Image*> _images;
  Gosu::Window* _window;
  Gosu::Font* _font;
public:
  static AssetManager& instance();
  void init(Gosu::Window*);
  int add_image(std::wstring);
  Gosu::Image* get(int);
  Gosu::Font* get_font();
private:
  AssetManager() {}
  AssetManager(AssetManager const&);
  void operator=(AssetManager const&);
};

//=============================================================================

#endif /* ASSET_MANAGER_HPP */
