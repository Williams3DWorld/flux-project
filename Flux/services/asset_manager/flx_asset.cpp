#include "flx_asset.h"

#include "types/flx_memory.h"

template <typename FLX_AssetConfigDerived>
FLX_Asset<FLX_AssetConfigDerived>::FLX_Asset(FLX_AssetConfigDerived&& config) :
    FLX_Resource<FLX_AssetConfigDerived>(flx_forward<FLX_AssetConfigDerived>(config)) {};