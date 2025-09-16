#include <iostream>
#include "flux.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

namespace flux {
    void init() {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        std::cout<<"successfully initialised flux!"<<std::endl;
    }
}