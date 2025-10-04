#include "flx_object.h"
#include "types/flx_memory.h"

template <typename FLX_ObjectConfigDerived>
FLX_Object<FLX_ObjectConfigDerived>::FLX_Object(FLX_ObjectConfigDerived&& config) :
    _config(flx_forward<FLX_ObjectConfigDerived>(config)) {}

template <typename FLX_ObjectConfigDerived>
[[nodiscard]] ui16 FLX_Object<FLX_ObjectConfigDerived>::uuid() const noexcept {
    return this->_config.uuid;
}

template<typename FLX_ObjectConfigDerived>
void FLX_Object<FLX_ObjectConfigDerived>::destroy() {}
