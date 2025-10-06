#pragma once

#ifndef FLX_INHERITANCE_H
#define FLX_INHERITANCE_H

#include <type_traits>

template<typename T, typename U>
constexpr bool flx_is_base_of = std::is_base_of_v<T, U>;

#endif