#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP
 
//=============================================================================

class AssetManager {
public:
  static AssetManager& instance();
private:
  AssetManager() {}
  AssetManager(AssetManager const&);
  void operator=(AssetManager const&);
};

//=============================================================================

#endif /* ASSET_MANAGER_HPP */
