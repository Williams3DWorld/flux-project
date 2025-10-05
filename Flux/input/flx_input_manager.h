#pragma once

#ifndef FLX_INPUT_H
#define FLX_INPUT_H

#include "./input_devices/flx_device_type.h"
#include "./input_devices/flx_input_device.h"
#include "./input_devices/flx_mouse_device.h"
#include "./input_devices/flx_keyboard_device.h"
#include "../types/flx_unordered_map.h"
#include "./input/flx_input_map.h"
#include "types/flx_memory.h"

class FLX_InputManager {
public:
    explicit FLX_InputManager(const FLX_InputOptions &options);

    const FLX_MouseDevice* mouse_device();
    const FLX_KeyboardDevice* keyboard_device();
    [[nodiscard]] const FLX_InputMap& input_map() const;

    void register_device(FLX_DeviceType device_type, flx_unique<FLX_InputDevice> device);
    void update() const;
    void poll_events(const SDL_Event& event) const;
private:
    flx_unordered_map<FLX_DeviceType, flx_unique<FLX_InputDevice>> _devices;
    flx_unique<FLX_InputMap> _input_map;
};

#endif