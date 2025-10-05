#include "flx_keyboard_device.h"
#include <ostream>

FLX_KeyboardDevice::FLX_KeyboardDevice() {
    _previous_key_states.fill(false);
    _key_states.fill(false);
}

void FLX_KeyboardDevice::poll_events(const SDL_Event& event) {
    if (event.type == SDL_EVENT_KEY_DOWN ||
        event.type == SDL_EVENT_KEY_UP) {
        const auto scancode = static_cast<FLX_Scancode>(event.key.scancode);
        _key_states[static_cast<size_t>(scancode)] = (event.type == SDL_EVENT_KEY_DOWN);
    }
}

void FLX_KeyboardDevice::update() {
    _previous_key_states = _key_states;
}

bool FLX_KeyboardDevice::is_key_pressed(FLX_Scancode scancode) const {
    const auto scancode_idx = static_cast<size_t>(scancode);
    return _key_states[scancode_idx] && !_previous_key_states[scancode_idx];
}
