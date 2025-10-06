#pragma once

#ifndef FLX_RESOURCE_H
#define FLX_RESOURCE_H

#include "flx_object.h"
#include "core/flx_string.h"

struct FLX_ResourceConfig : FLX_ObjectConfig {
    const flx_string path;
};

template <typename T>
concept FLX_ResourceConfigDerived = flx_is_base_of<FLX_ResourceConfig, T>;

template <typename FLX_ResourceConfigDerived>
class FLX_Resource : public FLX_Object<FLX_ResourceConfigDerived> {
public:
    explicit FLX_Resource(FLX_ResourceConfigDerived&& config);
    ~FLX_Resource() override = default;

    [[nodiscard]] flx_string& path() const noexcept;
};

template <typename FLX_ResourceConfigDerived>
FLX_Resource<FLX_ResourceConfigDerived>::FLX_Resource(FLX_ResourceConfigDerived&& config) :
    FLX_Object<FLX_ResourceConfigDerived>(std::forward<FLX_ResourceConfigDerived>(config)) {};

template <typename FLX_ResourceConfigDerived>
[[nodiscard]] flx_string& FLX_Resource<FLX_ResourceConfigDerived>::path() const noexcept {
    return this->_config.path;
}

#endif