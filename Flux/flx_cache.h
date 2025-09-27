#pragma once

#ifndef FLX_CACHE_H
#define FLX_CACHE_H

#include "types/flx_memory.h"
#include "types/flx_unordered_map.h"

template<typename K, typename V>
class FLX_Cache {
public:
    FLX_Cache() = default;
    ~FLX_Cache() = default;

    [[nodiscard]] flx_weak<V> get(const K& identifier) const;

    template<typename... Args>
    void set(K identifier, Args&&... args);

private:
    flx_unordered_map<K, flx_shared<V>> _data;
};

#endif