#pragma once

#ifndef FLX_INPUT_MANAGER_H
#define FLX_INPUT_MANAGER_H

#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_events.h>
#include <iostream>
#include <unordered_map>

class FLX_InputManager
{
public:
    void reset();
    void update();
    void process_events(const SDL_Event& event);
    void remove_action_binding(const std::string& action_id);
    void add_action_binding(const std::string& action_id, SDL_Scancode scancode);

    const SDL_Scancode* get_action_binding(const std::string& action_id) const;

    bool is_key_down(SDL_Scancode scancode) const;
    bool is_key_pressed(SDL_Scancode scancode) const;
    bool is_action_pressed(const std::string& action_id) const;
private:
    const bool* _keyboard_state = nullptr;
    std::unordered_map<SDL_Scancode, bool> _key_states;
    std::unordered_map<std::string, SDL_Scancode> _action_bindings;
};

#endif