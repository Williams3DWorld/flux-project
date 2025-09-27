#include "flx_resource.h"

template <typename FLX_ResourceConfigDerived>
FLX_Resource<FLX_ResourceConfigDerived>::FLX_Resource(FLX_ResourceConfigDerived&& config) :
    FLX_Object<FLX_ResourceConfigDerived>(config) {};

template <typename FLX_ResourceConfigDerived>
[[nodiscard]] flx_string& FLX_Resource<FLX_ResourceConfigDerived>::path() const noexcept {
    return this->_config.path;
}