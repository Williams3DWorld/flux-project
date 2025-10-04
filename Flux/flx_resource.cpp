#include "flx_resource.h"

#include "types/flx_memory.h"

template <typename FLX_ResourceConfigDerived>
FLX_Resource<FLX_ResourceConfigDerived>::FLX_Resource(FLX_ResourceConfigDerived&& config) :
    FLX_Object<FLX_ResourceConfigDerived>(flx_forward<FLX_ResourceConfigDerived>(config)) {};

template <typename FLX_ResourceConfigDerived>
[[nodiscard]] flx_string& FLX_Resource<FLX_ResourceConfigDerived>::path() const noexcept {
    return this->_config.path;
}