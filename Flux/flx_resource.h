#pragma once

#ifndef FLX_RESOURCE_H
#define FLX_RESOURCE_H

#include <string>
#include "flx_object.h"
#include "types/flx_resource_types.h"

template<typename T>
struct FLX_ResourceConfig : FLX_ObjectConfig {
    T data;
    std::string resource_path;
    FLX_ResourceType resource_type = FLX_ResourceType::Texture;
};

template <typename T, typename Data>
concept FLX_ResourceConfigDerived = std::is_base_of_v<FLX_ResourceConfig<Data>, T>;

template <typename FLX_ResourceConfigDerived, typename Data>
class FLX_Resource : public FLX_Object<FLX_ResourceConfigDerived> {
public:
    explicit FLX_Resource(FLX_ResourceConfigDerived&& config);
    ~FLX_Resource() override = default;

    [[nodiscard]] virtual Data data() const noexcept = 0;

    [[nodiscard]] std::string& path() const noexcept;
    [[nodiscard]] FLX_ResourceType& resource_type() const noexcept;
};

template <typename FLX_ResourceConfigDerived, typename Data>
FLX_Resource<FLX_ResourceConfigDerived, Data>::FLX_Resource(FLX_ResourceConfigDerived&& config) :
    FLX_Object<FLX_ResourceConfigDerived>(std::forward<FLX_ResourceConfigDerived>(config)) {};

template <typename FLX_ResourceConfigDerived, typename Data>
[[nodiscard]] std::string& FLX_Resource<FLX_ResourceConfigDerived, Data>::path() const noexcept {
    return this->_config.resource_path;
}

template <typename FLX_ResourceConfigDerived, typename Data>
[[nodiscard]] FLX_ResourceType& FLX_Resource<FLX_ResourceConfigDerived, Data>::resource_type() const noexcept {
    return this->_config.resource_type;
}

#endif