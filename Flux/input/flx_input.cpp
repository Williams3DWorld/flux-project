#include "flx_input.h"
#include "input_devices/flx_keyboard_device.h"
#include "input_devices/flx_mouse_device.h"

#include <ranges>

FLX_Input::FLX_Input() {
    _devices.reserve(2);
    _devices[FLX_DeviceType::MOUSE] = flx_make_unique<FLX_MouseDevice>();
    _devices[FLX_DeviceType::KEYBOARD] = flx_make_unique<FLX_KeyboardDevice>();
}

void FLX_Input::update_events(const SDL_Event& event) const {
    for (const auto &val: _devices | std::views::values) {
        val->update_events(event);
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
    return dynamic_cast<FLX_MouseDevice*>(_devices[FLX_DeviceType::MOUSE].get());
}

const FLX_KeyboardDevice* FLX_Input::keyboard_device() {
    return dynamic_cast<FLX_KeyboardDevice*>(_devices[FLX_DeviceType::KEYBOARD].get());
}