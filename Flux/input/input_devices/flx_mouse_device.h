#pragma once

#ifndef FLX_MOUSE_DEVICE_H
#define FLX_MOUSE_DEVICE_H

#include "flx_input_device.h"
#include "../../types/flx_unordered_map.h"

class FLX_MouseDevice : public FLX_InputDevice {
public:
    float get_mouse_x() const noexcept;
    float get_mouse_y() const noexcept;

    void reset() override;
    void update() override;
    void update_events(const SDL_Event& event) override;

    bool is_mouse_button_down(Uint8 index) const;
    bool is_mouse_button_pressed(Uint8 index) const;
private:
    float _mouse_x = 0;
    float _mouse_y = 0;
    Uint32 _mouse_state = 0;
    flx_unordered_map<Uint8, bool> _mouse_button_states;
};

#endif