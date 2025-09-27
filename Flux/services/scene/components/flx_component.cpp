#include "flx_component.h"

template<typename T>
FLX_Component<T>::FLX_Component(T data) : _value(flx_move(data)) {}

template<typename T>
[[nodiscard]] T FLX_Component<T>::value() const noexcept {
    return _value;
}

template<typename T>
void FLX_Component<T>::value(T data) {
    _value = data;
}