#include "flx_mouse_device.h"
#include <iostream>

void FLX_MouseDevice::update_events(const SDL_Event& event) {
    if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN ||
        event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
        _mouse_button_states[static_cast<int>(event.button.button)]
                = (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN);
    }
}

void FLX_MouseDevice::update() {
    _mouse_state = SDL_GetMouseState(&_mouse_x, &_mouse_y);
}

void FLX_MouseDevice::reset() {
    _mouse_button_states.clear();
}

bool FLX_MouseDevice::is_mouse_button_down(const Uint8 index) const {
    return (_mouse_state & SDL_BUTTON_MASK(index));
}

bool FLX_MouseDevice::is_mouse_button_pressed(const Uint8 index) const {
    const auto it = _mouse_button_states.find(index);
    return it != _mouse_button_states.end() && it->second == true;
}

inline float FLX_MouseDevice::get_mouse_x() const noexcept {
    return _mouse_x;
}

inline float FLX_MouseDevice::get_mouse_y() const noexcept {
    return _mouse_y;
}