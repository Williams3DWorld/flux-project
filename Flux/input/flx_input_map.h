#pragma once

#ifndef FLX_INPUTMAP_H
#define FLX_INPUTMAP_H

#include "./input_devices/flx_device_type.h"
#include "flx_input.h"
#include "../types/flx_unordered_map.h"
#include <string>

struct Binding {
    FLX_DeviceType device_type;
    int code;
};

class FLX_InputMap {
public:
    FLX_InputMap() = default;
    ~FLX_InputMap() {}

    void bind_action(const std::string& action_id, FLX_DeviceType device_type, int code);
    void remove_action(const std::string& action_id);
    bool is_action_pressed(const std::string& action_id, FLX_Input& input);
private:
    flx_unordered_map<std::string, Binding> _action_bindings;
};

#endif