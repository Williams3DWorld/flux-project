#pragma once

#ifndef FLX_CACHE_H
#define FLX_CACHE_H

#include "core/flx_memory.h"
#include "core/flx_unordered_map.h"

template<typename K, typename V>
class FLX_Cache {
public:
    explicit FLX_Cache();
    ~FLX_Cache() = default;

    [[nodiscard]] flx_unordered_map<K, flx_shared<V>>* data() noexcept;

    [[nodiscard]] V* get(const K& identifier) const;

    template<typename... Args>
    void set(K identifier, Args&&... args);

private:
    flx_shared<flx_unordered_map<K, flx_shared<V>>> _data;
};

template<typename K, typename V>
FLX_Cache<K, V>::FLX_Cache() :
    _data(flx_make_shared<flx_unordered_map<K, flx_shared<V>>>()) {}

template<typename K, typename V>
[[nodiscard]] flx_unordered_map<K, flx_shared<V>>* FLX_Cache<K, V>::data() noexcept {
    return _data.get();
}

template<typename K, typename V>
[[nodiscard]] V* FLX_Cache<K, V>::get(const K& identifier) const {
    auto it = data().find(identifier);
    return it != data().end() ? it->second.get() : nullptr;
}

template<typename K, typename V>
template<typename... Args>
void FLX_Cache<K, V>::set(K identifier, Args&&... args) {
    data()[identifier] = flx_make_shared<V>(std::forward<Args>(args)...);
}

#endif