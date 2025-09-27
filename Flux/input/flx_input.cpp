#include "flx_input.h"
#include "input_devices/flx_keyboard_device.h"
#include "input_devices/flx_mouse_device.h"
#include <ranges>

FLX_Input::FLX_Input() {
    register_device(MOUSE, flx_make_unique<FLX_MouseDevice>());
    register_device(KEYBOARD, flx_make_unique<FLX_KeyboardDevice>());
}

void FLX_Input::register_device(FLX_DeviceType device_type, flx_unique<FLX_InputDevice> device) {
    _devices[device_type] = std::move(device);
}

void FLX_Input::poll_events(const SDL_Event& event) const {
    for (const auto &val: _devices | std::views::values) {
        val->poll_events(event);
    }
}

void FLX_Input::update() {
    for (const auto &val: _devices | std::views::values) {
        val->update();
    }
}

void FLX_Input::reset() {
    for (const auto &val: _devices | std::views::values) {
        val->reset();
    }
}

const FLX_MouseDevice* FLX_Input::mouse_device() {
    return dynamic_cast<FLX_MouseDevice*>(_devices[MOUSE].get());
}

const FLX_KeyboardDevice* FLX_Input::keyboard_device() {
    return dynamic_cast<FLX_KeyboardDevice*>(_devices[KEYBOARD].get());
}