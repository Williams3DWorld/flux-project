#pragma once

#ifndef FLX_ASSET_STORE_H
#define FLX_ASSET_STORE_H

#include "utils/flx_cache.h"

template<typename T>
using flx_asset_store = FLX_Cache<std::string, T>;

#endif