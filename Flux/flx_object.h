#pragma once

#ifndef FLX_OBJECT_H
#define FLX_OBJECT_H

#include "core/flx_inheritance.h"
#include "core/flx_integer.h"

struct FLX_ObjectConfig {
    ui16 uuid = 0; // Temp
};

template <typename T>
concept FLX_ObjectConfigDerived = flx_is_base_of<FLX_ObjectConfig, T>;

template <typename FLX_ObjectConfigDerived>
class FLX_Object {
public:
    explicit FLX_Object(FLX_ObjectConfigDerived&& config);
    virtual ~FLX_Object() = default;

    [[nodiscard]] ui16 uuid() const noexcept;

protected:
     FLX_ObjectConfigDerived _config;
};

template <typename FLX_ObjectConfigDerived>
FLX_Object<FLX_ObjectConfigDerived>::FLX_Object(FLX_ObjectConfigDerived&& config) :
    _config(std::forward<FLX_ObjectConfigDerived>(config)) {}

template <typename FLX_ObjectConfigDerived>
[[nodiscard]] ui16 FLX_Object<FLX_ObjectConfigDerived>::uuid() const noexcept {
    return this->_config.uuid;
}

#endif