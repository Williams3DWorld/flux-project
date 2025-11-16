#pragma once

#ifndef FLX_INPUT_ACTION_H
#define FLX_INPUT_ACTION_H

#include "flx_input_device_types.h"
#include "services/input_manager/devices/flx_input_device.h"

struct InputAction {
    InputCode code = FLX_Scancode::ScancodeCount;
    FLX_InputDeviceType device = FLX_InputDeviceType::Keyboard;
};

#endif