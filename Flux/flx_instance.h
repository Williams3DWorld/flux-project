#pragma once

#ifndef FLX_INSTANCE_H
#define FLX_INSTANCE_H

#include "flx_window.h"
#include "services/input_manager/flx_input_manager.h"
#include "services/asset_manager/flx_asset_manager.h"
#include "services/render_manager/flx_render_manager.h"
#include "services/scene_manager/flx_scene_manager.h"

struct FLX_InstanceConfig : FLX_ObjectConfig {
    FLX_WindowConfig&& window;
    FLX_SceneManagerConfig&& scene_manager;
};

class FLX_Instance final : public FLX_Object<FLX_InstanceConfig> {
public:
    explicit FLX_Instance(FLX_InstanceConfig&& config);
    ~FLX_Instance() override = default;

    void run();

private:
    std::shared_ptr<FLX_Window> _window;

    std::shared_ptr<FLX_InputManager> _input_manager;
    std::shared_ptr<FLX_AssetManager> _asset_manager;
    std::shared_ptr<FLX_RenderManager> _render_manager;
    std::shared_ptr<FLX_SceneManager> _scene_manager;
};

#endif