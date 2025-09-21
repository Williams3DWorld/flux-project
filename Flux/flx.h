#pragma once

#ifndef FLX_H
#define FLX_H

#include "flx_instance.h"

inline FLX_Instance FLX_CreateInstance(const FLX_InstanceOptions &options) {
    return FLX_Instance(options);
}

inline void FLX_Init() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return;
    }
}

#endif