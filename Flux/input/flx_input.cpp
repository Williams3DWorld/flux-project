#include "flx_input.h"

#include <ranges>

#include "input_devices/flx_keyboard_device.h"
#include "input_devices/flx_mouse_device.h"

FLX_Input::FLX_Input() {
    _devices[FLX_DEVICE_TYPE::MOUSE] = flx_make_unique<FLX_MouseDevice>();
    _devices[FLX_DEVICE_TYPE::KEYBOARD] = flx_make_unique<FLX_KeyboardDevice>();
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