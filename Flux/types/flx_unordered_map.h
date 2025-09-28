#pragma once

#ifndef FLX_CONTAINERS_H
#define FLX_CONTAINERS_H

#include <unordered_map>
#include <string>

struct StringViewHash {
    using is_transparent = void;
    size_t operator()(const std::string_view s) const noexcept {
        return std::hash<std::string_view>{}(s);
    }
};

template<typename K, typename V>
using flx_unordered_map = std::unordered_map<K, V>;

template<typename K, typename V>
using flx_unordered_map_string_h = std::unordered_map<K, V, StringViewHash, std::equal_to<>>;

#endif