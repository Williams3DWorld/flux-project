#pragma once

#ifndef FLX_COMPONENT_H
#define FLX_COMPONENT_H

#include "flx_object.h"

template<typename T>
struct FLX_ComponentConfig : FLX_ObjectConfig {
    T data;
};

template<typename T>
class FLX_Component : FLX_Object<FLX_ComponentConfig<T>> {
public:
    explicit FLX_Component(FLX_ComponentConfig<T> config);
    ~FLX_Component() override = default;

    [[nodiscard]] T value() const noexcept;

    void value(T data) noexcept;
};

template<typename T>
FLX_Component<T>::FLX_Component(FLX_ComponentConfig<T> config) :
    FLX_Object<FLX_ComponentConfig<T>>(std::move<FLX_ComponentConfig<T>>(config)) {}

template<typename T>
[[nodiscard]] T FLX_Component<T>::value() const noexcept {
    return this->_config.data;
}

template<typename T>
void FLX_Component<T>::value(T data) noexcept {
    this->_config.data = data;
}

#endif