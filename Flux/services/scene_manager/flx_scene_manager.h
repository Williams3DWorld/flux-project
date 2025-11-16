#pragma once

#ifndef FLX_SCENE_MANAGER_H
#define FLX_SCENE_MANAGER_H

#include <string>
#include <unordered_map>
#include "flx_service.h"

struct FLX_SceneManagerConfig : FLX_ServiceConfig {
};

class FLX_Scene {
public:
    FLX_Scene() = default;
    ~FLX_Scene() = default;

    void on_enter() {}
    void on_exit() {}
    void update(float deltaTime) {}
    bool set_is_active(bool val) { _is_active = val; }
    bool is_active() const { return _is_active; }
private:
    bool _is_active = false;
};

class FLX_SceneManager final : public FLX_Service<FLX_SceneManagerConfig> {
public:
    explicit FLX_SceneManager(FLX_SceneManagerConfig&& config);
    ~FLX_SceneManager() override = default;

    void register_scene(const std::string& scene_id, FLX_Scene* scene);
    void set_active_scene(const std::string& scene_id);
    void update(float deltaTime) const;
private:
    FLX_Scene* _active_scene;
    std::unordered_map<std::string, FLX_Scene*> _scenes;
};

#endif