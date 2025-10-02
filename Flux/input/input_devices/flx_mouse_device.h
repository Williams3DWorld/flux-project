#pragma once

#ifndef FLX_MOUSE_DEVICE_H
#define FLX_MOUSE_DEVICE_H

#include "flx_input_device.h"
#include "../../types/flx_integer.h"
#include "../../types/flx_unordered_map.h"

class FLX_MouseDevice final : public FLX_InputDevice {
public:
    void reset() override;
    void update() override;
    void poll_events(const SDL_Event& event) override;

    [[nodiscard]] inline float get_mouse_x() const noexcept;
    [[nodiscard]] inline float get_mouse_y() const noexcept;

    [[nodiscard]] inline bool is_mouse_button_down(Uint8 index) const;
    [[nodiscard]] bool is_mouse_button_pressed(Uint8 index) const;
private:
    float _mouse_x = 0, _mouse_y = 0;
    ui32 _mouse_state = 0;
    flx_unordered_map<ui8, bool> _mouse_button_states;
};

#endif