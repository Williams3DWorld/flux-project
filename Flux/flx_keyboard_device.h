#pragma once

#ifndef FLX_KEYBOARD_DEVICE_H
#define FLX_KEYBOARD_DEVICE_H

#include "flx_input_device.h"
#include <SDL3/SDL_scancode.h>
#include <unordered_map>
#include <vector>

class FLX_KeyboardDevice : protected  FLX_InputDevice {
public:
    void update() override;
    void update_events(const SDL_Event& event) override;
    void reset() override;

    bool is_key_down(SDL_Scancode scancode) const;
    bool is_key_pressed(SDL_Scancode scancode) const;
private:
    const bool* _keyboard_state = nullptr;
    std::unordered_map<SDL_Scancode, bool> _key_states;
};

#endif