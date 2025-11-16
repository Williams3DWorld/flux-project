#pragma once

#ifndef FLX_INPUT_DEVICE_H
#define FLX_INPUT_DEVICE_H

#include <unordered_map>
#include <variant>
#include "flx_object.h"
#include "services/input_manager/types/flx_mouse_buttons.h"
#include "services/input_manager/types/flx_scancodes.h"

using InputCode = std::variant<FLX_Scancode, FLX_MouseButton>;

class FLX_Event;

using FLX_InputDeviceConfig = FLX_ObjectConfig;

class FLX_InputDevice : public FLX_Object<FLX_InputDeviceConfig> {
public:
    explicit FLX_InputDevice(FLX_InputDeviceConfig&& config);
    ~FLX_InputDevice() override = default;

    virtual void poll_events(FLX_Event& event) = 0;

    [[nodiscard]] bool is_active(InputCode identifier) const;

protected:
    std::unordered_map<InputCode, bool> _states;
};


#endif