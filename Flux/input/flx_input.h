#pragma once

#ifndef FLX_INPUT_H
#define FLX_INPUT_H

#include "./input_devices/flx_input_device.h"
#include "../types/flx_unordered_map.h"
#include "types/flx_memory.h"

enum class FLX_DEVICE_TYPE {
    MOUSE = 0,
    KEYBOARD = 1,
};

class FLX_Input {
public:
    FLX_Input();

    void reset();
    void update();
    void update_events(const SDL_Event& event) const;
private:
    flx_unordered_map<FLX_DEVICE_TYPE, flx_unique<FLX_InputDevice>> _devices;
};

#endif