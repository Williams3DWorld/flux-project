#pragma once

#ifndef FLX_INPUT_DEVICE_H
#define FLX_INPUT_DEVICE_H

#include <SDL3/SDL_events.h>

class FLX_InputDevice {
public:
    FLX_InputDevice() = default;
    virtual ~FLX_InputDevice() = default;
    virtual void update() {};
    virtual void poll_events(const SDL_Event& event) {};
};

#endif