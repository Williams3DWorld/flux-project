#pragma once

#ifndef FLX_INPUT_DEVICE_H
#define FLX_INPUT_DEVICE_H

#include <SDL3/SDL_events.h>

enum class FLX_DeviceType {
    MOUSE = 0,
    KEYBOARD = 1,
};

class FLX_InputDevice {
public:
    FLX_InputDevice() = default;
    virtual ~FLX_InputDevice() = default;
    virtual void reset() {};
    virtual void update() {};
    virtual void update_events(const SDL_Event& event) {};
};

#endif