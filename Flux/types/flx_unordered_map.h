#pragma once

#ifndef FLX_CONTAINERS_H
#define FLX_CONTAINERS_H

#include <unordered_map>

template<typename K, typename V>
using flx_unordered_map = std::unordered_map<K, V>;

#endif