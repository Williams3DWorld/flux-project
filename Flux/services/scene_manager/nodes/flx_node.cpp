#include "flx_node.h"

void FLX_Node::addChild(std::unique_ptr<FLX_Node> child) {
    child->setParent(this);
    _children.emplace_back(std::move(child));
}

void FLX_Node::removeChild(FLX_Node* child) {
    const auto it = std::remove_if(
      _children.begin(),
      _children.end(),
      [&](const std::unique_ptr<FLX_Node>& ptr) {
        return ptr.get() == child;
      }
    );
    if (it != _children.end()) {
        child->setParent(nullptr);
        _children.erase(it, _children.end());
    }
}

void FLX_Node::removeAllChildren() {
    _children.clear();
}

void FLX_Node::setParent(FLX_Node* parent_node) {
    _parent = parent_node;
}

void FLX_Node::setEnabled(const bool value) {
    _enabled = value;
}

void FLX_Node::update(float deltaTime) const {
    for (const auto& child : _children) {
        child->update(deltaTime);
    }
}

