#pragma once

#ifndef FLX_INSTANCE_H
#define FLX_INSTANCE_H

#include "flx_window.h"
#include "core/flx_memory.h"
#include "services/asset_manager/flx_asset_manager.h"

struct FLX_InstanceConfig : FLX_ObjectConfig {
    FLX_WindowConfig&& window;
};

class FLX_Instance final : public FLX_Object<FLX_InstanceConfig> {
public:
    explicit FLX_Instance(FLX_InstanceConfig&& config);
    ~FLX_Instance() override = default;

    void run();

private:
    flx_shared<FLX_Window> _window;

    flx_shared<FLX_AssetManager> _asset_manager;
};

#endif