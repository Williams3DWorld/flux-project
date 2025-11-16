#include "flx_keyboard_device.h"
#include "flx_event.h"
#include "types/flx_event_types.h"

FLX_KeyboardDevice::FLX_KeyboardDevice(FLX_InputDeviceConfig &&config) :
    FLX_InputDevice(std::forward<FLX_InputDeviceConfig>(config)) {}

void FLX_KeyboardDevice::poll_events(FLX_Event &event) {
    const auto e = event.event();

    if (const auto type = e.type;
        type == static_cast<uint32_t>(FLX_EventType::KeyDown) ||
        type == static_cast<uint32_t>(FLX_EventType::KeyUp)) {

        const auto key = e.key;
        const auto scancode = InputCode{static_cast<FLX_Scancode>(key.scancode)};

        _states[scancode] = key.down;
    }
}