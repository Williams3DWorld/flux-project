#include "flx_input_device.h"

FLX_InputDevice::FLX_InputDevice(FLX_InputDeviceConfig &&config) :
    FLX_Object(std::forward<FLX_InputDeviceConfig>(config)),
    _states({}) {}

bool FLX_InputDevice::is_active(const InputCode identifier) const {
    const auto it = _states.find(identifier);
    return it != _states.end() && it->second;
}