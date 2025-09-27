#pragma once

#ifndef FLX_INPUT_H
#define FLX_INPUT_H

#include "./input_devices/flx_input_device.h"
#include "./input_devices/flx_mouse_device.h"
#include "./input_devices/flx_keyboard_device.h"
#include "../types/flx_unordered_map.h"
#include "types/flx_memory.h"

class FLX_Input {
public:
    FLX_Input();

    const FLX_MouseDevice* mouse_device();
    const FLX_KeyboardDevice* keyboard_device();

    void reset();
    void update();
    void update_events(const SDL_Event& event) const;
private:
    flx_unordered_map<FLX_DeviceType, flx_unique<FLX_InputDevice>> _devices;
};

#endif