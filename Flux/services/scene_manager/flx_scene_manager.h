#pragma once

#ifndef FLX_SCENE_MANAGER_H
#define FLX_SCENE_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>

#include "flx_service.h"
#include "flx_scene.h"

struct FLX_SceneManagerConfig : FLX_ServiceConfig {};

class FLX_SceneManager final : public FLX_Service<FLX_SceneManagerConfig> {
public:
    explicit FLX_SceneManager(FLX_SceneManagerConfig&& config);
    ~FLX_SceneManager() override = default;

    void register_scene(const std::string& scene_id, std::unique_ptr<FLX_Scene> scene);
    void set_active_scene(const std::string& scene_id);
    void update(float deltaTime) const;
private:
    FLX_Scene* _active_scene = nullptr; // pointer to the currently active scene
    std::unordered_map<std::string, std::unique_ptr<FLX_Scene>> _scenes;
};

#endif