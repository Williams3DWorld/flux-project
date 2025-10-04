#pragma once

#ifndef FLX_LOADER_H
#define FLX_LOADER_H

#include "types/flx_string_view.h"

template<typename T>
class FLX_Loader {
public:
    explicit FLX_Loader(flx_string_view path);
    virtual ~FLX_Loader() = default;

    virtual T load() = 0;

private:
    flx_string_view _path;
};

#endif