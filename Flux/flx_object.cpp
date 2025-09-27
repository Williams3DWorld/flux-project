#include "flx_object.h"
#include "types/flx_memory.h"

template <typename T>
FLX_Object<T>::FLX_Object(T&& config) : _config(flx_move(config)) {}

template <typename T>
[[nodiscard]] ui16 FLX_Object<T>::uuid() const noexcept {
    return _uuid;
}

template<typename T>
void FLX_Object<T>::destroy() {}
