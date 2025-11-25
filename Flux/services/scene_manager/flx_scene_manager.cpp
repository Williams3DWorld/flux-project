#include "flx_scene_manager.h"

FLX_SceneManager::FLX_SceneManager(FLX_SceneManagerConfig&& config)
    : FLX_Service(std::forward<FLX_SceneManagerConfig>(config)) {}

bool FLX_SceneManager::set_active_scene(const std::string& scene_id) {
    const auto it = _config.scenes.find(scene_id);

    if (it == _config.scenes.end()) {
        return false;
    }

    if (_active_scene == it->second.get()) {
        return false;
    }

    if (_active_scene != nullptr) {
        _active_scene->on_exit();
        _active_scene->set_is_active(false);
    }

    it->second->on_enter();
    it->second->set_is_active(true);
    _active_scene = it->second.get();

    return true;
}

void FLX_SceneManager::update(float deltaTime) const {
    if (_active_scene) {
        _active_scene->update(deltaTime);
    }
}
