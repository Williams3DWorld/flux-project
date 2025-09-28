#include "flx_input_map.h"

#include <iostream>
#include <ostream>

void FLX_InputMap::bind_action(const std::string& action_id, FLX_DeviceType device_type, int code) {
    _action_bindings[action_id] = {
        device_type,
        code,
    };
}

void FLX_InputMap::remove_action(const std::string& action_id) {
    _action_bindings.erase(action_id);
}

const Binding* FLX_InputMap::get_action_binding(const std::string_view action_id) const {
    const auto it = _action_bindings.find(action_id);
    if (it != _action_bindings.end()) {
        return &it->second;
    }

    return nullptr;
}

bool FLX_InputMap::is_action_pressed(const std::string_view action_id, FLX_Input& input) const {
    if (const auto binding = get_action_binding(action_id)) {
        switch (binding->device_type) {
            case MOUSE:
                return input.mouse_device()->is_mouse_button_pressed(binding->code);
            case KEYBOARD:
                const auto scancode = static_cast<FLX_Scancode>(binding->code);
                return input.keyboard_device()->is_key_pressed(scancode);
        }
    }

    return false;
}
