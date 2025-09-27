#include "flx_input_map.h"

void FLX_InputMap::bind_action(const std::string& action_id, FLX_DeviceType device_type, int code) {
    _action_bindings[action_id] = {
        device_type,
        code,
    };
}

void FLX_InputMap::remove_action(const std::string& action_id) {
    _action_bindings.erase(action_id);
}

bool FLX_InputMap::is_action_pressed(const std::string& action_id, FLX_Input& input) {
    if (const auto it = _action_bindings.find(action_id); it != _action_bindings.end()) {
        switch (it->second.device_type) {
            case MOUSE:
                return input.mouse_device()->is_mouse_button_pressed(it->second.code);
            case KEYBOARD:
                const auto scancode = static_cast<FLX_Scancode>(it->second.code);
                return input.keyboard_device()->is_key_pressed(scancode);
        }
    }

    return false;
}
