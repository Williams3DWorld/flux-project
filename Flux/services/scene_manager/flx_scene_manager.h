#pragma once

#ifndef FLX_SCENE_MANAGER_H
#define FLX_SCENE_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>

#include "flx_service.h"
#include "scenes/flx_scene.h"

struct FLX_SceneManagerConfig : FLX_ServiceConfig {
    std::unordered_map<std::string, std::shared_ptr<FLX_Scene>> scenes;
};

class FLX_SceneManager final : public FLX_Service<FLX_SceneManagerConfig> {
public:
    explicit FLX_SceneManager(FLX_SceneManagerConfig&& config);
    ~FLX_SceneManager() override = default;

    bool set_active_scene(const std::string& scene_id);
    void update(float deltaTime);
private:
    FLX_Scene* _active_scene = nullptr;
};

#endif