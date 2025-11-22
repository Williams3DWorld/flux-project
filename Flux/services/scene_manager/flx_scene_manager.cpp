#include "flx_scene_manager.h"

#include <ranges>

FLX_SceneManager::FLX_SceneManager(FLX_SceneManagerConfig&& config) : FLX_Service(std::move(config)) {}

void FLX_SceneManager::register_scene(const std::string& scene_id, std::unique_ptr<FLX_Scene> scene) {
    if (!_scenes.contains(scene_id)) {
        _scenes.emplace(scene_id, std::move(scene));
    }
}

void FLX_SceneManager::set_active_scene(const std::string& scene_id) {
    const auto it = _scenes.find(scene_id);

    if (it == _scenes.end()) {
        return;
    }

    if (_active_scene == it->second.get()) {
        return;
    }

    if (_active_scene != nullptr) {
        _active_scene->on_exit();
        _active_scene->set_is_active(false);
    }

    it->second->on_enter();
    it->second->set_is_active(true);
    _active_scene = it->second.get();
}

void FLX_SceneManager::update(float deltaTime) const {
    if (_active_scene) {
        _active_scene->update(deltaTime);
    }
}
