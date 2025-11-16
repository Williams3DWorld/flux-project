#pragma once

#ifndef FLX_INPUT_MANAGER_H
#define FLX_INPUT_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>
#include "flx_service.h"
#include "types/flx_input_action.h"

class FLX_Event;
class FLX_InputDevice;

struct FLX_InputManagerConfig : FLX_ServiceConfig {
    std::unordered_map<std::string, InputAction> actions;
};

class FLX_InputManager final : public FLX_Service<FLX_InputManagerConfig> {
public:
    explicit FLX_InputManager(FLX_InputManagerConfig&& config);
    ~FLX_InputManager() override = default;

    [[nodiscard]] bool is_action(const std::string& identifier) const;

    void poll_events(FLX_Event& event) const noexcept;

private:
    std::unordered_map<FLX_InputDeviceType, std::shared_ptr<FLX_InputDevice>> _devices;
};

#endif