#include "flx_input_manager.h"
#include <SDL3/SDL_keyboard.h>

void FLX_InputManager::process_events(const SDL_Event& event) {
    if (event.type == SDL_EVENT_KEY_DOWN) {
        _key_states[event.key.scancode] = true;
    } else if (event.type == SDL_EVENT_KEY_UP) {
        _key_states[event.key.scancode] = false;
    }
}

void FLX_InputManager::update() {
    _keyboard_state = SDL_GetKeyboardState(nullptr);
}

// for resetting the _key_states array when using sdl_event key input
void FLX_InputManager::reset() {
    _key_states.clear();
}

bool FLX_InputManager::is_key_down(SDL_Scancode scancode) const {
    return _keyboard_state[scancode];
}

bool FLX_InputManager::is_key_pressed(SDL_Scancode scancode) const {
    const auto it = _key_states.find(scancode);
    return it != _key_states.end() && it->second == true;
}

const SDL_Scancode* FLX_InputManager::get_action_binding(const std::string& action_id) const {
    const auto it = _action_bindings.find(action_id);
    if (it != _action_bindings.end()) {
        return &it->second;
    }

    std::cout << "No action binding for action_id: " << action_id << std::endl;

    return nullptr;
}

bool FLX_InputManager::is_action_pressed(const std::string& action_id) const {
    if (const SDL_Scancode* scancode = get_action_binding(action_id)) {
        return _keyboard_state[*scancode];
    }

    return false;
}

void FLX_InputManager::remove_action_binding(const std::string &action_id) {
    _action_bindings.erase(_action_bindings.find(action_id));
}

void FLX_InputManager::add_action_binding(const std::string& action_id, SDL_Scancode scancode) {
    _action_bindings[action_id] = scancode;
}