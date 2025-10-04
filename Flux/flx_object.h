#pragma once

#ifndef FLX_OBJECT_H
#define FLX_OBJECT_H

#include "types/flx_inheritance.h"
#include "types/flx_integer.h"

struct FLX_ObjectConfig {
    const ui16 uuid = 0; // Eventually assign to a uuid4
};

template <typename T>
concept FLX_ObjectConfigDerived = flx_is_base_of<FLX_ObjectConfig, T>;

template <typename FLX_ObjectConfigDerived>
class FLX_Object {
public:
    explicit FLX_Object(FLX_ObjectConfigDerived&& config);
    virtual ~FLX_Object() = default;

    virtual void destroy();

    [[nodiscard]] ui16 uuid() const noexcept;

protected:
     FLX_ObjectConfigDerived _config;
};

#endif