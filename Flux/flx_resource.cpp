#include "flx_resource.h"

template <typename FLX_ResourceConfigDerived>
FLX_Resource<FLX_ResourceConfigDerived>::FLX_Resource(FLX_ResourceConfigDerived&& config) :
    FLX_Object<FLX_ResourceConfigDerived>(config) {};

template <typename FLX_ResourceConfigDerived>
void FLX_Resource<FLX_ResourceConfigDerived>::destroy() {
    this->_config.path = nullptr;
}

template <typename FLX_ResourceConfigDerived>
[[nodiscard]] const char* FLX_Resource<FLX_ResourceConfigDerived>::path() const noexcept {
    return this->_config.path;
}