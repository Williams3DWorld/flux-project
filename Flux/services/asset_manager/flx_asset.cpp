#include "flx_asset.h"

template <typename FLX_AssetConfigDerived>
FLX_Asset<FLX_AssetConfigDerived>::FLX_Asset(FLX_AssetConfigDerived&& config) :
    FLX_Resource<FLX_AssetConfigDerived>(config) {};