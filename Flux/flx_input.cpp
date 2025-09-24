#include "flx_input.h"
#include <SDL3/SDL_keyboard.h>

void FLX_Input::process_events(const SDL_Event& event) {
    if (event.type == SDL_EVENT_KEY_DOWN) {
        _key_states[event.key.scancode] = true;
    } else if (event.type == SDL_EVENT_KEY_UP) {
        _key_states[event.key.scancode] = false;
    }
}

void FLX_Input::update() {
    _keyboard_state = SDL_GetKeyboardState(nullptr);
}

// for resetting the _key_states array when using sdl_event key input
void FLX_Input::reset() {
    _key_states.clear();
}

bool FLX_Input::is_key_down(SDL_Scancode scancode) const {
    return _keyboard_state[scancode];
}

bool FLX_Input::is_key_pressed(SDL_Scancode scancode) const {
    const auto it = _key_states.find(scancode);
    return it != _key_states.end() && it->second == true;
}

const SDL_Scancode* FLX_Input::get_action_binding(const std::string& action_id) const {
    const auto it = _action_bindings.find(action_id);
    if (it != _action_bindings.end()) {
        return &it->second;
    }

    return nullptr;
}

bool FLX_Input::is_action_pressed(const std::string& action_id) const {
    if (const SDL_Scancode* scancode = get_action_binding(action_id)) {
        return is_key_pressed(*scancode);
    }

    return false;
}

void FLX_Input::remove_action_binding(const std::string &action_id) {
    _action_bindings.erase(_action_bindings.find(action_id));
}

void FLX_Input::add_action_binding(const std::string& action_id, SDL_Scancode scancode) {
    _action_bindings[action_id] = scancode;
}