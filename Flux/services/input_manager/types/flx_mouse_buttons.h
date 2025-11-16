#pragma once

#ifndef FLX_MOUSE_BUTTONS_H
#define FLX_MOUSE_BUTTONS_H

#include "SDL3/SDL_mouse.h"

enum class FLX_MouseButton : uint8_t {
    Left = SDL_BUTTON_LEFT,
    Middle = SDL_BUTTON_MIDDLE,
    Right = SDL_BUTTON_RIGHT,
    X1 = SDL_BUTTON_X1,
    X2 = SDL_BUTTON_X2
};

#endif