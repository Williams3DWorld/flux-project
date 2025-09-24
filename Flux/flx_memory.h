#pragma once

#ifndef FLX_MEMORY_H
#define FLX_MEMORY_H

#include <memory>

template<typename T>
using flx_weak = std::weak_ptr<T>;

template<typename T>
using flx_unique = std::unique_ptr<T>;

template<typename T>
using flx_shared = std::shared_ptr<T>;

template<typename T, typename... Args>
flx_shared<T> flx_make_shared(Args&&... args) {
    return std::make_shared<T>(args...);
}

template<typename T, typename... Args>
flx_unique<T> flx_make_unique(Args&&... args) {
    return std::make_unique<T>(args...);
}

#endif