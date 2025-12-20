#include "flx_scene.h"

void FLX_Scene::update(float deltaTime) const {
    for (auto& child : _children) {
        child->update(deltaTime);
    }
}