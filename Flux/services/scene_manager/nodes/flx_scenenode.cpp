#include "flx_scenenode.h"

void FLX_SceneNode::addChild(std::unique_ptr<FLX_SceneNode> child) {
    child->setParent(this);
    _children.emplace_back(std::move(child));
}

void FLX_SceneNode::removeChild(FLX_SceneNode* child) {
    const auto it = std::remove_if(
      _children.begin(),
      _children.end(),
      [&](const std::unique_ptr<FLX_SceneNode>& ptr) {
        return ptr.get() == child;
      }
    );
    if (it != _children.end()) {
        child->setParent(nullptr);
        _children.erase(it, _children.end());
    }
}

void FLX_SceneNode::removeAllChildren() {
    _children.clear();
}

void FLX_SceneNode::setParent(FLX_SceneNode* parent_node) {
    _parent = parent_node;
}

void FLX_SceneNode::setEnabled(const bool value) {
    _enabled = value;
}

void FLX_SceneNode::update(float deltaTime) const {
    for (const auto& child : _children) {
        if (child->isEnabled()) {
            child->update(deltaTime);
        }
    }
}

void FLX_SceneNode::render() const {
    this->renderSelf();

    for (const auto& child : _children) {
        if (child->isEnabled()) {
            child->render();
        }
    }
}
