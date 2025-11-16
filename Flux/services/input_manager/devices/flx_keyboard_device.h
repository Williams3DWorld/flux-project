#pragma once

#ifndef FLX_KEYBOARD_DEVICE_H
#define FLX_KEYBOARD_DEVICE_H

#include "flx_input_device.h"

class FLX_KeyboardDevice final : public FLX_InputDevice {
public:
    explicit FLX_KeyboardDevice(FLX_InputDeviceConfig&& config);
    ~FLX_KeyboardDevice() override = default;

    void poll_events(FLX_Event &event) override;
};

#endif