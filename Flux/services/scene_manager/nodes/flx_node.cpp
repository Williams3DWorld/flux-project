#include "flx_node.h"

void FLX_Node::addChild(std::unique_ptr<FLX_Node> child) {
    child->parent = this;
    _children.emplace_back(std::move(child));
}

void FLX_Node::removeChild(const std::unique_ptr<FLX_Node>& child) {
    std::erase(_children, child);
}

void FLX_Node::update(float deltaTime) const {
    for (auto& child : _children) {
        child->update(deltaTime);
    }
}

