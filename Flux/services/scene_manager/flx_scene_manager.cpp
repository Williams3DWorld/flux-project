#include "flx_scene_manager.h"

#include <ranges>

FLX_SceneManager::FLX_SceneManager(FLX_SceneManagerConfig&& config) : FLX_Service(std::move(config)) {
}

void FLX_SceneManager::register_scene(const std::string& scene_id, FLX_Scene* scene) {
    if (!_scenes.contains(scene_id)) {
        _scenes[scene_id] = scene;
    }
}

void FLX_SceneManager::set_active_scene(const std::string& scene_id) {
    const auto it = _scenes.find(scene_id);

    if (it == _scenes.end()) {
        return;
    }

    if (_active_scene == it->second) {
        return;
    }

    if (_active_scene != nullptr) {
        _active_scene->on_exit();
        _active_scene->set_is_active(false);
    }

    it->second->on_enter();
    it->second->set_is_active(true);
    _active_scene = it->second;
}

void FLX_SceneManager::update(float deltaTime) const {
    if (_active_scene) {
        _active_scene->update(deltaTime);
    }
}
