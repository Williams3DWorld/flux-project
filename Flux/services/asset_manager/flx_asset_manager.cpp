#include "flx_asset_manager.h"

FLX_AssetManager::FLX_AssetManager(FLX_AssetManagerConfig&& config) :
    FLX_Service(std::move(config)) {}

FLX_AssetManager::~FLX_AssetManager() {
    _texture_sources.data()->clear();
}