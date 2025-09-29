#pragma once

#ifndef FLX_RESOURCE_H
#define FLX_RESOURCE_H

#include "flx_object.h"
#include "types/flx_inheritance.h"

struct FLX_ResourceConfig {
    const char* path = "";
};

template <typename T>
concept FLX_ResourceConfigDerived = flx_is_base_of<FLX_ResourceConfig, T>;

template <typename FLX_ResourceConfigDerived>
class FLX_Resource : FLX_Object<FLX_ResourceConfigDerived> {
public:
    explicit FLX_Resource(FLX_ResourceConfigDerived&& config);

    void destroy() override;

    [[nodiscard]] const char* path() const noexcept;
};

#endif