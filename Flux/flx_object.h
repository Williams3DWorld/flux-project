#pragma once

#ifndef FLX_OBJECT_H
#define FLX_OBJECT_H

#include <type_traits>

struct FLX_ObjectConfig {
    uint16_t uuid = 0; // Temp
};

template <typename T>
concept FLX_ObjectConfigDerived = std::is_base_of_v<FLX_ObjectConfig, T>;

template <typename FLX_ObjectConfigDerived>
class FLX_Object {
public:
    explicit FLX_Object(FLX_ObjectConfigDerived&& config);
    virtual ~FLX_Object() = default;

    [[nodiscard]] uint16_t uuid() const noexcept;

protected:
     FLX_ObjectConfigDerived _config;
};

template <typename FLX_ObjectConfigDerived>
FLX_Object<FLX_ObjectConfigDerived>::FLX_Object(FLX_ObjectConfigDerived&& config) :
    _config(std::forward<FLX_ObjectConfigDerived>(config)) {}

template <typename FLX_ObjectConfigDerived>
[[nodiscard]] uint16_t FLX_Object<FLX_ObjectConfigDerived>::uuid() const noexcept {
    return this->_config.uuid;
}

#endif