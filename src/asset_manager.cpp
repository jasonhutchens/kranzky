#include <Gosu/Gosu.hpp>

#include "asset_manager.hpp"

//=============================================================================

AssetManager&
AssetManager::instance() {
  static AssetManager _instance;
  return _instance;
}

//=============================================================================
