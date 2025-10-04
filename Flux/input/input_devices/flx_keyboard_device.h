#pragma once

#ifndef FLX_KEYBOARD_DEVICE_H
#define FLX_KEYBOARD_DEVICE_H

#include "../../types/flx_unordered_map.h"
#include "flx_input_device.h"
#include "flx_scancode.h"

class FLX_KeyboardDevice final : public  FLX_InputDevice {
public:
    FLX_KeyboardDevice();

    void update() override;
    void poll_events(const SDL_Event& event) override;

    [[nodiscard]] inline bool is_key_down(FLX_Scancode scancode) const;
    [[nodiscard]] bool is_key_pressed(FLX_Scancode scancode) const;
private:
    const bool* _keyboard_state = nullptr;
    flx_unordered_map<FLX_Scancode, bool> _key_states;
};

#endif