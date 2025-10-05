#include "flx_input_manager.h"
#include "input_devices/flx_keyboard_device.h"
#include "input_devices/flx_mouse_device.h"
#include <ranges>

FLX_InputManager::FLX_InputManager(const FLX_InputOptions &options) {
    register_device(MOUSE, flx_make_unique<FLX_MouseDevice>());
    register_device(KEYBOARD, flx_make_unique<FLX_KeyboardDevice>());

    _input_map = flx_make_unique<FLX_InputMap>(options, *this);
}

void FLX_InputManager::register_device(FLX_DeviceType device_type, flx_unique<FLX_InputDevice> device) {
    _devices[device_type] = std::move(device);
}

void FLX_InputManager::poll_events(const SDL_Event& event) const {
    for (const auto &val: _devices | std::views::values) {
        val->poll_events(event);
    }
}

void FLX_InputManager::update() const {
    for (const auto &val: _devices | std::views::values) {
        val->update();
    }
}

const FLX_InputMap& FLX_InputManager::input_map() const {
    return *_input_map;
}

const FLX_MouseDevice* FLX_InputManager::mouse_device() {
    return dynamic_cast<FLX_MouseDevice*>(_devices[MOUSE].get());
}

const FLX_KeyboardDevice* FLX_InputManager::keyboard_device() {
    return dynamic_cast<FLX_KeyboardDevice*>(_devices[KEYBOARD].get());
}