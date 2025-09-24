#pragma once

#ifndef FLX_TYPES_H
#define FLX_TYPES_H

#include <memory>

template<typename T>
using flx_unique = std::unique_ptr<T>;

template<typename T>
using flx_weak = std::weak_ptr<T>;

#endif