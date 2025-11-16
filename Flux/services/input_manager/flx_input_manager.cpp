#include <ranges>
#include "flx_input_manager.h"
#include "devices/flx_keyboard_device.h"

FLX_InputManager::FLX_InputManager(FLX_InputManagerConfig&& config) :
    FLX_Service(std::forward<FLX_InputManagerConfig>(config)) {
    _devices[FLX_InputDeviceType::Keyboard] = std::make_shared<FLX_KeyboardDevice>(FLX_KeyboardDevice({}));
}

bool FLX_InputManager::is_action(const std::string &identifier) const {
    auto actions = _config.actions;

    if (const auto it = actions.find(identifier); it != actions.end()) {
        const auto [code, device] = it->second;

        if (const auto device_it = _devices.find(device); device_it != _devices.end()) {
            return device_it->second->is_active(code);
        }
    }

    return false;
}

void FLX_InputManager::poll_events(FLX_Event &event) const noexcept {
    for (const auto &val: _devices | std::views::values) {
        val->poll_events(event);
    }
}
