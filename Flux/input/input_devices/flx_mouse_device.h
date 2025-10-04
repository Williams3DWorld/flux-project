#pragma once

#ifndef FLX_MOUSE_DEVICE_H
#define FLX_MOUSE_DEVICE_H

#include <array>
#include "types/flx_integer.h"
#include "flx_input_device.h"

constexpr int NUM_MOUSE_BUTTONS = 3;

class FLX_MouseDevice final : public FLX_InputDevice {
public:
    FLX_MouseDevice();

    void update() override;
    void poll_events(const SDL_Event& event) override;

    [[nodiscard]] inline float get_mouse_x() const noexcept;
    [[nodiscard]] inline float get_mouse_y() const noexcept;

    [[nodiscard]] bool is_mouse_button_pressed(ui8 index) const;
private:
    float _mouse_x = 0, _mouse_y = 0;
    std::array<bool, NUM_MOUSE_BUTTONS> _mouse_button_states;
};

#endif