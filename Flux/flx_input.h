#pragma once

#ifndef FLX_INPUT_H
#define FLX_INPUT_H

#include "flx_mouse_device.h"
#include "flx_keyboard_device.h"

class FLX_Input {
public:
    void reset();
    void update();
    void update_events(const SDL_Event& event);

    //void remove_action_binding(const std::string& action_id);
    //void add_action_binding(const std::string& action_id, SDL_Scancode scancode);

    //const SDL_Scancode* get_action_binding(const std::string& action_id) const;

    bool is_key_down(SDL_Scancode scancode) const;
    bool is_key_pressed(SDL_Scancode scancode) const;

    //bool is_action_pressed(const std::string& action_id) const;
private:
    std::vector<FLX_InputDevice> _devices;
    //std::unordered_map<std::string, SDL_Scancode> _action_bindings;
};

#endif