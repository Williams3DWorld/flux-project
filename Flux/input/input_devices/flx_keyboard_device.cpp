#include "flx_keyboard_device.h"

void FLX_KeyboardDevice::update_events(const SDL_Event& event) {
    if (event.type == SDL_EVENT_KEY_DOWN ||
        event.type == SDL_EVENT_KEY_UP) {
        _key_states[event.key.scancode] = (event.type == SDL_EVENT_KEY_DOWN);
    }
}

void FLX_KeyboardDevice::update() {
    _keyboard_state = SDL_GetKeyboardState(nullptr);
}

void FLX_KeyboardDevice::reset() {
    _key_states.clear();
}

inline bool FLX_KeyboardDevice::is_key_down(SDL_Scancode scancode) const {
    return _keyboard_state[scancode];
}

bool FLX_KeyboardDevice::is_key_pressed(SDL_Scancode scancode) const {
    const auto it = _key_states.find(scancode);
    return it != _key_states.end() && it->second == true;
}
