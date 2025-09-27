#include "flx_loader.h"

template<typename LoaderConfig, typename ResourceConfig, typename Resource>
requires FLX_LoaderConfigDerived<LoaderConfig> && FLX_ResourceDerived<Resource, ResourceConfig>
FLX_Loader<LoaderConfig, ResourceConfig, Resource>::FLX_Loader(const LoaderConfig&& config)
    : FLX_Object<LoaderConfig>(config) {}