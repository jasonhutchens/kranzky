#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP
 
#include <Gosu/Gosu.hpp>

//=============================================================================

class AssetManager {
  std::vector<Gosu::Image*> _images;
public:
  static AssetManager& instance();
  void init(Gosu::Window*);
  Gosu::Image* get(int);
private:
  AssetManager() {}
  AssetManager(AssetManager const&);
  void operator=(AssetManager const&);
};

//=============================================================================

#endif /* ASSET_MANAGER_HPP */
