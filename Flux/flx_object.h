#pragma once

#ifndef FLX_OBJECT_H
#define FLX_OBJECT_H

#include "types/flx_integer.h"

template <typename T>
class FLX_Object {
public:
    explicit FLX_Object(T&& config);
    virtual ~FLX_Object() = default;

    virtual void destroy();

    [[nodiscard]] ui16 uuid() const noexcept;

protected:
     T _config;

private:
    static ui16 _object_count;

    ui16 _uuid = FLX_Object::_object_count++;
};

#endif