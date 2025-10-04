#include "flx_input_map.h"

#include <iostream>
#include <ostream>

FLX_InputMap::FLX_InputMap(const FLX_InputOptions &options, FLX_Input& input) :
    _options(options),
    _input(input)
{}

const Binding* FLX_InputMap::get_action_binding(const std::string_view action_id) const {
    const auto it = _options.action_bindings.find(action_id);
    if (it != _options.action_bindings.end()) {
        return &it->second;
    }

    return nullptr;
}

bool FLX_InputMap::is_action_pressed(const std::string_view action_id) const {
    if (const auto binding = get_action_binding(action_id)) {
        switch (binding->device_type) {
            case MOUSE:
                return _input.mouse_device()->is_mouse_button_pressed(binding->code);
            case KEYBOARD:
                const auto scancode = static_cast<FLX_Scancode>(binding->code);
                return _input.keyboard_device()->is_key_pressed(scancode);
        }
    }

    return false;
}
