#pragma once

#ifndef FLX_KEYBOARD_DEVICE_H
#define FLX_KEYBOARD_DEVICE_H

#include <array>
#include "flx_input_device.h"
#include "flx_scancode.h"

class FLX_KeyboardDevice final : public  FLX_InputDevice {
public:
    FLX_KeyboardDevice();

    void update() override;
    void poll_events(const SDL_Event& event) override;

    [[nodiscard]] bool is_key_pressed(FLX_Scancode scancode) const;
private:
    std::array<bool, SDL_SCANCODE_COUNT> _previous_key_states;
    std::array<bool, SDL_SCANCODE_COUNT> _key_states;
};

#endif