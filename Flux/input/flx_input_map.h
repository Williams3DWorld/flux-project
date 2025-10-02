#pragma once

#ifndef FLX_INPUTMAP_H
#define FLX_INPUTMAP_H

#include "./input_devices/flx_device_type.h"
#include "flx_input.h"
#include <string>

struct Binding {
    FLX_DeviceType device_type;
    int code;
};

class FLX_InputMap {
public:
    explicit FLX_InputMap(FLX_Input& input);

    [[nodiscard]] const Binding* get_action_binding(std::string_view action_id) const;

    void bind_action(const std::string& action_id, FLX_DeviceType device_type, int code);
    [[nodiscard]] bool is_action_pressed(std::string_view action_id) const;
private:
    flx_unordered_map_string_h<std::string, Binding> _action_bindings;
    FLX_Input& _input;
};

#endif