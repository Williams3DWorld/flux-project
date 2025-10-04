#include "flx_asset_loader.h"

template<typename T, typename Asset, typename AssetConfig>
requires FLX_AssetDerived<Asset, AssetConfig>
FLX_AssetLoader<T, Asset, AssetConfig>::FLX_AssetLoader(flx_string_view path) :
    FLX_Loader<T>(path) {}
