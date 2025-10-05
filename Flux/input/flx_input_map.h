#pragma once

#ifndef FLX_INPUTMAP_H
#define FLX_INPUTMAP_H

#include "./input_devices/flx_device_type.h"
#include "./types/flx_unordered_map.h"
#include <string>

class FLX_InputManager;

struct Binding {
    FLX_DeviceType device_type;
    int code;
};

struct FLX_InputOptions {
    flx_unordered_map_string_h<std::string, Binding> action_bindings;
};

class FLX_InputMap {
public:
    explicit FLX_InputMap(const FLX_InputOptions &options, FLX_InputManager &input);

    [[nodiscard]] const Binding* get_action_binding(std::string_view action_id) const;
    [[nodiscard]] bool is_action_pressed(std::string_view action_id) const;
private:
    FLX_InputOptions _options;
    FLX_InputManager& _input;
};

#endif