#pragma once

#ifndef FLX_RESOURCE_H
#define FLX_RESOURCE_H

#include "flx_object.h"
#include "types/flx_inheritance.h"
#include "types/flx_string.h"

struct FLX_ResourceConfig : FLX_ObjectConfig {
    const flx_string path;
};

template <typename T>
concept FLX_ResourceConfigDerived = flx_is_base_of<FLX_ResourceConfig, T>;

template <typename FLX_ResourceConfigDerived>
class FLX_Resource : protected FLX_Object<FLX_ResourceConfigDerived> {
public:
    explicit FLX_Resource(FLX_ResourceConfigDerived&& config);
    ~FLX_Resource() override = default;

    void destroy() override = 0;

    [[nodiscard]] flx_string& path() const noexcept;
};

#endif