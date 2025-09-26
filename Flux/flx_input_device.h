#pragma once

#ifndef FLX_INPUT_DEVICE_H
#define FLX_INPUT_DEVICE_H

#include <SDL3/SDL_events.h>

class FLX_InputDevice {
protected:
    FLX_InputDevice() = default;
    virtual ~FLX_InputDevice() = default;
    virtual void reset() = 0;
    virtual void update() = 0;
    virtual void update_events(const SDL_Event& event) = 0;
};

#endif