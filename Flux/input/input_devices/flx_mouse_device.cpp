#include "flx_mouse_device.h"

FLX_MouseDevice::FLX_MouseDevice() {
    _mouse_button_states.fill(false);
}

void FLX_MouseDevice::poll_events(const SDL_Event& event) {
    if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN ||
        event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
        _mouse_button_states[static_cast<int>(event.button.button)]
                = (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN);
    }
}

void FLX_MouseDevice::update() {
    SDL_GetMouseState(&_mouse_x, &_mouse_y);
}

bool FLX_MouseDevice::is_mouse_button_pressed(const ui8 index) const {
    return _mouse_button_states[index];
}

inline float FLX_MouseDevice::get_mouse_x() const noexcept {
    return _mouse_x;
}

inline float FLX_MouseDevice::get_mouse_y() const noexcept {
    return _mouse_y;
}