#include "flx_keyboard_device.h"

FLX_KeyboardDevice::FLX_KeyboardDevice() {
    _key_states.reserve(SDL_SCANCODE_COUNT);
}

void FLX_KeyboardDevice::poll_events(const SDL_Event& event) {
    if (event.type == SDL_EVENT_KEY_DOWN ||
        event.type == SDL_EVENT_KEY_UP) {
        const auto scancode = static_cast<FLX_Scancode>(event.key.scancode);
        _key_states[scancode] = (event.type == SDL_EVENT_KEY_DOWN);
    }
}

void FLX_KeyboardDevice::update() {
    _keyboard_state = SDL_GetKeyboardState(nullptr);
}

inline bool FLX_KeyboardDevice::is_key_down(FLX_Scancode scancode) const {
    return _keyboard_state[static_cast<SDL_Scancode>(scancode)];
}

bool FLX_KeyboardDevice::is_key_pressed(FLX_Scancode scancode) const {
    const auto it = _key_states.find(scancode);
    return it != _key_states.end() && it->second == true;
}
